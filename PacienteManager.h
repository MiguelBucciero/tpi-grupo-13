#pragma once
#include "PacienteArchivo.h"

class PacienteManager{
public:
    void cargarPaciente();
    void mostrarPaciente();

private:
    PacienteArchivo _archivo;
};
