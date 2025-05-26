#pragma once
#include "Especialidad.h"
#include "EspecialidadManager.h"

class MenuAdministrador {
public:
    int menuAdministrador();
    int menuInformesAdministrador();
private:
    EspecialidadManager _espManager;
};
