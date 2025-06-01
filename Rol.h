#pragma once

class Rol {
public:

    Rol();
    Rol(int tipo, const char* nombre);

    // Getters
    int getRol();
    char* getNombre();

    // Setters
    void setTipoRol(int valor);
    void setNombreRol(const char* valor);

    // Métodos
    void validarRol();

private:
    int _tipoRol;
    char _nombreRol[20];
};
