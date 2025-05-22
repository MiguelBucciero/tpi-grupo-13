#pragma once

class Hora{
public:

    Hora();
    Hora(int hora, int minutos);

    // Getters
    int getHora();
    int getMinutos();

    // Setters
    void setHora(int valor);
    void setMinutos(int valor);

    // Métodos
    void cargarHora();
    void mostrarHora();

protected:
    int _hora;
    int _minutos;
};
