#include "EspecialidadManager.h"
#include "Especialidad.h"
#include "rlutil.h"
#include <iostream>
#include <string>
using namespace std;


void EspecialidadManager::cargarEspecialidad() {
    Especialidad registro;
    int id = _archivo.getNuevoID();
    string nombre;

    rlutil::cls();
    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::locate(35, 3);
    cout << " CARGAR NUEVA ESPECIALIDAD ";
    rlutil::setColor(rlutil::COLOR::WHITE);

    rlutil::locate(35, 5);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "ID asignado: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    cout << id;

    rlutil::locate(35, 7);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Nombre de la especialidad: ";
    rlutil::setColor(rlutil::COLOR::WHITE);

    rlutil::locate(35, 8);
    cin.ignore();
    getline(cin, nombre);

    registro.setIDEspecialidad(id);
    registro.setNombre(nombre);
    registro.setEstado(true);

    rlutil::locate(35, 9);
    if (_archivo.guardar(registro)) {
        rlutil::setColor(rlutil::COLOR::GREEN);
        cout << "Especialidad cargada correctamente.";
    } else {
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "Error: no se pudo guardar la especialidad.";
    }
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void EspecialidadManager::mostrarEspecialidad() {
    int cantidad = _archivo.getCantidadRegistros();
    if (cantidad == 0) {
        rlutil::cls();
        rlutil::locate(40, 10);
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "No hay especialidades cargadas." << endl;
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        return;
    }

    Especialidad* vecEspecialidad = new Especialidad[cantidad];
    _archivo.leerMuchos(vecEspecialidad, cantidad);

    rlutil::cls();

    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::locate(45, 3);
    cout << " LISTADO DE ESPECIALIDADES ";
    rlutil::setColor(rlutil::COLOR::WHITE);

    int fila = 5;
    int mostrar=0;
    //este for recorre todas las especialidades.
    for (int i = 0; i < cantidad; i++) {
        if (vecEspecialidad[i].getEstado()) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
            rlutil::locate(35, fila);
            cout << "----------------------------------------";
            rlutil::locate(35, fila + 3);
            cout << "----------------------------------------";

            rlutil::locate(40, fila + 1);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "ID: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecEspecialidad[i].getIDEspecialidad();

            rlutil::locate(40, fila + 2);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Nombre: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecEspecialidad[i].getNombre();

            fila += 5;
            mostrar++;

            if (fila > 20) { //verificar si hay mas despues de activar las inactivas y mostrar el mensaje si hay mas
                bool hayMas=false;
                //este for chequea si hay mas especialidades activas despues de la actual.
                for (int j=i+1; j<cantidad; j++) { //i+1=despues de la actual posicion (i), si hay otra espe mas
                    if (vecEspecialidad[j].getEstado()) {
                        hayMas=true;
                        break;
                    }
                }
            if(hayMas){
                rlutil::locate(40, fila);
                rlutil::setColor(rlutil::YELLOW);
                cout << "Presione una tecla para ver mas especialidades...";
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
                rlutil::cls();
                rlutil::setColor(rlutil::COLOR::YELLOW);
                rlutil::locate(45, 3);
                cout << " LISTADO DE ESPECIALIDADES ";
                rlutil::setColor(rlutil::COLOR::WHITE);
                fila = 5;
            }
            }
        }
    }

    delete[] vecEspecialidad;

    rlutil::locate(40, fila);
    rlutil::setColor(rlutil::GREEN);
    cout << "Fin del listado. Presione una tecla para continuar...";
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void EspecialidadManager::DarBajaEspecialidad(){
    int id;
    bool encontrado=false;

    while(!encontrado){
        rlutil::cls();
        rlutil::setColor(rlutil::COLOR::YELLOW);
        rlutil::locate(35, 3);
        cout << " DAR BAJA ESPECIALIDAD ";
        rlutil::setColor(rlutil::COLOR::WHITE);

        rlutil::locate(35, 5);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Ingrese el ID de la especialidad a dar de baja: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(35, 6);
        cin >> id;

        int pos = _archivo.Buscar(id);
        Especialidad esp;
        if (pos == -1) {
            rlutil::locate(35, 7);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Especialidad no encontrada. Presione enter e intente nuevamente.";
            rlutil::anykey();
        }else{
            Especialidad esp = _archivo.Leer(pos);
            if (!esp.getEstado()) {
                rlutil::locate(35, 7);
                rlutil::setColor(rlutil::COLOR::RED);
                cout << "Especialidad ya dada de baja. Presione enter e intente nuevamente.";
                rlutil::anykey();
            }else{
                rlutil::setColor(rlutil::COLOR::CYAN);
                rlutil::locate(35, 9);
                cout << "Esta seguro que desea dar de baja a '" << id << "'? (s/n): ";
                rlutil::setColor(rlutil::COLOR::WHITE);
                char confirmacion;
                cin >> confirmacion;

                if (confirmacion == 's' || confirmacion == 'S') {
                    esp.setEstado(false);
                    if (_archivo.guardar(esp, pos)) {
                        rlutil::setColor(rlutil::COLOR::GREEN);
                        rlutil::locate(35, 11);
                        cout << "Especialidad dado de baja correctamente.";
                    } else {
                        rlutil::setColor(rlutil::COLOR::RED);
                        rlutil::locate(35, 11);
                        cout << "Error al intentar modificar el archivo.";
                    }
                }else{
                    rlutil::setColor(rlutil::COLOR::YELLOW);
                    rlutil::locate(35, 11);
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

void EspecialidadManager::ModificarEspecialidad(){
    int id;
    string nombreNuevo;
    char confirmacion;
    bool modificado=false;

    while(!modificado){
        rlutil::cls();
        rlutil::setColor(rlutil::COLOR::YELLOW);
        rlutil::locate(35, 3);
        cout << " MODIFICAR ESPECIALIDAD ";
        rlutil::setColor(rlutil::COLOR::WHITE);

        rlutil::locate(35, 5);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Ingrese el ID de la especialidad a modificar: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(35, 6);
        cin >> id;

        int pos = _archivo.Buscar(id);
        if (pos == -1) {
            rlutil::locate(35, 7);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Especialidad no encontrada.";
        }else{
            Especialidad esp = _archivo.Leer(pos);
            if (!esp.getEstado()) {
                rlutil::locate(35, 7);
                rlutil::setColor(rlutil::COLOR::RED);
                cout << "Especialidad dada de baja, no se puede modificar.";
            }else{
                rlutil::setColor(rlutil::COLOR::CYAN);
                rlutil::locate(35, 7);
                cout << "Esta seguro que desea modificar al usuario '" << id << "'? (s/n): ";
                rlutil::setColor(rlutil::COLOR::WHITE);
                cin >> confirmacion;

                if (confirmacion == 's' || confirmacion == 'S') {
                    rlutil::cls();
                    rlutil::setColor(rlutil::COLOR::YELLOW);
                    rlutil::locate(40, 3);
                    cout << " INGRESO DE NUEVOS DATOS ";

                    rlutil::locate(35, 8);
                    rlutil::setColor(rlutil::COLOR::CYAN);
                    cout << "Nombre actual: ";
                    rlutil::setColor(rlutil::COLOR::WHITE);
                    cout << esp.getNombre();

                    rlutil::locate(35, 9);
                    rlutil::setColor(rlutil::COLOR::CYAN);
                    cout << "Ingrese el nuevo nombre de la especialidad: ";
                    rlutil::setColor(rlutil::COLOR::WHITE);
                    rlutil::locate(35, 10);
                    cin.ignore();
                    getline(cin, nombreNuevo);

                    esp.setNombre(nombreNuevo);

                    if (_archivo.guardar(esp, pos)) {
                        rlutil::setColor(rlutil::COLOR::GREEN);
                        rlutil::locate(35, 12);
                        cout << "Especialidad modificada correctamente.";
                    } else {
                        rlutil::setColor(rlutil::COLOR::RED);
                        rlutil::locate(35, 12);
                        cout << "Error: no se pudo modificar la especialidad.";
                    }
                    modificado=true;
                }else{
                rlutil::setColor(rlutil::COLOR::YELLOW);
                rlutil::locate(35, 10);
                cout<<"Modificacion cancelada por el usuario.";
                modificado=true;
                }
            }
        }
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
    }
    rlutil::cls();
}

void EspecialidadManager::ReactivarEspecialidad(){
    int cantidad=_archivo.getCantidadRegistros();
    bool noActivo=false;
    int fila=4;

    rlutil::cls();
    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::locate(40, 2);
    cout << " ESPECIALIDADES INACTIVAS ";
    rlutil::setColor(rlutil::COLOR::WHITE);

    Especialidad especialidad;
    for(int i=0; i<cantidad; i++){
        especialidad=_archivo.Leer(i);
        if(especialidad.getEstado()==false){
            rlutil::locate(30, fila++);
            cout<<"(ID: "<<especialidad.getIDEspecialidad()<<") - Nombre: "<<especialidad.getNombre();
            noActivo=true;
        }
    }

    if(!noActivo){
        rlutil::locate(37, fila + 8);
        rlutil::setColor(rlutil::COLOR::RED);
        cout<<"No hay especialidades inactivas";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        return;
    }

    rlutil::locate(30, fila + 2);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout<<"Desea activar alguna especialidad? (s/n) ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    char confirmacion;
    cin >> confirmacion;


    if (confirmacion == 's' || confirmacion == 'S') {
        rlutil::locate(30, fila + 4);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout<<"Que especialidad desea activar?";
        rlutil::locate(31, fila + 5);
        cout<<"ID: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        int id;
        cin>>id;

        int pos=_archivo.Buscar(id);
        if(pos==-1){
            rlutil::locate(35, fila + 6);
            rlutil::setColor(rlutil::COLOR::RED);
            cout<<"ID de especialidad no encontrada";
        }else{
            especialidad=_archivo.Leer(pos);
            if(especialidad.getEstado()==true){
                rlutil::locate(35, fila + 6);
                rlutil::setColor(rlutil::COLOR::RED);
                cout<<"La especialidad ya esta activada";
            }else{
                especialidad.setEstado(true);
                if(_archivo.guardar(especialidad, pos)){
                    rlutil::locate(35, fila + 6);
                    rlutil::setColor(rlutil::COLOR::GREEN);
                    cout<<"Especialidad activada correctamente";
                }else{
                    rlutil::locate(35, fila + 6);
                    rlutil::setColor(rlutil::COLOR::RED);
                    cout<<"Error al guardar la especialidad";
                }
            }
        }
    } else {
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(35, fila++);
            cout << "Accion cancelada.";
        }
    rlutil::setColor(rlutil::COLOR::WHITE);

    rlutil::anykey();
    rlutil::cls();
}
