#pragma once
#include <string>
#include "Medico.h"

class MedicoArchivo{
public:
    MedicoArchivo(std::string nombreArchivo="Medicos.dat");
    bool guardar(Medico registro);
    bool guardar(Medico registro, int posicion);
    int Buscar(int IDMedico);
    Medico Leer(int posicion);
    void Leer(int cantidadRegistros, Medico *vector);
    int getCantidadRegistros();
    bool leerMuchos(Medico reg[], int cantidad);
    void CargarYguardar();
    int getNuevoID();
    bool esMedicoActivo(int IDMedico);

private:
    std::string _nombreArchivo;
};

