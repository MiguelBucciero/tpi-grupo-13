#include <iostream>
#include "Domicilio.h"
#include "rlutil.h"
#include <cstring>

using namespace std;

Domicilio::Domicilio() {
    strcpy(_calle, "");
    _altura = 0;
    strcpy(_localidad, "");
    strcpy(_provincia, "");
    strcpy(_codigoPostal, "");
}

Domicilio::Domicilio(string calle, int altura, string localidad, string provincia, string codigoPostal) {
    setCalle(calle);
    setAltura(altura);
    setLocalidad(localidad);
    setProvincia(provincia);
    setCodigoPostal(codigoPostal);
}

// Getters
const string Domicilio::getCalle() const {
    return _calle;
}

int Domicilio::getAltura() const {
    return _altura;
}

const string Domicilio::getLocalidad() const {
    return _localidad;
}

const string Domicilio::getProvincia() const {
    return _provincia;
}

const string Domicilio::getCodigoPostal() const {
    return _codigoPostal;
}


// Setters

void Domicilio::setCalle(const std::string &calle) {
    if(calle.size() < 30){
        strcpy(_calle, calle.c_str());
    }
}

void Domicilio::setAltura(int altura) {
    _altura = altura;
}

void Domicilio::setLocalidad(const string &localidad) {
    if(localidad.size() < 30){
        strcpy(_localidad, localidad.c_str());
    }
}

void Domicilio::setProvincia(const string &provincia) {
    if(provincia.size() < 30){
        strcpy(_provincia, provincia.c_str());
    }
}

void Domicilio::setCodigoPostal(const string &cpostal) {
    if(cpostal.size() < 6){
        strcpy(_codigoPostal, cpostal.c_str());
    }
}
