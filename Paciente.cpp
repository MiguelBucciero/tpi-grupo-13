#include<iostream>
#include "Paciente.h"

using namespace std;

Paciente::Paciente(){
    _IDPaciente=0;
    _carnet=0;
    _estado=true;
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
