#pragma once
#include "UsuarioArchivo.h"

class UsuarioManager{
public:
    void login();
    bool VerificarLoginDuplicados(const std::string &nombre, const std::string &contrasenia);
    void cargarUsuario();
    void mostrarUsuario();
    void DarBajaUsuario();
    void modificarUsuario();
    void CantidadUsuariosActivos();
    void reactivarUsuario();

private:
    UsuarioArchivo _archivo;
};
