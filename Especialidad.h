#pragma once
#include <string>

class Especialidad {
public:

    Especialidad();
    Especialidad(int IDEspecialidad, std::string nombre, bool estado);

    //Getters
    int getIDEspecialidad() const;
    const std::string getNombre() const;
    bool getEstado() const;

    //Setters
    void setIDEspecialidad(int id);
    void setNombre(const std::string &nombre);
    void setEstado(bool estado);

    void cargarEspecialidad();
    void mostrarEspecialidad();

protected:
    int _IDEspecialidad;
    char _nombre [50];
    bool _estado;
};



