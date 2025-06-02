#pragma once
#include "UsuarioArchivo.h"

class UsuarioManager{
public:
    void login();
    void cargarUsuario();
    void mostrarUsuario();

private:
    UsuarioArchivo _archivo;
};
