#pragma once
#include <string>
#include <ctime>

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

    // M�todos
    void cargarFecha();
    void cargarFecha(int dia, int mes, int anio);
    void mostrarFecha();
    bool esIgual(Fecha &otra);
    void obtenerFechaActual();
    void obtenerInicioDeSemana();


    std::string toString();
private:
    int _dia;
    int _mes;
    int _anio;

};
