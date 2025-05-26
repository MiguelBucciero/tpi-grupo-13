#include "PacienteManager.h"
#include <iostream>
#include <string>
using namespace std;

void PacienteManager::cargarPaciente() {
    Paciente paciente;
    string aux;
    int dni, carnet, id, altura;
    Fecha fechaNacimiento;
    Domicilio domicilio;

    cout << "INGRESO DE UN NUEVO PACIENTE" << endl;
    cout << "-----------------------------" << endl;
    cin.ignore();
    cout << "Apellido: ";
    getline(cin, aux);
    paciente.setApellido(aux);

    cout << "Nombre: ";
    getline(cin, aux);
    paciente.setNombre(aux);
    cout << "DNI: ";
    cin >> dni;
    cin.ignore();
    paciente.setDni(dni);
    cout << "Fecha de nacimiento" << endl;
    int dia, mes, anio;
    cout << "Dia: "; cin >> dia;
    cout << "Mes: "; cin >> mes;
    cout << "Anio: "; cin >> anio;
    cin.ignore();
    fechaNacimiento = Fecha(dia, mes, anio);
    paciente.setFechaNacimiento(fechaNacimiento);
    cout << "Genero: ";
    getline(cin, aux);
    paciente.setGenero(aux);
    cout << "Email: ";
    getline(cin, aux);
    paciente.setEmail(aux);
    cout << "Telefono: ";
    getline(cin, aux);
    paciente.setTelefono(aux);
    cout << "Domicilio:" << endl;
    cout << "Calle: ";
    getline(cin, aux);
    domicilio.setCalle(aux);
    cout << "Altura: ";
    cin >> altura;
    domicilio.setAltura(altura);
    cin.ignore();
    cout << "Localidad: ";
    getline(cin, aux);
    domicilio.setLocalidad(aux);
    cout << "Provincia: ";
    getline(cin, aux);
    domicilio.setProvincia(aux);
    cout << "Codigo postal: ";
    getline(cin, aux);
    domicilio.setCodigoPostal(aux);
    paciente.setDomicilio(domicilio);
    id = _archivo.getNuevoID();
    cout << "ID asignado automáticamente: " << id << endl;
    paciente.setIDPaciente(id);
    cout << "Numero de carnet: ";
    cin >> carnet;
    cin.ignore();
    paciente.setCarnet(carnet);
    paciente.setEstado(true); // activo por defecto

    if (_archivo.guardar(paciente)) {
        cout << "Paciente guardado correctamente." << endl;
    } else {
        cout << "Error al guardar paciente." << endl;
    }
}



void PacienteManager::mostrarPaciente() {
    int cantidad = _archivo.getCantidadRegistros();
    if (cantidad == 0) {
        cout << "No hay pacientes cargados." << endl;
        return;
    }

    Paciente* vecPaciente = new Paciente[cantidad];
    _archivo.leerMuchos(vecPaciente, cantidad);

    cout << "------- LISTADO DE PACIENTES -------" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "----------------------------------" << endl;
        cout << "Apellido: " << vecPaciente[i].getApellido() << endl;
        cout << "Nombre: " << vecPaciente[i].getNombre() << endl;
        cout << "DNI: " << vecPaciente[i].getDni() << endl;

        cout << "Fecha de nacimiento: ";
        vecPaciente[i].getFechaNacimiento().mostrarFecha();

        cout << "Genero: " << vecPaciente[i].getGenero() << endl;
        cout << "Email: " << vecPaciente[i].getEmail() << endl;
        cout << "Telefono: " << vecPaciente[i].getTelefono() << endl;

        cout << "Domicilio:" << endl;
        vecPaciente[i].getDomicilioCompleto().mostrarDomicilio();

        cout << "ID Paciente: " << vecPaciente[i].getIDPaciente() << endl;
        cout << "Carnet: " << vecPaciente[i].getCarnet() << endl;

        cout << "Estado: ";
        if (vecPaciente[i].getEstado()) {
            cout << "Activo" << endl;
        } else {
            cout << "Inactivo" << endl;
        }

        cout << "----------------------------------" << endl;
    }

    delete[] vecPaciente;
}

