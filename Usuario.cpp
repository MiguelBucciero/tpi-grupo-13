#include <iostream>
#include <cstring>
#include "Usuario.h"


using namespace std;

//Constructores

Usuario::Usuario(){
    strcpy(_nombreUsuario, "");
    strcpy(_contrasenia, "");
    _tipoRol= Rol();
    _estado=true;
    _IDMedico=0;
}

Usuario::Usuario(string nombre, string contrasenia, Rol tipoRol, bool estado, int IDMedico=-1)
{
    setNombreUsuario(nombre);
    setContrasenia(contrasenia);
    setTipoRol(tipoRol);
    setEstado(estado);
    setIDMedico(IDMedico);
}

//Getters

const string Usuario::getNombreUsuario() const {
    return _nombreUsuario;
}

const string Usuario::getContrasenia() const {
    return _contrasenia;
}

Rol Usuario::getRol(){
    return _tipoRol;
}

bool Usuario::getEstado(){
    return _estado;
}

int Usuario::getIDMedico(){
    return _IDMedico;
}

//Setters
void Usuario::setNombreUsuario (const string &nombre){
    //asi que arreglo no se rompe.
    strncpy(_nombreUsuario, nombre.c_str(), 49);
    _nombreUsuario[49]='\0';
}

void Usuario::setContrasenia (const string &contrasenia){
     //asi que arreglo no se rompe
    strncpy(_contrasenia, contrasenia.c_str(), 49);
    _contrasenia[49]='\0';
}

void Usuario::setTipoRol (Rol valor){
    _tipoRol=valor;
}

void Usuario::setEstado (bool valor){
    _estado=valor;
}

void Usuario::setIDMedico(int valor){
    _IDMedico=valor;
}
