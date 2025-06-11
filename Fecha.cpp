#include "Fecha.h"

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
bool Fecha::esIgual(Fecha &otra) {
    return(_dia==otra.getDia()&&_mes==otra.getMes()&&_anio==otra.getAnio());
}

void Fecha::obtenerFechaActual(){
    time_t fechaActual = time(0);
    tm* fecha = localtime(&fechaActual);
    setDia(fecha->tm_mday);
    setMes(fecha->tm_mon + 1);
    setAnio(fecha->tm_year + 1900);
}

void Fecha::obtenerInicioDeSemana(){
    time_t fechaActual = time(0);
    tm* fecha = localtime(&fechaActual);

    if (fecha->tm_wday == 0) {
        // Si es domingo (wday = 0), sumamos 1 para que sea lunes
        fecha->tm_mday += 1;
    } else {
        // Si es lunes a sábado
        fecha->tm_mday -= (fecha->tm_wday - 1);
    }

    mktime(fecha); // normaliza la fecha

    setDia(fecha->tm_mday);
    setMes(fecha->tm_mon + 1);
    setAnio(fecha->tm_year + 1900);
}

bool Fecha::esAnterior(Fecha &otra) {
    if (_anio < otra.getAnio()) {
        return true;
    }
    if (_anio == otra.getAnio() && _mes < otra.getMes()) {
        return true;
    }
    if (_anio == otra.getAnio() && _mes == otra.getMes() && _dia < otra.getDia()) {
        return true;
    }
    return false;
}
