#pragma once
#include "Persona.h"
#include "Domicilio.h"
#include "Fecha.h"

class Paciente:public Persona{
public:

    Paciente();
    Paciente(int id, int carnet, bool estado);

    // Getters
    int getIDPaciente();
    int getCarnet();
    bool getEstado();

    // Setters
    void setIDPaciente(int id);
    void setCarnet(int car);
    void setEstado(bool est);

    // M�todos
    void cargarPaciente();
    void mostrarPaciente();

protected:
    int _IDPaciente;
    int _carnet;
    bool _estado;
};
