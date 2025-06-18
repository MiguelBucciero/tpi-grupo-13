#pragma once

class Rol {
public:

    Rol();
    Rol(int tipo, const char* nombre);

    // Getters
    int getRol() const;
    const char* getNombre() const;

    // Setters
    void setTipoRol(int valor);
    void setNombreRol(const char* valor);

private:
    int _tipoRol;
    char _nombreRol[20];
};
