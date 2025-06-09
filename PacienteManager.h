#pragma once
#include "PacienteArchivo.h"

class PacienteManager{
public:
    void cargarPaciente();
    void mostrarPaciente();
    void DarBajaPaciente();
    void modificarPaciente();
private:
    PacienteArchivo _archivo;
};
