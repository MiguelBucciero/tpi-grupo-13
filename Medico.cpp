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

int Medico::getIDMedico(){
    return _IDMedico;
}

int Medico::getMatricula(){
    return _matricula;
}

int Medico::getIDEspecialidad(){
    return _IDEspecialidad;
}

bool Medico::getEstado(){
    return _estado;
}


// Setters
void Medico::setIDMedico(int IDMedico) {
    _IDMedico = IDMedico;
}

void Medico::setMatricula(int matricula) {
    _matricula = matricula;
}

void Medico::setIDEspecialidad(int IDEspecialidad) {
    _IDEspecialidad = IDEspecialidad;
}

void Medico::setEstado(bool estado) {
    _estado = estado;
}
