#include "EspecialidadManager.h"
#include "Especialidad.h"
#include "rlutil.h"
#include <iostream>
#include <string>
using namespace std;


void EspecialidadManager::cargarEspecialidad() {
    Especialidad registro;
    int id = _archivo.IDdisponible();
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

    registro = Especialidad(id, nombre, true);

    int pos = _archivo.Buscar(id);
    bool verificar;
    if (pos != -1) {
        verificar = _archivo.guardar(registro, pos);
    } else {
        verificar = _archivo.guardar(registro);
    }

    rlutil::locate(35, 9);
    if (verificar) {
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
            if (fila > 20) {
                rlutil::anykey();
                rlutil::cls();
                rlutil::setColor(rlutil::COLOR::YELLOW);
                rlutil::locate(45, 3);
                cout << " CONTINUACION DE ESPECIALIDADES ";
                rlutil::setColor(rlutil::COLOR::WHITE);
                fila = 5;
            }
        }
    }

    delete[] vecEspecialidad;

    rlutil::anykey();
    rlutil::cls();
}

void EspecialidadManager::DarBajaEspecialidad(){
    int id;

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
    if (pos == -1) {
        rlutil::locate(35, 7);
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "Especialidad no encontrada.";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return;
    }

    Especialidad esp = _archivo.Leer(pos);
    if (!esp.getEstado()) {
        rlutil::locate(35, 7);
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "Especialidad ya dada de baja.";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return;
    }

    esp.setEstado(false);
    bool ok = _archivo.guardar(esp, pos);

    rlutil::locate(35, 7);
    if (ok) {
        rlutil::setColor(rlutil::COLOR::GREEN);
        cout << "Especialidad dada de baja correctamente.";
    } else {
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "Error: no se pudo dar de baja la especialidad.";
    }
    rlutil::setColor(rlutil::COLOR::WHITE);

    rlutil::anykey();
    rlutil::cls();
}

void EspecialidadManager::ModificarEspecialidad(){
    int id;
    string nombreNuevo;

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
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return;
    }

    Especialidad esp = _archivo.Leer(pos);
    if (!esp.getEstado()) {
        rlutil::locate(35, 7);
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "Especialidad dada de baja, no se puede modificar.";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return;
    }

    rlutil::locate(35, 7);
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
    bool ok = _archivo.guardar(esp, pos);

    rlutil::locate(35, 11);
    if (ok) {
        rlutil::setColor(rlutil::COLOR::GREEN);
        cout << "Especialidad modificada correctamente.";
    } else {
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "Error: no se pudo modificar la especialidad.";
    }
    rlutil::setColor(rlutil::COLOR::WHITE);

    rlutil::anykey();
    rlutil::cls();
}
