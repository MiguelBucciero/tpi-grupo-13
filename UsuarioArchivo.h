#pragma once
#include <string>
#include <cstring>
#include "Usuario.h"

class UsuarioArchivo{
public:
    UsuarioArchivo(std::string nombreArchivo="Usuarios.dat");
    bool guardar(Usuario registro);
    bool guardar(Usuario registro, int posicion);
    int Buscar(const std::string &nombreUsuario);
    Usuario Leer(int posicion);
    int getCantidadRegistros();
    bool leerMuchos(Usuario reg[], int cantidad);

private:
    std::string _nombreArchivo;
};

