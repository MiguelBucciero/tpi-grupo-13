#pragma once
#include "TurnoArchivo.h"

class TurnoManager{
public:
    void cargarTurno();
    void mostrarTurno();
    void reprogramarTurno();
    void cancelarTurno();
    void BuscarTurnoEstado();
    void TurnosDelDia();
    void TurnosDeLaSemana();

private:
    TurnoArchivo _archivo;
};
