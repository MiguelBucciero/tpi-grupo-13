#pragma once
#include "PacienteArchivo.h"

class PacienteManager{
public:
    void cargarPaciente();
    void mostrarPaciente(Paciente& paciente);
    void mostrarPaciente();

private:
    PacienteArchivo _archivo;
};
