#pragma once
#include "Fecha.h"
#include "Hora.h"

class Turno {
public:

    Turno();
    Turno(int idTurno, int idPaciente, int idMedico, Fecha fecha, Hora hora, int idEspecialidad, int estado);

    // Getters
    int getIDTurno();
    int getIDPaciente();
    int getIDMedico();
    Fecha getFechaTurno();
    Hora getHoraTurno();
    int getEspecialidad();
    bool getEstado();

    // Setters
    void setIDTurno(int valor);
    void setIDPaciente(int valor);
    void setIDMedico(int valor);
    void setFechaTurno(Fecha valor);
    void setHoraTurno(Hora valor);
    void setEspecialidad(int valor);
    void setEstado(bool valor);

    // Métodos
    void cargarTurno();
    void mostrarTurno();

private:
    int _IDTurno;
    int _IDPaciente;
    int _IDMedico;
    Fecha _FechaTurno;
    Hora _HoraTurno;
    int _IDEspecialidad;
    int _EstadoTurno;
};
