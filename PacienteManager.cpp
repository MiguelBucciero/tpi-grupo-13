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
    rlutil::locate(45, 4);
    getline(cin, aux);
    paciente.setApellido(aux);

    rlutil::locate(30, 5);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Nombre: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 5);
    getline(cin, aux);
    paciente.setNombre(aux);

    rlutil::locate(30, 6);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "DNI: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 6);
    cin >> dni;
    cin.ignore();
    paciente.setDni(dni);

    rlutil::setColor(rlutil::COLOR::CYAN);
    rlutil::locate(30, 7);
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
    paciente.setFechaNacimiento(Fecha(dia, mes, anio));

    rlutil::locate(30, 11);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Genero: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 11);
    getline(cin, aux);
    paciente.setGenero(aux);

    rlutil::locate(30, 12);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Email: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 12);
    getline(cin, aux);
    paciente.setEmail(aux);

    rlutil::locate(30, 13);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Telefono: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 13);
    getline(cin, aux);
    paciente.setTelefono(aux);

    rlutil::locate(30, 14);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Domicilio: ";
    rlutil::locate(33, 15);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Calle: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 15);
    getline(cin, aux);
    domicilio.setCalle(aux);

    rlutil::locate(30, 16);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Altura: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 16);
    cin >> altura;
    domicilio.setAltura(altura);
    cin.ignore();

    rlutil::locate(30, 17);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Localidad: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 17);
    getline(cin, aux);
    domicilio.setLocalidad(aux);

    rlutil::locate(30, 18);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Provincia: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 18);
    getline(cin, aux);
    domicilio.setProvincia(aux);

    rlutil::locate(30, 19);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Codigo Postal: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 19);
    getline(cin, aux);
    domicilio.setCodigoPostal(aux);

    paciente.setDomicilio(domicilio);

    id = _archivo.getNuevoID();
    rlutil::locate(30, 20);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "ID asignado: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 20);
    cout << id;
    paciente.setIDPaciente(id);

    rlutil::locate(30, 21);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Numero de carnet: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(48, 21);
    cin >> carnet;
    cin.ignore();
    paciente.setCarnet(carnet);
    paciente.setEstado(true);

    rlutil::locate(30, 24);
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
        rlutil::cls();
        return;
    }

    Paciente* vecPaciente = new Paciente[cantidad];
    _archivo.leerMuchos(vecPaciente, cantidad);

    rlutil::cls();
    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::locate(50, 2);
    cout << " LISTADO DE PACIENTES ";
    rlutil::setColor(rlutil::COLOR::WHITE);

    int fila = 4;

        for (int i = 0; i < cantidad; i++) {
            if (vecPaciente[i].getEstado()== true || vecPaciente[i].getEstado()==false) {
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(52, 3);
            cout << " PACIENTE " << (i + 1) << " DE " << cantidad;
            rlutil::setColor(rlutil::COLOR::WHITE);

            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
            rlutil::locate(30, fila);     cout << "------------------------------------------------------------";
            rlutil::locate(30, fila + 17); cout << "------------------------------------------------------------";

            rlutil::locate(32, fila + 1);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Apellido: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getApellido();

            rlutil::locate(32, fila + 2);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Nombre: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getNombre();

            rlutil::locate(32, fila + 3);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "DNI: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getDni();

            rlutil::locate(32, fila + 4);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Fecha de nacimiento: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout<<vecPaciente[i].getFechaNacimiento().getDia()<<"/"<<vecPaciente[i].getFechaNacimiento().getMes()<<"/"<<vecPaciente[i].getFechaNacimiento().getAnio();

            rlutil::locate(32, fila + 5);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Genero: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getGenero();

            rlutil::locate(32, fila + 6);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Email: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getEmail();

            rlutil::locate(32, fila + 7);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Telefono: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getTelefono();

            rlutil::locate(32, fila + 8);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Domicilio: ";

            rlutil::locate(32, fila + 9);
            cout << "Calle: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getDomicilioCompleto().getCalle();

            rlutil::locate(32, fila + 10);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Altura: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getDomicilioCompleto().getAltura();

            rlutil::locate(32, fila + 11);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Localidad: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getDomicilioCompleto().getLocalidad();

            rlutil::locate(32, fila + 12);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Provincia: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getDomicilioCompleto().getProvincia();

            rlutil::locate(32, fila + 13);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Codigo Postal: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getDomicilioCompleto().getCodigoPostal();

            rlutil::locate(32, fila + 14);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Carnet: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getCarnet();

            rlutil::locate(32, fila + 15);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "ID Paciente: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getIDPaciente();

            rlutil::locate(32, fila + 16);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Estado: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            if(vecPaciente[i].getEstado()){
                cout << "Activo";
            }
            else{
                cout << "Inactivo";
            }

            rlutil::locate(35, fila + 18);
            rlutil::setColor(rlutil::COLOR::YELLOW);
            cout << "Presione una tecla para ver el siguiente paciente...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::cls();
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

void PacienteManager::DarBajaPaciente(){


    int id;
    bool encontrado = false;

    while (!encontrado) {
        rlutil::cls();
        rlutil::setColor(rlutil::COLOR::YELLOW);
        rlutil::locate(40, 3);
        cout << " DAR DE BAJA PACIENTE ";

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 6);
        cout << "Ingrese el ID del paciente a dar de baja: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(75, 6);
        cin >> id;

        int pos=_archivo.Buscar(id);
        Paciente posPaciente;

        if (pos == -1) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "Paciente no encontrado. Intente nuevamente.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            continue;
        }

        posPaciente = _archivo.Leer(pos);
        if (!posPaciente.getEstado()) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "El Paciente ya esta dado de baja.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            continue;
        }

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 9);
        cout << "Esta seguro que desea dar de baja al Paciente de ID '" << id << "'? (s/n): ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        char confirmacion;
        cin >> confirmacion;

        if (confirmacion == 's' || confirmacion == 'S') {
            posPaciente.setEstado(false);
            if (_archivo.guardar(posPaciente, pos)) {
                rlutil::setColor(rlutil::COLOR::GREEN);
                rlutil::locate(30, 11);
                cout << "Paciente dado de baja correctamente.";
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

void PacienteManager::modificarPaciente(){
    string aux;
    int dni, carnet, id, altura, dia, mes, anio;
    Fecha fechaNacimiento;
    Domicilio domicilio;
    char confirmacion;
    bool modificado = false;


        while (!modificado) {
        rlutil::cls();
        rlutil::setColor(rlutil::COLOR::YELLOW);
        rlutil::locate(40, 3);
        cout << " MODIFICAR PACIENTE ";

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 6);
        cout << "Ingrese el ID del paciente a modificar: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(73, 6);
        cin >> id;

        int pos = _archivo.Buscar(id);
        Paciente paciente;

        if (pos == -1) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "Paciente no encontrado. Intente nuevamente.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            continue;
        }

        paciente = _archivo.Leer(pos);

        if (!paciente.getEstado()) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "El paciente esta dado de baja. No se puede modificar.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            continue;
        }

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 9);
        cout << "Esta seguro que desea modificar al Paciente ID '" << id << "'? (s/n): ";
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
        getline(cin, aux); paciente.setApellido(aux);


        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 7);
        cout << "Nuevo Nombre: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 7);
        getline(cin, aux); paciente.setNombre(aux);

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 8);
        cout << "Nuevo DNI: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 8);
        cin >> dni; cin.ignore(); paciente.setDni(dni);

        rlutil::locate(30, 9);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Nueva fecha de nacimiento:";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(30, 10);
        cout << "Dia: ";
        rlutil::locate(55, 10);
        cin >> dia;
        rlutil::locate(30, 11);
        cout << "Mes: ";
        rlutil::locate(55, 11);
        cin >> mes;
        rlutil::locate(30, 12);
        cout << "Anio: ";
        rlutil::locate(55, 12);
        cin >> anio;
        cin.ignore();
  	fechaNacimiento = Fecha(dia, mes, anio);
  	paciente.setFechaNacimiento(fechaNacimiento);

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 13);
        cout << "Nuevo Genero: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 13);
        getline(cin, aux);
        paciente.setGenero(aux);

        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 14);
        cout << "Nuevo Email: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 14);
        getline(cin, aux);
        paciente.setEmail(aux);


        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 15);
        cout << "Nuevo Telefono: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 15);
        getline(cin, aux);
        paciente.setTelefono(aux);


        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 16);
        cout << "Nuevo Domicilio: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 16);



        rlutil::locate(30, 17);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Calle: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 17);
        getline(cin, aux);
        domicilio.setCalle(aux);

        rlutil::locate(30, 18);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Altura: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 18);
        cin >> altura;
        domicilio.setAltura(altura);
        cin.ignore();

        rlutil::locate(30, 19);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Localidad: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 19);
        getline(cin, aux);
        domicilio.setLocalidad(aux);

        rlutil::locate(30, 20);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Provincia: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 20);
        getline(cin, aux);
        domicilio.setProvincia(aux);

        rlutil::locate(30, 21);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Codigo Postal: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 21);
        getline(cin, aux);
        domicilio.setCodigoPostal(aux);

        paciente.setDomicilio(domicilio);


        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 22);
        cout << "Nuevo numero de carnet: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(55, 22);
        cin >> carnet;
        paciente.setCarnet(carnet);

        if (_archivo.guardar(paciente, pos)) {
                      system("cls");
            rlutil::setColor(rlutil::COLOR::GREEN);
            rlutil::locate(30, 10);
            cout << "Paciente modificado correctamente.";
        } else {
                  system("cls");
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 10);
            cout << "Error al intentar modificar el paciente.";
        }

        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        modificado = true;
    }

    rlutil::cls();
}

