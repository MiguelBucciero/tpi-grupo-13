#pragma once
#include "MedicoArchivo.h"

class MedicoManager{
public:
    int cargarMedico();
    void mostrarMedico();
    void buscarMedicoPorEspecialidad();

private:
    MedicoArchivo _archivo;
};
