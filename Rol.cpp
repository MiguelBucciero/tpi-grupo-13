#include "Rol.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

Rol::Rol(){
    _tipoRol=-9;
    strcpy(_nombreRol, "");
}

Rol::Rol(int tipo, const char* nombre){
    setTipoRol(tipo);
    setNombreRol(nombre);
}

int Rol::getRol(){
    return _tipoRol;
}
char* Rol::getNombre(){
    return _nombreRol;
}

void Rol::setTipoRol(int valor){
    _tipoRol=valor;
}
void Rol::setNombreRol(const char* valor){
    strcpy(_nombreRol, valor);
}

void Rol::validarRol(){
    if(_tipoRol>999||_tipoRol<-999){
        cout<<"Tipo de rol fuera de rango"<<endl;
    }
}
