#pragma once
#include "EspecialidadArchivo.h"

class EspecialidadManager{
public:
    void cargarEspecialidad();
    void mostrarEspecialidad();
    void DarBajaEspecialidad();
    void ModificarEspecialidad();
    void ReactivarEspecialidad();

private:
    EspecialidadArchivo _archivo;
};
