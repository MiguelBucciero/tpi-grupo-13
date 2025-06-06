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
    cout << "Contrasenia: ";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(55, 5);
    cin.getline(contrasenia, 50);

    rlutil::locate(35, 6);
    rlutil::setColor(rlutil::CYAN);
    cout << "Tipo de Rol (-1=Administrador | 0=Recepcionista | 1=Medico): ";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(97, 6);
    cin >> tipoRol;
    cin.ignore();

    // Validación duplicados
    if (VerificarLoginDuplicados(nombre, contrasenia)) {
        rlutil::setColor(rlutil::COLOR::RED);
        rlutil::locate(35, 8);
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
        rlutil::locate(30, fila); cout << "------------------------------------------------------------";
        rlutil::locate(30, fila + 7); cout << "------------------------------------------------------------";

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
            cout << "Presione una tecla para ver más usuarios...";
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
    char user[50]= {};
    cout<<"Ingrese el nombre del usuario a dar de baja: ";
    cin>>user;

    int pos=_archivo.Buscar(user);
    if(pos==-1){
        cout<<"Usuario no encontrado"<<endl;
        system("pause");
        return;
    }

    Usuario posUsuario=_archivo.Leer(pos);

    if(!posUsuario.getEstado()){
        cout<<"Usuario ya dado de baja"<<endl;
        system("pause");
        return;

    }

    posUsuario.setEstado(false);

    if(_archivo.guardar(posUsuario, pos)){
        cout<<"Usuario dado de baja correctamente"<<endl;
    } else{
    cout<<"No se pudo modificar el archivo"<<endl;
    }
    system ("pause");
    system("cls");
}


void UsuarioManager::modificarUsuario(){
    char user[50];
    cout<<"Ingrese nombre del usuario que desea modificar: ";
    cin>>user;

    int pos=_archivo.Buscar(user);
    if(pos==-1){
        cout<<"Usuario no encontrado"<<endl;
            system ("pause");
        return;
    }
    Usuario usuario=_archivo.Leer(pos);
    if(!usuario.getEstado()){
        cout<<"El usuario ingresado esta dado de baja, no se puede modificar"<<endl;
    system ("pause");
        return;
    }

    char nombre[50];
    char contrasenia[50];
    Rol nuevoRol;
    int rol;

    cin.ignore();

    cout<<"Nombre actual del usuario: "<<usuario.getNombreUsuario()<<endl;
    cout<<"Ingrese el nuevo nombre de usuario: ";
    cin>>nombre;
    cout<<endl;

    cout<<"Contrasenia actual del usuario: "<<usuario.getContrasenia()<<endl;
    cout<<"Ingrese la nueva contrasenia de usuario: ";
    cin>>contrasenia;
    cout<<endl;

    cout<<"Rol ID actual del usuario: "<<usuario.getRol().getRol()<<endl;
    cout<<"Ingrese el nuevo Rol ID del usuario: ";
    cin>>rol;

    cout<<endl;

    nuevoRol.setTipoRol(rol);
    usuario.setTipoRol(nuevoRol);

    usuario.setNombreUsuario(nombre);
    usuario.setContrasenia(contrasenia);
    usuario.setTipoRol(nuevoRol);

   if(_archivo.guardar(usuario, pos)){
        cout<<"Usuario modificada correctamente"<<endl;

    }else{
        cout<<"No se pudo modificar el archivo"<<endl;

    }
    system ("pause");
    system("cls");
}
