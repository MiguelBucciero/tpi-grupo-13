#include "PacienteManager.h"
#include "rlutil.h"
#include <iostream>
#include <string>
#include "Validador.h"
using namespace std;

void PacienteManager::cargarPaciente() {
    Paciente paciente;
    Validador val;
    string aux;
    int dni, carnet, id, altura, dia, mes, anio;
    Fecha fechaNacimiento;
    Domicilio domicilio;

    rlutil::cls();
    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::locate(40, 2);
    cout << "INGRESO DE NUEVO PACIENTE";
    rlutil::setColor(rlutil::COLOR::WHITE);
        cin.clear();
        cin.ignore(1000, '\n');

        //Apellido

do {
        rlutil::locate(30, 4);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Apellido: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(45, 4);
        getline(cin, aux);
        if (!val.esTextoValido(aux)) {
            rlutil::locate(30, 23);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Apellido invalido. Ingrese solo letras.                        ";
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, 24);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();

            rlutil::locate(45, 4);
            cout << "                                                                           ";
            rlutil::locate(30, 23);
            cout << "                                                                           ";
            rlutil::locate(30, 24);
            cout << "                                                                           ";
        }
    } while (!val.esTextoValido(aux));
    paciente.setApellido(aux);

//Nombre

    do {
        rlutil::locate(30, 5);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Nombre: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(45, 5);
        getline(cin, aux);
        if (!val.esTextoValido(aux)) {
        rlutil::locate(30, 23);
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "Nombre invalido. Ingrese solo letras.                        ";
        rlutil::setColor(rlutil::COLOR::YELLOW);
        rlutil::locate(30, 24);
        cout << "Presione una tecla para continuar...";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        rlutil::locate(45, 5);
        cout << "                                                                           ";
        rlutil::locate(30, 23);
        cout << "                                                                           ";
        rlutil::locate(30, 24);
        cout << "                                                                           ";
        }
    } while (!val.esTextoValido(aux));
    paciente.setNombre(aux);

//DNI
    do {
        rlutil::locate(30, 6);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "DNI: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(45, 6);
        cin >> dni;
        if (cin.fail() || !val.esEnteroPositivo(dni)) {
            cin.clear();
            cin.ignore(1000, '\n');
            rlutil::locate(30, 23);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "DNI invalido. Solo numeros.                        ";
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, 24);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(45, 6);
            cout << "                                                                           ";
            rlutil::locate(30, 23);
            cout << "                                                                           ";
            rlutil::locate(30, 24);
            cout << "                                                                           ";
        }
    } while (cin.fail() || !val.esEnteroPositivo(dni));
    cin.ignore();
    paciente.setDni(dni);


//Fecha Nacimiento

    do {
        rlutil::locate(30, 7);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Fecha de nacimiento:";
        rlutil::setColor(rlutil::COLOR::WHITE);

        rlutil::locate(30, 8);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Dia: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(45, 8);
        cin >> dia;

        rlutil::locate(30, 9);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Mes: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(45, 9);
        cin >> mes;

        rlutil::locate(30, 10);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Anio: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(45, 10);
        cin >> anio;

        if (cin.fail() || !val.esFechaValida(dia, mes, anio)) {
            cin.clear();
            cin.ignore(1000, '\n');
            rlutil::locate(30, 23);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Fecha invalida.                        ";
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, 24);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(45, 8);
            cout << "   ";
            rlutil::locate(45, 9);
            cout << "   ";
            rlutil::locate(45, 10);
            cout << "     ";
            rlutil::locate(30, 23);
            cout << "                                                                           ";
            rlutil::locate(30, 24);
            cout << "                                                                           ";
        }
    } while (cin.fail() || !val.esFechaValida(dia, mes, anio));
    cin.ignore();
    paciente.setFechaNacimiento(Fecha(dia, mes, anio));


