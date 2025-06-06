#pragma once
#include "Especialidad.h"
#include "EspecialidadManager.h"
#include "MedicoManager.h"
#include "UsuarioManager.h"
#include "TurnoManager.h"


class MenuAdministrador {
public:
    int menuAdministrador();
    int menuInformesAdministrador();
private:
    EspecialidadManager _espManager;
    MedicoManager _medicoManger;
    UsuarioManager _usuarioManager;
    TurnoManager _turnoManager;
};
