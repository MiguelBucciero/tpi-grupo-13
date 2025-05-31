#include "TurnoManager.h"
#include "PacienteArchivo.h"
#include "MedicoArchivo.h"
#include "Medico.h"
#include "TurnoArchivo.h"
#include "EspecialidadArchivo.h"
#include "Fecha.h"
#include <iostream>
#include <ctime>

using namespace std;


Fecha obtenerFechaActual() {
    int dia, mes, anio;
    time_t fechaActual = time(0);
    tm* fecha = localtime(&fechaActual);

    dia = fecha->tm_mday;
    mes = fecha->tm_mon + 1;
    anio = fecha->tm_year + 1900;

    return Fecha(dia, mes, anio);
}
Fecha obtenerInicioDeSemana() {
    time_t fechaActual = time(0);
    tm* fecha = localtime(&fechaActual);

    // Restar días hasta llegar al lunes
    fecha->tm_mday -= (fecha->tm_wday - 1);

     // Si es domingo (wday = 0), se suma 1
    if (fecha->tm_wday == 0) {
        fecha->tm_mday += 1;
    }

     // Normaliza y actualiza fecha
    mktime(fecha);

    return Fecha(fecha->tm_mday, fecha->tm_mon + 1, fecha->tm_year + 1900);
}


void TurnoManager::cargarTurno(){
    TurnoArchivo archiT("Turnos.dat");
    Turno turno;
    PacienteArchivo archiP;
    MedicoArchivo archiM;
    EspecialidadArchivo archiE;
    int idPaciente, idMedico, idEspecialidad;
    Fecha fecha;
    Hora hora;

    turno.setIDTurno(archiT.getNuevoID());
    //validacion de paciente
    do{
        cout<<"Ingrese el ID del paciente: ";
        cin>> idPaciente;
        if(!archiP.esPacienteActivo(idPaciente)){
            cout<<"ID invalido o dado de baja. Intentar de nuevo"<<endl;
        }
    }while(!archiP.esPacienteActivo(idPaciente));
    turno.setIDPaciente(idPaciente);

    //hay que validad al medico
    do{
        cout<<"Ingrese el ID del medico: ";
        cin>> idMedico;
        if(!archiM.esMedicoActivo(idMedico)){
            cout<<"ID invalido o dado de baja. Intentar de neuvo"<<endl;
        }
    }while(!archiM.esMedicoActivo(idMedico));
    turno.setIDMedico(idMedico);

    //validacion del turno para las superposiciones
    char opcion;
    do{
        cout<<"Ingrese la fecha del turno: ";
        fecha.cargarFecha();
        cout<<"Ingrese la hora del turno: ";
        hora.cargarHora();
        if(archiT.existeTurno(idMedico, fecha, hora)){
            cout<<"El medico ya tiene un turno registrado a esa fecha y hora. Intente otro horario (s/n): ";
            cin>>opcion;
            if(opcion=='n'||opcion=='N'){
                cout<<"Cancelando cargar de turno"<<endl;
                return;
            }
        } else{
            break; //no hay superposiciones, se sigue
        }
    }while(true);
    turno.setFechaTurno(fecha);
    turno.setHoraTurno(hora);

    //validacion de especialidad
    do{
        cout<<"Ingrese el ID de especialidad: ";
        cin>> idEspecialidad;
        if(!archiE.esEspecialidadValida(idEspecialidad)){
            cout<<"ID invalido o dado de baja. Intentar de nuevo"<<endl;
        }
    }while(!archiE.esEspecialidadValida(idEspecialidad));
    turno.setEspecialidad(idEspecialidad);

    cout<<"Estado del turno: Activo "<<endl;
    turno.setEstado(1);

    if(archiT.guardar(turno)){
        cout<<"Turno guardado correctamente"<<endl;
    } else{
        cout<<"Error al guardar turno"<<endl;
    }
    system ("pause");
    system("cls");
}

void TurnoManager::mostrarTurno(){
    int cantidad=_archivo.getCantidadRegistros();
    if(cantidad==0){
        cout<<"No hay turnos cargados"<<endl;
        return;
    }

    Turno *vecTurno;
    vecTurno=new Turno[cantidad];

    if(!_archivo.leerMuchos(vecTurno, cantidad)){
        cout<<"Error al leer los turnos del archivo"<<endl;
        delete[] vecTurno;
        return;
    }
    cout<<"-------LISTADO DE TURNOS("<<cantidad<<")-------"<<endl;
    for(int i=0; i<cantidad; i++){
        cout<<"----------------------------------"<<endl;
        cout<<"----------------------------------"<<endl;
       vecTurno[i].mostrarTurno();
    }
    delete[] vecTurno;
    system ("pause");
    system("cls");

}

