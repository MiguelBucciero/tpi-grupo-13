#include "UsuarioManager.h"
#include "MenuRecepcionista.h"
#include "MenuAdministrador.h"
#include "MenuMedico.h"
#include "MedicoManager.h"
#include "rlutil.h"
#include <iostream>
#include <cstring>

using namespace std;

void UsuarioManager::login(){
    UsuarioArchivo archiU("Usuarios.dat");
    MenuRecepcionista menuR;
    MenuAdministrador menuA;
    MenuMedico menuM;

    bool encontrado = false;
    char nombre[50] = {}, contrasenia[50] = {};

    while (!encontrado) {
        rlutil::cls();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(50, 5); cout << " SISTEMA DE LOGIN ";
        rlutil::setColor(rlutil::WHITE);

        rlutil::locate(35, 8); cout << "Usuario: ";
        rlutil::locate(45, 8); cin.getline(nombre, 50);
        rlutil::locate(35, 9); cout << "Contrasenia: ";
        rlutil::locate(48, 9); cin.getline(contrasenia, 50);

        int cantidad = archiU.getCantidadRegistros();

        for (int i = 0; i < cantidad; i++) {
            Usuario usuario = archiU.Leer(i);

            if (strcmp(usuario.getNombreUsuario(), nombre) == 0 &&
                strcmp(usuario.getContrasenia(), contrasenia) == 0 &&
                usuario.getEstado() == true) {

                rlutil::cls();
                rlutil::setColor(rlutil::GREEN);
                rlutil::locate(50, 12); cout << "ACCESO CONCEDIDO!";
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
                rlutil::cls();

                int tipoRol = usuario.getRol().getRol();
                if (tipoRol == -1) {
                    menuA.menuAdministrador();
                } else if (tipoRol == 0) {
                    menuR.menuRecepcionista();
                } else {
                    menuM.menuMedico(usuario);
                }

                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            rlutil::setColor(rlutil::RED);
            rlutil::locate(35, 12); cout << "Usuario y/o contrasenia incorrecta. Intenta de nuevo...";
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
        }
    }

    rlutil::cls();
}

bool UsuarioManager::VerificarLoginDuplicados(const char *nombre, const char *contrasenia){
    int cantidad=_archivo.getCantidadRegistros();
    for(int i=0; i<cantidad; i++){
        Usuario usuario=_archivo.Leer(i);
        if(strcmp(usuario.getNombreUsuario(), nombre)==0&&
           strcmp(usuario.getContrasenia(), contrasenia)==0){
            return true;
        }
    }
    return false;
}

void UsuarioManager::cargarUsuario(){
    char nombre[50] = {}, contrasenia[50] = {};
    int tipoRol;

    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(45, 2);
    cout << "CARGA DE NUEVO USUARIO";
    rlutil::setColor(rlutil::WHITE);

    rlutil::locate(35, 4);
    rlutil::setColor(rlutil::CYAN);
    cout << "Nombre de usuario: ";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(55, 4);
    cin.getline(nombre, 50);

    rlutil::locate(35, 5);
    rlutil::setColor(rlutil::CYAN);
    cout << "Contrasenia (minimo 6 caracteres): ";
    rlutil::setColor(rlutil::WHITE);

    do{
        rlutil::locate(71, 5);
        cout<<"                                                    "; //limpia para que vuelva a escribir
        rlutil::locate(71, 5);
        cin.getline(contrasenia, 50);

        if(strlen(contrasenia)<6){
            rlutil::locate(35, 6);
            rlutil::setColor(rlutil::RED);
            cout<<"La contrasenia es muy corta. Intente de nuevo.";
            rlutil::setColor(rlutil::WHITE);
        }else{
            rlutil::locate(35, 6);
            cout<<"                                                    ";//limpia para que se vea los roles.
        }
    }while(strlen(contrasenia)<6);

    rlutil::locate(35, 7);
    rlutil::setColor(rlutil::CYAN);
    cout << "Tipo de Rol (-1=Administrador | 0=Recepcionista | 1=Medico): ";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(97, 7);
    cin >> tipoRol;
    cin.ignore();

    // Validación duplicados
    if (VerificarLoginDuplicados(nombre, contrasenia)) {
        rlutil::setColor(rlutil::COLOR::RED);
        rlutil::locate(35, 9);
        cout << "Ya existe un usuario con ese nombre y contrasenia.";
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return;
    }

    Usuario usuario;
    const char* nombreRol;

    if (tipoRol == -1) {
        nombreRol = "Administrador";
    } else if (tipoRol == 0) {
        nombreRol = "Recepcionista";
    } else {
        nombreRol = "Medico";
        rlutil::cls();
        rlutil::locate(40, 3);
        cout << "Cargando datos del medico asociado...";
        MedicoManager medicM;
        int idMedico = medicM.cargarMedico();
        if (idMedico == -1) {
            rlutil::locate(40, 5);
            rlutil::setColor(rlutil::RED);
            cout << "No se pudo cargar correctamente el ID del medico.";
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
            rlutil::cls();
            return;
        }
        usuario.setIDMedico(idMedico);
    }

    Rol rol(tipoRol, nombreRol);

    usuario.setNombreUsuario(nombre);
    usuario.setContrasenia(contrasenia);
    usuario.setTipoRol(rol);
    usuario.setEstado(true);

    rlutil::locate(35, 9);
    if (_archivo.guardar(usuario)) {
        rlutil::setColor(rlutil::GREEN);
        cout << "Usuario guardado con exito.";
    } else {
        rlutil::setColor(rlutil::RED);
        cout << "Error al guardar el usuario.";
    }

    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void UsuarioManager::mostrarUsuario(){
    int contadorPantalla, fila, cantidad = _archivo.getCantidadRegistros();
    if (cantidad == 0) {
        rlutil::cls();
        rlutil::locate(40, 10);
        rlutil::setColor(rlutil::RED);
        cout << "No hay usuarios cargados." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return;
    }

    Usuario* vecUsuarios = new Usuario[cantidad];
    _archivo.leerMuchos(vecUsuarios, cantidad);

    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(45, 2);
    cout << " LISTADO DE USUARIOS ";
    rlutil::setColor(rlutil::WHITE);

    contadorPantalla = 0;
    fila = 4;

    for (int i = 0; i < cantidad; i++) {
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::locate(30, fila);
        cout << "------------------------------------------------------------";
        rlutil::locate(30, fila + 7);
        cout << "------------------------------------------------------------";

        rlutil::locate(32, fila + 1);
        rlutil::setColor(rlutil::CYAN);
        cout << "Usuario: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecUsuarios[i].getNombreUsuario();

        rlutil::locate(32, fila + 2);
        rlutil::setColor(rlutil::CYAN);
        cout << "Contrasenia: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecUsuarios[i].getContrasenia();

        rlutil::locate(32, fila + 3);
        rlutil::setColor(rlutil::CYAN);
        cout << "Rol: ";
        rlutil::setColor(rlutil::WHITE);

        if (vecUsuarios[i].getRol().getRol() < 0) {
            cout << "Administrador";
        } else if (vecUsuarios[i].getRol().getRol() == 0) {
            cout << "Recepcionista";
        } else {
            cout << "Medico";
            rlutil::locate(32, fila + 4);
            rlutil::setColor(rlutil::CYAN);
            cout << "ID Medico: ";
            rlutil::setColor(rlutil::WHITE);
            cout << vecUsuarios[i].getIDMedico();
        }

        rlutil::locate(32, fila + 5);
        rlutil::setColor(rlutil::CYAN);
        cout << "Estado: ";
        rlutil::setColor(rlutil::WHITE);
        if(vecUsuarios[i].getEstado()){
            cout << "Activo";
        } else {
            cout << "Inactivo";
        }

        fila += 9;
        contadorPantalla++;

        if (contadorPantalla == 2 && i < cantidad - 1) {
            rlutil::locate(40, fila);
            rlutil::setColor(rlutil::YELLOW);
            cout << "Presione una tecla para ver mas usuarios...";
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
            rlutil::cls();
            rlutil::locate(45, 2);
            rlutil::setColor(rlutil::YELLOW);
            cout << " LISTADO DE USUARIOS ";
            rlutil::setColor(rlutil::WHITE);
            fila = 4;
            contadorPantalla = 0;
        }
    }

    delete[] vecUsuarios;

    rlutil::locate(40, fila);
    rlutil::setColor(rlutil::YELLOW);
    cout << "Fin del listado. Presione una tecla para continuar...";
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void UsuarioManager::DarBajaUsuario(){
    char user[50];
    bool encontrado = false;

    while (!encontrado) {
        rlutil::cls();
        rlutil::setColor(rlutil::COLOR::YELLOW);
        rlutil::locate(40, 3);
        cout << " DAR DE BAJA USUARIO ";

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 6);
        cout << "Ingrese el nombre del usuario a dar de baja: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(75, 6);
        cin >> user;

        int pos = _archivo.Buscar(user);
        Usuario posUsuario;

        if (pos == -1) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "Usuario no encontrado. Intente nuevamente.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            continue;
        }

        posUsuario = _archivo.Leer(pos);
        if (!posUsuario.getEstado()) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "El usuario ya esta dado de baja.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            continue;
        }

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 9);
        cout << "Esta seguro que desea dar de baja a '" << user << "'? (s/n): ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        char confirmacion;
        cin >> confirmacion;

        if (confirmacion == 's' || confirmacion == 'S') {
            posUsuario.setEstado(false);
            if (_archivo.guardar(posUsuario, pos)) {
                rlutil::setColor(rlutil::COLOR::GREEN);
                rlutil::locate(30, 11);
                cout << "Usuario dado de baja correctamente.";
            } else {
                rlutil::setColor(rlutil::COLOR::RED);
                rlutil::locate(30, 11);
                cout << "Error al intentar modificar el archivo.";
            }
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            encontrado = true;
        } else {
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, 11);
            cout << "Accion cancelada por el usuario.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            encontrado = true;
        }
    }

    rlutil::cls();
}

