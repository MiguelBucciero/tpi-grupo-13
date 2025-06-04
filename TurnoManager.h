#pragma once
#include "TurnoArchivo.h"

class TurnoManager{
public:
    void cargarTurno();
    void mostrarTurno();
    void reprogramarTurno();
    void cancelarTurno();
    void TurnoNoAsistido();
    void BuscarTurnoEstado();
    void TurnosDelDia();
    void TurnosDeLaSemana();
    void CantidadTurnosPorEspecialidad();
    void CantidadTurnosNoAsistidos();
    void HistorialTurnosAtendidos(int idMedico);

private:
    TurnoArchivo _archivo;
};
