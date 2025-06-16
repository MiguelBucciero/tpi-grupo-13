#pragma once
#include "Rol.h"

class Usuario {
public:

    Usuario();
    Usuario(std::string nombre, std::string contrasenia, Rol tipoRol, bool estado, int IDMedico);

    // Getters
    //const char* getNombreUsuario();
    const std::string getNombreUsuario() const;
    //const char* getContrasenia();
    const std::string getContrasenia() const;
    Rol getRol();
    bool getEstado();
    int getIDMedico();

    // Setters
    //void setNombreUsuario(const char* valor);
    void setNombreUsuario(const std::string &nombre);
    //void setContrasenia(const char* valor);
    void setContrasenia(const std::string &constrasenia);
    void setTipoRol(Rol valor);
    void setEstado(bool valor);
    void setIDMedico(int valor);

private:
    //Aca quitamos el IDUsuario porque basicamente cumplia la misma funcion que Rol.
    char _nombreUsuario[50];
    char _contrasenia[50];
    Rol _tipoRol;
    bool _estado;
    int _IDMedico;
};

