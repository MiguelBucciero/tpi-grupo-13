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
    void CantidadTurnosReprogramadosMes();
    void CantidadTurnosPorEspecialidadAdmin(int anio);
    void buscarTurnosPorFecha();
    void cantidadTurnosPorMedico();
    void cantidadTurnosPorPaciente();
    void cantidadTurnosCanceladosPorMes();

private:
    TurnoArchivo _archivo;
};
