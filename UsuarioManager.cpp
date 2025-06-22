#include "UsuarioManager.h"
#include "MenuRecepcionista.h"
#include "MenuAdministrador.h"
#include "MenuMedico.h"
#include "MedicoManager.h"
#include "Validador.h"
#include "rlutil.h"
#include <iostream>
#include <string>


using namespace std;

void UsuarioManager::login(){
    MenuRecepcionista menuR;
    MenuAdministrador menuA;
    MenuMedico menuM;

    bool encontrado = false;
    string nombre, contrasenia;

    while (!encontrado) {
        rlutil::cls();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(50, 5);
        cout << " SISTEMA DE LOGIN ";
        rlutil::setColor(rlutil::WHITE);

        rlutil::locate(35, 8);
        cout << "Usuario: ";
        rlutil::locate(45, 8);
        cin>> nombre;
        rlutil::locate(35, 9);
        cout << "Contrasenia: ";
        rlutil::locate(48, 9);
        cin>> contrasenia;

        int cantidad = _archivo.getCantidadRegistros();

        for (int i = 0; i < cantidad; i++) {
            Usuario usuario = _archivo.Leer(i);

            if (usuario.getNombreUsuario()==nombre &&
                usuario.getContrasenia()==contrasenia&&
                usuario.getEstado() == true) {

                rlutil::cls();
                rlutil::setColor(rlutil::GREEN);
                rlutil::locate(50, 12);
                cout << "ACCESO CONCEDIDO!";
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
            rlutil::locate(35, 12);
            cout << "Usuario y/o contrasenia incorrecta. Intenta de nuevo...";
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
        }
    }

    rlutil::cls();
}

bool UsuarioManager::VerificarLoginDuplicados(const string &nombre, const string &contrasenia){
    int cantidad=_archivo.getCantidadRegistros();
    for(int i=0; i<cantidad; i++){
        Usuario usuario=_archivo.Leer(i);
        if(usuario.getNombreUsuario()==nombre&&usuario.getContrasenia()==contrasenia){
            return true;
        }
    }
    return false;
}

void UsuarioManager::cargarUsuario(){
    string nombre, contrasenia, nombreRol;
    int tipoRol;
    Validador val;
    bool rolValido = false;

    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(45, 2);
    cout << "CARGA DE NUEVO USUARIO";
    rlutil::setColor(rlutil::WHITE);

    // Validacion de nombre de usuario
    do {
        rlutil::locate(35, 4);
        rlutil::setColor(rlutil::CYAN);
        cout << "Nombre de usuario (solo letras): ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(69, 4);
        cout << "                                                                   ";
        rlutil::locate(69, 4);
        cin.clear();
        cin.ignore(1000, '\n');
        getline(cin, nombre);

        if (!val.esTextoSinEspacios(nombre)) {
            rlutil::locate(35, 8);
            rlutil::setColor(rlutil::RED);
            cout << "Nombre invalido. Use solo letras sin numeros ni simbolos.";
            rlutil::setColor(rlutil::YELLOW);
            rlutil::locate(35, 9);
            cout << "Presione un tecla para continuar...";
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
            rlutil::locate(35, 8);
            cout << "                                                                ";
            rlutil::locate(35, 9);
            cout << "                                                                ";
        }
    } while (!val.esTextoSinEspacios(nombre));



    do{
        rlutil::locate(35, 5);
        rlutil::setColor(rlutil::CYAN);
        cout << "Contrasenia (minimo 6 caracteres): ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(71, 5);
        cout<<"                                                    ";
        rlutil::locate(71, 5);
        cin>>contrasenia;

        if(contrasenia.length()<6){
            rlutil::locate(35, 8);
            rlutil::setColor(rlutil::RED);
            cout<<"La contrasenia es muy corta. Intente de nuevo.";
            rlutil::setColor(rlutil::YELLOW);
            rlutil::locate(35, 9);
            cout << "Presione un tecla para continuar...";
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
            rlutil::locate(35, 8);
            cout<<"                                                 ";
            rlutil::locate(35, 9);
            cout<<"                                                 ";

        }else{
            rlutil::locate(35, 6);
            cout<<"                                                    ";
        }
    }while(contrasenia.length()<6);


    // Validacion duplicados
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
    nombreRol = "Desconocido";
    do{
        rlutil::locate(35, 7);
        rlutil::setColor(rlutil::CYAN);
        cout << "Tipo de Rol (-1=Administrador | 0=Recepcionista | 1=Medico): ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(97, 7);
        cout<<"         "<<endl;
        rlutil::locate(97, 7);
        cin >> tipoRol;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            rolValido = false;// Marcar como invalido
            rlutil::locate(35, 9);
            rlutil::setColor(rlutil::RED);
            cout << "Rol invalido. Solo puede ingresar -1, 0 o 1.";
            rlutil::setColor(rlutil::YELLOW);
            rlutil::locate(35, 10);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();

            // Limpiar las lineas
            rlutil::locate(35, 9);
            cout << "                                                        ";
            rlutil::locate(35, 10);
            cout << "                                                        ";
            rlutil::locate(97, 7);
            cout << "         ";
        }
        // Validar que el numero este dentro de los valores permitidos
        else if (tipoRol != -1 && tipoRol != 0 && tipoRol != 1) {
            rolValido = false; // Marcar como invalido
            rlutil::locate(35, 9);
            rlutil::setColor(rlutil::RED);
            cout << "Rol inv�lido. Solo puede ingresar -1, 0 o 1.";
            rlutil::setColor(rlutil::YELLOW);
            rlutil::locate(35, 10);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();

            rlutil::locate(35, 9);
            cout << "                                                        ";
            rlutil::locate(35, 10);
            cout << "                                                        ";
        }
        else{
            rolValido = true; // Marcar como valido
            rlutil::locate(35, 9);
            cout << "                                                        ";
            rlutil::locate(35, 10);
            cout << "                                                        ";

            // Asignar nombre del rol
            if (tipoRol == -1){
                nombreRol = "Administrador";
            }
            else if (tipoRol == 0) {
                nombreRol = "Recepcionista";
            }
            else if (tipoRol == 1) {
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
        }
    }while(!rolValido);

    Rol rol(tipoRol, nombreRol.c_str());

    // Configurar el usuario
    usuario.setNombreUsuario(nombre);
    usuario.setContrasenia(contrasenia);
    usuario.setTipoRol(rol);
    usuario.setEstado(true);

    // Guardar el usuario
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
        cout << "No hay usuarios cargados.";
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
    string user;
    char confirmacion;
    bool confirmacionValida, encontrado;
    Validador val;

    encontrado=false;
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
        cin>>user;

        // Validacion del nombre ingresado
        if (!val.esTextoSinEspacios(user)) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "Nombre invalido. Use solo letras sin numeros ni simbolos.";
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, 9);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            continue;
        }

        int pos = _archivo.Buscar(user);
        Usuario posUsuario;

        if (pos == -1) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "Usuario no encontrado. Presione enter e intente nuevamente.";
            rlutil::anykey();
        }else{
             posUsuario = _archivo.Leer(pos);
             if (!posUsuario.getEstado()) {
                rlutil::setColor(rlutil::COLOR::RED);
                rlutil::locate(30, 8);
                cout << "El usuario ya esta dado de baja. Presione enter e intente nuevamente.";
                rlutil::setColor(rlutil::COLOR::YELLOW);
                rlutil::locate(30, 9);
                cout << "Presione una tecla para continuar...";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
            }else{
                confirmacionValida = false;
                cin.ignore();
                do {
                    rlutil::setColor(rlutil::COLOR::CYAN);
                    rlutil::locate(30, 9);
                    cout << "Esta seguro que desea dar de baja a '" << user << "'? (s/n): ";
                    rlutil::setColor(rlutil::COLOR::WHITE);
                    rlutil::locate(85, 9);
                    cin >> confirmacion;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        rlutil::setColor(rlutil::COLOR::RED);
                        rlutil::locate(30, 11);
                        cout << "Opcion invalida. Ingrese 's' o 'n'.";
                        rlutil::setColor(rlutil::COLOR::YELLOW);
                        rlutil::locate(30, 12);
                        cout << "Presione una tecla para continuar...";
                        rlutil::setColor(rlutil::COLOR::WHITE);
                        rlutil::anykey();
                        rlutil::locate(30, 11);
                        cout << "                                                     ";
                        rlutil::locate(30, 12);
                        cout << "                                                     ";
                        rlutil::locate(85, 9);
                        cout << "                                                     ";
                    }
                    else if(!val.esConfirmacionSN(confirmacion)){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        rlutil::setColor(rlutil::COLOR::RED);
                        rlutil::locate(30, 11);
                        cout << "Opcion invalida. Ingrese 's' o 'n'.";
                        rlutil::setColor(rlutil::COLOR::YELLOW);
                        rlutil::locate(30, 12);
                        cout << "Presione una tecla para continuar...";
                        rlutil::setColor(rlutil::COLOR::WHITE);
                        rlutil::anykey();
                        rlutil::locate(30, 11);
                        cout << "                                                     ";
                        rlutil::locate(30, 12);
                        cout << "                                                     ";
                        rlutil::locate(85, 9);
                        cout << "                                                     ";
                    }
                    else{
                        confirmacionValida = true;
                    }

                } while (!confirmacionValida);

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

            } else {
                rlutil::setColor(rlutil::COLOR::YELLOW);
                rlutil::locate(30, 11);
                cout << "Accion cancelada por el usuario.";
            }
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            encontrado = true;
            }
        }
        rlutil::setColor(rlutil::COLOR::WHITE);
    }

    rlutil::cls();
}

