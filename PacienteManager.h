#pragma once
#include "PacienteArchivo.h"

class PacienteManager{
public:
    void cargarPaciente();
    void mostrarPaciente();
    void DarBajaPaciente();
    void modificarPaciente();
    void reactivarPaciente();
private:
    PacienteArchivo _archivo;
};
