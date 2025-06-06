#include <iostream>
#include <string>
#include "MedicoManager.h"
#include "rlutil.h"

using namespace std;

int MedicoManager::cargarMedico() {
    Medico medico;
    string aux;
    int dni, matricula, id, idEspecialidad, altura,dia, mes, anio;
    Fecha fechaNacimiento;
    Domicilio domicilio;

    cout << "INGRESO DE UN NUEVO MEDICO" << endl;
    cout << "---------------------------" << endl;

   // cin.ignore();

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
        system ("pause");
        system("cls");
        return id;
    } else {
        cout << "Error al guardar medico." << endl;
        system ("pause");
        system("cls");
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


