#include<iostream>
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


int Paciente::getIDPaciente(){
    return _IDPaciente;
}

int Paciente::getCarnet(){
    return _carnet;
}

bool Paciente::getEstado(){
   return _estado;
}

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

//void Paciente::cargarPaciente(){}
void Paciente::mostrarPaciente(){
    Persona::mostrarDatos();
    cout<<"ID: "<<getIDPaciente()<<endl;
    cout<<"Carnet: "<<getCarnet()<<endl;
    cout<<"Estado: ";
    if(_estado){
        cout<<"Activo"<<endl;
    }else{
        cout<<"Inactivo"<<endl;
    }
}