//Genero

    do {
        rlutil::locate(30, 11);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Genero: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(45, 11);
        getline(cin, aux);
        if (!val.esTextoValido(aux)) {
            rlutil::locate(30, 23);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Genero invalido. Ingrese solo letras.                        ";
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, 24);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(45, 11);
            cout << "                                                                           ";
            rlutil::locate(30, 23);
            cout << "                                                                           ";
            rlutil::locate(30, 24);
            cout << "                                                                           ";
        }
    } while (!val.esTextoValido(aux));
    paciente.setGenero(aux);


//Mail
 do {
        rlutil::locate(30, 12);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Email: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(45, 12);
        getline(cin, aux);
        if (!val.esEmailValido(aux)) {
            rlutil::locate(30, 23);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "El email es invalido.Vuelva a intentar                        ";
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, 24);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(45, 12);
            cout << "                                                                           ";
            rlutil::locate(30, 23);
            cout << "                                                                           ";
            rlutil::locate(30, 24);
            cout << "                                                                           ";
        }
    } while (!val.esEmailValido(aux));
    paciente.setEmail(aux);


//Telefono
    do {
        rlutil::locate(30, 13);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Telefono: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(45, 13);
        getline(cin, aux);
        if (!val.esNumeroValido(aux)) {
            rlutil::locate(30, 23);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Numero de telefono invalido. Ingrese solo numeros                        ";
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, 24);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(45, 13);
            cout << "                                                                           ";
            rlutil::locate(30, 23);
            cout << "                                                                           ";
            rlutil::locate(30, 24);
            cout << "                                                                           ";
        }
    } while (!val.esNumeroValido(aux));
    paciente.setTelefono(aux);


//Domicilio

    rlutil::locate(30, 14);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Domicilio:";
    rlutil::setColor(rlutil::COLOR::WHITE);

    // Calle
    do {
        rlutil::locate(30, 15);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Calle: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(45, 15);
        getline(cin, aux);
        if (!val.esTextoValido(aux)) {
            rlutil::locate(30, 23);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Calle invalida. Ingrese solo letras.                        ";
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, 24);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(45, 15);
            cout << "                                                                           ";
            rlutil::locate(30, 23);
            cout << "                                                                           ";
            rlutil::locate(30, 24);
            cout << "                                                                           ";
        }
    } while (!val.esTextoValido(aux));
    domicilio.setCalle(aux);

    // Altura
    do {
        rlutil::locate(30, 16);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Altura: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(45, 16);
        cin >> altura;
        if (cin.fail() || !val.esEnteroPositivo(altura)) {
            cin.clear();
            cin.ignore(1000, '\n');
            rlutil::locate(30, 23);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Altura invalida. Ingrese solo numeros.                        ";
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, 24);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(45, 16);
            cout << "                                                                           ";
            rlutil::locate(30, 23);
            cout << "                                                                           ";
            rlutil::locate(30, 24);
            cout << "                                                                           ";
        }
    } while (cin.fail() || !val.esEnteroPositivo(altura));
    cin.ignore();
    domicilio.setAltura(altura);

    // Localidad
    do {
        rlutil::locate(30, 17);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Localidad: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(45, 17);
        getline(cin, aux);
        if (!val.esTextoValido(aux)) {
            rlutil::locate(30, 23);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Localidad invalida.                        ";
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, 24);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(45, 17);
            cout << "                                                                           ";
            rlutil::locate(30, 23);
            cout << "                                                                           ";
            rlutil::locate(30, 24);
            cout << "                                                                           ";
        }
    } while (!val.esTextoValido(aux));
    domicilio.setLocalidad(aux);

    // Provincia
    do {
        rlutil::locate(30, 18);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Provincia: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(45, 18);
        getline(cin, aux);
        if (!val.esTextoValido(aux)) {
            rlutil::locate(30, 23);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Provincia invalida.                        ";
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, 24);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(45, 18);
            cout << "                                                                           ";
            rlutil::locate(30, 23);
            cout << "                                                                           ";
            rlutil::locate(30, 24);
            cout << "                                                                           ";
        }
    } while (!val.esTextoValido(aux));
    domicilio.setProvincia(aux);

    // Codigo Postal
    do {
        rlutil::locate(30, 19);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Codigo Postal: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(45, 19);
        getline(cin, aux);
        if (!val.esNumeroValido(aux)) {
            rlutil::locate(30, 23);
            rlutil::setColor(rlutil::RED);
            cout << "Codigo postal invalido.Ingrese solo numeros.                       ";
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, 24);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
            rlutil::locate(45, 19);
            cout << "                                                                           ";
            rlutil::locate(30, 23);
            cout << "                                                                           ";
            rlutil::locate(30, 24);
            cout << "                                                                           ";
        }
    } while (!val.esNumeroValido(aux));
    domicilio.setCodigoPostal(aux);

    paciente.setDomicilio(domicilio);


