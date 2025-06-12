#include<iostream>
#include "Turno.h"
#include "rlutil.h"

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
