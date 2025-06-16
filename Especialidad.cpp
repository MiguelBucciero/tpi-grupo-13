#include <iostream>
#include "Especialidad.h"
#include <cstring>

using namespace std;

Especialidad::Especialidad() {
    setIDEspecialidad(0);
    setNombre("");
    setEstado(true);
}

Especialidad::Especialidad(int IDEspecialidad, string nombre, bool estado) {
    setIDEspecialidad(IDEspecialidad);
    setNombre(nombre);
    setEstado(estado);
}

// Getters
int Especialidad::getIDEspecialidad() const {
    return _IDEspecialidad;
}

const string Especialidad::getNombre() const {
    return _nombre;
}

bool Especialidad::getEstado() const {
    return _estado;
}

// Setters
void Especialidad::setIDEspecialidad(int id) {
    _IDEspecialidad=id;
}

void Especialidad::setNombre(const string &nombre) {
    if(nombre.size()<sizeof(_nombre)){ //si el nombre el menor al tam, se copia.
        strcpy(_nombre, nombre.c_str());
    }else{
        strncpy(_nombre, nombre.c_str(), sizeof(_nombre)-1); //asegura que no copie de mas.
        _nombre[sizeof(_nombre)-1]='\0';
    }
}

void Especialidad::setEstado(bool estado) {
    _estado=estado;
}


