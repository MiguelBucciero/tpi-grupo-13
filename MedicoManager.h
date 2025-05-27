#pragma once
#include "MedicoArchivo.h"

class MedicoManager{
public:
    void cargarMedico();
    void mostrarMedico();

private:
    MedicoArchivo _archivo;
};
