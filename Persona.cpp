#include <string>
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
const string Persona::getApellido() const{
    return _apellido;
}

const string Persona::getNombre() const{
    return _nombre;
}

int Persona::getDni() const{
    return _dni;
}

Fecha Persona::getFechaNacimiento() const{
    return _fechaNacimiento;
}

const string Persona::getGenero() const{
    return _genero;
}

const string Persona::getEmail() const{
    return _email;
}

const string Persona::getTelefono() const{
    return _telefono;
}

Domicilio Persona::getDomicilioCompleto() const{
    return _domicilio;
}

// Setters
void Persona::setApellido(const string &apellido) {
    if (apellido.length() < sizeof(_apellido)) {
        strcpy(_apellido, apellido.c_str());
    }
    else{
        strncpy(_apellido, apellido.c_str(), sizeof(_apellido)-1);
        _apellido[sizeof(_apellido)-1]='\0';
    }
}

void Persona::setNombre(const string &nombre) {
    if (nombre.length() < sizeof(_nombre)) {
        strcpy(_nombre, nombre.c_str());
    }
    else{
        strncpy(_nombre, nombre.c_str(), sizeof(_nombre)-1);
        _nombre[sizeof(_nombre)-1]='\0';
    }
}


void Persona::setDni(int dni) {
    if (dni > 1000000 && dni < 99999999) {
        _dni = dni;
    }
    else{
        _dni = 0;
    }
}

void Persona::setFechaNacimiento(const Fecha &fecha) {
    _fechaNacimiento = fecha;
}

void Persona::setGenero(const string &genero) {
    if(genero.size()<sizeof(_genero)){
        strcpy(_genero, genero.c_str());
    }else{
        strncpy(_genero, genero.c_str(), sizeof(_genero)-1);
        _genero[sizeof(_genero)-1]='\0';
    }
}

void Persona::setEmail(const string &email) {
    if(email.size()<sizeof(_email)){
        strcpy(_email, email.c_str());
    }else{
        strncpy(_email, email.c_str(), sizeof(_email)-1);
        _email[sizeof(_email)-1]='\0';
    }
}

void Persona::setTelefono(const string &telefono) {
    if(telefono.size()<sizeof(_telefono)){
        strcpy(_telefono, telefono.c_str());
    }else{
        strncpy(_telefono, telefono.c_str(), sizeof(_telefono)-1);
        _telefono[sizeof(_telefono)-1]='\0';
    }
}

void Persona::setDomicilio(const Domicilio &domicilio) {
    _domicilio = domicilio;
}
