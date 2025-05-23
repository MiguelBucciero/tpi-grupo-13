#include <iostream>
#include "Domicilio.h"
#include <cstring>

using namespace std;

Domicilio::Domicilio() {
    strcpy(_calle, "");
    _altura = 0;
    strcpy(_localidad, "");
    strcpy(_provincia, "");
    strcpy(_codigoPostal, "");
}

Domicilio::Domicilio(std::string calle, int altura, std::string localidad, std::string provincia, std::string codigoPostal) {
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

// Métodos
void Domicilio::cargarDomicilio() {
    string aux;
    int altura;

    cout << "Ingrese calle: ";
    getline(cin, aux);
    setCalle(aux);

    cout << "Ingrese altura: ";
    cin >> altura;
    cin.ignore();
    setAltura(altura);

    cout << "Ingrese localidad: ";
    getline(cin, aux);
    setLocalidad(aux);

    cout << "Ingrese provincia: ";
    getline(cin, aux);
    setProvincia(aux);

    cout << "Ingrese codigo postal: ";
    getline(cin, aux);
    setCodigoPostal(aux);
}

void Domicilio::mostrarDomicilio() {
    cout << "Calle: " << getCalle() << endl;
    cout << "Altura: " << getAltura() << endl;
    cout << "Localidad: " << getLocalidad() << endl;
    cout << "Provincia: " << getProvincia() << endl;
    cout << "Codigo Postal: " << getCodigoPostal() << endl;
}
