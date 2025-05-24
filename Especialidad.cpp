#include <iostream>
#include "Especialidad.h"
#include <cstring>

using namespace std;

Especialidad::Especialidad() {
    _IDEspecialidad = 0;
    strcpy(_nombre, "");
    _estado = true;
}

Especialidad::Especialidad(int IDEspecialidad, std::string nombre, bool estado) {
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
    _IDEspecialidad = id;
}

void Especialidad::setNombre(const string &nombre) {
    if(nombre.size() < 50){
        strcpy(_nombre, nombre.c_str());
    }
}

void Especialidad::setEstado(bool estado) {
    _estado = estado;
}



