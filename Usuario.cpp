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

Usuario::Usuario(const char* nombre, const char* contrasenia, Rol tipoRol, bool estado)
{

    setNombreUsuario(nombre);
    setContrasenia(contrasenia);
    setTipoRol(tipoRol);
    setEstado(estado);
}

//Getters

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

//Setters


void Usuario::setNombreUsuario (const char* valor){
if (strlen(valor)<sizeof(_nombreUsuario)){
    strcpy(_nombreUsuario, valor);

}
}

void Usuario::setContrasenia (const char* valor){
if (strlen(valor)<sizeof(_contrasenia)){
    strcpy(_contrasenia, valor);

}
}

void Usuario::setTipoRol (Rol valor){
_tipoRol=valor;
}

void Usuario::setEstado (bool valor){
_estado=valor;
}
