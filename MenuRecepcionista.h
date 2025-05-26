#pragma once
#include "Paciente.h"
#include "PacienteManager.h"

class MenuRecepcionista{
public:
    int menuRecepcionista();
    int menuConsultasRecepcionista();
    int menuInformesRecepcionista();

private:
    PacienteManager _pacienteManager;
};
