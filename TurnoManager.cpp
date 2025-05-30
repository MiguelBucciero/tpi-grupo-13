#include "TurnoManager.h"
#include "PacienteArchivo.h"
#include "MedicoArchivo.h"
#include "TurnoArchivo.h"
#include "EspecialidadArchivo.h"
#include "Fecha.h"
#include <iostream>

using namespace std;

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
    if(turno.getEstado()==2){
        cout<<"Turno ya cancelado"<<endl;
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

    cout<<"Fecha de hoy: "<<endl;
    if(_archivo.leerMuchos(lista, cantidad)){
        Fecha hoy;
        hoy.cargarFecha();
        cout<<endl;
        cout<<"-------LISTADO DE TURNOS DEL DIA-------"<<endl;
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
    cout << "Ingrese la fecha (inicio de la semana): ";
    fechaActual.cargarFecha();

    cout << "\n------- LISTADO DE TURNOS DE LA SEMANA -------" << endl;

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

