#pragma once
#include "MedicoArchivo.h"


class MedicoManager{
public:
    int cargarMedico();
    void mostrarMedico();
    void buscarMedicoPorEspecialidad();
    void verTurnosAsignados(int idMedico);

private:
    MedicoArchivo _archivo;
};
