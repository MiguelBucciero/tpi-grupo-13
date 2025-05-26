#pragma once
#include "EspecialidadArchivo.h"

class EspecialidadManager{
public:
    void cargarEspecialidad();
    void mostrarEspecialidad();
    void DarBajaEspecialidad();

private:
    EspecialidadArchivo _archivo;
};