void UsuarioManager::modificarUsuario(){
    char user[50], nuevoNombre[50], nuevaContrasenia[50];;
    char confirmacion;
    int nuevoRol;
    bool modificado = false;

    while (!modificado) {
        rlutil::cls();
        rlutil::setColor(rlutil::COLOR::YELLOW);
        rlutil::locate(40, 3);
        cout << " MODIFICAR USUARIO ";

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 6);
        cout << "Ingrese el nombre del usuario a modificar: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(73, 6);
        cin >> user;

        int pos = _archivo.Buscar(user);
        Usuario usuario;

        if (pos == -1) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "Usuario no encontrado. Intente nuevamente.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            continue;
        }

        usuario = _archivo.Leer(pos);

        if (!usuario.getEstado()) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "El usuario está dado de baja. No se puede modificar.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            continue;
        }

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 9);
        cout << "Esta seguro que desea modificar al usuario '" << user << "'? (s/n): ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        cin >> confirmacion;
        cin.ignore();

        if (confirmacion != 's' && confirmacion != 'S') {
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, 11);
            cout << "Modificacion cancelada por el usuario.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            break;
        }

        rlutil::cls();
        rlutil::setColor(rlutil::COLOR::YELLOW);
        rlutil::locate(40, 3);
        cout << " INGRESO DE NUEVOS DATOS ";

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 6);
        cout << "Nuevo nombre de usuario: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 6);
        cin.getline(nuevoNombre, 50);

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 7);
        cout << "Nueva contrasenia (minimo 6 caracteres): ";
        rlutil::setColor(rlutil::COLOR::WHITE);

        do{
            rlutil::locate(71, 7);
            cout<<"                                                    "; //limpia para que vuelva a escribir
            rlutil::locate(71, 7);
            cin.getline(nuevaContrasenia, 50);

            if(strlen(nuevaContrasenia)<6){
                rlutil::locate(35, 8);
                rlutil::setColor(rlutil::RED);
                cout<<"La contrasenia es muy corta. Intente de nuevo.";
                rlutil::setColor(rlutil::WHITE);
            }else{
                rlutil::locate(35, 8);
                cout<<"                                                    "; //limpia para que se vea los roles.
            }
        }while(strlen(nuevaContrasenia)<6);

        // Validación duplicados
        if (VerificarLoginDuplicados(nuevoNombre, nuevaContrasenia)) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(35, 9);
            cout << "Ya existe un usuario con ese nombre y contrasenia.";
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
            rlutil::cls();
            return;
        }

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 8);
        cout << "Nuevo Rol ID ( -1:Administrador | 0:Recepcionista | 1:Medico ): ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(94, 8);
        cin >> nuevoRol;
        cin.ignore();

        Rol nuevoRolObj;
        nuevoRolObj.setTipoRol(nuevoRol);

        usuario.setNombreUsuario(nuevoNombre);
        usuario.setContrasenia(nuevaContrasenia);
        usuario.setTipoRol(nuevoRolObj);

        if (_archivo.guardar(usuario, pos)) {
            rlutil::setColor(rlutil::COLOR::GREEN);
            rlutil::locate(30, 10);
            cout << "Usuario modificado correctamente.";
        } else {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 10);
            cout << "Error al intentar modificar el usuario.";
        }

        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        modificado = true;
    }

    rlutil::cls();
}

