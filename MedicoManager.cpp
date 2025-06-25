#include <iostream>
#include <string>
#include "MedicoManager.h"
#include "rlutil.h"
#include "TurnoArchivo.h"
#include "Turno.h"
#include "PacienteArchivo.h"
#include "Paciente.h"
#include "MedicoArchivo.h"
#include "Medico.h"
#include "Validador.h"

using namespace std;

bool MedicoManager::esMedicoActivo(int id) {
    int cantidad = _archivo.getCantidadRegistros();
    for (int i = 0; i < cantidad; i++) {
        Medico m = _archivo.Leer(i);
        if (m.getIDMedico() == id && m.getEstado()) {
            return true;
        }
    }
    return false;
}

int MedicoManager::cargarMedico() {
    Medico medico;
    Domicilio domicilio;
    Fecha fechaNacimiento;
    Validador val;
    string aux;
    int dni, matricula, id, idEspecialidad, altura, dia, mes, anio;

    rlutil::cls();
    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::locate(40, 2);
    cout << "INGRESO DE NUEVO MEDICO";
    rlutil::setColor(rlutil::COLOR::WHITE);

    // Limpiar buffer antes de usar getline
    cin.ignore(1000, '\n');

    // Apellido
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
    medico.setApellido(aux);

    // Nombre
    do {
        rlutil::locate(30, 5);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Nombre: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(45, 5);
        getline(cin, aux);

        if (!val.esTextoValido(aux)) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 23);
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
    medico.setNombre(aux);

    // DNI
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
    medico.setDni(dni);

    // Limpiar buffer antes de usar getline
    cin.ignore(1000, '\n');

    // Fecha de nacimiento
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
    medico.setFechaNacimiento(Fecha(dia, mes, anio));

    // Limpiar buffer antes de usar getline
    cin.ignore(1000, '\n');

    // Genero
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
    medico.setGenero(aux);

    // Email
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
            cout << "El email invalido.                        ";
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
    medico.setEmail(aux);

    // Telefono
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
    medico.setTelefono(aux);

    // Domicilio
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
    domicilio.setAltura(altura);

    // Limpiar buffer antes de usar getline
    cin.ignore(1000, '\n');

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
    medico.setDomicilio(domicilio);

    id = _archivo.getNuevoID();
    medico.setIDMedico(id);
    rlutil::locate(30, 20);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "ID asignado: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 20);
    cout << id;

    // Matricula
    do {
        rlutil::locate(30, 21);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Matricula: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(45, 21);
        cin >> matricula;

        if (cin.fail() || !val.esEnteroPositivo(matricula)) {
            cin.clear();
            cin.ignore(1000, '\n');
            rlutil::locate(30, 23);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Matricula invalida.                        ";
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
    } while (cin.fail() || !val.esEnteroPositivo(matricula));
    medico.setMatricula(matricula);

    // ID Especialidad
    do {
        rlutil::locate(30, 22);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "ID de Especialidad: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(52, 22);
        cin >> idEspecialidad;

        if (cin.fail() || !val.esEnteroPositivo(idEspecialidad)) {
            cin.clear();
            cin.ignore(1000, '\n');
            rlutil::locate(30, 23);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "ID invalido.                        ";
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, 24);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(52, 22);
            cout << "                                                                           ";
            rlutil::locate(30, 23);
            cout << "                                                                           ";
            rlutil::locate(30, 24);
            cout << "                                                                           ";
        }
    } while (cin.fail() || !val.esEnteroPositivo(idEspecialidad));
    medico.setIDEspecialidad(idEspecialidad);

    medico.setEstado(true);

    rlutil::locate(30, 24);
    if (_archivo.guardar(medico)) {
        rlutil::setColor(rlutil::COLOR::GREEN);
        cout << "Medico guardado correctamente.                                 ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return id;
    } else {
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "Error al guardar medico.                                       ";
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
        rlutil::cls();
        return;
    }

    Medico* vecMedico = new Medico[cantidad];
    _archivo.leerMuchos(vecMedico, cantidad);

    for (int i = 0; i < cantidad; i++) {
        if (vecMedico[i].getEstado()==true || vecMedico[i].getEstado()==false) {
            rlutil::cls();
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(45, 2);
            cout << " LISTADO DE MEDICOS " << (i + 1) << " DE " << cantidad;
            rlutil::setColor(rlutil::COLOR::WHITE);

            int fila = 4;

            rlutil::locate(30, fila);
            cout << "------------------------------------------------------------";
            rlutil::locate(30, fila + 18);
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
            cout<<vecMedico[i].getFechaNacimiento().getDia()<<"/"<<vecMedico[i].getFechaNacimiento().getMes()<<"/"<<vecMedico[i].getFechaNacimiento().getAnio();

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
            cout << "Domicilio: ";

            rlutil::locate(32, fila + 9);
            cout << "Calle: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getDomicilioCompleto().getCalle();

            rlutil::locate(32, fila + 10);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Altura: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getDomicilioCompleto().getAltura();

            rlutil::locate(32, fila + 11);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Localidad: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getDomicilioCompleto().getLocalidad();

            rlutil::locate(32, fila + 12);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Provincia: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getDomicilioCompleto().getProvincia();

            rlutil::locate(32, fila + 13);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Codifgo Postal: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getDomicilioCompleto().getCodigoPostal();

            rlutil::locate(32, fila + 14);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Matricula: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getMatricula();
            rlutil::locate(32, fila + 15);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "ID Especialidad: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getIDEspecialidad();
            rlutil::locate(32, fila + 16);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "ID Medico: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            cout << vecMedico[i].getIDMedico();

            rlutil::locate(32, fila + 17);
            rlutil::setColor(rlutil::COLOR::CYAN);
            cout << "Estado: ";
            rlutil::setColor(rlutil::COLOR::WHITE);
            if(vecMedico[i].getEstado()){
                cout<<"Activo"<<endl;
            } else{
                cout<<"Inactivo"<<endl;
            }

            rlutil::locate(32, fila + 19);
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
     Validador val;
    int idEspecialidad, fila;
    bool encontrados = false;

    rlutil::cls();
    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::locate(50, 2);
    cout << "BUSCAR MEDICOS POR ESPECIALIDAD";
    rlutil::setColor(rlutil::COLOR::WHITE);

    // Validar entrada de ID
    do {
        rlutil::locate(45, 4);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Ingrese el ID de especialidad que desea buscar: ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(92, 4);
        cin >> idEspecialidad;

        if (cin.fail() || !val.esEnteroPositivo(idEspecialidad)) {
            cin.clear();
            cin.ignore(1000, '\n');
            rlutil::locate(45, 6);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "ID invalido. Ingrese un numero entero positivo.";
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(45, 7);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(92, 4);
            cout << "     ";
            rlutil::locate(45, 6);
            cout << "                                                    ";
            rlutil::locate(45, 7);
            cout << "                                                    ";

        }
    } while (cin.fail() || !val.esEnteroPositivo(idEspecialidad));

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

            // Paginacion si se sale de pantalla
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
    string h, m;

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
            cout << "Fecha: " << t.getFechaTurno().getDia()<<"/"<<t.getFechaTurno().getMes()<<"/"<<t.getFechaTurno().getAnio();
            rlutil::locate(32, fila++);
            cout << "Hora: ";//t.getHoraTurno().toString();
            if (t.getHoraTurno().getHora() < 10) {
                    h = "0" + to_string(t.getHoraTurno().getHora());
                } else {
                    h = to_string(t.getHoraTurno().getHora());
                }

                if (t.getHoraTurno().getMinutos() < 10) {
                    m = "0" + to_string(t.getHoraTurno().getMinutos());
                } else {
                    m = to_string(t.getHoraTurno().getMinutos());
                }
            cout<<h + ":" + m + " hs.";
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
    Validador val;
    int id;
    char confirmacion;
    bool encontrado = false, idValido=false;

    while (!encontrado) {
        rlutil::cls();
        rlutil::setColor(rlutil::COLOR::YELLOW);
        rlutil::locate(40, 3);
        cout << " DAR DE BAJA MEDICO ";
        do{
            rlutil::setColor(rlutil::COLOR::CYAN);
            rlutil::locate(30, 6);
            cout << "Ingrese el ID del medico a dar de baja: ";
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

        int pos = _archivo.Buscar(id);
        Medico posMedico;

        if (pos == -1) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "Medico no encontrado. Presione enter e intente nuevamente.";
            rlutil::anykey();
        }else{
            posMedico = _archivo.Leer(pos);
            if (!posMedico.getEstado()) {
                rlutil::setColor(rlutil::COLOR::RED);
                rlutil::locate(30, 8);
                cout << "El Medico ya esta dado de baja. Presione enter e intente nuevamente.";
                rlutil::anykey();
            }else{
                do{
                    rlutil::setColor(rlutil::COLOR::CYAN);
                    rlutil::locate(30, 9);
                    cout << "Esta seguro que desea dar de baja al medico de ID '" << id << "'? (s/n): ";
                    rlutil::setColor(rlutil::COLOR::WHITE);
                    rlutil::locate(92, 9);
                    cin >> confirmacion;

                    if (cin.fail() || !val.esConfirmacionSN(confirmacion)) {
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
                }while(cin.fail() || !val.esConfirmacionSN(confirmacion));

                if (confirmacion == 's' || confirmacion == 'S') {
                    posMedico.setEstado(false);
                    if (_archivo.guardar(posMedico, pos)) {
                        rlutil::setColor(rlutil::COLOR::GREEN);
                        rlutil::locate(30, 11);
                        cout << "Medico dado de baja correctamente.         ";
                    } else {
                        rlutil::setColor(rlutil::COLOR::RED);
                        rlutil::locate(30, 11);
                        cout << "Error al intentar modificar el archivo.        ";
                    }
                } else {
                    rlutil::setColor(rlutil::COLOR::YELLOW);
                    rlutil::locate(30, 11);
                    cout << "Accion cancelada por el usuario.               ";
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

void MedicoManager::modificarMedico(){
    Validador val;
    string aux;
    int dni, matricula, id, idEspecialidad, altura, dia, mes, anio;
    Fecha fechaNacimiento;
    Domicilio domicilio;
    char confirmacion;
    bool modificado = false, confirmacionValida=false;

    while (!modificado) {
        rlutil::cls();
        rlutil::setColor(rlutil::COLOR::YELLOW);
        rlutil::locate(40, 3);
        cout << " MODIFICAR MEDICO ";
        do{
        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(30, 6);
        cout << "Ingrese el ID del medico a modificar: ";
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

        int pos = _archivo.Buscar(id);
        Medico medico;

        if (pos == -1) {
            rlutil::setColor(rlutil::COLOR::RED);
            rlutil::locate(30, 8);
            cout << "Medico no encontrado. Presione enter e intente nuevamente.";
        } else {
            medico = _archivo.Leer(pos);
            if (!medico.getEstado()) {
                rlutil::setColor(rlutil::COLOR::RED);
                rlutil::locate(30, 8);
                cout << "El medico esta dado de baja, no se puede modificar. Presione enter e intente nuevamente.";
            } else {
                while(!confirmacionValida){
                    rlutil::setColor(rlutil::COLOR::CYAN);
                    rlutil::locate(30, 9);
                    cout << "Esta seguro que desea modificar al medico ID '" << id << "'? (s/n): ";
                    rlutil::setColor(rlutil::COLOR::WHITE);
                    rlutil::locate(93, 9);
                    cin >> confirmacion;

                    if (cin.fail() || !val.esConfirmacionSN(confirmacion)) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        rlutil::locate(30,11);
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
                    }
                }

                if (confirmacion == 's' || confirmacion == 'S') {
                    rlutil::cls();
                    rlutil::setColor(rlutil::COLOR::YELLOW);
                    rlutil::locate(40, 3);
                    cout << " INGRESO DE NUEVOS DATOS ";

                    // Limpiar buffer antes de usar getline
                    cin.ignore(1000, '\n');

                    // Apellido
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
                            cout << "Apellido invalido. Ingrese solo letras.";
                            rlutil::setColor(rlutil::COLOR::YELLOW);
                            rlutil::locate(30, 26);
                            cout << "Presione una tecla para continuar...";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::anykey();
                            rlutil::locate(60, 6);
                            cout << "                                                                           ";//Limpiar el campo
                            rlutil::locate(30, 25);
                            cout << "                                                                           ";
                            rlutil::locate(30, 26);
                            cout << "                                                                           ";
                        }
                    } while (!val.esTextoValido(aux));
                    medico.setApellido(aux);

                    // Nombre
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
                            cout << "Nombre invalido. Ingrese solo letras.";
                            rlutil::setColor(rlutil::COLOR::YELLOW);
                            rlutil::locate(30, 26);
                            cout << "Presione una tecla para continuar...";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::anykey();
                            rlutil::locate(60, 7);
                            cout << "                                                                           ";//Limpiar el campo
                            rlutil::locate(30, 25);
                            cout << "                                                                           ";
                            rlutil::locate(30, 26);
                            cout << "                                                                           ";
                        }
                    } while (!val.esTextoValido(aux));
                    medico.setNombre(aux);

                    // DNI
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
                            cout << "DNI invalido.Ingrese solo numeros.";
                            rlutil::setColor(rlutil::COLOR::YELLOW);
                            rlutil::locate(30, 26);
                            cout << "Presione una tecla para continuar...";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::anykey();
                            rlutil::locate(60, 8);
                            cout << "                                                                           ";//Limpiar el campo
                            rlutil::locate(30, 25);
                            cout << "                                                                           ";
                            rlutil::locate(30, 26);
                            cout << "                                                                           ";
                        }
                    } while (cin.fail() || !val.esEnteroPositivo(dni));
                    medico.setDni(dni);

                    // Fecha nacimiento
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
                            cout << "Fecha invalida.Ingrese de nuevo la fecha...";
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
                            cout << "                                                                           ";//Limpiar el campo
                            rlutil::locate(30, 25);
                            cout << "                                                                           ";
                            rlutil::locate(30, 26);
                            cout << "                                                                           ";
                        }
                    } while (cin.fail() || !val.esFechaValida(dia, mes, anio));
                    medico.setFechaNacimiento(Fecha(dia, mes, anio));

                    // Limpiar buffer antes de usar getline
                    cin.ignore(1000, '\n');
                    // Genero
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
                            cout << "Genero invalido.Ingrese solo letras.";
                            rlutil::setColor(rlutil::COLOR::YELLOW);
                            rlutil::locate(30, 26);
                            cout << "Presione una tecla para continuar...";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::anykey();
                            rlutil::locate(60, 13);
                            cout << "                                                                           ";//Limpiar el campo
                            rlutil::locate(30, 25);
                            cout << "                                                                           ";
                            rlutil::locate(30, 26);
                            cout << "                                                                           ";
                        }
                    } while (!val.esTextoValido(aux));
                    medico.setGenero(aux);

                    // Email
                    do {
                        rlutil::locate(30, 14);
                        rlutil::setColor(rlutil::COLOR::CYAN);
                        cout << "Email: ";
                        rlutil::setColor(rlutil::COLOR::WHITE);
                        rlutil::locate(60, 14);
                        getline(cin, aux);

                        if (!val.esEmailValido(aux)) {
                            rlutil::locate(30, 25);
                            rlutil::setColor(rlutil::COLOR::RED);
                            cout << "El email invalido.";
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
                    medico.setEmail(aux);

                    // Telefono
                    do {
                        rlutil::locate(30, 15);
                        rlutil::setColor(rlutil::COLOR::CYAN);
                        cout << "Telefono: ";
                        rlutil::setColor(rlutil::COLOR::WHITE);
                        rlutil::locate(60, 15);
                        getline(cin, aux);

                        if (!val.esNumeroValido(aux)) {
                            rlutil::locate(30, 25);
                            rlutil::setColor(rlutil::COLOR::RED);
                            cout << "Numero de telefono invalido. Ingrese solo numeros ";
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
                    medico.setTelefono(aux);

                    // Domicilio
                    rlutil::locate(30, 16);
                    rlutil::setColor(rlutil::COLOR::CYAN);
                    cout << "Nuevo Domicilio: ";

                    // Calle
                    do {
                        rlutil::locate(30, 17);
                        rlutil::setColor(rlutil::COLOR::CYAN);
                        cout << "Calle: ";
                        rlutil::locate(60, 17);
                        rlutil::setColor(rlutil::COLOR::WHITE);
                        getline(cin, aux);

                        if (!val.esTextoValido(aux)) {
                            rlutil::locate(30, 25);
                            rlutil::setColor(rlutil::COLOR::RED);
                            cout << "Calle invalida. Ingrese solo letras.";
                            rlutil::setColor(rlutil::COLOR::YELLOW);
                            rlutil::locate(30, 26);
                            cout << "Presione una tecla para continuar...";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::anykey();
                            rlutil::locate(60, 17);
                            cout << "                                                                           ";//Limpiar el campo
                            rlutil::locate(30, 25);
                            cout << "                                                                           ";
                            rlutil::locate(30, 26);
                            cout << "                                                                           ";
                        }
                    } while (!val.esTextoValido(aux));
                    domicilio.setCalle(aux);

                    // Altura
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
                            cout << "                                                                           ";//Limpiar el campo
                            rlutil::locate(30, 25);
                            cout << "                                                                           ";
                            rlutil::locate(30, 26);
                            cout << "                                                                           ";
                        }
                    } while (cin.fail() || !val.esEnteroPositivo(altura));
                    domicilio.setAltura(altura);

                    // Limpiar buffer antes de usar getline
                    cin.ignore(1000, '\n');
                    // Localidad
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
                            cout << "                                                                           ";//Limpiar el campo
                            rlutil::locate(30, 25);
                            cout << "                                                                           ";
                            rlutil::locate(30, 26);
                            cout << "                                                                           ";
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
                            cout << "                                                                           ";//Limpiar el campo
                            rlutil::locate(30, 25);
                            cout << "                                                                           ";
                            rlutil::locate(30, 26);
                            cout << "                                                                           ";
                        }
                    } while (!val.esTextoValido(aux));
                    domicilio.setProvincia(aux);

                    // Codigo Postal
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

                    medico.setDomicilio(domicilio);

                    // Matricula
                    do {
                        rlutil::locate(30, 22);
                        rlutil::setColor(rlutil::COLOR::CYAN);
                        cout << "Nueva Matricula: ";
                        rlutil::setColor(rlutil::COLOR::WHITE);
                        rlutil::locate(60, 22);
                        cin >> matricula;

                        if (cin.fail() || !val.esEnteroPositivo(matricula)) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            rlutil::locate(30, 25);
                            rlutil::setColor(rlutil::COLOR::RED);
                            cout << "Matricula invalida.Ingrese solo numeros.                   ";
                            rlutil::setColor(rlutil::COLOR::YELLOW);
                            rlutil::locate(30, 26);
                            cout << "Presione una tecla para continuar...";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::anykey();
                            rlutil::locate(60, 22);
                            cout << "                                                                           ";//Limpiar el campo
                            rlutil::locate(30, 25);
                            cout << "                                                                           ";
                            rlutil::locate(30, 26);
                            cout << "                                                                           ";
                        }
                    } while (cin.fail() || !val.esEnteroPositivo(matricula));
                    medico.setMatricula(matricula);

                    // ID Especialidad
                    do {
                        rlutil::locate(30, 23);
                        rlutil::setColor(rlutil::COLOR::CYAN);
                        cout << "Nuevo ID de Especialidad: ";
                        rlutil::setColor(rlutil::COLOR::WHITE);
                        rlutil::locate(60, 23);
                        cin >> idEspecialidad;

                        if (cin.fail() || !val.esEnteroPositivo(idEspecialidad)) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            rlutil::locate(30, 25);
                            rlutil::setColor(rlutil::COLOR::RED);
                            cout << "ID invalido. Ingrese solo numeros.                       ";
                            rlutil::setColor(rlutil::COLOR::YELLOW);
                            rlutil::locate(30, 26);
                            cout << "Presione una tecla para continuar...";
                            rlutil::setColor(rlutil::COLOR::WHITE);
                            rlutil::anykey();
                            rlutil::locate(60, 23);
                            cout << "                                                                           ";//Limpiar el campo
                            rlutil::locate(30, 25);
                            cout << "                                                                           ";
                            rlutil::locate(30, 26);
                            cout << "                                                                           ";
                        }
                    } while (cin.fail() || !val.esEnteroPositivo(idEspecialidad));
                    medico.setIDEspecialidad(idEspecialidad);

                    if (_archivo.guardar(medico, pos)) {
                        rlutil::setColor(rlutil::COLOR::GREEN);
                        rlutil::locate(30, 25);
                        cout << "Medico modificado correctamente.                                               ";
                    } else {
                        rlutil::setColor(rlutil::COLOR::RED);
                        rlutil::locate(30, 25);
                        cout << "Error al intentar modificar el medico.                                         ";
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

void MedicoManager::buscarPacientePorDNI(int IDMedico){
    Validador val;
    int dni, idPaciente;
    bool hayPaciente=false;
    string h, m;

    // Validacion de ingreso de DNI
    do {
        rlutil::cls();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(40, 2);
        cout << "BUSCAR PACIENTE POR DNI";
        rlutil::setColor(rlutil::WHITE);

        rlutil::locate(30, 4);
        cout << "Ingrese el DNI del paciente: ";
        rlutil::locate(60, 4);
        cout << "               ";
        rlutil::locate(60, 4);
        cin >> dni;

        if (cin.fail() || !val.esEnteroPositivo(dni)) {
            cin.clear();
            cin.ignore(1000, '\n');
            rlutil::locate(30, 6);
            rlutil::setColor(rlutil::RED);
            cout << "DNI invalido. Ingrese solo numeros positivos.";
            rlutil::setColor(rlutil::YELLOW);
            rlutil::locate(30, 7);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
            rlutil::locate(30, 6);
            cout << "                                                    ";
            rlutil::locate(30, 7);
            cout << "                                                    ";
        }
    } while (cin.fail() || !val.esEnteroPositivo(dni));

    PacienteArchivo archip("Pacientes.dat");
    int cantidadP=archip.getCantidadRegistros();

    for(int i=0; i<cantidadP; i++){
        Paciente paciente=archip.Leer(i);
        if(paciente.getDni()==dni&&paciente.getEstado()){
            idPaciente=paciente.getIDPaciente();
            hayPaciente=true;
            rlutil::locate(30, 6);
            cout << "Paciente encontrado: "<<paciente.getApellido()<<", "<<paciente.getNombre()<<" (ID: "<<paciente.getIDPaciente()<<")";
            break;
        }
    }
    if(!hayPaciente){
        rlutil::locate(30, 6);
        rlutil::setColor(rlutil::RED);
        cout<<"Paciente no encontrado o no activo";
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return;
    }

    TurnoArchivo archiTurno("Turnos.dat");
    bool hayTurnos=false;
    int fila=8;
    int cantidadT=archiTurno.getCantidadRegistros();

    for(int i=0; i<cantidadT; i++){
        Turno turno=archiTurno.Leer(i);
        if(turno.getIDPaciente()==idPaciente&&turno.getIDMedico()==IDMedico){
            rlutil::locate(30, fila++);
            cout<<"Turno "<< turno.getIDTurno();
            rlutil::locate(30, fila++);
            cout<<"Fecha: "<<turno.getFechaTurno().getDia()<<"/"<<turno.getFechaTurno().getMes()<<"/"<<turno.getFechaTurno().getAnio();
            rlutil::locate(30, fila++);
            cout<<"Hora: ";
            if (turno.getHoraTurno().getHora() < 10) {
                h = "0" + to_string(turno.getHoraTurno().getHora());
            }
            else {
                h = to_string(turno.getHoraTurno().getHora());
            }

            if (turno.getHoraTurno().getMinutos() < 10) {
                m = "0" + to_string(turno.getHoraTurno().getMinutos());
            }
            else {
                m = to_string(turno.getHoraTurno().getMinutos());
            }
            cout<<h + ":" + m + " hs.";
            hayTurnos=true;
        }
    }
    if(!hayTurnos){
        rlutil::locate(30, fila++);
        rlutil::setColor(rlutil::RED);
        cout<<"No tiene turnos programados con usted.";
    }
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void MedicoManager::reactivarMedico(){
    MedicoArchivo archivo("Medicos.dat");
    Validador val;
    int cantidad, fila, id, mostrados;

    cantidad = archivo.getCantidadRegistros();
    bool hayInactivos = false;
    mostrados = 0;  // contador de medicos mostrados

    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(40, 2);
    cout << "=== MEDICOS INACTIVOS ===";
    rlutil::setColor(rlutil::WHITE);

    fila = 4;

    for(int i = 0; i < cantidad && mostrados < 4; i++){
        Medico m = archivo.Leer(i);
        if(m.getEstado() == false){
            hayInactivos = true;
            rlutil::locate(30, fila++);
            cout << "ID: " << m.getIDMedico();
            rlutil::locate(30, fila++);
            cout << "Nombre: " << m.getNombre() << " " << m.getApellido();
            rlutil::locate(30, fila++);
            cout << "DNI: " << m.getDni();
            rlutil::locate(30, fila++);
            cout << "------------------------------";
            fila++;
            mostrados++;
        }
    }

    if(!hayInactivos){
        rlutil::locate(30, fila);
        rlutil::setColor(rlutil::RED);
        cout << "No hay medicos inactivos.";
        rlutil::locate(30, fila + 1);
        rlutil::setColor(rlutil::COLOR::YELLOW);
        cout << "Presione una tecla para continuar...";
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return;
    }

    // Solicitar ID con validacion
    do {
        rlutil::locate(30, fila);
        cout << "Ingrese el ID del medico que desea reactivar: ";
        cin >> id;

        if (cin.fail() || !val.esEnteroPositivo(id)) {
            cin.clear();
            cin.ignore(1000, '\n');
            rlutil::locate(30, fila + 4);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "ID invalido. Ingrese un numero entero positivo.";
            rlutil::setColor(rlutil::COLOR::YELLOW);
            rlutil::locate(30, fila + 5);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(30, fila + 4);
            cout << "                                                                  ";
            rlutil::locate(30, fila + 5);
            cout << "                                                                  ";
            rlutil::locate(75, fila);
            cout << "                                                                  ";
        }
    } while (cin.fail() || !val.esEnteroPositivo(id));

    // Buscar el medico por ID
    for(int i = 0; i < cantidad; i++){
        Medico m = archivo.Leer(i);
        if(m.getIDMedico() == id && m.getEstado() == false){
            m.setEstado(true);  // Reactivar
            archivo.guardar(m, i);
            rlutil::locate(30, fila + 1);
            cout << "                                                          ";
            rlutil::locate(30, fila + 2);
            rlutil::setColor(rlutil::GREEN);
            cout << "Medico reactivado correctamente.                   ";
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
            rlutil::cls();
            return;
        }
    }

    rlutil::locate(30, fila + 2);
    rlutil::setColor(rlutil::RED);
    cout << "No se encontro un medico inactivo con ese ID.              ";
    rlutil::locate(30, fila + 3);
    rlutil::setColor(rlutil::COLOR::YELLOW);
    cout << "Presione una tecla para continuar...";
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    rlutil::cls();
}
