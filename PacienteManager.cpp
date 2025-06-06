#include "PacienteManager.h"
#include "rlutil.h"
#include <iostream>
#include <string>
using namespace std;

void PacienteManager::cargarPaciente() {
    Paciente paciente;
    string aux;
    int dni, carnet, id, altura, dia, mes, anio;
    Fecha fechaNacimiento;
    Domicilio domicilio;

    rlutil::cls();
    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::locate(40, 2);
    cout << "INGRESO DE NUEVO PACIENTE";
    rlutil::setColor(rlutil::COLOR::WHITE);

    rlutil::locate(30, 4);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Apellido: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(40, 4);
    getline(cin, aux);
    paciente.setApellido(aux);

    rlutil::locate(30, 5);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Nombre: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(40, 5);
    getline(cin, aux);
    paciente.setNombre(aux);

    rlutil::locate(30, 6);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "DNI: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(40, 6);
    cin >> dni;
    cin.ignore();
    paciente.setDni(dni);

    rlutil::setColor(rlutil::COLOR::CYAN);
    rlutil::locate(30, 7);
    cout << "Fecha de nacimiento:";
    rlutil::setColor(rlutil::COLOR::WHITE);

    rlutil::locate(30, 8);
    cout << "Dia: ";
    rlutil::locate(40, 8);
    cin >> dia;
    rlutil::locate(30, 9);
    cout << "Mes: ";
    rlutil::locate(40, 9);
    cin >> mes;
    rlutil::locate(30, 10);
    cout << "Anio: ";
    rlutil::locate(40, 10);
    cin >> anio;
    cin.ignore();
    fechaNacimiento = Fecha(dia, mes, anio);
    paciente.setFechaNacimiento(fechaNacimiento);

    rlutil::locate(30, 11);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Genero: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(40, 11);
    getline(cin, aux);
    paciente.setGenero(aux);

    rlutil::locate(30, 12);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Email: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(40, 12);
    getline(cin, aux);
    paciente.setEmail(aux);

    rlutil::locate(30, 13);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Telefono: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(40, 13);
    getline(cin, aux);
    paciente.setTelefono(aux);

    domicilio.cargarDomicilio();
    paciente.setDomicilio(domicilio);

    id = _archivo.getNuevoID();
    rlutil::locate(30, 4);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "ID asignado: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    cout << id;
    paciente.setIDPaciente(id);

    rlutil::locate(30, 5);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Numero de carnet: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(40, 5);
    cin >> carnet;
    cin.ignore();
    paciente.setCarnet(carnet);
    paciente.setEstado(true);

    rlutil::locate(30, 7);
    if (_archivo.guardar(paciente)) {
        rlutil::setColor(rlutil::COLOR::GREEN);
        cout << "Paciente guardado correctamente.";
    } else {
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "Error al guardar paciente.";
    }

    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::anykey();
    rlutil::cls();
}



void PacienteManager::mostrarPaciente() {
    int cantidad = _archivo.getCantidadRegistros();
    if (cantidad == 0) {
        rlutil::cls();
        rlutil::locate(40, 10);
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "No hay pacientes cargados." << endl;
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        return;
    }

    Paciente* vecPaciente = new Paciente[cantidad];
    _archivo.leerMuchos(vecPaciente, cantidad);

    rlutil::cls();
    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::locate(45, 2);
    cout << " LISTADO DE PACIENTES ";
    rlutil::setColor(rlutil::COLOR::WHITE);

    int fila = 4;

        for (int i = 0; i < cantidad; i++) {
            if (vecPaciente[i].getEstado()) {
            rlutil::cls();
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(45, 2);
            cout << " PACIENTE " << (i + 1) << " DE " << cantidad;
            rlutil::setColor(rlutil::COLOR::WHITE);

            int fila = 4;
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
            rlutil::locate(30, fila);     cout << "------------------------------------------------------------";
            rlutil::locate(30, fila + 15); cout << "------------------------------------------------------------";

            rlutil::locate(32, fila + 1);
            rlutil::setColor(rlutil::COLOR::CYAN); cout << "Apellido: "; rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getApellido();

            rlutil::locate(32, fila + 2);
            rlutil::setColor(rlutil::COLOR::CYAN); cout << "Nombre: "; rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getNombre();

            rlutil::locate(32, fila + 3);
            rlutil::setColor(rlutil::COLOR::CYAN); cout << "DNI: "; rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getDni();

            rlutil::locate(32, fila + 4);
            rlutil::setColor(rlutil::COLOR::CYAN); cout << "Fecha de nacimiento: "; rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getFechaNacimiento().toString();

            rlutil::locate(32, fila + 5);
            rlutil::setColor(rlutil::COLOR::CYAN); cout << "Genero: "; rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getGenero();

            rlutil::locate(32, fila + 6);
            rlutil::setColor(rlutil::COLOR::CYAN); cout << "Email: "; rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getEmail();

            rlutil::locate(32, fila + 7);
            rlutil::setColor(rlutil::COLOR::CYAN); cout << "Telefono: "; rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getTelefono();

            rlutil::locate(32, fila + 8);
            rlutil::setColor(rlutil::COLOR::CYAN); cout << "Domicilio: "; rlutil::setColor(rlutil::COLOR::WHITE);
            vecPaciente[i].getDomicilioCompleto().mostrarDomicilio(32, fila + 8);

            rlutil::locate(32, fila + 13);
            rlutil::setColor(rlutil::COLOR::CYAN); cout << "Carnet: "; rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getCarnet();

            rlutil::locate(32, fila + 14);
            rlutil::setColor(rlutil::COLOR::CYAN); cout << "ID Paciente: "; rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getIDPaciente();

            rlutil::locate(35, fila + 17);
            rlutil::setColor(rlutil::COLOR::YELLOW);
            cout << "Presione una tecla para ver el siguiente paciente...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
        }
    }

    delete[] vecPaciente;
    rlutil::cls();
    rlutil::locate(40, 10);
    rlutil::setColor(rlutil::COLOR::GREEN);
    cout << "Fin del listado. Presione una tecla para continuar...";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::anykey();
    rlutil::cls();
}





