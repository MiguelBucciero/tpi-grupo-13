#include <iostream>
#include <cstring>
#include "Usuario.h"


using namespace std;

//Constructores

Usuario::Usuario()
{
    _idUsuario=0;
    strcpy(_nombreUsuario, "");
    strcpy(_contrasenia, "");
    _tipoRol= Rol();
    _estado=true;
}

Usuario::Usuario(int id, const char* nombre, const char* contrasenia, Rol tipoRol, bool estado)
{
    setIDUsuario(id);
    setNombreUsuario(nombre);
    setContrasenia(contrasenia);
    setTipoRol(tipoRol);
    setEstado(estado);
}

//Getters

int Usuario::getIDUsuario(){
return _idUsuario;
}

char* Usuario::getNombreUsuario(){
return _nombreUsuario;
}

char* Usuario::getContrasenia(){
return _contrasenia;
}

Rol Usuario::getRol(){
return _tipoRol;
}

bool Usuario::getEstado(){
return _estado;
}


