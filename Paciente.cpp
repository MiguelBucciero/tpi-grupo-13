#include <string>
#include <cstring>
#include "Paciente.h"

using namespace std;

Paciente::Paciente():Persona(){
    setIDPaciente(0);
    setCarnet(0);
    setEstado(true);
}
Paciente::Paciente(string apellido, string nombre, int dni, Fecha fechaNacimiento, string genero,
                 string email, string telefono, Domicilio domicilio,int id, int carnet, bool estado)
:Persona(apellido, nombre, dni, fechaNacimiento, genero,
                 email, telefono, domicilio){
    setIDPaciente(id);
    setCarnet(carnet);
    setEstado(estado);
                 }

//Getters

int Paciente::getIDPaciente() const{
    return _IDPaciente;
}

int Paciente::getCarnet() const{
    return _carnet;
}

bool Paciente::getEstado() const{
   return _estado;
}

//Setters

void Paciente::setIDPaciente(int id){
    if(id>0){
        _IDPaciente=id;
    }
}

void Paciente::setCarnet(int car){
    if(car>0){
        _carnet=car;
    }
}
void Paciente::setEstado(bool est){
    _estado=est;
}

