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
            cout << (vecMedico[i].getEstado() ? "Activo" : "Inactivo");

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
    int idEspecialidad;
    cout<<"Ingrese el ID de especialidad que desea buscar: ";
    cin>>idEspecialidad;

    int cantidad=_archivo.getCantidadRegistros();
    if (cantidad==0) {
        cout<<"No hay medicos cargados."<<endl;
        return;
    }

    Medico* vecMedico=new Medico[cantidad];
    _archivo.leerMuchos(vecMedico, cantidad);

    bool encontrados=false;
    cout << "\n--- Medicos con ID de especialidad "<<idEspecialidad<<" ---"<<endl;

    for (int i=0; i<cantidad; i++) {
        if (vecMedico[i].getIDEspecialidad()==idEspecialidad && vecMedico[i].getEstado()) {
            cout<<"----------------------------------"<<endl;
            cout<<"ID Medico: "<<vecMedico[i].getIDMedico()<<endl;
            cout<<"Nombre: "<<vecMedico[i].getNombre()<<" " <<vecMedico[i].getApellido()<<endl;
            cout<<"DNI: "<<vecMedico[i].getDni()<<endl;
            cout<<"Email: " << vecMedico[i].getEmail()<<endl;
            cout<<"Telefono: "<<vecMedico[i].getTelefono()<<endl;
            encontrados = true;
        }
    }

    if (!encontrados) {
        cout << "No se encontraron medicos activos con esa especialidad."<<endl;
    }

    delete[] vecMedico;
    system ("pause");
    system("cls");
}


void MedicoManager::verTurnosAsignados(int idMedico) {
    TurnoArchivo archivo("Turnos.dat");
    int cantidad = archivo.getCantidadRegistros();
    bool hayTurnos = false;

    for (int i = 0; i < cantidad; i++) {
        Turno t = archivo.Leer(i);
        if (t.getIDMedico() == idMedico && t.getEstado() == 1) {
            t.mostrarTurno();
            hayTurnos = true;
        }
    }

    if (!hayTurnos) {
        cout << "No hay turnos asignados para este médico." << endl;
    }

    rlutil::anykey("Presione una tecla para continuar...");
}
