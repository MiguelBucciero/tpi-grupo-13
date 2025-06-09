#include "TurnoManager.h"
#include "PacienteArchivo.h"
#include "MedicoArchivo.h"
#include "Medico.h"
#include "TurnoArchivo.h"
#include "EspecialidadArchivo.h"
#include "Fecha.h"
#include <iostream>

#include "Turno.h"
#include "Paciente.h"
#include "Especialidad.h"
#include "rlutil.h"


using namespace std;

void TurnoManager::cargarTurno(){
    TurnoArchivo archiT("Turnos.dat");
    Turno turno;
    PacienteArchivo archiP;
    MedicoArchivo archiM;
    EspecialidadArchivo archiE;
    int idPaciente, idMedico, idEspecialidad, dia, mes, anio, horas, minutos;
    Fecha fecha;
    Hora hora;
    char opcion;



    turno.setIDTurno(archiT.getNuevoID());
    //validacion de paciente
    do {
        rlutil::cls();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(40, 2);
        cout << "CARGAR NUEVO TURNO";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(30, 4);
        cout << "ID Paciente: ";
        rlutil::locate(45, 4);
        cin >> idPaciente;
        if (!archiP.esPacienteActivo(idPaciente)) {
            rlutil::locate(30, 5);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "ID invalido o paciente dado de baja.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(30, 5);
            rlutil::cls();
            cout << string(50, ' ');
        }
    } while (!archiP.esPacienteActivo(idPaciente));
    turno.setIDPaciente(idPaciente);

    //hay que validar al medico
    do {
        rlutil::locate(30, 6);
        cout << "ID Medico: ";
        rlutil::locate(45, 6);
        cin >> idMedico;
        if (!archiM.esMedicoActivo(idMedico)) {
            rlutil::locate(30, 7);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "ID invalido o medico dado de baja.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(30, 7);
            cout << string(50, ' ');
        }
    } while (!archiM.esMedicoActivo(idMedico));
    turno.setIDMedico(idMedico);

    //validacion del turno para las superposiciones
    do {
        //validamos la fecha ingresada
        do {
        rlutil::locate(30, 8);
        cout << "Fecha del turno - Dia: ";
        rlutil::locate(55, 8);
        cin >> dia;
        rlutil::locate(30, 9);
        cout << "Mes: ";
        rlutil::locate(55, 9);
        cin >> mes;
        rlutil::locate(30, 10);
        cout << "Anio: ";
        rlutil::locate(55, 10);
        cin >> anio;

        if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 1900 || anio > 2100) {
            rlutil::locate(30, 11);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Fecha invalida. Intente de nuevo.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(30, 11); cout << string(50, ' ');
            rlutil::cls();
        }
        } while (dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 1900 || anio > 2100);

        fecha.setDia(dia);
        fecha.setMes(mes);
        fecha.setAnio(anio);

        //validamos la hora ingresada...
        do {
        rlutil::locate(30, 12);
        cout << "Hora - Horas (0-23): ";
        rlutil::locate(55, 12);
        cin >> horas;
        rlutil::locate(30, 13);
        cout << "Minutos (0-59): ";
        rlutil::locate(55, 13);
        cin >> minutos;

        if (horas < 0 || horas > 23 || minutos < 0 || minutos > 59) {
            rlutil::locate(30, 14);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Hora invalida. Intente de nuevo.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(30, 14);
            cout << string(50, ' ');
            rlutil::cls();
        }
        } while (horas < 0 || horas > 23 || minutos < 0 || minutos > 59);

        hora.setHora(horas);
        hora.setMinutos(minutos);

        if (archiT.existeTurno(idMedico, fecha, hora)) {
            rlutil::locate(30, 13);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Ya existe un turno con esa fecha y hora.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::locate(30, 14);
            cout << "Desea intentar otra fecha y hora? (s/n): ";
            cin >> opcion;
            if (opcion == 'n' || opcion == 'N') {
                rlutil::locate(30, 15);
                cout << "Cancelando carga de turno.";
                rlutil::anykey();
                return;
            }
            rlutil::cls();
        } else {
            break; //no hay superposiciones, se sigue
        }
    } while (true);
    turno.setFechaTurno(fecha);
    turno.setHoraTurno(hora);

    //validacion de especialidad
    do {
        rlutil::locate(30, 16);
        cout << "ID Especialidad: ";
        rlutil::locate(55, 16);
        cin >> idEspecialidad;
        if (!archiE.esEspecialidadValida(idEspecialidad)) {
            rlutil::locate(30, 17);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Especialidad invalida.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::locate(30, 17);
            cout << string(50, ' ');
        }
    } while (!archiE.esEspecialidadValida(idEspecialidad));
    turno.setEspecialidad(idEspecialidad);

    turno.setEstado(1); // Activo

    if (archiT.guardar(turno)) {
        rlutil::locate(30, 18);
        rlutil::setColor(rlutil::COLOR::GREEN);
        cout << "Turno guardado correctamente.";
    } else {
        rlutil::locate(30, 18);
        rlutil::setColor(rlutil::COLOR::RED);
        cout << "Error al guardar el turno.";
    }

    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void TurnoManager::mostrarTurno(){
    int cantidad = _archivo.getCantidadRegistros();

    if (cantidad == 0) {
        rlutil::cls();
        rlutil::locate(40, 10);
        rlutil::setColor(rlutil::RED);
        cout << "No hay turnos cargados." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
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
        rlutil::locate(32, fila++);
        cout << "ID Turno: " << vecTurno[i].getIDTurno();
        rlutil::locate(32, fila++);
        cout << "ID Paciente: " << vecTurno[i].getIDPaciente();
        rlutil::locate(32, fila++);
        cout << "ID Medico: " << vecTurno[i].getIDMedico();

        rlutil::locate(32, fila++);
        cout << "Fecha: " << vecTurno[i].getFechaTurno().toString();

        rlutil::locate(32, fila++);
        cout << "Hora: " << vecTurno[i].getHoraTurno().toString();

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
    int dia, mes, anio, hora, minuto;
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
            if (turno.getIDTurno() == idTurno && turno.getEstado() == 1) {
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

/*void TurnoManager::TurnoNoAsistido(){
    int cantidad = _archivo.getCantidadRegistros();
    bool algunTurnoProcesado = false;

    if (cantidad == 0) {
        cout << "No hay turnos cargados." << endl;
        system("pause");
        system("cls");
        return;
    }

    Turno* lista = new Turno[cantidad];
    if (!_archivo.leerMuchos(lista, cantidad)) {
        cout << "No se pudieron leer los turnos." << endl;
        delete[] lista;
        system("pause");
        system("cls");
        return;
    }

    Fecha hoy;
    hoy.obtenerFechaActual();

    for (int i = 0; i < cantidad; i++) {
        Fecha fechaTurno = lista[i].getFechaTurno();

        // Solo considerar turnos anteriores a hoy con estado Activo (1) o Reprogramado (3)
        if ((lista[i].getEstado() == 1 || lista[i].getEstado() == 3) &&
            fechaTurno.esAnterior(hoy)) {

            cout << "------------------------------------------" << endl;
            lista[i].mostrarTurno();
            cout << "El paciente asistio al turno? (s/n): ";
            char opcion;
            cin >> opcion;

            int pos = _archivo.Buscar(lista[i].getIDTurno());
            if (pos != -1) {
                if (opcion == 's' || opcion == 'S') {
                    lista[i].setEstado(5); // Asistido
                    if (_archivo.modificar(lista[i], pos)) {
                        cout << "Turno marcado como 'Asistido' correctamente." << endl;
                    } else {
                        cout << "Error al modificar el turno." << endl;
                    }
                } else if (opcion == 'n' || opcion == 'N') {
                    lista[i].setEstado(4); // No asistido
                    if (_archivo.modificar(lista[i], pos)) {
                        cout << "Turno marcado como 'No Asistido' correctamente." << endl;
                    } else {
                        cout << "Error al modificar el turno." << endl;
                    }
                } else {
                    cout << "Opcion invalida. No se modifico el turno." << endl;
                }
            } else {
                cout << "No se encontro el turno en el archivo." << endl;
            }

            algunTurnoProcesado = true;
        }
    }

    if (!algunTurnoProcesado) {
        cout << "No hay turnos anteriores a la fecha actual que esten activos o reprogramados." << endl;
    }

    delete[] lista;
    system("pause");
    system("cls");
}

void TurnoManager::BuscarTurnoEstado(){
    int estado;
    cout<<"Indique el estado de turnos que desee buscar (1.Activo - 2.Cancelado - 3.Reprogramado - 4.No Asistido -5.Asistido): ";
    cin>>estado;

    int cantidad=_archivo.getCantidadRegistros();
    Turno* turnos=new Turno[cantidad];
    int encontrados=0;

    for(int i=0; i<cantidad; i++){
        Turno t=_archivo.Leer(i);
        if(t.getEstado()==estado){
            turnos[encontrados]=t;
            encontrados++;
        }
    }
    if(encontrados==0){
        cout<<"No se encontraron turnos con ese estado"<<endl;
    }else{
        cout<<"-------LISTADO DE TURNOS("<<encontrados<<")-------"<<endl;
        for(int i=0; i<encontrados; i++){
            cout<<"----------------------------------"<<endl;
            cout<<"----------------------------------"<<endl;
            turnos[i].mostrarTurno();
        }
    }
    delete[] turnos;
    system ("pause");
    system("cls");
}

void TurnoManager::TurnosDelDia(){
    int cantidad=_archivo.getCantidadRegistros();
    Turno* lista;
    lista=new Turno[cantidad];

    if(_archivo.leerMuchos(lista, cantidad)){
        Fecha hoy;
        hoy.obtenerFechaActual();
        cout<<endl;
        cout<<"-------LISTADO DE TURNOS DEL DIA-------"<<endl;
        cout << "---------------" << hoy.toString() << "---------------" << endl;
        for(int i=0; i<cantidad; i++){
            if(lista[i].getFechaTurno().esIgual(hoy)&&lista[i].getEstado()==1){
                cout<<"---------------------------------------"<<endl;
                lista[i].mostrarTurno();
            }
        }
    }else{
        cout<<"No se pudieron leer los turnos"<<endl;
    }
    delete[] lista;
    system ("pause");
    system("cls");
}

void TurnoManager::TurnosDeLaSemana() {
    int cantidad = _archivo.getCantidadRegistros();
    if (cantidad == 0) {
        cout << "No hay turnos cargados." << endl;
        return;
    }

    Turno* lista = new Turno[cantidad];
    if (!_archivo.leerMuchos(lista, cantidad)) {
        cout << "No se pudieron leer los turnos." << endl;
        delete[] lista;
        return;
    }

    Fecha fechaActual;
    fechaActual.obtenerInicioDeSemana();

    cout << "\n------- LISTADO DE TURNOS DE LA SEMANA -------" << endl;
    cout << "----------------- " << fechaActual.toString() << " ------------------" << endl;

    for (int i = 0; i < cantidad; i++) {
        Fecha f = lista[i].getFechaTurno();
        if (lista[i].getEstado() == 1 &&
            f.getAnio() == fechaActual.getAnio() &&
            f.getMes() == fechaActual.getMes() &&
            f.getDia() >= fechaActual.getDia() &&
            f.getDia() <= fechaActual.getDia() + 6) {
            cout << "----------------------------------------------" << endl;
            lista[i].mostrarTurno();
        }
    }

    delete[] lista;
    system ("pause");
    system("cls");
}

void TurnoManager::CantidadTurnosPorEspecialidad(){
    EspecialidadArchivo archiEsp;
    int cantidadEsp=archiEsp.getCantidadRegistros();
    Especialidad *especialidades=new Especialidad[cantidadEsp];

    archiEsp.leerMuchos(especialidades, cantidadEsp);

    int* cont=new int[cantidadEsp];
    for(int i=0; i<cantidadEsp; i++){
        cont[i]=0;
    }

    int cantidadTurno=_archivo.getCantidadRegistros();
    Turno *turno=new Turno[cantidadTurno];
    _archivo.leerMuchos(turno, cantidadTurno);

    for(int i=0; i<cantidadTurno; i++){
        if(turno[i].getEstado()==1||turno[i].getEstado()==3){ //1=activo || 3=reprogramado pero tambien seria un activo
            int idEspTurno=turno[i].getEspecialidad();
            for(int j=0; j<cantidadEsp; j++){
                if(especialidades[j].getIDEspecialidad()==idEspTurno){
                    cont[j]++;
                    break;
                }
            }
        }
    }
    for(int i=0; i<cantidadEsp; i++){
        cout<<especialidades[i].getNombre()<<": "<<cont[i]<<" turnos"<<endl;
    }
    delete[] turno;
    delete[] especialidades;
    delete[] cont;

    system ("pause");
    system("cls");
}*/

void TurnoManager::CantidadTurnosNoAsistidos(){ //vero -recep
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

    delete[] medico;
    delete[] turno;
    delete[] cont;
    rlutil::locate(40, fila + 2);
    rlutil::setColor(rlutil::COLOR::YELLOW);
    cout << "Fin del resumen. Presione una tecla para continuar...";
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void TurnoManager::HistorialTurnosAtendidos(int idMedico) { //vero (medico)
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

    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(40, 2);
    cout << "HISTORIAL DE TURNOS ATENDIDOS";
    rlutil::setColor(rlutil::WHITE);

    int encontrados = 0, fila=4, pantalla=0;
    for (int i = 0; i < cantidad; i++) {
        if (turnos[i].getIDMedico() == idMedico && turnos[i].getEstado() == 5) {
            rlutil::locate(30, fila++);
            cout << "--------------------------------------------" << endl;
            turnos[i].mostrarTurno(fila);
            fila+=8;
            pantalla++;
            encontrados++;

            if (pantalla == 4) {
                rlutil::locate(30, fila + 1);
                rlutil::setColor(rlutil::YELLOW);
                cout << "Presione una tecla para ver más turnos...";
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
                rlutil::cls();
                rlutil::locate(40, 2);
                rlutil::setColor(rlutil::YELLOW);
                cout << "HISTORIAL DE TURNOS ATENDIDOS";
                rlutil::setColor(rlutil::WHITE);
                fila = 4;
                pantalla = 0;
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

    delete[] turnos;
    rlutil::locate(30, fila + 2);
    rlutil::setColor(rlutil::COLOR::YELLOW);
    cout << "Fin del historial. Presione una tecla para continuar...";
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void TurnoManager::CantidadTurnosReprogramadosMes(){ //vero - (admin)
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
    rlutil::setColor(rlutil::COLOR::YELLOW);
    cout << "Fin del resumen. Presione una tecla para continuar...";
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void TurnoManager::CantidadTurnosPorEspecialidadAdmin(int anio){ //vero - (admin)
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
                        cont[j]++;
                        break;
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
        rlutil::locate(35, fila++);
        cout<<especialidades[i].getNombre()<<": "<<cont[i]<<" turnos"<<endl;
    }
    delete[] especialidades;
    delete[] cont;

    rlutil::locate(35, fila + 1);
    rlutil::setColor(rlutil::COLOR::YELLOW);
    cout << "Fin del resumen. Presione una tecla para continuar...";
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void TurnoManager::buscarTurnosPorFecha() { //vero - en proceso
    rlutil::cls();
    Fecha fechaBuscada;

    cout << "Ingrese la fecha para buscar turnos:" << endl;
    fechaBuscada.cargarFecha();

    TurnoArchivo archivo("Turnos.dat");
    PacienteArchivo archivoPacientes("pacientes.dat");
    EspecialidadArchivo archivoEspecialidades("especialidad.dat");

    int cantidad = archivo.getCantidadRegistros();
    bool hayTurnos = false;

    for (int i = 0; i < cantidad; i++) {
        Turno t = archivo.Leer(i);
        if (t.getFechaTurno().esIgual(fechaBuscada) && t.getEstado() == 1) {
            hayTurnos = true;

            Paciente p = archivoPacientes.Leer(archivoPacientes.Buscar(t.getIDPaciente()));
            Especialidad e = archivoEspecialidades.Leer(archivoEspecialidades.Buscar(t.getEspecialidad()));

            cout << "\n----------------------------" << endl;
            cout << "ID Turno: " << t.getIDTurno() << endl;
            cout << "Hora: " << t.getHoraTurno().toString() << endl;
            cout << "Paciente: " << p.getNombre() << " " << p.getApellido() << endl;
            cout << "Especialidad: " << e.getNombre() << endl;
        }
    }

    if (!hayTurnos) {
        cout << "\nNo se encontraron turnos activos en esa fecha." << endl;
    }

    rlutil::anykey();
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
                    contador[j]++;
                    break;
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
                cout << "CANTIDAD DE TURNOS POR MÉDICO";
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

