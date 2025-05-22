#pragma once
#include "Persona.h"

class Medico : public Persona {
public:

    Medico();
    Medico(int idMedico, int matricula, int idEspecialidad, bool estado);

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

    // Métodos
    void cargarMedico();
    void mostrarMedico();

protected:
    int _IDMedico;
    int _matricula;
    int _IDEspecialidad;
    bool _estado;
};
