#pragma once
#include <string>

class Hora{
public:

    Hora();
    Hora(int hora, int minutos);

    // Getters
    int getHora() const;
    int getMinutos() const;

    // Setters
    void setHora(int hora);
    void setMinutos(int minutos);

    // Métodos
    bool esIgual(Hora &otra);

private:
    int _hora;
    int _minutos;
};
