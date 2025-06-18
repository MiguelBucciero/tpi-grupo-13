#pragma once
#include <string>
#include <ctime>

class Fecha{
public:

    Fecha();
    Fecha(int dia, int mes, int anio);

    // Getters
    int getDia() const;
    int getMes() const;
    int getAnio() const;

    // Setters
    void setDia(int valor);
    void setMes(int valor);
    void setAnio(int valor);

    // Métodos
    bool esIgual(Fecha &otra);
    void obtenerFechaActual();
    void obtenerInicioDeSemana();
    bool esAnterior(Fecha &otra);

private:
    int _dia;
    int _mes;
    int _anio;

};
