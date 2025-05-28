#pragma once
#include "Especialidad.h"
#include "EspecialidadManager.h"
#include "MedicoManager.h"


class MenuAdministrador {
public:
    int menuAdministrador();
    int menuInformesAdministrador();
private:
    EspecialidadManager _espManager;
    MedicoManager _medicoManger;
};
