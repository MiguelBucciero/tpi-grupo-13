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

private:
    TurnoArchivo _archivo;
};
