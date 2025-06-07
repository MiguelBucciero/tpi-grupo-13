#pragma once
#include "TurnoManager.h"
#include "PacienteManager.h"
#include "UsuarioManager.h"

#include "MedicoManager.h"

class MenuMedico {
public:
    int menuMedico(Usuario usuarioLogeado);
private:
    TurnoManager _turnoManger;
    PacienteManager _pacienteManager;

    MedicoManager _medicoManager;
};
