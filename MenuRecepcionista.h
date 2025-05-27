#pragma once
#include "Paciente.h"
#include "PacienteManager.h"
#include "MedicoManager.h"
#include "TurnoManager.h"

class MenuRecepcionista{
public:
    int menuRecepcionista();
    int menuConsultasRecepcionista();
    int menuInformesRecepcionista();

private:
    PacienteManager _pacienteManager;
    MedicoManager _medicoManager;
    TurnoManager _turnoManager;
};