void PacienteManager::reactivarPaciente(){
    int cantidad, fila, contador, contadorInactivos, posicion;
    bool noActivo=false;
    char confirmacion;

    cantidad = _archivo.getCantidadRegistros();
    if (cantidad == 0) {
        rlutil::cls();
        rlutil::locate(40, 10);
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "No hay pacientes cargados." << endl;
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return;
    }

    Paciente* vecPaciente = new Paciente[cantidad];
    _archivo.leerMuchos(vecPaciente, cantidad);

    rlutil::cls();
    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::locate(50, 2);
    cout << " LISTADO DE PACIENTES INACTIVOS ";
    rlutil::setColor(rlutil::COLOR::WHITE);

    fila = 4;
    contador=0;
    contadorInactivos=0;
    for (int x = 0; x < cantidad; x++){
        if(vecPaciente[x].getEstado()==false){
            contadorInactivos++;
        }
    }
    for (int i = 0; i < cantidad; i++){

        if (vecPaciente[i].getEstado()==false) {
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(55, 3);
            cout << " PACIENTE " << (contador + 1) << " DE " << contadorInactivos;
            rlutil::setColor(rlutil::COLOR::WHITE);

            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
            rlutil::locate(30, fila);     cout << "------------------------------------------------------------";
            rlutil::locate(30, fila + 19); cout << "------------------------------------------------------------";

            rlutil::locate(32, fila + 1);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Apellido: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getApellido();

            rlutil::locate(32, fila + 2);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Nombre: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getNombre();

            rlutil::locate(32, fila + 3);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "DNI: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getDni();

            rlutil::locate(32, fila + 4);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Fecha de nacimiento: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout<<vecPaciente[i].getFechaNacimiento().getDia()<<"/"<<vecPaciente[i].getFechaNacimiento().getMes()<<"/"<<vecPaciente[i].getFechaNacimiento().getAnio();

            rlutil::locate(32, fila + 5);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Genero: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getGenero();

            rlutil::locate(32, fila + 6);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Email: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getEmail();

            rlutil::locate(32, fila + 7);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Telefono: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getTelefono();

            rlutil::locate(32, fila + 8);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Domicilio: ";

            rlutil::locate(32, fila + 9);
            cout << "Calle: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getDomicilioCompleto().getCalle();

            rlutil::locate(32, fila + 10);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Altura: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getDomicilioCompleto().getAltura();

            rlutil::locate(32, fila + 11);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Localidad: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getDomicilioCompleto().getLocalidad();

            rlutil::locate(32, fila + 12);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Provincia: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getDomicilioCompleto().getProvincia();

            rlutil::locate(32, fila + 13);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Codigo Postal: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getDomicilioCompleto().getCodigoPostal();

            rlutil::locate(32, fila + 14);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Carnet: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getCarnet();

            rlutil::locate(32, fila + 15);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "ID Paciente: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecPaciente[i].getIDPaciente();

            rlutil::locate(32, fila + 17);
            rlutil::setColor(rlutil::COLOR::GREEN);
            cout<<"DESEA ACTIVAR EL PACIENTE? (s/n): ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cin >> confirmacion;

            if (confirmacion == 's' || confirmacion == 'S') {
                vecPaciente[i].setEstado(true);
                posicion = _archivo.Buscar(vecPaciente[i].getIDPaciente());
                if(_archivo.guardar(vecPaciente[i], posicion)){
                        rlutil::locate(32, fila + 18);
                        rlutil::setColor(rlutil::COLOR::GREEN);
                        cout<<"Paciente activado correctamente.";
                    }else{
                        rlutil::locate(32, fila + 18);
                        rlutil::setColor(rlutil::COLOR::RED);
                        cout<<"Error al guardar el paciente.";
                    }
                }else{
                    rlutil::setColor(rlutil::COLOR::YELLOW);
                    rlutil::locate(32,fila + 18);
                    cout << "Accion cancelada.";
                    rlutil::setColor(rlutil::COLOR::WHITE);
                }


            rlutil::locate(35, fila + 20);
            rlutil::setColor(rlutil::COLOR::YELLOW);
            cout << "Presione una tecla para ver el siguiente paciente...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::cls();
            contador++;
            noActivo=true;
        }
    }

    if(!noActivo){
        delete[] vecPaciente;
        rlutil::locate(40, 9);
        rlutil::setColor(rlutil::COLOR::RED);
        cout<<"No hay pacientes inactivos...";
         rlutil::locate(40, 11);
        rlutil::setColor(rlutil::COLOR::GREEN);
        cout << "Presione una tecla para continuar...";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return;
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

