#include <iostream>
#include <string>
#include "Medico.h"

using namespace std;

Medico::Medico():Persona(){
    setIDMedico(0);
    setMatricula(0);
    setIDEspecialidad(0);
    setEstado(true);
}

Medico::Medico(string apellido, string nombre, int dni, Fecha fechaNacimiento, string genero,
               string email, string telefono, Domicilio domicilio,
               int idMedico, int matricula, int idEspecialidad, bool estado)
    : Persona(apellido, nombre, dni, fechaNacimiento, genero, email, telefono, domicilio) {
    setIDMedico(idMedico);
    setMatricula(matricula);
    setIDEspecialidad(idEspecialidad);
    setEstado(estado);
}

// Getters

int Medico::getIDMedico() const{
    return _IDMedico;
}

int Medico::getMatricula() const{
    return _matricula;
}

int Medico::getIDEspecialidad() const{
    return _IDEspecialidad;
}

bool Medico::getEstado() const{
    return _estado;
}


// Setters
void Medico::setIDMedico(int IDMedico) {
    if (IDMedico > 0) {
        _IDMedico = IDMedico;
    } else {
        _IDMedico = 0;
    }
}

void Medico::setMatricula(int matricula) {
    if (matricula >= 1 && matricula <= 999999) {
        _matricula = matricula;
    } else {
        _matricula = 0;
    }
}

void Medico::setIDEspecialidad(int IDEspecialidad) {
    if (IDEspecialidad > 0) {
        _IDEspecialidad = IDEspecialidad;
    } else {
        _IDEspecialidad = 0;
    }
}

void Medico::setEstado(bool estado) {
    _estado = estado;
}
