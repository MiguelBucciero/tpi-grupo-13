#pragma once
#include "Paciente.h"
#include "PacienteManager.h"
#include "MedicoManager.h"

class MenuRecepcionista{
public:
    int menuRecepcionista();
    int menuConsultasRecepcionista();
    int menuInformesRecepcionista();

private:
    PacienteManager _pacienteManager;
    MedicoManager _medicoManager;
};
