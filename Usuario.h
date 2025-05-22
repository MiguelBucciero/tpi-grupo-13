#pragma once
#include "Rol.h"

class Usuario {
public:

    Usuario();
    Usuario(int id, const char* nombre, const char* contrasenia, Rol tipoRol, bool estado);

    // Getters
    int getIDUsuario();
    char* getNombreUsuario();
    char* getContrasenia();
    Rol getRol();
    bool getEstado();

    // Setters
    void setIDUsuario(int valor);
    void setNombreUsuario(const char* valor);
    void setContrasenia(const char* valor);
    void setTipoRol(Rol valor);
    void setEstado(bool valor);

    // Métodos
    void validarUsuario();
    void cargarUsuario();

private:
    int _idUsuario;
    char _nombreUsuario[50];
    char _contrasenia[50];
    Rol _tipoRol;
    bool _estado;
};