void TurnoManager::reprogramarTurno(){
    int idTurno;
    cout<<"Ingrese el ID del turno al que desea modificar la consulta: ";
    cin>> idTurno;

    int cantidad=_archivo.getCantidadRegistros();
    Turno turno;
    bool encontrado=false;
    int pos;

    //buscamos el turno
    for(int i=0; i<cantidad; i++){
        turno=_archivo.Leer(i);
        if(turno.getIDTurno()==idTurno&&turno.getEstado()==1){
            encontrado=true;
            pos=i;
            break;
        }
    }
    if(!encontrado){
        cout<<"Turno no encontrado o no activo"<<endl;
        system ("pause");
        system("cls");
        return;
    }

    //nueva fecha y hora, evitando la superposicion
    Fecha fechaNueva;
    Hora horaNueva;
    char opcion;
    do{
        cout<<"Ingrese nueva fecha: ";
        fechaNueva.cargarFecha();
        cout<<"Ingrese nueva hora: ";
        horaNueva.cargarHora();
        if(_archivo.existeTurno(turno.getIDMedico(), fechaNueva, horaNueva)){
            cout<<"El medico ya tiene un turno registrado a esa fecha y hora. Intente otro horario (s/n): ";
            cin>>opcion;
            if(opcion=='n'||opcion=='N'){
                cout<<"Cancelando cargar de turno"<<endl;
                return;
            }
        } else{
            break; //no hay superposiciones, se sigue
        }
    }while(true);

    turno.setFechaTurno(fechaNueva);
    turno.setHoraTurno(horaNueva);
    turno.setEstado(3);

    if(_archivo.modificar(turno, pos)){
        cout<<"Turno reprogramado correctamente"<<endl;
    } else{
        cout<<"Error al reprogramar el turno"<<endl;
    }
    system ("pause");
    system("cls");
}

void TurnoManager::cancelarTurno(){
    int idTurno;
    cout<<"Ingrese el ID del turno que desea cancelar: ";
    cin>> idTurno;

    int pos=_archivo.Buscar(idTurno);
    if(pos==-1){
        cout<<"No hay un turno con ese ID"<<endl;
        return;
    }

    Turno turno;
    turno=_archivo.Leer(pos);

    if(turno.getEstado()!=1&&turno.getEstado()!=3){
        cout<<"Turno ya cancelado"<<endl;
        system ("pause");
        system("cls");
        return;
    }
    turno.setEstado(2);
    if(_archivo.modificar(turno, pos)){
        cout<<"El turno fue cancelado correctamente"<<endl;
    } else{
        cout<<"Error al cancelar el turno"<<endl;
    }
    system ("pause");
    system("cls");
}

void TurnoManager::TurnoNoAsistido(){
    int idTurno;
    cout<<"Ingrese el ID del turno: ";
    cin>> idTurno;

    int pos=_archivo.Buscar(idTurno);
    if(pos==-1){
        cout<<"No hay un turno con ese ID"<<endl;
        return;
    }

    Turno turno;
    turno=_archivo.Leer(pos);
    if(turno.getEstado()!=1&&turno.getEstado()!=3){
        cout<<"No se puede marcar como turno no asistido"<<endl;
        system ("pause");
        system("cls");
        return;
    }
    turno.setEstado(4);
    if(_archivo.modificar(turno, pos)){
        cout<<"El turno marcado como 'no asistido' correctamente"<<endl;
    } else{
        cout<<"Error al guardar el cambio"<<endl;
    }
    system ("pause");
    system("cls");
}

void TurnoManager::BuscarTurnoEstado(){
    int estado;
    cout<<"Indique el estado de turnos que desee buscar (1.Activo - 2.Cancelado - 3.Reprogramado - 4.No Asistido): ";
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
        Fecha hoy = obtenerFechaActual();
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
    fechaActual = obtenerInicioDeSemana();

    cout << "\n------- LISTADO DE TURNOS DE LA SEMANA -------" << endl;
    cout << "----------------- " << fechaActual.toString() << " ------------------" << endl;

    for (int i = 0; i < cantidad; i++) {
        Fecha f = lista[i].getFechaTurno();
        if (lista[i].getEstado() == 1 &&
            f.getAnio() == fechaActual.getAnio() &&
            f.getMes() == fechaActual.getMes() &&
            f.getDia() >= fechaActual.getDia() &&
            f.getDia() <= fechaActual.getDia() + 6) {
            cout << "----------------------------------" << endl;
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
    cout<<"Cantidad de turnos no asistidos por medico"<<endl;
    for(int i=0; i<cantidadM; i++){
        cout<<medico[i].getNombre()<<": "<<cont[i]<<endl;
    }

    delete[] medico;
    delete[] turno;
    delete[] cont;
    system ("pause");
    system("cls");
}
