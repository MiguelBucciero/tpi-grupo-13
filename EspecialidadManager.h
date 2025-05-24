#pragma once
#include "EspecialidadArchivo.h"

class EspecialidadManager {
public:
    void cargarEspecialidad();
    void mostrarEspecialidad();

private:
    EspecialidadArchivo _archivo;
};
