#pragma once
#include "MedicoArchivo.h"

class MedicoManager{
public:
    void cargarMedico();
    void mostrarMedico();
    void buscarMedicoPorEspecialidad();

private:
    MedicoArchivo _archivo;
};
