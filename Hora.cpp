#include <iostream>
#include "Hora.h"

using namespace std;


Hora::Hora(){
    _hora=0;
    _minutos=0;
}

Hora::Hora(int hora, int minutos) {
    setHora(hora);
    setMinutos(minutos);
}

// Getters
int Hora::getHora() {
    return _hora;
}

int Hora::getMinutos() {
    return _minutos;
}

// Setters
void Hora::setHora(int hora) {
    if (hora >= 0 && hora <= 23) {
        _hora = hora;
    }
}

void Hora::setMinutos(int minutos) {
    if (minutos >= 0 && minutos <= 59) {
        _minutos = minutos;
    }
}

// M�todos
void Hora::cargarHora() {
    int h, m;

    cout << "Ingrese hora (0-23): ";
    cin >> h;
    setHora(h);

    cout << "Ingrese minutos (0-59): ";
    cin >> m;
    setMinutos(m);
}

void Hora::mostrarHora() {
    cout << "Hora: " << toString() << std::endl;
}
string Hora::toString() {
    return to_string(_hora) + ":" + to_string(_minutos) + " hs.";
}
