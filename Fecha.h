#pragma once
#include <string>

class Fecha{
public:

    Fecha();
    Fecha(int dia, int mes, int anio);

    // Getters
    int getDia();
    int getMes();
    int getAnio();

    // Setters
    void setDia(int valor);
    void setMes(int valor);
    void setAnio(int valor);

    // Métodos
    void cargarFecha();
    void cargarFecha(int dia, int mes, int anio);
    void mostrarFecha();

    std::string toString();
protected:
    int _dia;
    int _mes;
    int _anio;

};