void UsuarioManager::CantidadUsuariosActivos(){
    int cantidad=_archivo.getCantidadRegistros();

    int cont=0;
    Usuario usuario;

    for(int i=0; i<cantidad; i++){
        usuario=_archivo.Leer(i);
        if(usuario.getEstado()){
            cont++;
        }
    }
    rlutil::cls();
    if(cont==0){
        rlutil::locate(45, 10);
        rlutil::setColor(rlutil::RED);
        cout<<"NO HAY USUARIOS ACTIVOS."<<endl;
    }else{
        rlutil::setColor(rlutil::COLOR::GREEN);
        rlutil::locate(45, 10);
        cout<<"CANTIDAD DE USUARIOS ACTIVOS: "<<cont<<endl;
    }

    rlutil::locate(45, 20);
    rlutil::setColor(rlutil::YELLOW);
    cout << "Presione una tecla para continuar...";
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void UsuarioManager::reactivarUsuario(){

    int contador, fila, cantidad, posicion, contadorInactivos;
    char confirmacion;

    cantidad = _archivo.getCantidadRegistros();
    if (cantidad == 0) {
        rlutil::cls();
        rlutil::locate(40, 10);
        rlutil::setColor(rlutil::RED);
        cout << "No hay usuarios cargados." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return;
    }

    Usuario* vecUsuarios = new Usuario[cantidad];
    _archivo.leerMuchos(vecUsuarios, cantidad);

    contadorInactivos = 0;
    for(int x = 0; x < cantidad; x++){
        if(vecUsuarios[x].getEstado()==false){
            contadorInactivos++;
        }
    }

    if(contadorInactivos==0){
        delete[] vecUsuarios;
        rlutil::locate(40, 9);
        rlutil::setColor(rlutil::COLOR::RED);
        cout<<"No hay usuarios inactivos...";
         rlutil::locate(40, 11);
        rlutil::setColor(rlutil::COLOR::GREEN);
        cout << "Presione una tecla para continuar...";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return;
    }

    contador = 0;
    fila = 4;
    for (int i = 0; i < cantidad; i++) {

        if(vecUsuarios[i].getEstado()==false){

            rlutil::cls();
            rlutil::setColor(rlutil::YELLOW);
            rlutil::locate(45, 2);
            cout << " LISTADO DE USUARIOS INACTIVOS ";
            rlutil::setColor(rlutil::WHITE);
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(50, 3);
            cout << " USUARIOS " << (contador + 1) << " DE " << contadorInactivos;
            rlutil::setColor(rlutil::COLOR::WHITE);

            rlutil::setBackgroundColor(rlutil::BLACK);
            rlutil::locate(30, fila);
            cout << "------------------------------------------------------------";
            rlutil::locate(30, fila + 7);
            cout << "------------------------------------------------------------";

            rlutil::locate(32, fila + 1);
            rlutil::setColor(rlutil::CYAN);
            cout << "Usuario: ";
            rlutil::setColor(rlutil::WHITE);
            cout << vecUsuarios[i].getNombreUsuario();

            rlutil::locate(32, fila + 2);
            rlutil::setColor(rlutil::CYAN);
            cout << "Contrasenia: ";
            rlutil::setColor(rlutil::WHITE);
            cout << vecUsuarios[i].getContrasenia();

            rlutil::locate(32, fila + 3);
            rlutil::setColor(rlutil::CYAN);
            cout << "Rol: ";
            rlutil::setColor(rlutil::WHITE);

            if (vecUsuarios[i].getRol().getRol() < 0) {
                cout << "Administrador";
            } else if (vecUsuarios[i].getRol().getRol() == 0) {
                cout << "Recepcionista";
            } else {
                cout << "Medico";
                rlutil::locate(32, fila + 4);
                rlutil::setColor(rlutil::CYAN);
                cout << "ID Medico: ";
                rlutil::setColor(rlutil::WHITE);
                cout << vecUsuarios[i].getIDMedico();
            }

            rlutil::locate(32, fila + 5);
            rlutil::setColor(rlutil::COLOR::GREEN);
            cout<<"DESEA ACTIVAR EL USUARIO? (s/n): ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cin >> confirmacion;

            if (confirmacion == 's' || confirmacion == 'S') {
                vecUsuarios[i].setEstado(true);
                posicion = _archivo.Buscar(vecUsuarios[i].getNombreUsuario());
                if(_archivo.guardar(vecUsuarios[i], posicion)){
                        rlutil::locate(32, fila + 6);
                        rlutil::setColor(rlutil::COLOR::GREEN);
                        cout<<"Paciente activado correctamente.";
                    }else{
                        rlutil::locate(32, fila + 6);
                        rlutil::setColor(rlutil::COLOR::RED);
                        cout<<"Error al guardar el paciente.";
                    }
                }else{
                    rlutil::setColor(rlutil::COLOR::YELLOW);
                    rlutil::locate(32,fila + 6);
                    cout << "Accion cancelada.";
                    rlutil::setColor(rlutil::COLOR::WHITE);
                }

                if(contador +1 == contadorInactivos){
                    delete[] vecUsuarios;
                    rlutil::locate(40, fila+8);
                    rlutil::setColor(rlutil::YELLOW);
                    cout << "Fin del listado. Presione una tecla para volver...";
                    rlutil::setColor(rlutil::WHITE);
                    rlutil::anykey();
                    rlutil::cls();
                }
                else{
                    rlutil::locate(40, fila+8);
                    rlutil::setColor(rlutil::YELLOW);
                    cout << "Presione una tecla para ver mas usuarios...";
                    rlutil::setColor(rlutil::WHITE);
                    rlutil::anykey();
                    rlutil::cls();
                }

                contador++;
        }
    }

}
