#pragma once
#include "Rol.h"

class Usuario {
public:

    Usuario();
    Usuario(std::string nombre, std::string contrasenia, Rol tipoRol, bool estado, int IDMedico);

    // Getters
    const std::string getNombreUsuario() const;
    const std::string getContrasenia() const;
    Rol getRol() const;
    bool getEstado() const;
    int getIDMedico() const;

    // Setters
    void setNombreUsuario(const std::string &nombre);
    void setContrasenia(const std::string &constrasenia);
    void setTipoRol(const Rol &valor);
    void setEstado(bool valor);
    void setIDMedico(int valor);

private:
    char _nombreUsuario[50];
    char _contrasenia[50];
    Rol _tipoRol;
    bool _estado;
    int _IDMedico;
};

