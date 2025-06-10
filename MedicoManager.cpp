#include <iostream>
#include <string>
#include "MedicoManager.h"
#include "rlutil.h"

#include "TurnoArchivo.h"
#include "Turno.h"


using namespace std;

int MedicoManager::cargarMedico() {
    Medico medico;
    string aux;
    int dni, matricula, id, idEspecialidad, altura, dia, mes, anio;
    Fecha fechaNacimiento;
    Domicilio domicilio;

    rlutil::cls();
    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::locate(40, 2);
    cout << "INGRESO DE NUEVO MEDICO";
    rlutil::setColor(rlutil::COLOR::WHITE);

    rlutil::locate(30, 4);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Apellido: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 4);
    getline(cin, aux); medico.setApellido(aux);

    rlutil::locate(30, 5);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Nombre: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 5);
    getline(cin, aux); medico.setNombre(aux);

    rlutil::locate(30, 6);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "DNI: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 6);
    cin >> dni; cin.ignore(); medico.setDni(dni);

    rlutil::locate(30, 7);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Fecha de nacimiento:";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(30, 8);
    cout << "Dia: ";
    rlutil::locate(45, 8);
    cin >> dia;
    rlutil::locate(30, 9);
    cout << "Mes: ";
    rlutil::locate(45, 9);
    cin >> mes;
    rlutil::locate(30, 10);
    cout << "Anio: ";
    rlutil::locate(45, 10);
    cin >> anio;
    cin.ignore();
    medico.setFechaNacimiento(Fecha(dia, mes, anio));

    rlutil::locate(30, 11);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Genero: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 11);
    getline(cin, aux);
    medico.setGenero(aux);

    rlutil::locate(30, 12);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Email: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 12);
    getline(cin, aux);
    medico.setEmail(aux);

    rlutil::locate(30, 13);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Telefono: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 13);
    getline(cin, aux);
    medico.setTelefono(aux);

    rlutil::locate(30, 14);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Domicilio: ";

    rlutil::locate(32, 15);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Calle: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 15);
    getline(cin, aux);
    domicilio.setCalle(aux);

    rlutil::locate(32, 16);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Altura: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 16);
    cin >> altura;
    domicilio.setAltura(altura);
    cin.ignore();

    rlutil::locate(32, 17);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Localidad: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 17);
    getline(cin, aux);
    domicilio.setLocalidad(aux);

    rlutil::locate(32, 18);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Provincia: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 18);
    getline(cin, aux);
    domicilio.setProvincia(aux);

    rlutil::locate(32, 19);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Codigo Postal: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 19);
    getline(cin, aux);
    domicilio.setCodigoPostal(aux);

    medico.setDomicilio(domicilio);

    id = _archivo.getNuevoID();
    medico.setIDMedico(id);
    rlutil::locate(30, 20);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "ID asignado: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    cout << id;

    rlutil::locate(30, 21);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Matricula: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 21);
    cin >> matricula;
    medico.setMatricula(matricula);

    rlutil::locate(30, 22);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "ID de Especialidad: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(52, 22);
    cin >> idEspecialidad;
    medico.setIDEspecialidad(idEspecialidad);

    medico.setEstado(true);

    rlutil::locate(30, 24);
    if (_archivo.guardar(medico)) {
        rlutil::setColor(rlutil::COLOR::GREEN);
        cout << "Medico guardado correctamente.";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return id;
    } else {
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "Error al guardar medico.";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return -1;
    }
}

