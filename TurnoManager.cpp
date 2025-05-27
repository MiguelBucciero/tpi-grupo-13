#include "TurnoManager.h"
#include "PacienteArchivo.h"
#include "TurnoArchivo.h"
#include "EspecialidadArchivo.h"
#include <iostream>

using namespace std;

void TurnoManager::cargarTurno(){
    TurnoArchivo archiT("Turnos.dat");
    Turno turno;
    PacienteArchivo archiP;
    EspecialidadArchivo archiE;
    int idPaciente, idMedico, idEspecialidad, estado;
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
    cout<<"Ingrese el ID del medico: ";
    cin>> idMedico;
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

    cout<<"Estado del turno (1=activo, 2=cancelado, 3=reprogramado, 4=no asistido): ";
    cin>>estado;
    while(estado<1||estado>4){
        cout<<"Estado invalido. Ingrese un valor entre 1 y 4"<<endl;
        cin>>estado;
    }
    turno.setEstado(estado);

    if(archiT.guardar(turno)){
        cout<<"Turno guardado correctamente"<<endl;
    } else{
        cout<<"Error al guardar turno"<<endl;
    }
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
    cout << "-------LISTADO DE TURNOS("<<cantidad<<")-------" << endl;
    for(int i=0; i<cantidad; i++){
        cout << "----------------------------------" << endl;
        cout << "----------------------------------" << endl;
       vecTurno[i].mostrarTurno();
    }
    delete[] vecTurno;

}

void TurnoManager::reprogramarTurno(){
    int idTurno;
    cout<<"Ingrese el ID del paciente al que desea modificar la consulta: ";
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
}
void TurnoManager::cancelarTurno(){
    int idTurno;
    cout<<"Ingrese el ID del paciente al que desea modificar la consulta: ";
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
}
