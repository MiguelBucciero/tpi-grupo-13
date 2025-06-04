#include<iostream>
#include "Turno.h"

using namespace std;

Turno::Turno(){
    _IDTurno=0;
    _IDPaciente=0;
    _IDMedico=0;
    _FechaTurno=Fecha();
    _HoraTurno=Hora();

    _IDEspecialidad=0;
    _EstadoTurno=0;
}
Turno::Turno(int idTurno, int idPaciente, int idMedico, Fecha fecha, Hora hora, int idEspecialidad, int estado){
    setIDTurno(idTurno);
    setIDPaciente(idPaciente);
    setIDMedico(idMedico);
    setFechaTurno(fecha);
    setHoraTurno(hora);
    setEspecialidad(idEspecialidad);
    setEstado(estado);
}

int Turno::getIDTurno(){
    return _IDTurno;
}
int Turno::getIDPaciente(){
    return _IDPaciente;
}
int Turno::getIDMedico(){
    return _IDMedico;
}
Fecha Turno::getFechaTurno(){
    return _FechaTurno;
}
Hora Turno::getHoraTurno(){
    return _HoraTurno;
}
int Turno::getEspecialidad(){
    return _IDEspecialidad;
}
int Turno::getEstado(){
    return _EstadoTurno;
}

void Turno::setIDTurno(int valor){
    _IDTurno=valor;
}
void Turno::setIDPaciente(int valor){
    _IDPaciente=valor;
}
void Turno::setIDMedico(int valor){
    _IDMedico=valor;
}
void Turno::setFechaTurno(Fecha valor){
    _FechaTurno=valor;
}
void Turno::setHoraTurno(Hora valor){
    _HoraTurno=valor;
}
void Turno::setEspecialidad(int valor){
    _IDEspecialidad=valor;
}
void Turno::setEstado(int valor){
    _EstadoTurno=valor;
}

void Turno::mostrarTurno(){
    cout<<"ID Turno: "<<_IDTurno<<endl;
    cout<<"ID Paciente: "<<_IDPaciente<<endl;
    cout<<"ID Medico: "<<_IDMedico<<endl;
    cout<<"Fecha del turno: ";
    _FechaTurno.mostrarFecha();
    cout<<"Hora del turno: ";
    _HoraTurno.mostrarHora();
    cout<<"ID Especialidad: "<<_IDEspecialidad<<endl;
    cout<<"Estado del turno: ";
    switch(_EstadoTurno){
    case 1: cout<<"Activo"<<endl;
            break;
    case 2: cout<<"Cancelado"<<endl;
            break;
    case 3: cout<<"Reprogramado"<<endl;
            break;
    case 4: cout<<"No asistido"<<endl;
            break;
    case 5: cout<<"Asistido"<<endl;
            break;
    default: cout<<"Desconocido"<<endl;
            break;
    }
    cout<<endl;
}
