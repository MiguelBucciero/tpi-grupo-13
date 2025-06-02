#pragma once
#include "Rol.h"

class Usuario {
public:

    Usuario();
    Usuario(const char* nombre, const char* contrasenia, Rol tipoRol, bool estado, int IDMedico);

    // Getters
    const char* getNombreUsuario();
    const char* getContrasenia();
    Rol getRol();
    bool getEstado();
    int getIDMedico();

    // Setters
    void setNombreUsuario(const char* valor);
    void setContrasenia(const char* valor);
    void setTipoRol(Rol valor);
    void setEstado(bool valor);
    void setIDMedico(int valor);

    // Metodos
    void validarUsuario();
    void cargarUsuario();

private:
    //Aca quitamos el IDUsuario porque basicamente cumplia la misma funcion que Rol.
    char _nombreUsuario[50];
    char _contrasenia[50];
    Rol _tipoRol;
    bool _estado;
    int _IDMedico;
};

