#pragma once
#include <string>

class Hora{
public:

    Hora();
    Hora(int hora, int minutos);

    // Getters
    int getHora();
    int getMinutos();

    // Setters
    void setHora(int hora);
    void setMinutos(int minutos);

    // Métodos
    void cargarHora();
    void mostrarHora();
    bool esIgual(Hora &otra);

    std::string toString();

private:
    int _hora;
    int _minutos;
};
