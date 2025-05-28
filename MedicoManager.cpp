#include <iostream>
#include <string>
#include "MedicoManager.h"

using namespace std;

void MedicoManager::cargarMedico() {
    Medico medico;
    string aux;
    int dni, matricula, id, idEspecialidad, altura,dia, mes, anio;
    Fecha fechaNacimiento;
    Domicilio domicilio;

    cout << "INGRESO DE UN NUEVO MEDICO" << endl;
    cout << "---------------------------" << endl;

    cin.ignore();

    cout << "Apellido: ";
    getline(cin, aux);
    medico.setApellido(aux);

    cout << "Nombre: ";
    getline(cin, aux);
    medico.setNombre(aux);

    cout << "DNI: ";
    cin >> dni;
    cin.ignore();
    medico.setDni(dni);

    cout << "Fecha de nacimiento" << endl;
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Anio: ";
    cin >> anio;
    cin.ignore();
    medico.setFechaNacimiento(Fecha(dia, mes, anio));

    cout << "Genero: ";
    getline(cin, aux);
    medico.setGenero(aux);

    cout << "Email: ";
    getline(cin, aux);
    medico.setEmail(aux);

    cout << "Telefono: ";
    getline(cin, aux);
    medico.setTelefono(aux);

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

    medico.setDomicilio(domicilio);


    id = _archivo.getNuevoID();
    medico.setIDMedico(id);
    cout << "ID asignado: " << id << endl;

    cout << "Matricula: ";
    cin >> matricula;
    medico.setMatricula(matricula);

    cout << "ID de Especialidad: ";
    cin >> idEspecialidad;
    medico.setIDEspecialidad(idEspecialidad);

    medico.setEstado(true);

    if (_archivo.guardar(medico)) {
        cout << "Medico guardado correctamente." << endl;
    } else {
        cout << "Error al guardar medico." << endl;
    }
}

void MedicoManager::mostrarMedico() {
    int cantidad = _archivo.getCantidadRegistros();
    if (cantidad == 0) {
        cout << "No hay medicos cargados." << endl;
        return;
    }

    Medico* vecMedico = new Medico[cantidad];
    _archivo.leerMuchos(vecMedico, cantidad);

    cout << "------- LISTADO DE MEDICOS -------" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "----------------------------------" << endl;
        cout << "Apellido: " << vecMedico[i].getApellido() << endl;
        cout << "Nombre: " << vecMedico[i].getNombre() << endl;
        cout << "DNI: " << vecMedico[i].getDni() << endl;

        cout << "Fecha de nacimiento: ";
        vecMedico[i].getFechaNacimiento().mostrarFecha();

        cout << "Genero: " << vecMedico[i].getGenero() << endl;
        cout << "Email: " << vecMedico[i].getEmail() << endl;
        cout << "Telefono: " << vecMedico[i].getTelefono() << endl;

        cout << "Domicilio:" << endl;
        vecMedico[i].getDomicilioCompleto().mostrarDomicilio();

        cout << "ID Medico: " << vecMedico[i].getIDMedico() << endl;
        cout << "Matricula: " << vecMedico[i].getMatricula() << endl;
        cout << "ID Especialidad: " << vecMedico[i].getIDEspecialidad() << endl;

        cout << "Estado: ";
        if (vecMedico[i].getEstado()) {
            cout << "Activo" << endl;
        } else {
            cout << "Inactivo" << endl;
        }
        cout << "----------------------------------" << endl;
    }

    delete[] vecMedico;
}

void MedicoManager::buscarMedicoPorEspecialidad() {
    int idEspecialidad;
    cout << "Ingrese el ID de especialidad que desea buscar: ";
    cin >> idEspecialidad;

    int cantidad = _archivo.getCantidadRegistros();
    if (cantidad == 0) {
        cout << "No hay medicos cargados." << endl;
        return;
    }

    Medico* vecMedico = new Medico[cantidad];
    _archivo.leerMuchos(vecMedico, cantidad);

    bool encontrados = false;
    cout << "\n--- Medicos con ID de especialidad " << idEspecialidad << " ---" << endl;

    for (int i = 0; i < cantidad; i++) {
        if (vecMedico[i].getIDEspecialidad() == idEspecialidad && vecMedico[i].getEstado()) {
            cout << "----------------------------------" << endl;
            cout << "ID Medico: " << vecMedico[i].getIDMedico() << endl;
            cout << "Nombre: " << vecMedico[i].getNombre() << " " << vecMedico[i].getApellido() << endl;
            cout << "DNI: " << vecMedico[i].getDni() << endl;
            cout << "Email: " << vecMedico[i].getEmail() << endl;
            cout << "Telefono: " << vecMedico[i].getTelefono() << endl;
            encontrados = true;
        }
    }

    if (!encontrados) {
        cout << "No se encontraron medicos activos con esa especialidad." << endl;
    }

    delete[] vecMedico;
}


