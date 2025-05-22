#pragma once

class Especialidad {
public:

    Especialidad();
    Especialidad(int IDEspecialidad, char nombre, bool estado);

    //Getters
    int getIDEspecialidad() const;
    char getNombre() const;
    bool getEstado() const;

    //Setters
    void setIDEspecialidad(int id);
    void setNombre(char *);
    void setEstado(bool estado);
    void cargarEspecialidad();
    void mostrarEspecialidad();

protected:
    int _IDEspecialidad;
    char _nombre [50];
    bool _estado;
};



