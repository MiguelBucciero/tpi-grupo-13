#pragma once
#include "Persona.h"

class Paciente : public Persona {
public:

    Paciente();
    Paciente(int id, int carnet, bool estado);

    // Getters
    int getIDPaciente();
    int getCarnet();
    bool getEstado();

    // Setters
    void setIDPaciente(int valor);
    void setCarnet(int valor);
    void setEstado(bool valor);

    // Métodos
    void cargarPaciente();
    void mostrarPaciente();

protected:
    int _IDPaciente;
    int _carnet;
    bool _estado;
};