//ID
    id = _archivo.getNuevoID();
    rlutil::locate(30, 20);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "ID asignado: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 20);
    cout << id;
    paciente.setIDPaciente(id);

//Carnet

   do {
        rlutil::locate(30, 21);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Numero de carnet: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(48, 21);
        cin >> carnet;
        if (cin.fail() || !val.esEnteroPositivo(carnet)) {
            cin.clear();
            cin.ignore(1000, '\n');
            rlutil::locate(30, 23);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Numero de Carnet invalido.                        ";
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, 24);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(45, 21);
            cout << "                                                                           ";
            rlutil::locate(30, 23);
            cout << "                                                                           ";
            rlutil::locate(30, 24);
            cout << "                                                                           ";
        }
    } while (cin.fail() || !val.esEnteroPositivo(carnet));
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
    Validador val;
    char confirmacion;
    int id;
    bool encontrado = false, idValido=false, confirmarValidacion=false;


    while (!encontrado) {
        rlutil::cls();
        rlutil::setColor(rlutil::COLOR::YELLOW);
        rlutil::locate(40, 3);
        cout << " DAR DE BAJA PACIENTE ";

    do{
        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 6);
        cout << "Ingrese el ID del paciente a dar de baja: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(75, 6);
        cin >> id;

        if (cin.fail() || !val.esEnteroPositivo(id)) {
            cin.clear();
            cin.ignore(1000, '\n');
            rlutil::locate(30, 8);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "ID invalido. Ingrese un numero entero positivo.";
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, 9);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(75, 6);
            cout << "                                                       ";
            rlutil::locate(30, 8);
            cout << "                                                       ";
            rlutil::locate(30, 9);
            cout << "                                                       ";

        }
        else{
                idValido=true;
        }
        }while(!idValido);

        int pos=_archivo.Buscar(id);
        Paciente posPaciente;

        if (pos == -1) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "Paciente no encontrado. Presione enter e intente nuevamente.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
        }else{

            posPaciente = _archivo.Leer(pos);
            if (!posPaciente.getEstado()) {
                rlutil::setColor(rlutil::COLOR::RED);
                rlutil::locate(30, 8);
                cout << "El Paciente ya esta dado de baja. Presione enter e intente nuevamente";
                rlutil::anykey();
            }else{
                do{

                rlutil::setColor(rlutil::COLOR::CYAN);
                rlutil::locate(30, 9);
                cout << "Esta seguro que desea dar de baja al Paciente de ID '" << id << "'? (s/n): ";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::locate(95, 9);
                cin >> confirmacion;

                if (!val.esConfirmacionSN(confirmacion)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    rlutil::locate(30, 13);
                    rlutil::setColor(rlutil::COLOR::RED);
                    cout << "Opcion invalida. Ingrese solo 's' o 'n'.";
                    rlutil::setColor(rlutil::COLOR::YELLOW);
                    rlutil::locate(30, 14);
                    cout << "Presione una tecla para continuar...";
                    rlutil::setColor(rlutil::COLOR::WHITE);
                    rlutil::anykey();
                    rlutil::locate(92, 9);
                    cout << "                                                      ";
                    rlutil::locate(30, 13);
                    cout << "                                                       ";
                    rlutil::locate(30, 14);
                    cout << "                                                       ";
                }
            }while(!val.esConfirmacionSN(confirmacion));

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
    }
}