void MedicoManager::mostrarMedico() {
    int cantidad = _archivo.getCantidadRegistros();
    if (cantidad == 0) {
        rlutil::cls();
        rlutil::locate(40, 10);
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "No hay medicos cargados.";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        return;
    }

    Medico* vecMedico = new Medico[cantidad];
    _archivo.leerMuchos(vecMedico, cantidad);

    for (int i = 0; i < cantidad; i++) {
        if (vecMedico[i].getEstado()) {
            rlutil::cls();
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(45, 2);
            cout << " LISTADO DE MEDICOS " << (i + 1) << " DE " << cantidad;
            rlutil::setColor(rlutil::COLOR::WHITE);

            int fila = 4;

            rlutil::locate(30, fila);
            cout << "------------------------------------------------------------";
            rlutil::locate(30, fila + 13);
            cout << "------------------------------------------------------------";

            rlutil::locate(32, fila + 1);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Apellido: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getApellido();
            rlutil::locate(32, fila + 2);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Nombre: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getNombre();
            rlutil::locate(32, fila + 3);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "DNI: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getDni();

            rlutil::locate(32, fila + 4);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Fecha de nacimiento: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getFechaNacimiento().toString();

            rlutil::locate(32, fila + 5);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Genero: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getGenero();
            rlutil::locate(32, fila + 6);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Email: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getEmail();
            rlutil::locate(32, fila + 7);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Telefono: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getTelefono();

            rlutil::locate(32, fila + 8);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Matricula: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getMatricula();
            rlutil::locate(32, fila + 9);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "ID Especialidad: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getIDEspecialidad();
            rlutil::locate(32, fila + 10);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "ID Medico: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getIDMedico();

            rlutil::locate(32, fila + 11);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Estado: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            if(vecMedico[i].getEstado()){
                cout<<"Activo"<<endl;
            } else{
                cout<<"Inactivo"<<endl;
            }

            rlutil::locate(32, fila + 14);
            rlutil::setColor(rlutil::COLOR::YELLOW);
            cout << "Presione una tecla para ver el siguiente medico...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
        }
    }

    delete[] vecMedico;
    rlutil::cls();
    rlutil::locate(40, 10);
    rlutil::setColor(rlutil::COLOR::GREEN);
    cout << "Fin del listado. Presione una tecla para continuar...";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void MedicoManager::buscarMedicoPorEspecialidad() {
    int idEspecialidad, fila;
    bool encontrados = false;

    rlutil::cls();
    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::locate(50, 2);
    cout << "BUSCAR MEDICOS POR ESPECIALIDAD";
    rlutil::setColor(rlutil::COLOR::WHITE);

    rlutil::locate(45, 4);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Ingrese el ID de especialidad que desea buscar: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(92, 4);
    cin >> idEspecialidad;

    int cantidad = _archivo.getCantidadRegistros();
    if (cantidad == 0) {
        rlutil::locate(45, 6);
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "No hay medicos cargados.";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return;
    }

    Medico* vecMedico = new Medico[cantidad];
    _archivo.leerMuchos(vecMedico, cantidad);


    fila = 6;

    rlutil::cls();
    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::locate(50, 2);
    cout << " MEDICOS CON ID DE ESPECIALIDAD " << idEspecialidad;
    rlutil::setColor(rlutil::COLOR::WHITE);

    for (int i = 0; i < cantidad; i++) {
        if (vecMedico[i].getIDEspecialidad() == idEspecialidad && vecMedico[i].getEstado()) {
            rlutil::locate(45, fila);
            cout << "------------------------------------------------------------";
            rlutil::locate(45, fila + 6);
            cout << "------------------------------------------------------------";

            rlutil::locate(45, fila + 1);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "ID Medico: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getIDMedico();

            rlutil::locate(45, fila + 2);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Nombre: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getNombre() << " " << vecMedico[i].getApellido();

            rlutil::locate(45, fila + 3);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "DNI: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getDni();

            rlutil::locate(45, fila + 4);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Email: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getEmail();

            rlutil::locate(45, fila + 5);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Telefono: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getTelefono();

            fila += 8;

            // Paginación si se sale de pantalla
            if (fila + 6 > 45) {
                rlutil::locate(45, fila);
                rlutil::setColor(rlutil::COLOR::YELLOW);
                cout << "Presione una tecla para continuar...";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
                rlutil::cls();
                rlutil::locate(50, 2);
                cout << " MEDICOS CON ID DE ESPECIALIDAD " << idEspecialidad;
                fila = 6;
            }

            encontrados = true;
        }
    }

    if (!encontrados) {
        rlutil::locate(45, fila);
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "No se encontraron medicos activos con esa especialidad.";
        rlutil::setColor(rlutil::COLOR::WHITE);
    }

    delete[] vecMedico;

    rlutil::locate(45, fila + 2);
    rlutil::setColor(rlutil::COLOR::YELLOW);
    cout << "Fin de la busqueda. Presione una tecla para continuar...";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::anykey();
    rlutil::cls();
}


void MedicoManager::verTurnosAsignados(int idMedico) {
    TurnoArchivo archivo("Turnos.dat");
    int cantidad = archivo.getCantidadRegistros();
    bool hayTurnos = false;
    int fila = 4;

    rlutil::cls();
    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::locate(40, 2);
    cout << "TURNOS ASIGNADOS AL MEDICO ID: " << idMedico;
    rlutil::setColor(rlutil::COLOR::WHITE);

    for (int i = 0; i < cantidad; i++) {
        Turno t = archivo.Leer(i);

        if (t.getIDMedico() == idMedico && (t.getEstado() == 1||t.getEstado()==3)) {
            rlutil::locate(30, fila - 1);
            cout << "------------------------------------------------------------";

            rlutil::locate(32, fila++);
            cout << "ID Turno: " << t.getIDTurno();
            rlutil::locate(32, fila++);
            cout << "ID Paciente: " << t.getIDPaciente();
            rlutil::locate(32, fila++);
            cout << "ID Medico: " << t.getIDMedico();
            rlutil::locate(32, fila++);
            cout << "Fecha: " << t.getFechaTurno().toString();
            rlutil::locate(32, fila++);
            cout << "Hora: " << t.getHoraTurno().toString();
            rlutil::locate(32, fila++);
            cout << "ID Especialidad: " << t.getEspecialidad();
            rlutil::locate(32, fila++);
            cout << "Estado: ";
            switch (t.getEstado()) {
                case 1: cout << "Activo"; break;
                case 3: cout << "Reprogramado"; break;
                default: cout << "Desconocido"; break;
            }
            rlutil::locate(30, fila++);
            cout << "------------------------------------------------------------";

            fila++;  // Espacio entre turnos

            hayTurnos = true;

            if (fila > 43) {
                rlutil::locate(40, fila);
                rlutil::setColor(rlutil::COLOR::YELLOW);
                cout << "Presione una tecla para continuar...";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
                rlutil::cls();
                rlutil::locate(40, 2);
                rlutil::setColor(rlutil::COLOR::YELLOW);
                cout << "TURNOS ASIGNADOS AL MEDICO ID: " << idMedico;
                rlutil::setColor(rlutil::COLOR::WHITE);
                fila = 4;
            }
        }
    }

    if (!hayTurnos) {
        rlutil::locate(40, 10);
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "No hay turnos asignados para este medico.";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return;
    }

    rlutil::locate(40, fila+1);
    rlutil::setColor(rlutil::COLOR::GREEN);
    cout << "Fin de la busqueda. Presione una tecla para continuar...";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::anykey();
    rlutil::cls();
}


void MedicoManager::DarBajaMedico(){
    int id;
    bool encontrado = false;

    while (!encontrado) {
        rlutil::cls();
        rlutil::setColor(rlutil::COLOR::YELLOW);
        rlutil::locate(40, 3);
        cout << " DAR DE BAJA MEDICO ";

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 6);
        cout << "Ingrese el ID del medico a dar de baja: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(75, 6);
        cin >> id;

        int pos = _archivo.Buscar(id);
        Medico posMedico;

        if (pos == -1) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "Medico no encontrado. Intente nuevamente.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            continue;
        }

        posMedico = _archivo.Leer(pos);
        if (!posMedico.getEstado()) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "El Medico ya esta dado de baja.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            continue;
        }

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 9);
        cout << "Esta seguro que desea dar de baja al medico de ID '" << id << "'? (s/n): ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        char confirmacion;
        cin >> confirmacion;

        if (confirmacion == 's' || confirmacion == 'S') {
            posMedico.setEstado(false);
            if (_archivo.guardar(posMedico, pos)) {
                rlutil::setColor(rlutil::COLOR::GREEN);
                rlutil::locate(30, 11);
                cout << "Medico dado de baja correctamente.";
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



void MedicoManager::modificarMedico(){
    string aux;
    int dni, matricula, id, idEspecialidad, altura, dia, mes, anio;
    Fecha fechaNacimiento;
    Domicilio domicilio;
    char confirmacion;
    bool modificado = false;


        while (!modificado) {
        rlutil::cls();
        rlutil::setColor(rlutil::COLOR::YELLOW);
        rlutil::locate(40, 3);
        cout << " MODIFICAR MEDICO ";

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 6);
        cout << "Ingrese el ID del medico a modificar: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(73, 6);
        cin >> id;

        int pos = _archivo.Buscar(id);
        Medico medico;

        if (pos == -1) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "Medico no encontrado. Intente nuevamente.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            continue;
        }

        medico = _archivo.Leer(pos);

        if (!medico.getEstado()) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "El medico está dado de baja. No se puede modificar.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            continue;
        }

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 9);
        cout << "Esta seguro que desea modificar al medico ID '" << id << "'? (s/n): ";
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
        cout << "Nuevo Apellido: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 6);
        getline(cin, aux); medico.setApellido(aux);


        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 7);
        cout << "Nuevo Nombre: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 7);
        getline(cin, aux); medico.setNombre(aux);

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 8);
        cout << "Nuevo DNI: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 8);
        cin >> dni; cin.ignore(); medico.setDni(dni);

        rlutil::locate(30, 9);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Nueva fecha de nacimiento:";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(30, 10);
        cout << "Dia: ";
        rlutil::locate(50, 10);
        cin >> dia;
        rlutil::locate(30, 11);
        cout << "Mes: ";
        rlutil::locate(50, 11);
        cin >> mes;
        rlutil::locate(30, 12);
        cout << "Anio: ";
        rlutil::locate(50, 12);
        cin >> anio;
        cin.ignore();
        medico.setFechaNacimiento(Fecha(dia, mes, anio));

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 13);
        cout << "Nuevo Genero: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 13);
        getline(cin, aux);
        medico.setGenero(aux);

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 14);
        cout << "Nuevo Email: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 14);
        getline(cin, aux);
        medico.setEmail(aux);


        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 15);
        cout << "Nuevo Telefono: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 15);
        getline(cin, aux);
        medico.setTelefono(aux);


        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 16);
        cout << "Nuevo Domicilio: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 16);



        rlutil::locate(30, 17);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Calle: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(50, 17);
        getline(cin, aux);
        domicilio.setCalle(aux);

        rlutil::locate(30, 18);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Altura: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(50, 18);
        cin >> altura;
        domicilio.setAltura(altura);
        cin.ignore();

        rlutil::locate(30, 19);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Localidad: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(50, 19);
        getline(cin, aux);
        domicilio.setLocalidad(aux);

        rlutil::locate(30, 20);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Provincia: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(50, 20);
        getline(cin, aux);
        domicilio.setProvincia(aux);

        rlutil::locate(30, 21);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Codigo Postal: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(50, 21);
        getline(cin, aux);
        domicilio.setCodigoPostal(aux);

        medico.setDomicilio(domicilio);


        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 22);
        cout << "Nueva Matricula: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 22);
        cin >> matricula;
        medico.setMatricula(matricula);

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 23);
        cout << "Nuevo ID de Especialidad: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 23);
        cin >> idEspecialidad;
        medico.setIDEspecialidad(idEspecialidad);


        if (_archivo.guardar(medico, pos)) {
                      system("cls");
            rlutil::setColor(rlutil::COLOR::GREEN);
            rlutil::locate(30, 10);
            cout << "Medico modificado correctamente.";
        } else {
                  system("cls");
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



