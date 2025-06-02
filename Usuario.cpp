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
}

Usuario::Usuario(const char* nombre, const char* contrasenia, Rol tipoRol, bool estado, int IDMedico=-1)
{
    setNombreUsuario(nombre);
    setContrasenia(contrasenia);
    setTipoRol(tipoRol);
    setEstado(estado);
    setIDMedico(IDMedico);
}

//Getters

const char* Usuario::getNombreUsuario(){
return _nombreUsuario;
}

const char* Usuario::getContrasenia(){
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


void Usuario::setNombreUsuario (const char* valor){
    //asi que arreglo no se rompe.
    strncpy(_nombreUsuario, valor, 49);
    _nombreUsuario[49]='\0';
}

void Usuario::setContrasenia (const char* valor){
     //asi que arreglo no se rompe
    strncpy(_contrasenia, valor, 49);
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
