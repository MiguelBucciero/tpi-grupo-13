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
void Domicilio::setCalle(const string &calle) {
    if(calle.size()<sizeof(_calle)){
        strcpy(_calle, calle.c_str());
    }else{
        strncpy(_calle, calle.c_str(), sizeof(_calle)-1);
        _calle[sizeof(_calle)-1]='\0';
    }
}

void Domicilio::setAltura(int altura) {
    _altura = altura;
}

void Domicilio::setLocalidad(const string &localidad) {
    if(localidad.size()<sizeof(_localidad)){
        strcpy(_localidad, localidad.c_str());
    }else{
        strncpy(_localidad, localidad.c_str(), sizeof(_localidad)-1);
        _localidad[sizeof(_localidad)-1]='\0';
    }
}

void Domicilio::setProvincia(const string &provincia) {
    if(provincia.size()<sizeof(_provincia)){
        strcpy(_provincia, provincia.c_str());
    }else{
        strncpy(_provincia, provincia.c_str(), sizeof(_provincia)-1);
        _provincia[sizeof(_provincia)-1]='\0';
    }
}

void Domicilio::setCodigoPostal(const string &cpostal) {
    if(cpostal.size()<sizeof(_codigoPostal)){
        strcpy(_codigoPostal, cpostal.c_str());
    }else{
        strncpy(_codigoPostal, cpostal.c_str(), sizeof(_codigoPostal)-1);
        _codigoPostal[sizeof(_codigoPostal)-1]='\0';
    }
}
