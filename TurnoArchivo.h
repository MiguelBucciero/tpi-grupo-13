#pragma once
#include <string>
#include "Turno.h"

class TurnoArchivo{

public:
    TurnoArchivo(std::string nombreArchivo="Turnos.dat");
    bool guardar(Turno registro);
    bool guardar(Turno registro, int posicion);
    int Buscar(int IDTurno);
    Turno Leer(int posicion);
    int getCantidadRegistros();
    bool leerMuchos(Turno reg[], int cantidad);
    int getNuevoID();
    bool existeTurno(int idMedico, Fecha fecha, Hora hora);
    bool modificar(Turno turno, int pos);

private:
    std::string _nombreArchivo;
};
