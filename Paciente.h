#pragma once
#include "Persona.h"
#include "Domicilio.h"
#include "Fecha.h"

class Paciente:public Persona{
public:

    Paciente();
    Paciente(std::string apellido,std::string nombre, int dni, Fecha fechaNacimiento,std::string genero,
                 std::string email, std::string telefono, Domicilio domicilio, int id, int carnet, bool estado);

    // Getters
    int getIDPaciente() const;
    int getCarnet() const;
    bool getEstado() const;

    // Setters
    void setIDPaciente(int id);
    void setCarnet(int car);
    void setEstado(bool est);

private:
    int _IDPaciente;
    int _carnet;
    bool _estado;
};
