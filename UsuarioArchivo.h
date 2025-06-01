#pragma once
#include <string>
#include <cstring>
#include "Usuario.h"

class UsuarioArchivo{
public:
    UsuarioArchivo(std::string nombreArchivo="Usuarios.dat");
    bool guardar(Usuario registro);
    bool guardar(Usuario registro, int posicion);
    int Buscar(const char* nombreUsuario);
    Usuario Leer(int posicion);
    void Leer(int cantidadRegistros, Usuario *vector);
    int getCantidadRegistros();
    bool esUsuarioActivo(const char* nombreUsuario);

    ///por ahora dejo estos porque creo que no se usan.
    //bool leerMuchos(Usuario reg[], int cantidad);
    //void CargarYguardar();
    //int getNuevoID();

private:
    std::string _nombreArchivo;
};

