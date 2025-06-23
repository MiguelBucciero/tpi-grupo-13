#include "TurnoManager.h"
#include "PacienteArchivo.h"
#include "MedicoArchivo.h"
#include "TurnoArchivo.h"
#include "EspecialidadArchivo.h"
#include "Fecha.h"
#include <iostream>

#include "Turno.h"
#include "Paciente.h"
#include "Medico.h"
#include "Especialidad.h"
#include "rlutil.h"
#include "Validador.h"


using namespace std;

void TurnoManager::cargarTurno() {
    Turno turno;
    PacienteArchivo archiP;
    Medico medico;
    MedicoArchivo archiM;
    EspecialidadArchivo archiE;
    Validador val;
    int idPaciente, idMedico, idEspecialidad, dia, mes, anio, horas, minutos;
    int fila = 2;
    Fecha fecha, fechaActual;
    Hora hora;
    char opcion;
    string inputStr;
    bool entradaValida;

    opcion = 's';
    turno.setIDTurno(_archivo.getNuevoID());

    while (opcion == 's' || opcion == 'S') {
        rlutil::cls();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(40, fila);
        cout << "CARGAR NUEVO TURNO";
        rlutil::setColor(rlutil::WHITE);

        // Validación ID Paciente
        do {
            rlutil::locate(30, fila + 2);
            cout << "ID Paciente: ";
            rlutil::locate(45, fila + 2);
            cout << "                                                                                      ";
            rlutil::locate(55, fila + 2);
            cin >> inputStr;

            entradaValida = val.esNumeroValido(inputStr);
            if (cin.fail() || !entradaValida) {
                cin.clear();
                cin.ignore(1000, '\n');
                rlutil::locate(30, fila + 3);
                rlutil::setColor(rlutil::COLOR::RED);
                cout << "Debe ingresar un numero valido. Presione una tecla.";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
                continue;
            }

            idPaciente = stoi(inputStr);

            if (!archiP.esPacienteActivo(idPaciente)) {
                rlutil::locate(30, fila + 3);
                rlutil::setColor(rlutil::COLOR::RED);
                cout << "ID invalido o paciente dado de baja. Presione una tecla.";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
            }
        } while (!archiP.esPacienteActivo(idPaciente));
        turno.setIDPaciente(idPaciente);

        // Validación Fecha
        bool fechaValida = false;
        do {
            rlutil::locate(30, fila + 3);
            cout << "Fecha del turno - Dia: ";
            rlutil::locate(55, fila + 3);
            cin >> inputStr;
            if (cin.fail() || !val.esNumeroValido(inputStr)) {
                cin.clear();
                cin.ignore(1000, '\n');
                rlutil::locate(30, fila + 4);
                rlutil::setColor(rlutil::COLOR::RED);
                cout << "Dato invalido. Ingrese un numero correcto.";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
                continue;
            }
            dia = stoi(inputStr);

            rlutil::locate(30, fila + 4);
            cout << "Mes: ";
            rlutil::locate(55, fila + 4);
            cin >> inputStr;
            if (cin.fail() || !val.esNumeroValido(inputStr)) {
                cin.clear();
                cin.ignore(1000, '\n');
                rlutil::locate(30, fila + 5);
                rlutil::setColor(rlutil::COLOR::RED);
                cout << "Dato invalido. Ingrese un numero correcto.";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
                continue;
            }
            mes = stoi(inputStr);

            rlutil::locate(30, fila + 5);
            cout << "Anio: ";
            rlutil::locate(55, fila + 5);
            cin >> inputStr;
            if (cin.fail() || !val.esNumeroValido(inputStr)) {
                cin.clear();
                cin.ignore(1000, '\n');
                rlutil::locate(30, fila + 6);
                rlutil::setColor(rlutil::COLOR::RED);
                cout << "Dato invalido. Ingrese un numero correcto.";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
                continue;
            }
            anio = stoi(inputStr);

            fechaActual.obtenerFechaActual();
            if (!val.esFechaValida(dia, mes, anio)) {
                rlutil::locate(30, fila + 6);
                rlutil::setColor(rlutil::COLOR::RED);
                cout << "Fecha invalida. Presione una tecla.";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
            } else if (anio < fechaActual.getAnio() ||
                       (anio == fechaActual.getAnio() && mes < fechaActual.getMes()) ||
                       (anio == fechaActual.getAnio() && mes == fechaActual.getMes() && dia < fechaActual.getDia())) {
                rlutil::locate(30, fila + 6);
                rlutil::setColor(rlutil::COLOR::RED);
                cout << "Fecha pasada. Ingrese una fecha desde hoy en adelante.";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
            } else {
                fechaValida = true;
            }
        } while (!fechaValida);
        fecha.setDia(dia);
        fecha.setMes(mes);
        fecha.setAnio(anio);

        // Validar hora
        val.validarHora(horas, minutos, fila + 6);
        hora.setHora(horas);
        hora.setMinutos(minutos);

        // Validar ID especialidad
        do {
            rlutil::locate(30, fila + 8);
            cout << "ID Especialidad: ";
            rlutil::locate(55, fila + 8);
            cin >> inputStr;

            entradaValida = val.esNumeroValido(inputStr);
            if (cin.fail() || !entradaValida) {
                cin.clear();
                cin.ignore(1000, '\n');
                rlutil::locate(30, fila + 9);
                rlutil::setColor(rlutil::COLOR::RED);
                cout << "Debe ingresar un numero valido. Presione una tecla.";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
                continue;
            }

            idEspecialidad = stoi(inputStr);

            if (!archiE.esEspecialidadValida(idEspecialidad)) {
                rlutil::locate(30, fila + 9);
                rlutil::setColor(rlutil::COLOR::RED);
                cout << "Especialidad invalida. Presione una tecla.";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
            }
        } while (!archiE.esEspecialidadValida(idEspecialidad));

        // Mostrar médicos disponibles
        bool hayMedico = false;
        int cantidad = archiM.getCantidadRegistros();
        for (int i = 0; i < cantidad; i++) {
            medico = archiM.Leer(i);
            if (medico.getIDEspecialidad() == idEspecialidad && medico.getEstado()) {
                if (!_archivo.existeTurno(medico.getIDMedico(), fecha, hora)) {
                    rlutil::locate(30, fila + 10);
                    cout << "Medico disponible: " << medico.getApellido() << ", " << medico.getNombre() << " (ID: " << medico.getIDMedico() << ")";
                    fila++;
                    hayMedico = true;
                    opcion = 'n';
                }
            }
        }

        if (!hayMedico) {
            rlutil::locate(30, fila + 11);
            cout << "No hay medicos disponibles en esa fecha y hora.";
            rlutil::locate(30, fila + 12);
            cout << "Desea intentar otra fecha y hora? (s/n): ";
            cin >> opcion;
            if (cin.fail() || !val.esConfirmacionSN(opcion)) {
                cin.clear();
                cin.ignore(1000, '\n');
                rlutil::locate(30, fila + 13);
                rlutil::setColor(rlutil::COLOR::RED);
                cout << "Opcion invalida. Presione una tecla.";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
                continue;
            }
            if (opcion == 'n' || opcion == 'N') {
                rlutil::locate(30, fila + 14);
                cout << "Cancelando carga de turno.";
                rlutil::anykey();
                rlutil::cls();
                return;
            }
        }
    }

    // Seleccion de médico
    do {
        rlutil::locate(30, fila + 11);
        cout << "ID Medico: ";
        rlutil::locate(45, fila + 11);
        cin >> inputStr;

        entradaValida = val.esNumeroValido(inputStr);
        if (cin.fail() || !entradaValida) {
            cin.clear();
            cin.ignore(1000, '\n');
            rlutil::locate(30, fila + 12);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Debe ingresar un número válido. Presione una tecla.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            continue;
        }

        idMedico = stoi(inputStr);
        int pos = archiM.Buscar(idMedico);
        if (pos != -1) {
            medico = archiM.Leer(pos);
            if (medico.getEstado() && medico.getIDEspecialidad() == idEspecialidad) {
                break;
            } else {
                rlutil::locate(30, fila + 12);
                rlutil::setColor(rlutil::COLOR::RED);
                cout << "ID invalido o no es de esta especialidad. Presione una tecla.";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
            }
        } else {
            rlutil::locate(30, fila + 12);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "ID invalido o no existe. Presione una tecla.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
        }
    } while (true);

    turno.setIDMedico(idMedico);
    turno.setFechaTurno(fecha);
    turno.setHoraTurno(hora);
    turno.setEspecialidad(idEspecialidad);
    turno.setEstado(1); // Activo

    if (_archivo.guardar(turno)) {
        rlutil::locate(45, fila + 15);
        rlutil::setColor(rlutil::COLOR::GREEN);
        cout << "Turno guardado correctamente.";
    } else {
        rlutil::locate(45, fila + 15);
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "Error al guardar el turno.";
        rlutil::setColor(rlutil::COLOR::WHITE);
    }

    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void TurnoManager::mostrarTurno(){
    int cantidad = _archivo.getCantidadRegistros();
    string h, m;

    if (cantidad == 0) {
        rlutil::cls();
        rlutil::locate(40, 10);
        rlutil::setColor(rlutil::RED);
        cout << "No hay turnos cargados." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return;
    }

    Turno* vecTurno = new Turno[cantidad];
    if (!_archivo.leerMuchos(vecTurno, cantidad)) {
        rlutil::cls();
        rlutil::locate(40, 10);
        rlutil::setColor(rlutil::RED);
        cout << "Error al leer los turnos del archivo." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        delete[] vecTurno;
        rlutil::cls();
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        rlutil::cls();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(45, 2);
        cout << " MOSTRANDO TURNO " << (i + 1) << " DE " << cantidad;
        rlutil::setColor(rlutil::WHITE);

        int fila = 4;
        rlutil::locate(30, fila++);
        cout << "------------------------------------------------------------";
        rlutil::locate(30, fila + 7);
        cout << "------------------------------------------------------------";

        rlutil::locate(32, fila++);
        cout << "ID Turno: " << vecTurno[i].getIDTurno();
        rlutil::locate(32, fila++);
        cout << "ID Paciente: " << vecTurno[i].getIDPaciente();
        rlutil::locate(32, fila++);
        cout << "ID Medico: " << vecTurno[i].getIDMedico();

        rlutil::locate(32, fila++);
        cout << "Fecha: " << vecTurno[i].getFechaTurno().getDia()<<"/"<<vecTurno[i].getFechaTurno().getMes()<<"/"<<vecTurno[i].getFechaTurno().getAnio();

        rlutil::locate(32, fila++);
        cout << "Hora: ";
        if (vecTurno[i].getHoraTurno().getHora() < 10) {
            h = "0" + to_string(vecTurno[i].getHoraTurno().getHora());
        } else {
            h = to_string(vecTurno[i].getHoraTurno().getHora());
        }

        if (vecTurno[i].getHoraTurno().getMinutos() < 10) {
            m = "0" + to_string(vecTurno[i].getHoraTurno().getMinutos());
        } else {
            m = to_string(vecTurno[i].getHoraTurno().getMinutos());
        }
        cout<<h + ":" + m + " hs.";

        rlutil::locate(32, fila++);
        cout << "ID Especialidad: " << vecTurno[i].getEspecialidad();

        rlutil::locate(32, fila++);
        cout << "Estado: ";
        switch (vecTurno[i].getEstado()) {
            case 1: cout << "Activo"; break;
            case 2: cout << "Cancelado"; break;
            case 3: cout << "Reprogramado"; break;
            case 4: cout << "No Asistido"; break;
            case 5: cout << "Asistido"; break;
            default: cout << "Desconocido"; break;
        }

        rlutil::locate(30, fila + 2);
        rlutil::setColor(rlutil::YELLOW);
        cout << "Presione una tecla para ver el siguiente turno...";
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
    }

    delete[] vecTurno;

    rlutil::cls();
    rlutil::locate(40, 10);
    rlutil::setColor(rlutil::GREEN);
    cout << "Fin del listado de turnos.";
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    rlutil::cls();

}

void TurnoManager::reprogramarTurno(){
    int idTurno, cantidad, pos;
    int dia, mes, anio;
    int hora, minuto;
    bool encontrado = false;
    char opcion;
    Turno turno;

    cantidad = _archivo.getCantidadRegistros();
    if (cantidad == 0) {
        rlutil::cls();
        rlutil::locate(40, 10);
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "No hay turnos cargados.";
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return;
    }

    while (!encontrado) {
        rlutil::cls();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(40, 2);
        cout << "REPROGRAMAR TURNO";
        rlutil::setColor(rlutil::WHITE);

        rlutil::locate(30, 4);
        cout << "Ingrese el ID del turno a reprogramar (0 para cancelar): ";
        rlutil::locate(87, 4);
        cin >> idTurno;

        if (idTurno == 0) {
            rlutil::locate(30, 6);
            cout << "Reprogramación cancelada.";
            rlutil::anykey();
            rlutil::cls();
            return;
        }

        //buscamos el turno
        for (int i = 0; i < cantidad; i++) {
            turno = _archivo.Leer(i);
            if (turno.getIDTurno() == idTurno && (turno.getEstado() == 1||turno.getEstado()==3)) {
                encontrado = true;
                pos = i;
                break;
            }
        }

        if (!encontrado) {
            rlutil::locate(30, 6);
            rlutil::setColor(rlutil::RED);
            cout << "Turno no encontrado o no activo.";
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
        }
    }

    //nueva fecha y hora, evitando la superposicion
    Fecha fechaNueva;
    Hora horaNueva;

    do {
        rlutil::cls();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(40, 2);
        cout << "INGRESO DE NUEVA FECHA Y HORA";
        rlutil::setColor(rlutil::WHITE);

        rlutil::locate(30, 4);
        cout << "Dia: ";
        rlutil::locate(40, 4);
        cin >> dia;

        rlutil::locate(30, 5);
        cout << "Mes: ";
        rlutil::locate(40, 5);
        cin >> mes;

        rlutil::locate(30, 6);
        cout << "Anio: ";
        rlutil::locate(40, 6);
        cin >> anio;

        fechaNueva.setDia(dia);
        fechaNueva.setMes(mes);
        fechaNueva.setAnio(anio);

        rlutil::locate(30, 8);
        cout << "Hora (0-23): ";
        rlutil::locate(45, 8);
        cin >> hora;

        rlutil::locate(30, 9);
        cout << "Minuto (0-59): ";
        rlutil::locate(45, 9);
        cin >> minuto;

        horaNueva.setHora(hora);
        horaNueva.setMinutos(minuto);

        if (_archivo.existeTurno(turno.getIDMedico(), fechaNueva, horaNueva)) {
            rlutil::locate(30, 12);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Ya existe un turno para el medico en esa fecha y hora.";
            rlutil::setColor(rlutil::COLOR::WHITE);

            rlutil::locate(30, 13);
            cout << "Desea intentar otra fecha y hora? (s/n): ";
            cin >> opcion;
            if (opcion == 'n' || opcion == 'N') {
                rlutil::locate(30, 15);
                cout << "Cancelando reprogramacion...";
                rlutil::anykey();
                rlutil::cls();
                return;
            }
        } else {
            break;
        }
    } while (true);

    turno.setFechaTurno(fechaNueva);
    turno.setHoraTurno(horaNueva);
    turno.setEstado(3); // Reprogramado

    if (_archivo.modificar(turno, pos)) {
        rlutil::locate(30, 15);
        rlutil::setColor(rlutil::COLOR::GREEN);
        cout << "Turno reprogramado correctamente.";
    } else {
        rlutil::locate(30, 15);
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "Error al reprogramar el turno.";
    }

    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void TurnoManager::cancelarTurno(){
    int idTurno, pos;
    char confirmacion;

    while (true) {
        rlutil::cls();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(35, 3);
        cout << "CANCELACION DE TURNO";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(30, 5);
        cout << "Ingrese el ID del turno que desea cancelar: ";
        rlutil::locate(75, 5);
        cin >> idTurno;

        pos = _archivo.Buscar(idTurno);
        if (pos == -1) {
            rlutil::locate(30, 7);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "No hay un turno con ese ID. Intente nuevamente.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::cls();
            continue;
        }

        Turno turno = _archivo.Leer(pos);

        if (turno.getEstado() != 1 && turno.getEstado() != 3) {
            rlutil::locate(30, 7);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "El turno ya fue cancelado o no esta activo/reprogramado.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::cls();
            continue;
        }

        rlutil::locate(30, 7);
        rlutil::setColor(rlutil::COLOR::CYAN);
        cout << "Esta seguro que desea cancelar el turno? (s/n): ";
        rlutil::setColor(rlutil::COLOR::WHITE);
        cin >> confirmacion;

        if (confirmacion == 's' || confirmacion == 'S') {
            turno.setEstado(2);  // Estado 2 = Cancelado

            if (_archivo.modificar(turno, pos)) {
                rlutil::locate(30, 9);
                rlutil::setColor(rlutil::COLOR::GREEN);
                cout << "El turno fue cancelado correctamente";
            } else {
                rlutil::locate(30, 9);
                rlutil::setColor(rlutil::COLOR::RED);
                cout << "Error al cancelar el turno.";
            }
            rlutil::setColor(rlutil::COLOR::WHITE);
            break;
        } else {
            rlutil::locate(30, 9);
            rlutil::setColor(rlutil::COLOR::YELLOW);
            cout << "Cancelacion abortada por el usuario.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            break;
        }
    }

    rlutil::anykey();
    rlutil::cls();
}

void TurnoManager::TurnoNoAsistido(){
    int cantidad = _archivo.getCantidadRegistros();
    bool algunTurnoProcesado = false;
    int fila;
    string h, m;

    if (cantidad == 0) {
        rlutil::cls();
        rlutil::setColor(rlutil::RED);
        rlutil::locate(30, 10);
        cout << "No hay turnos cargados.";
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }

    Turno* lista = new Turno[cantidad];
    if (!_archivo.leerMuchos(lista, cantidad)) {
        rlutil::cls();
        rlutil::setColor(rlutil::RED);
        rlutil::locate(30, 10);
        cout << "No se pudieron leer los turnos.";
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        delete[] lista;
        return;
    }

    Fecha hoy;
    hoy.obtenerFechaActual();
    fila = 4;

    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(35, 2);
    cout << "REGISTRO DE ASISTENCIA A TURNOS";
    rlutil::setColor(rlutil::WHITE);

    for (int i = 0; i < cantidad; i++) {
        Fecha fechaTurno = lista[i].getFechaTurno();

        // Solo considerar turnos anteriores a hoy con estado Activo (1) o Reprogramado (3)
        if ((lista[i].getEstado() == 1 || lista[i].getEstado() == 3) &&
            fechaTurno.esAnterior(hoy)) {

            rlutil::locate(28, fila++);
            cout << "------------------------------------------------------------";
            rlutil::locate(30, fila++);
            cout << "ID Turno: " << lista[i].getIDTurno();
            rlutil::locate(30, fila++);
            cout << "ID Paciente: " << lista[i].getIDPaciente();
            rlutil::locate(30, fila++);
            cout << "ID Medico: " << lista[i].getIDMedico();
            rlutil::locate(30, fila++);
            cout << "Fecha: " << lista[i].getFechaTurno().getDia()<<"/"<<lista[i].getFechaTurno().getMes()<<"/"<<lista[i].getFechaTurno().getAnio();
            rlutil::locate(30, fila++);
            cout << "Hora: ";
            if (lista[i].getHoraTurno().getHora() < 10) {
                h = "0" + to_string(lista[i].getHoraTurno().getHora());
            } else {
                h = to_string(lista[i].getHoraTurno().getHora());
            }

            if (lista[i].getHoraTurno().getMinutos() < 10) {
                m = "0" + to_string(lista[i].getHoraTurno().getMinutos());
            } else {
                m = to_string(lista[i].getHoraTurno().getMinutos());
            }
            cout<<h + ":" + m + " hs.";

            rlutil::locate(30, fila++);
            cout << "Especialidad: " << lista[i].getEspecialidad();
            rlutil::locate(30, fila++);
            cout << "Estado: " << (lista[i].getEstado() == 1 ? "Activo" : "Reprogramado");
            rlutil::locate(30, fila++);
            cout << "El paciente asistio al turno? (s/n): ";
            char opcion;
            cin >> opcion;

            int pos = _archivo.Buscar(lista[i].getIDTurno());
            if (pos != -1) {
                if (opcion == 's' || opcion == 'S') {
                    lista[i].setEstado(5); // Asistido
                    if (_archivo.modificar(lista[i], pos)) {
                        rlutil::locate(30, fila++);
                        rlutil::setColor(rlutil::GREEN);
                        cout << "Turno marcado como 'Asistido' correctamente.";
                    } else {
                        rlutil::locate(30, fila++);
                        rlutil::setColor(rlutil::RED);
                        cout << "Error al modificar el turno.";
                    }
                } else if (opcion == 'n' || opcion == 'N') {
                    lista[i].setEstado(4); // No asistido
                    if (_archivo.modificar(lista[i], pos)) {
                        rlutil::locate(30, fila++);
                        rlutil::setColor(rlutil::GREEN);
                        cout << "Turno marcado como 'No Asistido' correctamente.";
                    } else {
                        rlutil::locate(30, fila++);
                        rlutil::setColor(rlutil::RED);
                        cout << "Error al modificar el turno.";
                    }
                } else {
                    rlutil::locate(30, fila++);
                    rlutil::setColor(rlutil::YELLOW);
                    cout << "Opcion invalida. No se modifico el turno.";
                }
            } else {
                rlutil::locate(30, fila++);
                rlutil::setColor(rlutil::RED);
                cout << "No se encontro el turno en el archivo.";
            }

            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(30, fila++);
            cout << "Presione una tecla para continuar...";
            rlutil::anykey();

            rlutil::cls();
            fila = 4;
            rlutil::setColor(rlutil::YELLOW);
            rlutil::locate(35, 2);
            cout << "REGISTRO DE ASISTENCIA A TURNOS";
            rlutil::setColor(rlutil::WHITE);

            algunTurnoProcesado = true;
        }
    }

    if (!algunTurnoProcesado) {
        rlutil::cls();
        rlutil::locate(30, 10);
        rlutil::setColor(rlutil::YELLOW);
        cout << "No hay turnos anteriores a la fecha actual que esten activos o reprogramados.";
        rlutil::setColor(rlutil::WHITE);
    }

    delete[] lista;

    rlutil::locate(30, 12);
    rlutil::setColor(rlutil::GREEN);
    cout << "Presione una tecla para finalizar...";
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void TurnoManager::BuscarTurnoEstado(){
    int estado, cantidad, encontrados, fila, index;
    string h, m;

    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(30, 3);
    cout << "BUSQUEDA DE TURNOS POR ESTADO";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(30, 5);
    cout << "Indique el estado de turnos que desea buscar:";
    rlutil::locate(30, 6);
    cout << "1. Activo - 2. Cancelado - 3. Reprogramado - 4. No Asistido - 5. Asistido";
    rlutil::locate(30, 7);
    cout << "Estado: ";
    cin >> estado;

    cantidad = _archivo.getCantidadRegistros();
    Turno* turnos = new Turno[cantidad];
    encontrados = 0;

    for (int i = 0; i < cantidad; i++) {
        Turno t = _archivo.Leer(i);
        if (t.getEstado() == estado) {
            turnos[encontrados] = t;
            encontrados++;
        }
    }

    rlutil::cls();
    if (encontrados == 0) {
        rlutil::setColor(rlutil::RED);
        rlutil::locate(30, 10);
        cout << "No se encontraron turnos con ese estado.";
        rlutil::setColor(rlutil::WHITE);
    } else {
        index = 0;
        while (index < encontrados) {
            rlutil::cls();
            rlutil::setColor(rlutil::CYAN);
            rlutil::locate(30, 2);
            cout << "MOSTRANDO TURNOS (" << index + 1;

            if (index + 1 < encontrados) {
                cout << " a " << index + 2;
            }

            cout << " de " << encontrados << ")";
            rlutil::setColor(rlutil::WHITE);

            fila = 4;
            for (int i = 0; i < 2; i++) {
                if ((index + i) >= encontrados) {
                    break;
                }

                Turno t = turnos[index + i];
                rlutil::locate(28, fila++);
                cout << "------------------------------------------------------------";
                rlutil::locate(30, fila++);
                cout << "ID Turno: " << t.getIDTurno();
                rlutil::locate(30, fila++);
                cout << "ID Paciente: " << t.getIDPaciente();
                rlutil::locate(30, fila++);
                cout << "ID Medico: " << t.getIDMedico();
                rlutil::locate(30, fila++);
                cout << "Fecha: " << t.getFechaTurno().getDia()<<"/"<<t.getFechaTurno().getMes()<<"/"<<t.getFechaTurno().getAnio();
                rlutil::locate(30, fila++);
                cout << "Hora: ";
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

                rlutil::locate(30, fila++);
                cout << "ID Especialidad: " << t.getEspecialidad();
                rlutil::locate(30, fila++);
                cout << "Estado: ";
                switch (t.getEstado()) {
                    case 1: cout << "Activo"; break;
                    case 2: cout << "Cancelado"; break;
                    case 3: cout << "Reprogramado"; break;
                    case 4: cout << "No Asistido"; break;
                    case 5: cout << "Asistido"; break;
                    default: cout << "Desconocido"; break;
                }
                fila += 2;
            }

            rlutil::setColor(rlutil::GREEN);
            rlutil::locate(30, fila++);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
            index += 2;
        }
    }

    delete[] turnos;
    rlutil::cls();
}

void TurnoManager::TurnosDelDia(){
    int cantidad, mostrados, fila;
    string h, m;
    MedicoArchivo medioActivo;

    cantidad = _archivo.getCantidadRegistros();
    Turno* lista = new Turno[cantidad];

    if (_archivo.leerMuchos(lista, cantidad)) {
        Fecha hoy;
        hoy.obtenerFechaActual();

        rlutil::cls();
        rlutil::setColor(rlutil::CYAN);
        rlutil::locate(50, 2);
        cout << " LISTADO DE TURNOS DEL DIA ";
        rlutil::locate(50, 3);
        cout << "       Fecha: " << hoy.getDia()<<"/"<<hoy.getMes()<<"/"<<hoy.getAnio() << "        ";
        rlutil::setColor(rlutil::WHITE);

        mostrados = 0;
        fila = 5;

        for (int i = 0; i < cantidad; i++) {
            if (lista[i].getFechaTurno().esIgual(hoy) && (lista[i].getEstado() == 1||lista[i].getEstado()==3)&&medioActivo.esMedicoActivo(lista[i].getIDMedico())) { //si el medico esta activo, se ven los turnos 1 y 3
                if (mostrados > 0 && mostrados % 2 == 0) { // cada 2 turnos, pausa
                    rlutil::locate(45, fila);
                    rlutil::setColor(rlutil::GREEN);
                    cout << "Presione una tecla para continuar...";
                    rlutil::setColor(rlutil::WHITE);
                    rlutil::anykey();
                    rlutil::cls();
                    fila = 5;
                    rlutil::setColor(rlutil::CYAN);
                    rlutil::locate(50, 2);
                    cout << " LISTADO DE TURNOS DEL DIA";
                    rlutil::locate(50, 3);
                    cout << "       Fecha: " << hoy.getDia()<<"/"<<hoy.getMes()<<"/"<<hoy.getAnio() << "        ";
                    rlutil::setColor(rlutil::WHITE);
                }

                rlutil::locate(45, fila++);
                cout << "-------------------------------";
                rlutil::locate(45, fila++);
                cout << "ID Turno: " << lista[i].getIDTurno();
                rlutil::locate(45, fila++);
                cout << "ID Paciente: " << lista[i].getIDPaciente();
                rlutil::locate(45, fila++);
                cout << "ID Medico: " << lista[i].getIDMedico();
                rlutil::locate(45, fila++);
                cout << "Fecha: " << lista[i].getFechaTurno().getDia()<<"/"<<lista[i].getFechaTurno().getMes()<<"/"<<lista[i].getFechaTurno().getAnio();
                rlutil::locate(45, fila++);
                cout << "Hora: ";
                if (lista[i].getHoraTurno().getHora() < 10) {
                    h = "0" + to_string(lista[i].getHoraTurno().getHora());
                } else {
                    h = to_string(lista[i].getHoraTurno().getHora());
                }

                if (lista[i].getHoraTurno().getMinutos() < 10) {
                    m = "0" + to_string(lista[i].getHoraTurno().getMinutos());
                } else {
                    m = to_string(lista[i].getHoraTurno().getMinutos());
                }
                cout<<h + ":" + m + " hs.";
                rlutil::locate(45, fila++);
                cout << "ID Especialidad: " << lista[i].getEspecialidad();
                rlutil::locate(45, fila++);
                cout << "Estado: Activo";
                fila++;

                mostrados++;
            }
        }
        if (mostrados == 0) {
            rlutil::locate(45, fila);
            rlutil::setColor(rlutil::YELLOW);
            cout << "No hay turnos activos para el dia de hoy.";
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(45, fila+2);
            rlutil::setColor(rlutil::GREEN);
            cout << "Presione una tecla para salir...";
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
        } else {
            rlutil::locate(45, fila);
            rlutil::setColor(rlutil::GREEN);
            cout << "Fin de la lista. Presione una tecla para salir...";
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
        }
    } else {
        rlutil::cls();
        rlutil::setColor(rlutil::RED);
        rlutil::locate(45, 10);
        cout << "No se pudieron leer los turnos";
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
    }
    delete[] lista;
    rlutil::cls();
}

void TurnoManager::TurnosDeLaSemana() {
    int cantidad, mostrados, fila;
    string h, m;
    MedicoArchivo medioActivo;

    cantidad = _archivo.getCantidadRegistros();
    if (cantidad == 0) {
        rlutil::cls();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(45, 10);
        cout << "No hay turnos cargados.";
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return;
    }

    Turno* lista = new Turno[cantidad];
    if (!_archivo.leerMuchos(lista, cantidad)) {
        rlutil::cls();
        rlutil::setColor(rlutil::RED);
        rlutil::locate(45, 10);
        cout << "No se pudieron leer los turnos.";
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        rlutil::cls();
        delete[] lista;
        return;
    }

    Fecha inicioSemana;
    inicioSemana.obtenerInicioDeSemana();

    rlutil::cls();
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(50, 2);
    cout << " LISTADO DE TURNOS DE LA SEMANA ";
    rlutil::locate(55, 3);
    cout << "Semana desde: " << inicioSemana.getDia()<<"/"<<inicioSemana.getMes()<<"/"<<inicioSemana.getAnio();
    rlutil::setColor(rlutil::WHITE);

    mostrados = 0;
    fila = 5;

    for (int i = 0; i < cantidad; i++) {
        Fecha f = lista[i].getFechaTurno();

        if ((lista[i].getEstado() == 1||lista[i].getEstado()==3) &&
            medioActivo.esMedicoActivo(lista[i].getIDMedico())&& //si el medico esta activo, se ven los turnos 1 y 3
            f.getAnio() == inicioSemana.getAnio() &&
            f.getMes() == inicioSemana.getMes() &&
            f.getDia() >= inicioSemana.getDia() &&
            f.getDia() <= inicioSemana.getDia() + 6) {

            if (mostrados > 0 && mostrados % 2 == 0) {
                rlutil::locate(45, fila);
                rlutil::setColor(rlutil::GREEN);
                cout << "Presione una tecla para continuar...";
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
                rlutil::cls();
                fila = 5;
                rlutil::setColor(rlutil::CYAN);
                rlutil::locate(50, 2);
                cout << " LISTADO DE TURNOS DE LA SEMANA ";
                rlutil::locate(55, 3);
                cout << "Semana desde: " << inicioSemana.getDia()<<"/"<<inicioSemana.getMes()<<"/"<<inicioSemana.getAnio();
                rlutil::setColor(rlutil::WHITE);
            }

            rlutil::locate(45, fila++);
            cout << "-------------------------------";
            rlutil::locate(45, fila++);
            cout << "ID Turno: " << lista[i].getIDTurno();
            rlutil::locate(45, fila++);
            cout << "ID Paciente: " << lista[i].getIDPaciente();
            rlutil::locate(45, fila++);
            cout << "ID Medico: " << lista[i].getIDMedico();
            rlutil::locate(45, fila++);
            cout << "Fecha: " << lista[i].getFechaTurno().getDia()<<"/"<<lista[i].getFechaTurno().getMes()<<"/"<<lista[i].getFechaTurno().getAnio();
            rlutil::locate(45, fila++);
            cout << "Hora: ";
            if (lista[i].getHoraTurno().getHora() < 10) {
                    h = "0" + to_string(lista[i].getHoraTurno().getHora());
                } else {
                    h = to_string(lista[i].getHoraTurno().getHora());
                }

                if (lista[i].getHoraTurno().getMinutos() < 10) {
                    m = "0" + to_string(lista[i].getHoraTurno().getMinutos());
                } else {
                    m = to_string(lista[i].getHoraTurno().getMinutos());
                }
            cout<<h + ":" + m + " hs.";

            rlutil::locate(45, fila++);
            cout << "ID Especialidad: " << lista[i].getEspecialidad();
            rlutil::locate(45, fila++);
            cout << "Estado: Activo";
            fila++;

            mostrados++;
        }
    }

    if (mostrados == 0) {
        rlutil::locate(45, fila);
        rlutil::setColor(rlutil::YELLOW);
        cout << "No hay turnos activos para esta semana.";
    } else {
        rlutil::locate(45, fila);
        rlutil::setColor(rlutil::GREEN);
        cout << "Fin de la lista. Presione una tecla para salir...";
    }

    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    delete[] lista;
    rlutil::cls();
}

void TurnoManager::CantidadTurnosPorEspecialidad(){
    EspecialidadArchivo archiEsp;
    int cantidadEsp, cantidadTurno, mostrados, fila;

    cantidadEsp = archiEsp.getCantidadRegistros();
    Especialidad* especialidades = new Especialidad[cantidadEsp];

    archiEsp.leerMuchos(especialidades, cantidadEsp);

    int* cont = new int[cantidadEsp];
    for (int i = 0; i < cantidadEsp; i++) {
        cont[i] = 0;
    }

    cantidadTurno = _archivo.getCantidadRegistros();
    Turno* turno = new Turno[cantidadTurno];
    _archivo.leerMuchos(turno, cantidadTurno);

    MedicoArchivo medicoActivo;

    for (int i = 0; i < cantidadTurno; i++) {
        if ((turno[i].getEstado() == 1 || turno[i].getEstado() == 3)&&medicoActivo.esMedicoActivo(turno[i].getIDMedico())) { //1=activo || 3=reprogramado pero tambien seria un activo; medico activo
            int idEspTurno = turno[i].getEspecialidad();
            for (int j = 0; j < cantidadEsp; j++) {
                if (especialidades[j].getIDEspecialidad() == idEspTurno) {
                    cont[j]++;
                    break;
                }
            }
        }
    }

    rlutil::cls();
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(50, 2);
    cout << "CANTIDAD DE TURNOS POR ESPECIALIDAD";
    rlutil::setColor(rlutil::WHITE);

    mostrados = 0;
    fila = 4;

    for (int i = 0; i < cantidadEsp; i++) {
        if (mostrados > 0 && mostrados % 10 == 0) {
            rlutil::locate(45, fila + 1);
            rlutil::setColor(rlutil::GREEN);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
            rlutil::cls();
            rlutil::setColor(rlutil::CYAN);
            rlutil::locate(50, 2);
            cout << "CANTIDAD DE TURNOS POR ESPECIALIDAD";
            rlutil::setColor(rlutil::WHITE);
            fila = 4;
        }

        rlutil::locate(45, fila++);
        cout << especialidades[i].getNombre() << ": " << cont[i] << " turnos";
        mostrados++;
    }

    rlutil::locate(45, fila + 2);
    rlutil::setColor(rlutil::GREEN);
    cout << "Presione una tecla para salir...";
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();

    delete[] turno;
    delete[] especialidades;
    delete[] cont;

    rlutil::cls();
}

void TurnoManager::CantidadTurnosNoAsistidos(){
    MedicoArchivo archiM;
    int cantidadM=archiM.getCantidadRegistros();
    Medico *medico=new Medico[cantidadM];
    archiM.leerMuchos(medico, cantidadM);

    int *cont=new int[cantidadM];
    for(int i=0; i<cantidadM; i++){
        cont[i]=0;
    }

    int cantidadTurno=_archivo.getCantidadRegistros();
    Turno *turno=new Turno[cantidadTurno];
    _archivo.leerMuchos(turno, cantidadTurno);

    for(int i=0; i<cantidadTurno; i++){
        if(turno[i].getEstado()==4){ //4=no asistido
            for(int j=0; j<cantidadM; j++){
               if(medico[j].getIDMedico()==turno[i].getIDMedico()){
                cont[j]++;
                break;
               }
            }
        }
    }
    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(40, 2);
    cout << "CANTIDAD DE TURNOS NO ASISTIDOS POR MEDICO";
    rlutil::setColor(rlutil::WHITE);

    int fila=4;
    for(int i=0; i<cantidadM; i++){
        rlutil::locate(40, fila++);
        cout<<"- "<< medico[i].getApellido()<<", "<<medico[i].getNombre()<<" (ID: "<<medico[i].getIDMedico()<<") -> "<<cont[i]<<" turno(s) no asistido(s)";

    if(fila>=45){
    rlutil::locate(40, fila);
    rlutil::setColor(rlutil::YELLOW);
    cout << "Presione una tecla para continuar...";
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    rlutil::cls();
    rlutil::locate(40, 2);
    rlutil::setColor(rlutil::YELLOW);
    cout << "CANTIDAD DE TURNOS NO ASISTIDOS POR MEDICO";
    rlutil::setColor(rlutil::WHITE);
    fila = 4;
    }
    }

    rlutil::locate(40, fila + 2);
    rlutil::setColor(rlutil::COLOR::GREEN);
    cout << "Fin del resumen. Presione una tecla para salir...";
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();

    delete[] medico;
    delete[] turno;
    delete[] cont;

    rlutil::cls();
}

void TurnoManager::HistorialTurnosAtendidos(int idMedico) {
    int cantidad = _archivo.getCantidadRegistros();
    if (cantidad == 0) {
        rlutil::cls();
        rlutil::locate(40, 10);
        rlutil::setColor(rlutil::RED);
        cout << "No hay turnos cargados.";
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }

    Turno* turnos = new Turno[cantidad];
    _archivo.leerMuchos(turnos, cantidad);

    string h, m;

    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(40, 2);
    cout << "HISTORIAL DE TURNOS ATENDIDOS";
    rlutil::setColor(rlutil::WHITE);

    int encontrados = 0, fila=4;
    for (int i = 0; i < cantidad; i++) {
        if (turnos[i].getIDMedico() == idMedico && turnos[i].getEstado() == 5) {
            rlutil::locate(30, fila++);
            cout << "--------------------------------------------" << endl;
            rlutil::locate(32, fila++);
            cout << "ID Turno: " << turnos[i].getIDTurno();
            rlutil::locate(32, fila++);
            cout << "ID Paciente: " << turnos[i].getIDPaciente();
            rlutil::locate(32, fila++);
            cout << "ID Medico: " << turnos[i].getIDMedico();

            rlutil::locate(32, fila++);
            cout << "Fecha: " << turnos[i].getFechaTurno().getDia()<<"/"<<turnos[i].getFechaTurno().getMes()<<"/"<<turnos[i].getFechaTurno().getAnio();

            rlutil::locate(32, fila++);
            cout << "Hora: ";
            if (turnos[i].getHoraTurno().getHora() < 10) {
                h = "0" + to_string(turnos[i].getHoraTurno().getHora());
            } else {
                h = to_string(turnos[i].getHoraTurno().getHora());
            }

            if (turnos[i].getHoraTurno().getMinutos() < 10) {
                m = "0" + to_string(turnos[i].getHoraTurno().getMinutos());
            } else {
                m = to_string(turnos[i].getHoraTurno().getMinutos());
            }
            cout<<h + ":" + m + " hs.";

            rlutil::locate(32, fila++);
            cout << "ID Especialidad: " << turnos[i].getEspecialidad();

            rlutil::locate(32, fila++);
            cout << "Estado: "<<"Asistido";

            encontrados++;

            if(fila>=20){
                rlutil::locate(40, fila + 2);
                rlutil::setColor(rlutil::YELLOW);
                cout << "Presione una tecla para continuar...";
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
                rlutil::cls();
                rlutil::locate(40, 2);
                rlutil::setColor(rlutil::YELLOW);
                cout << "HISTORIAL DE TURNOS ATENDIDOS";
                rlutil::setColor(rlutil::WHITE);
                fila = 4;
            }
        }
    }

    if (encontrados == 0) {
        rlutil::cls();
        rlutil::locate(30, 6);
        rlutil::setColor(rlutil::RED);
        cout << "No se encontraron turnos asistidos para este medico." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        delete[] turnos;
        rlutil::cls();
        return;
    }

    rlutil::locate(30, fila + 2);
    rlutil::setColor(rlutil::COLOR::GREEN);
    cout << "Fin del historial. Presione una tecla para salir...";
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();

    delete[] turnos;

    rlutil::cls();
}

void TurnoManager::CantidadTurnosReprogramadosMes(){
    int cantidad=_archivo.getCantidadRegistros();
    int vecMes[12]={}; //numeros meses
    const char* vecMeses[12]={"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO",
     "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"}; //nombres meses
     int anio=2025, fila=4;

    Turno turno;
    for(int i=0; i<cantidad; i++){
        turno=_archivo.Leer(i);
        if(turno.getEstado()==3){
            Fecha fecha=turno.getFechaTurno();
            if(fecha.getAnio()==anio){ //tambien hay turnos de otros anios.
                if(fecha.getMes()>=1&&fecha.getMes()<=12){
                vecMes[fecha.getMes()-1]++;
            }
            }
        }
    }
    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(40, 2);
    cout << "CANTIDAD DE TURNOS REPROGRAMADOS POR MES";
    rlutil::setColor(rlutil::WHITE);

    for(int i=0; i<12; i++){
        rlutil::locate(35, fila++);
        cout<<vecMeses[i]<<": "<<vecMes[i]<<endl;
    }
    rlutil::locate(35, fila + 1);
    rlutil::setColor(rlutil::COLOR::GREEN);
    cout << "Fin del resumen. Presione una tecla para salir...";
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void TurnoManager::CantidadTurnosPorEspecialidadAdmin(int anio){
    EspecialidadArchivo archiEsp;
    int cantidadEsp=archiEsp.getCantidadRegistros();
    Especialidad *especialidades=new Especialidad[cantidadEsp];
    archiEsp.leerMuchos(especialidades, cantidadEsp);

    int* cont=new int[cantidadEsp];
    for(int i=0; i<cantidadEsp; i++){
        cont[i]=0;
    }

    int cantidadTurno=_archivo.getCantidadRegistros();
    Turno turno;

    for(int i=0; i<cantidadTurno; i++){
        turno=_archivo.Leer(i);
        Fecha fecha=turno.getFechaTurno();
        if(turno.getEstado()==1||turno.getEstado()==3||turno.getEstado()==5){
            if(fecha.getAnio()==anio){
                int idEspTurno=turno.getEspecialidad();
                for(int j=0; j<cantidadEsp; j++){
                    if(especialidades[j].getIDEspecialidad()==idEspTurno){
                        if(especialidades[j].getEstado()){
                            cont[j]++;
                            break;
                        }
                    }
                }
            }
        }
    }
    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(40, 2);
    cout << "CANTIDAD DE TURNOS TOTALES POR ESPECIALIDAD, EN EL ANIO";
    rlutil::setColor(rlutil::WHITE);

    int fila=4;
    for(int i=0; i<cantidadEsp; i++){
        if(especialidades[i].getEstado()){
            rlutil::locate(35, fila++);
            cout<<especialidades[i].getNombre()<<": "<<cont[i]<<" turnos"<<endl;
        }
    }

    rlutil::locate(35, fila + 1);
    rlutil::setColor(rlutil::COLOR::GREEN);
    cout << "Fin del resumen. Presione una tecla para salir...";
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();

    delete[] especialidades;
    delete[] cont;

    rlutil::cls();
}

void TurnoManager::buscarTurnosPorFecha(int idMedico) {
    int dia, mes, anio;
    string h, m;

    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(35, 3);
    cout << "TURNOS POR FECHA";
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(30, 5);
    cout << "Ingrese la fecha para buscar turnos:"<<endl;
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(30, 6);
    cout << "Dia: ";
    rlutil::locate(35, 6);
    cin >> dia;
    rlutil::locate(30, 7);
    cout << "Mes: ";
    rlutil::locate(35, 7);
    cin >> mes;
    rlutil::locate(30, 8);
    cout << "Anio: ";
    rlutil::locate(35, 8);
    cin >> anio;

    Fecha fechaBuscada(dia, mes, anio);

    PacienteArchivo archivoPacientes("pacientes.dat");
    EspecialidadArchivo archivoEspecialidades("especialidad.dat");

    int cantidad = _archivo.getCantidadRegistros();
    bool hayTurnos = false;
    int fila=11;

    for (int i = 0; i < cantidad; i++) {
        Turno t = _archivo.Leer(i);
        if (t.getIDMedico()==idMedico&&t.getFechaTurno().esIgual(fechaBuscada) &&(t.getEstado() == 1||t.getEstado()==3)) {
            hayTurnos = true;

            Paciente p = archivoPacientes.Leer(archivoPacientes.Buscar(t.getIDPaciente()));
            Especialidad e = archivoEspecialidades.Leer(archivoEspecialidades.Buscar(t.getEspecialidad()));
            rlutil::locate(30, fila++);
            cout << "------------------------------";
            rlutil::locate(30, fila++);
            cout << "ID Turno: " << t.getIDTurno();
            rlutil::locate(30, fila++);
            cout << "Hora: ";
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

            rlutil::locate(30, fila++);
            cout << "Paciente: " << p.getNombre() << " " << p.getApellido();
            rlutil::locate(30, fila++);
            cout << "Especialidad: " << e.getNombre();

            if(fila>=45){
                rlutil::locate(40, fila);
                rlutil::setColor(rlutil::YELLOW);
                cout << "Presione una tecla para continuar...";
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
                rlutil::cls();
                rlutil::locate(30, 3);
                rlutil::setColor(rlutil::YELLOW);
                cout << "TURNOS POR FECHA";
                rlutil::setColor(rlutil::WHITE);
                fila = 5;
            }
        }
    }

    if (!hayTurnos) {
        rlutil::locate(35, fila++);
        rlutil::setColor(rlutil::RED);
        cout << "No se encontraron turnos en esa fecha.";
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        rlutil::cls();
        return;
    }

    rlutil::locate(35, fila + 2);
    rlutil::setColor(rlutil::COLOR::GREEN);
    cout << "Fin de la lista. Presione una tecla para salir...";
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void TurnoManager::cantidadTurnosPorMedico() {
    MedicoArchivo archiM;
    int cantidadM, cantidadT = 0, fila = 0, idMedicoTurno = 0;

    cantidadM = archiM.getCantidadRegistros();
    if (cantidadM == 0) {
        rlutil::cls();
        rlutil::locate(40, 10);
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "No hay medicos cargados.";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
        return;
    }

    Medico* listaMedicos = new Medico[cantidadM];
    archiM.leerMuchos(listaMedicos, cantidadM);

    int* contador = new int[cantidadM]();
    cantidadT = _archivo.getCantidadRegistros();
    Turno* listaTurnos = new Turno[cantidadT];
    _archivo.leerMuchos(listaTurnos, cantidadT);

    for (int i = 0; i < cantidadT; i++) {
        if (listaTurnos[i].getEstado() == 1 || listaTurnos[i].getEstado() == 3) {
            idMedicoTurno = listaTurnos[i].getIDMedico();
            for (int j = 0; j < cantidadM; j++) {
                if (listaMedicos[j].getIDMedico() == idMedicoTurno) {
                    if(listaMedicos[j].getEstado()){
                        contador[j]++;
                        break;
                    }
                }
            }
        }
    }

    rlutil::cls();
    rlutil::locate(40, 2);
    rlutil::setColor(rlutil::COLOR::YELLOW);
    cout << "CANTIDAD DE TURNOS POR MEDICO";
    rlutil::setColor(rlutil::COLOR::WHITE);

    fila = 4;
    for (int i = 0; i < cantidadM; i++) {
        if (listaMedicos[i].getEstado()) {
            rlutil::locate(30, fila++);
            cout << "----------------------------------------------";
            rlutil::locate(32, fila++);
            cout << "Nombre: " << listaMedicos[i].getNombre() << " " << listaMedicos[i].getApellido();
            rlutil::locate(32, fila++);
            cout << "ID Medico: " << listaMedicos[i].getIDMedico();
            rlutil::locate(32, fila++);
            cout << "Cantidad de turnos: " << contador[i];
            fila++;

            if (fila > 22 && i < cantidadM - 1) {
                rlutil::locate(40, fila);
                rlutil::setColor(rlutil::COLOR::YELLOW);
                cout << "Presione una tecla para continuar...";
                rlutil::setColor(rlutil::COLOR::WHITE);
                rlutil::anykey();
                rlutil::cls();
                rlutil::locate(40, 2);
                rlutil::setColor(rlutil::COLOR::YELLOW);
                cout << "CANTIDAD DE TURNOS POR MEDICO";
                rlutil::setColor(rlutil::COLOR::WHITE);
                fila = 4;
            }
        }
    }

    delete[] listaMedicos;
    delete[] listaTurnos;
    delete[] contador;

    rlutil::locate(40, fila);
    rlutil::setColor(rlutil::COLOR::YELLOW);
    cout << "Fin del listado. Presione una tecla para salir.";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void TurnoManager::cantidadTurnosPorPaciente() {
    PacienteArchivo archiP;
    int cantidadP, cantidadT, idPaciente, fila;

    cantidadP = archiP.getCantidadRegistros();
    if (cantidadP == 0) {
        rlutil::cls();
        rlutil::setColor(rlutil::RED);
        rlutil::locate(40, 10);
        cout << "No hay pacientes cargados." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }

    Paciente* pacientes = new Paciente[cantidadP];
    archiP.leerMuchos(pacientes, cantidadP);

    int* contadores = new int[cantidadP];
    for (int i = 0; i < cantidadP; i++) {
        contadores[i] = 0;
    }

    cantidadT = _archivo.getCantidadRegistros();
    Turno* turnos = new Turno[cantidadT];
    _archivo.leerMuchos(turnos, cantidadT);

    for (int i = 0; i < cantidadT; i++) {
        idPaciente = turnos[i].getIDPaciente();
        for (int j = 0; j < cantidadP; j++) {
            if (pacientes[j].getIDPaciente() == idPaciente && pacientes[j].getEstado()) {
                contadores[j]++;
                break;
            }
        }
    }

    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(40, 2);
    cout << "CANTIDAD DE TURNOS POR PACIENTE";
    rlutil::setColor(rlutil::WHITE);

    fila = 4;
    for (int i = 0; i < cantidadP; i++) {
        if (pacientes[i].getEstado()) {
            rlutil::locate(30, fila++);
            cout << "- " << pacientes[i].getApellido() << ", " << pacientes[i].getNombre()
                 << " (ID: " << pacientes[i].getIDPaciente() << ") -> "
                 << contadores[i] << " turno(s)";
        }

        if (fila >= 45) {
            rlutil::locate(40, fila);
            rlutil::setColor(rlutil::YELLOW);
            cout << "Presione una tecla para continuar...";
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
            rlutil::cls();
            rlutil::locate(40, 2);
            cout << "CANTIDAD DE TURNOS POR PACIENTE";
            fila = 4;
        }
    }

    delete[] pacientes;
    delete[] turnos;
    delete[] contadores;

    rlutil::locate(40, fila + 2);
    rlutil::setColor(rlutil::COLOR::YELLOW);
    cout << "Fin del listado. Presione una tecla para continuar...";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void TurnoManager::cantidadTurnosCanceladosPorMes() {
    const int MESES = 12;
    int* contadores = new int[MESES];
    int cantidad, fila, mes;
    const char* meses[MESES] = {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };

    for (int i = 0; i < MESES; i++) {
        contadores[i] = 0;
    }

    cantidad = _archivo.getCantidadRegistros();
    if (cantidad == 0) {
        rlutil::cls();
        rlutil::locate(40, 10);
        rlutil::setColor(rlutil::RED);
        cout << "No hay turnos cargados.";
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }

    Turno* turnos = new Turno[cantidad];
    _archivo.leerMuchos(turnos, cantidad);

    for (int i = 0; i < cantidad; i++) {
        if (turnos[i].getEstado() == 2) {  // Cancelado
            mes = turnos[i].getFechaTurno().getMes();  // De 1 a 12
            if (mes >= 1 && mes <= 12) {
                contadores[mes - 1]++;
            }
        }
    }

    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(40, 2);
    cout << "TURNOS CANCELADOS POR MES";
    rlutil::setColor(rlutil::WHITE);

    fila = 4;
    for (int i = 0; i < MESES; i++) {
        rlutil::locate(35, fila++);
        cout << meses[i] << ": " << contadores[i] << " turno(s) cancelado(s)";
    }

    delete[] contadores;
    delete[] turnos;

    rlutil::locate(35, fila + 1);
    rlutil::setColor(rlutil::COLOR::YELLOW);
    cout << "Fin del resumen. Presione una tecla para continuar...";
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