void PacienteManager::modificarPaciente(){
    Validador val;
    string aux;
    int dni, carnet, id, altura, dia, mes, anio;
    Fecha fechaNacimiento;
    Domicilio domicilio;
    char confirmacion;
    bool modificado = false, confirmacionValida=false;


    while (!modificado) {
    rlutil::cls();
    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::locate(40, 3);
    cout << " MODIFICAR PACIENTE ";
    do{
            rlutil::setColor(rlutil::COLOR::CYAN);
            rlutil::locate(30, 6);
            cout << "Ingrese el ID del paciente a modificar: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::locate(73, 6);
            cin >> id;
                if (cin.fail() || !val.esEnteroPositivo(id)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    rlutil::locate(30, 8);
                    rlutil::setColor(rlutil::COLOR::RED);
                    cout << "ID invalido. Presione enter e intente nuevamente.";
                    rlutil::setColor(rlutil::COLOR::WHITE);
                    rlutil::anykey();
                    rlutil::locate(73, 6);
                    cout<<"                                                                           ";
                    rlutil::locate(30, 8);
                    cout<<"                                                                           ";
                }
    }while(cin.fail() || !val.esEnteroPositivo(id));
    cin.ignore(1000, '\n');
    int pos = _archivo.Buscar(id);
    Paciente paciente;

    if (pos == -1) {
        rlutil::setColor(rlutil::COLOR::RED);
        rlutil::locate(30, 8);
        cout << "Paciente no encontrado. Presione enter e intente nuevamente.";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
    }else{
        paciente = _archivo.Leer(pos);

        if (!paciente.getEstado()) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "El paciente esta dado de baja. No se puede modificar. Presione enter e intente nuevamente.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
        }else{
            while(!confirmacionValida){
                rlutil::setColor(rlutil::COLOR::CYAN);
                rlutil::locate(30, 9);
                cout << "Esta seguro que desea modificar al Paciente ID '" << id << "'? (s/n): ";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::locate(93, 9);
                cin >> confirmacion;

            if (cin.fail() || !val.esConfirmacionSN(confirmacion)) {
                cin.clear();
                cin.ignore(1000, '\n');
                rlutil::locate(30, 11);
                rlutil::setColor(rlutil::COLOR::RED);
                cout << "Ingrese solo 's' o 'n'. Presione una tecla para continuar";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
                rlutil::locate(30, 11);
                cout << "                                                         ";
                rlutil::locate(93, 9);
                cout << "                                                             ";
            }else{
                confirmacionValida=true;
                cin.ignore(1000, '\n');
            }
            }


            if (confirmacion == 's' || confirmacion == 'S') {
                    rlutil::cls();
                    rlutil::setColor(rlutil::COLOR::YELLOW);
                    rlutil::locate(40, 3);
                    cout << " INGRESO DE NUEVOS DATOS ";

                    //Apellido
                    do {
                            rlutil::locate(30, 6);
                            rlutil::setColor(rlutil::COLOR::CYAN);
                            cout << "Nuevo Apellido: ";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::locate(60, 6);
                            getline(cin, aux);
                            if (!val.esTextoValido(aux)) {
                                rlutil::locate(30, 25);
                                rlutil::setColor(rlutil::COLOR::RED);
                                cout << "Apellido invalido. Ingrese solo letras.                        ";
                                rlutil::setColor(rlutil::COLOR::YELLOW);
                                rlutil::locate(30, 26);
                                cout << "Presione una tecla para continuar...";
                                rlutil::setColor(rlutil::COLOR::WHITE);
                                rlutil::anykey();
                                rlutil::locate(60, 6);
                                cout << "                                                                           ";
                                rlutil::locate(30, 25);
                                cout << "                                                                           ";
                                rlutil::locate(30, 26);
                                cout << "                                                                           ";
                            }
                    } while (!val.esTextoValido(aux));
                    paciente.setApellido(aux);

                    //Nombre
                    do {
                            rlutil::locate(30, 7);
                            rlutil::setColor(rlutil::COLOR::CYAN);
                            cout << "Nuevo Nombre: ";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::locate(60, 7);
                            getline(cin, aux);
                            if (!val.esTextoValido(aux)) {
                                rlutil::locate(30, 25);
                                rlutil::setColor(rlutil::COLOR::RED);
                                cout << "Nombre invalido. Ingrese solo letras.                         ";
                                rlutil::setColor(rlutil::COLOR::YELLOW);
                                rlutil::locate(30, 26);
                                cout << "Presione una tecla para continuar...";
                                rlutil::setColor(rlutil::COLOR::WHITE);
                                rlutil::anykey();
                                rlutil::locate(60, 7);
                                cout << "                                                                           ";
                                rlutil::locate(30, 25);
                                cout << "                                                                           ";
                                rlutil::locate(30, 26);
                                cout << "                                                                           ";
                            }//Limpiar el campo
                    } while (!val.esTextoValido(aux));
                    paciente.setNombre(aux);

                    //DNI
                    do {
                            rlutil::locate(30, 8);
                            rlutil::setColor(rlutil::COLOR::CYAN);
                            cout << "Nuevo DNI: ";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::locate(60, 8);
                            cin >> dni;
                            if (cin.fail() || !val.esEnteroPositivo(dni)) {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                rlutil::locate(30, 25);
                                rlutil::setColor(rlutil::COLOR::RED);
                                cout << "DNI invalido.Ingrese solo numeros.                     ";
                                rlutil::setColor(rlutil::COLOR::YELLOW);
                                rlutil::locate(30, 26);
                                cout << "Presione una tecla para continuar...";
                                rlutil::setColor(rlutil::COLOR::WHITE);
                                rlutil::anykey();
                                rlutil::locate(60, 8);
                                cout << "                                                                           ";
                                rlutil::locate(30, 25);
                                cout << "                                                                           ";
                                rlutil::locate(30, 26);
                                cout << "                                                                           ";
                            }//Limpiar el campo
                    } while (cin.fail() || !val.esEnteroPositivo(dni));
                    paciente.setDni(dni);

                    //Fecha de Nacimiento
                    do {
                            rlutil::locate(30, 9);
                            rlutil::setColor(rlutil::COLOR::CYAN);
                            cout << "Nueva fecha de nacimiento:";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::locate(30, 10);
                            cout << "Dia: ";
                            rlutil::locate(60, 10);
                            cin >> dia;
                            rlutil::locate(30, 11);
                            cout << "Mes: ";
                            rlutil::locate(60, 11);
                            cin >> mes;
                            rlutil::locate(30, 12);
                            cout << "Anio: ";
                            rlutil::locate(60, 12);
                            cin >> anio;
                            if (cin.fail() || !val.esFechaValida(dia, mes, anio)) {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                rlutil::locate(30, 25);
                                rlutil::setColor(rlutil::COLOR::RED);
                                cout << "Fecha invalida.Ingrese de nuevo la fecha...                        ";
                                rlutil::setColor(rlutil::COLOR::YELLOW);
                                rlutil::locate(30, 26);
                                cout << "Presione una tecla para continuar...";
                                rlutil::setColor(rlutil::COLOR::WHITE);
                                rlutil::anykey();
                                // Limpiar los campos
                                rlutil::locate(60, 10);
                                cout << "                                                                           ";//Limpiar el campo
                                rlutil::locate(60, 11);
                                cout << "                                                                           ";//Limpiar el campo
                                rlutil::locate(60, 12);
                                cout << "                                                                           ";
                                rlutil::locate(30, 25);
                                cout << "                                                                           ";

                                rlutil::locate(30, 26);
                                cout << "                                                                           ";
                            }//Limpiar el campo
                    } while (cin.fail() || !val.esFechaValida(dia, mes, anio));
                    cin.ignore(1000, '\n');
                    paciente.setFechaNacimiento(fechaNacimiento);

                    //Genero
                     do {
                            rlutil::locate(30, 13);
                            rlutil::setColor(rlutil::COLOR::CYAN);
                            cout << "Nuevo Genero: ";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::locate(60, 13);
                            getline(cin, aux);
                            if (!val.esTextoValido(aux)) {
                                rlutil::locate(30, 25);
                                rlutil::setColor(rlutil::COLOR::RED);
                                cout << "Genero invalido.Ingrese solo letras.                       ";
                                rlutil::setColor(rlutil::COLOR::YELLOW);
                                rlutil::locate(30, 26);
                                cout << "Presione una tecla para continuar...";
                                rlutil::setColor(rlutil::COLOR::WHITE);
                                rlutil::anykey();
                                rlutil::locate(60, 13);
                                cout << "                                                                           ";
                                rlutil::locate(30, 25);
                                cout << "                                                                           ";

                                rlutil::locate(30, 26);
                                cout << "                                                                           ";
                                //Limpiar el campo
                            }
                    } while (!val.esTextoValido(aux));
                    paciente.setGenero(aux);

                    //Mail
                     do {
                            rlutil::setColor(rlutil::COLOR::CYAN);
                            rlutil::locate(30, 14);
                            cout << "Nuevo Email: ";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::locate(60, 14);
                            getline(cin, aux);

                            if (!val.esEmailValido(aux)) {
                                rlutil::locate(30, 25);
                                rlutil::setColor(rlutil::COLOR::RED);
                                cout << "El email es invalido. Vuelva a intentar                       ";
                                rlutil::setColor(rlutil::COLOR::YELLOW);
                                rlutil::locate(30, 26);
                                cout << "Presione una tecla para continuar...";
                                rlutil::setColor(rlutil::COLOR::WHITE);
                                rlutil::anykey();
                                rlutil::locate(60, 14);
                                cout << "                                                                           ";
                                rlutil::locate(30, 25);
                                cout << "                                                                           ";
                                rlutil::locate(30, 26);
                                cout << "                                                                           ";
                            }

                    } while (!val.esEmailValido(aux));
                    paciente.setEmail(aux);

                    //Telefono
                    do{
                            rlutil::setColor(rlutil::COLOR::CYAN);
                            rlutil::locate(30, 15);
                            cout << "Nuevo Telefono: ";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::locate(60, 15);
                            getline(cin, aux);

                            if (!val.esNumeroValido(aux)) {
                                rlutil::locate(30, 25);
                                rlutil::setColor(rlutil::COLOR::RED);
                                cout << "Numero de telefono invalido. Ingrese solo numeros.                        ";
                                rlutil::setColor(rlutil::COLOR::YELLOW);
                                rlutil::locate(30, 26);
                                cout << "Presione una tecla para continuar...";
                                rlutil::setColor(rlutil::COLOR::WHITE);
                                rlutil::anykey();
                                rlutil::locate(60, 15);
                                cout << "                                                                           ";
                                rlutil::locate(30, 25);
                                cout << "                                                                           ";
                                rlutil::locate(30, 26);
                                cout << "                                                                           ";
                            }
                    } while (!val.esNumeroValido(aux));
                    paciente.setTelefono(aux);


                    //Domicilio

                            rlutil::setColor(rlutil::COLOR::CYAN);
                            rlutil::locate(30, 16);
                            cout << "Nuevo Domicilio: ";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::locate(55, 16);

                    //Calle
                     do {
                            rlutil::locate(30, 17);
                            rlutil::setColor(rlutil::COLOR::CYAN);
                            cout << "Calle: ";
                            rlutil::locate(60, 17);
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            getline(cin, aux);
                            if (cin.fail() ||!val.esTextoValido(aux)) {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                rlutil::locate(30, 25);
                                rlutil::setColor(rlutil::COLOR::RED);
                                cout << "Calle invalida. Ingrese solo letras.                       ";
                                rlutil::setColor(rlutil::COLOR::YELLOW);
                                rlutil::locate(30, 26);
                                cout << "Presione una tecla para continuar...";
                                rlutil::setColor(rlutil::COLOR::WHITE);
                                rlutil::anykey();
                                rlutil::locate(60, 17);
                                cout << "                                                                           ";
                                rlutil::locate(30, 25);
                                cout << "                                                                           ";
                                rlutil::locate(30, 26);
                                cout << "                                                                           ";//Limpiar el campo
                        }
                    } while (!val.esTextoValido(aux));
                    domicilio.setCalle(aux);


                    //Altura
                    do {
                            rlutil::locate(30, 18);
                            rlutil::setColor(rlutil::COLOR::CYAN);
                            cout << "Altura: ";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::locate(60, 18);
                            cin >> altura;
                            if (cin.fail() || !val.esEnteroPositivo(altura)) {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                rlutil::locate(30, 25);
                                rlutil::setColor(rlutil::COLOR::RED);
                                cout << "Altura invalida. Ingrese solo numeros.                          ";
                                rlutil::setColor(rlutil::COLOR::YELLOW);
                                rlutil::locate(30, 26);
                                cout << "Presione una tecla para continuar...";
                                rlutil::setColor(rlutil::COLOR::WHITE);
                                rlutil::anykey();
                                rlutil::locate(60, 18);
                                cout << "                                                                           ";
                                rlutil::locate(30, 25);
                                cout << "                                                                           ";
                                rlutil::locate(30, 26);
                                cout << "                                                                           ";//Limpiar el campo
                                }
                    } while (cin.fail() || !val.esEnteroPositivo(altura));
                    cin.ignore(1000, '\n');
                    domicilio.setAltura(altura);

                    //Localidad
                    do {
                            rlutil::locate(30, 19);
                            rlutil::setColor(rlutil::COLOR::CYAN);
                            cout << "Localidad: ";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::locate(60, 19);
                            getline(cin, aux);
                            if (!val.esTextoValido(aux)) {
                                rlutil::locate(30, 25);
                                rlutil::setColor(rlutil::COLOR::RED);
                                cout << "Localidad invalida.Ingrese solo letras.                        ";
                                rlutil::setColor(rlutil::COLOR::YELLOW);
                                rlutil::locate(30, 26);
                                cout << "Presione una tecla para continuar...";
                                rlutil::setColor(rlutil::COLOR::WHITE);
                                rlutil::anykey();
                                rlutil::locate(60, 19);
                                cout << "                                                                           ";
                                rlutil::locate(30, 25);
                                cout << "                                                                           ";
                                rlutil::locate(30, 26);
                                cout << "                                                                           ";//Limpiar el campo
                                }
                    } while (!val.esTextoValido(aux));
                    domicilio.setLocalidad(aux);

                     // Provincia
                    do {
                            rlutil::locate(30, 20);
                            rlutil::setColor(rlutil::COLOR::CYAN);
                            cout << "Provincia: ";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::locate(60, 20);
                            getline(cin, aux);
                            if (!val.esTextoValido(aux)) {
                                rlutil::locate(30, 25);
                                rlutil::setColor(rlutil::COLOR::RED);
                                cout << "Provincia invalida. Ingrese solo letras.                      ";
                                rlutil::setColor(rlutil::COLOR::YELLOW);
                                rlutil::locate(30, 26);
                                cout << "Presione una tecla para continuar...";
                                rlutil::setColor(rlutil::COLOR::WHITE);
                                rlutil::anykey();
                                rlutil::locate(60, 20);
                                cout << "                                                                           ";
                                rlutil::locate(30, 25);
                                cout << "                                                                           ";
                                rlutil::locate(30, 26);
                                cout << "                                                                           ";//Limpiar el campo
                            }
                    } while (!val.esTextoValido(aux));
                    domicilio.setProvincia(aux);

                    //Codigo Postal
                     do {
                            rlutil::locate(30, 21);
                            rlutil::setColor(rlutil::COLOR::CYAN);
                            cout << "Codigo Postal: ";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::locate(60, 21);
                            getline(cin, aux);
                            if (!val.esNumeroValido(aux)) {
                                rlutil::locate(30, 25);
                                rlutil::setColor(rlutil::RED);
                                cout << "Codigo postal invalido.Ingrese solo numeros.                       ";
                                rlutil::setColor(rlutil::COLOR::YELLOW);
                                rlutil::locate(30, 26);
                                cout << "Presione una tecla para continuar...";
                                rlutil::setColor(rlutil::WHITE);
                                rlutil::anykey();
                                rlutil::locate(60, 21);
                                cout << "                                                                           ";
                                rlutil::locate(30, 25);
                                cout << "                                                                           ";
                                rlutil::locate(30, 26);
                                cout << "                                                                           ";
                            }
                    } while (!val.esNumeroValido(aux));
                    domicilio.setCodigoPostal(aux);
                    paciente.setDomicilio(domicilio);

                    //Carnet
                    do {
                        rlutil::setColor(rlutil::COLOR::CYAN);
                        rlutil::locate(30, 22);
                        cout << "Nuevo numero de carnet: ";
                        rlutil::setColor(rlutil::COLOR::WHITE);
                        rlutil::locate(60, 22);
                        cin >> carnet;

                        if (cin.fail() || !val.esEnteroPositivo(carnet)) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            rlutil::locate(30, 25);
                            rlutil::setColor(rlutil::COLOR::RED);
                            cout << "Numero de Carnet invalido.                        ";
                            rlutil::setColor(rlutil::COLOR::YELLOW);
                            rlutil::locate(30, 26);
                            cout << "Presione una tecla para continuar...";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::anykey();
                            rlutil::locate(60, 22);
                            cout << "                                                                           ";
                            rlutil::locate(30, 25);
                            cout << "                                                                           ";
                            rlutil::locate(30, 26);
                            cout << "                                                                           ";
                        }
                    } while (cin.fail() || !val.esEnteroPositivo(carnet));
                    cin.ignore(1000, '\n');
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
            modificado = true;
            } else {
                rlutil::setColor(rlutil::COLOR::YELLOW);
                rlutil::locate(30, 11);
                cout << "Modificacion cancelada por el usuario.                                             ";
                modificado = true;
            }
                }
    }
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::anykey();
    }
    rlutil::cls();
}

void PacienteManager::reactivarPaciente(){
    Validador val;
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

            do{
            rlutil::locate(32, fila + 17);
            rlutil::setColor(rlutil::COLOR::GREEN);
            cout<<"DESEA ACTIVAR EL PACIENTE? (s/n): ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::locate(70, fila + 17);
            cin >> confirmacion;
            if (!val.esConfirmacionSN(confirmacion)) {
                cin.clear();
                cin.ignore(1000, '\n');
                rlutil::locate(32, fila + 18);
                rlutil::setColor(rlutil::COLOR::RED);
                cout << "Opcion invalida. Ingrese solo 's' o 'n'. Presione una tecla para continuar...";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
                rlutil::locate(70, fila + 17);
                cout << "                                                      ";
                rlutil::locate(32, fila + 18);
                cout << "                                                                                       ";
                }

            }while (confirmacion!='s' && confirmacion!='S' && confirmacion!='n' && confirmacion!='N');

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


