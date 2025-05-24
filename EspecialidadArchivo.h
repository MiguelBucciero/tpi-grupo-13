#pragma once
#include <string>
#include "Especialidad.h"

class EspecialidadArchivo{

public:
    EspecialidadArchivo(std::string nombreArchivo="especialidad.dat");
    bool guardar(Especialidad registro);
    bool Guardar(Especialidad registro, int posicion);
    int Buscar(int IDServicio);
    Especialidad Leer(int posicion);
    void Leer(int cantidadRegistros, Especialidad *vector);
    int getCantidadRegistros();
    bool leerMuchos(Especialidad reg[], int cantidad);
private:
    std::string _nombreArchivo;
};
