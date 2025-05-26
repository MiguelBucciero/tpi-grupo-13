#include <iostream>
#include "Fecha.h"
using namespace std;

Fecha::Fecha() {
    _dia=1;
    _mes=1;
    _anio=2000;
}

Fecha::Fecha(int dia, int mes, int anio) {
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

// Getters
int Fecha::getDia() {
    return _dia;
}

int Fecha::getMes() {
    return _mes;
}

int Fecha::getAnio() {
    return _anio;
}

// Setters
void Fecha::setDia(int dia) {
    if (dia >= 1 && dia <= 31) {
        _dia = dia;
    }
}

void Fecha::setMes(int mes) {
    if (mes >= 1 && mes <= 12) {
        _mes = mes;
    }
}

void Fecha::setAnio(int anio) {
    if (anio >= 1900 && anio <= 2100) {
        _anio = anio;
    }
}

// Métodos
void Fecha::cargarFecha() {
    int dia, mes, anio;

    cout << "Ingrese dia: ";
    cin >> dia;
    setDia(dia);

    cout << "Ingrese mes: ";
    cin >> mes;
    setMes(mes);

    cout << "Ingrese anio: ";
    cin >> anio;
    cin.ignore();
    setAnio(anio);
}

void Fecha::cargarFecha(int dia, int mes, int anio){
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

void Fecha::mostrarFecha() {
    cout << toString() << endl;
}
string Fecha::toString(){
    return to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
}
