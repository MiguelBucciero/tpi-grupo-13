#include <iostream>
#include <cstring>
#include "Persona.h"

using namespace std;

Persona::Persona() {
    strcpy(_apellido, "");
    strcpy(_nombre, "");
    _dni = 0;
    _fechaNacimiento = Fecha();
    strcpy(_genero, "");
    strcpy(_email, "");
    strcpy(_telefono, "");
    _domicilio = Domicilio();
}


Persona::Persona(string apellido, string nombre, int dni, Fecha fechaNacimiento, string genero,
                 string email, string telefono, Domicilio domicilio) {
    setApellido(apellido);
    setNombre(nombre);
    setDni(dni);
    setFechaNacimiento(fechaNacimiento);
    setGenero(genero);
    setEmail(email);
    setTelefono(telefono);
    setDomicilio(domicilio);
}

// Getters
const string Persona::getApellido() {
    return _apellido;
}

const string Persona::getNombre() {
    return _nombre;
}

int Persona::getDni() {
    return _dni;
}

Fecha Persona::getFechaNacimiento() {
    return _fechaNacimiento;
}

const string Persona::getGenero() {
    return _genero;
}

const string Persona::getEmail() {
    return _email;
}

const string Persona::getTelefono() {
    return _telefono;
}

Domicilio Persona::getDomicilioCompleto() {
    return _domicilio;
}

// Setters
void Persona::setApellido(const string &apellido) {
    if (apellido.length() < sizeof(_apellido)) {
        strcpy(_apellido, apellido.c_str());
    }
}

void Persona::setNombre(const string &nombre) {
    if (nombre.length() < sizeof(_nombre)) {
        strcpy(_nombre, nombre.c_str());
    }
}


void Persona::setDni(int dni) {
    if (dni > 1000000 && dni < 99999999) {
        _dni = dni;
    }
}

void Persona::setFechaNacimiento(const Fecha &fecha) {
    _fechaNacimiento = fecha;
}

void Persona::setGenero(const string &genero) {
    if (genero.length() < sizeof(_genero)) {
        strcpy(_genero, genero.c_str());
    }
}

void Persona::setEmail(const string &email) {
    if (email.length() < sizeof(_email)) {
        strcpy(_email, email.c_str());
    }
}

void Persona::setTelefono(const string &telefono) {
    if (telefono.length() < sizeof(_telefono)) {
        strcpy(_telefono, telefono.c_str());
    }
}

void Persona::setDomicilio(const Domicilio &domicilio) {
    _domicilio = domicilio;
}
