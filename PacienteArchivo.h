#pragma once
#include <string>
#include "Paciente.h"

class PacienteArchivo{

public:
    PacienteArchivo(std::string nombreArchivo="Pacientes.dat");
    bool guardar(Paciente registro);
    bool guardar(Paciente registro, int posicion);
    int Buscar(int IDPaciente);
    Paciente Leer(int posicion);
    int getCantidadRegistros();
    bool leerMuchos(Paciente reg[], int cantidad);
    int getNuevoID();
    bool esPacienteActivo(int IDPaciente);

private:
    std::string _nombreArchivo;
};