void UsuarioManager::modificarUsuario() {
    string user, nuevoNombre, nuevaContrasenia;
    char confirmacion;
    int nuevoRol, pos;
    bool  confirmacionValida = false, nombreValido=false, modificado = false, nuevoNombreValido = false, contraseniaValida = false, rolValido = false;
    Usuario usuario;
    Validador validador;

    while (!modificado) {
        rlutil::cls();
        rlutil::setColor(rlutil::COLOR::YELLOW);
        rlutil::locate(40, 3);
        cout << " MODIFICAR USUARIO ";

        // Validacion del nombre de usuario a buscar
        while (!nombreValido) {
            rlutil::setColor(rlutil::COLOR::CYAN);
            rlutil::locate(30, 6);
            cout << "Ingrese el nombre del usuario a modificar: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::locate(73, 6);
            cin >> user;

            if (validador.esTextoSinEspacios(user)) {
                nombreValido = true;
            } else {
                rlutil::setColor(rlutil::COLOR::RED);
                rlutil::locate(30, 8);
                cout << "Nombre de usuario invalido. Debe contener solo letras, sin espacios.";
                rlutil::setColor(rlutil::COLOR::YELLOW);
                rlutil::locate(30, 9);
                cout << "Presione una tecla para continuar...";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
                rlutil::locate(30, 8);
                cout << "                                                                        ";
                rlutil::locate(30, 9);
                cout << "                                                                        ";
                rlutil::locate(73, 6);
                cout << "                                                                        ";
            }
        }

        pos = _archivo.Buscar(user);

        if (pos == -1) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "Usuario no encontrado. Intente nuevamente.";
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, 9);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(30, 8);
            cout << "                                                                        ";
            rlutil::locate(30, 9);
            cout << "                                                                        ";
            rlutil::locate(73, 6);
            cout << "                                                                        ";
            nombreValido = false;
        } else {
            usuario = _archivo.Leer(pos);
            if (!usuario.getEstado()) {
                rlutil::setColor(rlutil::COLOR::RED);
                rlutil::locate(30, 8);
                cout << "El usuario esta dado de baja. No se puede modificar.";
                rlutil::setColor(rlutil::COLOR::YELLOW);
                rlutil::locate(30, 9);
                cout << "Presione una tecla para continuar...";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
                rlutil::locate(30, 8);
                cout << "                                                                        ";
                rlutil::locate(30, 9);
                cout << "                                                                        ";
                rlutil::locate(73, 6);
                cout << "                                                                        ";
                nombreValido = false;

            } else {
                while (!confirmacionValida) {
                    rlutil::setColor(rlutil::COLOR::CYAN);
                    rlutil::locate(30, 9);
                    cout << "Esta seguro que desea modificar al usuario '" << user << "'? (s/n): ";
                    rlutil::setColor(rlutil::COLOR::WHITE);
                    rlutil::locate(90, 9);
                    cin >> confirmacion;

                    if (cin.fail() || !validador.esConfirmacionSN(confirmacion)) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        rlutil::setColor(rlutil::COLOR::RED);
                        rlutil::locate(30, 11);
                        cout << "Respuesta invalida. Ingrese 's' para Si o 'n' para No.";
                        rlutil::setColor(rlutil::COLOR::YELLOW);
                        rlutil::locate(30, 12);
                        cout << "Presione una tecla para continuar...";
                        rlutil::setColor(rlutil::COLOR::WHITE);
                        rlutil::anykey();
                        rlutil::locate(30, 11);
                        cout << "                                                                        ";
                        rlutil::locate(30, 12);
                        cout << "                                                                        ";
                        rlutil::locate(90, 9);
                        cout << "                                                                        ";
                    } else {
                        confirmacionValida = true;
                    }
                }

                if (confirmacion == 's' || confirmacion == 'S') {
                    rlutil::cls();
                    rlutil::setColor(rlutil::COLOR::YELLOW);
                    rlutil::locate(40, 3);
                    cout << " INGRESO DE NUEVOS DATOS ";

                    // Validacion del nuevo nombre de usuario
                    while (!nuevoNombreValido) {
                        rlutil::setColor(rlutil::COLOR::CYAN);
                        rlutil::locate(30, 6);
                        cout << "Nuevo nombre de usuario (sin espacios): ";
                        rlutil::setColor(rlutil::COLOR::WHITE);
                        rlutil::locate(71, 6);
                        cin.ignore();
                        cin >> nuevoNombre;

                        if (validador.esTextoSinEspacios(nuevoNombre)) {
                            nuevoNombreValido = true;
                        } else {
                            rlutil::setColor(rlutil::COLOR::RED);
                            rlutil::locate(30, 8);
                            cout << "Nombre invalido. Debe contener solo letras, sin espacios.";
                            rlutil::setColor(rlutil::COLOR::YELLOW);
                            rlutil::locate(30, 9);
                            cout << "Presione una tecla para continuar...";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::anykey();
                            rlutil::locate(30, 8);
                            cout << "                                                                        ";
                            rlutil::locate(30, 9);
                            cout << "                                                                        ";
                            rlutil::locate(71, 6);
                            cout << "                                                                        ";
                        }
                    }

                    // Validacion de la nueva contraseña
                    while (!contraseniaValida) {
                        rlutil::setColor(rlutil::COLOR::CYAN);
                        rlutil::locate(30, 7);
                        cout << "Nueva contrasenia (minimo 6 caracteres): ";
                        rlutil::setColor(rlutil::COLOR::WHITE);
                        rlutil::locate(71, 7);
                        cin >> nuevaContrasenia;

                        if (nuevaContrasenia.length() >= 6) {
                            contraseniaValida = true;
                        } else {
                            rlutil::locate(30, 9);
                            rlutil::setColor(rlutil::COLOR::RED);
                            cout << "La contrasenia es muy corta. Intente de nuevo.";
                            rlutil::setColor(rlutil::COLOR::YELLOW);
                            rlutil::locate(30, 10);
                            cout << "Presione una tecla para continuar...";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::anykey();
                            rlutil::locate(30, 9);
                            cout << "                                                                        ";
                            rlutil::locate(30, 10);
                            cout << "                                                                        ";
                            rlutil::locate(71, 7);
                            cout << "                                                    ";
                        }
                    }

                    // Validacion duplicados
                    if (VerificarLoginDuplicados(nuevoNombre, nuevaContrasenia)) {
                        rlutil::setColor(rlutil::COLOR::RED);
                        rlutil::locate(30, 9);
                        cout << "Ya existe un usuario con ese nombre y contrasenia.";
                        rlutil::setColor(rlutil::COLOR::YELLOW);
                        rlutil::locate(30, 10);
                        cout << "Presione una tecla para continuar...";
                        rlutil::setColor(rlutil::COLOR::WHITE);
                        rlutil::anykey();
                        rlutil::locate(30, 9);
                        cout << "                                                                        ";
                        rlutil::locate(30, 10);
                        cout << "                                                                        ";
                        rlutil::locate(71, 6);
                        cout << "                                                                        ";
                        rlutil::locate(71, 7);
                        cout << "                                                                        ";
                        nuevoNombreValido = false;
                        contraseniaValida = false;

                    } else {
                        while (!rolValido) {
                            rlutil::setColor(rlutil::COLOR::CYAN);
                            rlutil::locate(30, 11);
                            cout << "Nuevo Rol ID ( -1:Administrador | 0:Recepcionista | 1:Medico ): ";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::locate(94, 11);
                            cin >> nuevoRol;

                            if (cin.fail() || !(nuevoRol == -1 || nuevoRol == 0 || nuevoRol == 1)){
                                cin.clear();
                                cin.ignore(1000, '\n');
                                rlutil::locate(30, 13);
                                rlutil::setColor(rlutil::COLOR::RED);
                                cout << "Rol invalido. Debe ser -1, 0 o 1.";
                                rlutil::setColor(rlutil::COLOR::YELLOW);
                                rlutil::locate(30, 14);
                                cout << "Presione una tecla para continuar...";
                                rlutil::setColor(rlutil::COLOR::WHITE);
                                rlutil::anykey();
                                rlutil::locate(30, 13);
                                cout << "                                                                        ";
                                rlutil::locate(30, 14);
                                cout << "                                                                        ";
                                rlutil::locate(94, 11);
                                cout << "                                                                        ";
                            } else {
                                rolValido = true;
                            }
                        }

                        Rol nuevoRolObj;
                        nuevoRolObj.setTipoRol(nuevoRol);

                        usuario.setNombreUsuario(nuevoNombre);
                        usuario.setContrasenia(nuevaContrasenia);
                        usuario.setTipoRol(nuevoRolObj);

                        if (_archivo.guardar(usuario, pos)) {
                            rlutil::setColor(rlutil::COLOR::GREEN);
                            rlutil::locate(30, 13);
                            cout << "Usuario modificado correctamente.";
                            rlutil::setColor(rlutil::COLOR::YELLOW);
                            rlutil::locate(30, 14);
                            cout << "Presione una tecla para continuar...";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                        } else {
                            rlutil::setColor(rlutil::COLOR::RED);
                            rlutil::locate(30, 13);
                            cout << "Error al intentar modificar el usuario.";
                            rlutil::setColor(rlutil::COLOR::YELLOW);
                            rlutil::locate(30, 14);
                            cout << "Presione una tecla para continuar...";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                        }
                        modificado = true;
                    }
                } else {
                    rlutil::setColor(rlutil::COLOR::YELLOW);
                    rlutil::locate(30, 13);
                    cout << "Modificacion cancelada por el usuario.";
                    rlutil::setColor(rlutil::COLOR::YELLOW);
                    rlutil::locate(30, 14);
                    cout << "Presione una tecla para continuar...";
                    rlutil::setColor(rlutil::COLOR::WHITE);
                    rlutil::anykey();
                    modificado = true;
                }
            }
        }
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
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
    bool confirmacionValida=false;
    Validador val;

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
            while(!confirmacionValida){
                rlutil::locate(32, fila + 5);
                rlutil::setColor(rlutil::COLOR::GREEN);
                cout<<"DESEA ACTIVAR EL USUARIO? (s/n): ";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::locate(66, fila + 5 );
                cin >> confirmacion;

                if (cin.fail() || !val.esConfirmacionSN(confirmacion)) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            rlutil::setColor(rlutil::COLOR::RED);
                            rlutil::locate(30, fila + 11);
                            cout << "Respuesta invalida. Ingrese 's' para Si o 'n' para No.";
                            rlutil::setColor(rlutil::COLOR::YELLOW);
                            rlutil::locate(30, fila + 12);
                            cout << "Presione una tecla para continuar...";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::anykey();
                            rlutil::locate(30, fila + 11);
                            cout << "                                                                        ";
                            rlutil::locate(30, fila + 12);
                            cout << "                                                                        ";
                            rlutil::locate(66, fila + 5);
                            cout << "                                                                        ";
                        } else {
                            confirmacionValida = true;
                        }
            }

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
