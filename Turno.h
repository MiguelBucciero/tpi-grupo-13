#pragma once
#include "Fecha.h"
#include "Hora.h"

class Turno {
public:

    Turno();
    Turno(int idTurno, int idPaciente, int idMedico, Fecha fecha, Hora hora, int idEspecialidad, int estado);

    // Getters
    int getIDTurno() const;
    int getIDPaciente() const;
    int getIDMedico() const;
    Fecha getFechaTurno() const;
    Hora getHoraTurno() const;
    int getEspecialidad() const;
    int getEstado() const;

    // Setters
    void setIDTurno(int valor);
    void setIDPaciente(int valor);
    void setIDMedico(int valor);
    void setFechaTurno(const Fecha &valor);
    void setHoraTurno(const Hora &valor);
    void setEspecialidad(int valor);
    void setEstado(int valor);

private:
    int _IDTurno;
    int _IDPaciente;
    int _IDMedico;
    Fecha _FechaTurno;
    Hora _HoraTurno;
    int _IDEspecialidad;
    int _EstadoTurno;
};
