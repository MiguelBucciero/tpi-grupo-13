#pragma once
#include "Persona.h"

class Medico : public Persona {
public:

    Medico();
    Medico(std::string apellido,std::string nombre, int dni, Fecha fechaNacimiento,std::string genero,std::string email,
           std::string telefono, Domicilio domicilio, int idMedico, int matricula, int idEspecialidad, bool estado);


    // Getters
    int getIDMedico();
    int getMatricula();
    int getIDEspecialidad();
    bool getEstado();

    // Setters
    void setIDMedico(int valor);
    void setMatricula(int valor);
    void setIDEspecialidad(int valor);
    void setEstado(bool valor);

private:
    int _IDMedico;
    int _matricula;
    int _IDEspecialidad;
    bool _estado;
};
