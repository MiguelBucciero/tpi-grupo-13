#pragma once
#include "MedicoArchivo.h"


class MedicoManager{
public:
    int cargarMedico();
    void mostrarMedico();
    void buscarMedicoPorEspecialidad();
    void verTurnosAsignados(int idMedico);
    void DarBajaMedico();
    void modificarMedico();
    void buscarPacientePorDNI();
private:
    MedicoArchivo _archivo;
};
