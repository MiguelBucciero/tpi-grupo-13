#pragma once
#include "UsuarioArchivo.h"

class UsuarioManager{
public:
    void login();
    bool VerificarLoginDuplicados(const char *nombre, const char *contrasenia);
    void cargarUsuario();
    void mostrarUsuario();
    void DarBajaUsuario();
    void modificarUsuario();

private:
    UsuarioArchivo _archivo;
};
