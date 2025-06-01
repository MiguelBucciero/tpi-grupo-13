#pragma once
#include "UsuarioArchivo.h"

class UsuarioManager{
public:
    void login();
    void cargarUsuario();

private:
    UsuarioArchivo _archivo;
};
