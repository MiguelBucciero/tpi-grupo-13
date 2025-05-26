#pragma once
#include "PacienteArchivo.h"

class PacienteManager{
public:
    Paciente cargarPaciente();
    void mostrarPaciente(Paciente& paciente);

private:
    PacienteArchivo _archivo;
};
