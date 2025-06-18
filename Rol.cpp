#include "Rol.h"
#include <cstring>
#include <string>
using namespace std;

Rol::Rol(){
    _tipoRol=-9;
    strcpy(_nombreRol, "");
}

Rol::Rol(int tipo, const char* nombre){
    setTipoRol(tipo);
    setNombreRol(nombre);
}
//Getters

int Rol::getRol() const{
    return _tipoRol;
}
const char* Rol::getNombre() const{
    return _nombreRol;
}
//Setters

void Rol::setTipoRol(int valor){
    _tipoRol=valor;
}
void Rol::setNombreRol(const char* valor){
    strcpy(_nombreRol, valor);
}

