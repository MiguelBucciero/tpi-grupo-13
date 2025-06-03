#pragma once
#include "EspecialidadArchivo.h"

class EspecialidadManager{
public:
    void cargarEspecialidad();
    void mostrarEspecialidad();
    void DarBajaEspecialidad();
    void ModificarEspecialidad();

private:
    EspecialidadArchivo _archivo;
};
