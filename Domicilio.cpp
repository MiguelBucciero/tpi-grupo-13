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

// Métodos
void Domicilio::cargarDomicilio() {
    string aux;
    int altura;

    rlutil::cls();
    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::locate(40, 2);
    cout << "CARGAR DOMICILIO";
    rlutil::setColor(rlutil::COLOR::WHITE);

    // Calle
    rlutil::locate(30, 4);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Calle: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(40, 4);
    getline(cin, aux);
    setCalle(aux);

    // Altura
    rlutil::locate(30, 5);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Altura: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(40, 5);
    cin >> altura;
    cin.ignore();
    setAltura(altura);

    // Localidad
    rlutil::locate(30, 6);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Localidad: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(40, 6);
    getline(cin, aux);
    setLocalidad(aux);

    // Provincia
    rlutil::locate(30, 7);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Provincia: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(40, 7);
    getline(cin, aux);
    setProvincia(aux);

    // Código Postal
    rlutil::locate(30, 8);
    rlutil::setColor(rlutil::COLOR::CYAN);
    cout << "Codigo Postal: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(45, 8);
    getline(cin, aux);
    setCodigoPostal(aux);

    rlutil::setColor(rlutil::COLOR::GREEN);
    rlutil::locate(30, 10);
    cout << "Domicilio cargado correctamente.";
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void Domicilio::mostrarDomicilio(int columna, int filaBase) {
    rlutil::setColor(rlutil::COLOR::CYAN);
    rlutil::locate(columna, filaBase);
    cout << "Calle: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    cout << getCalle();

    rlutil::setColor(rlutil::COLOR::CYAN);
    rlutil::locate(columna, filaBase + 1);
    cout << "Altura: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    cout << getAltura();

    rlutil::setColor(rlutil::COLOR::CYAN);
    rlutil::locate(columna, filaBase + 2);
    cout << "Localidad: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    cout << getLocalidad();

    rlutil::setColor(rlutil::COLOR::CYAN);
    rlutil::locate(columna, filaBase + 3);
    cout << "Provincia: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    cout << getProvincia();

    rlutil::setColor(rlutil::COLOR::CYAN);
    rlutil::locate(columna, filaBase + 4);
    cout << "Codigo Postal: ";
    rlutil::setColor(rlutil::COLOR::WHITE);
    cout << getCodigoPostal();
}
