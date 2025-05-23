#include <iostream>
#include "Especialidad.h"
#include <cstring>

using namespace std;

// Constructor por defecto
Especialidad::Especialidad() {
    _IDEspecialidad = 0;
    strcpy(_nombre, "");
    _estado = true;
}

// Constructor con parámetros
Especialidad::Especialidad(int IDEspecialidad, std::string nombre, bool estado) {
    setIDEspecialidad(IDEspecialidad);
    setNombre(nombre);
    setEstado(estado);
}

// Getters
int Especialidad::getIDEspecialidad() const {
    return _IDEspecialidad;
}

const string Especialidad::getNombre() const {
    return _nombre;
}

bool Especialidad::getEstado() const {
    return _estado;
}

// Setters
void Especialidad::setIDEspecialidad(int id) {
    _IDEspecialidad = id;
}

void Especialidad::setNombre(const string &nombre) {
    if(nombre.size() < 50){
        strcpy(_nombre, nombre.c_str());
    }
}

void Especialidad::setEstado(bool estado) {
    _estado = estado;
}

// Métodos
void Especialidad::cargarEspecialidad() {
    string aux;
    char respuesta;
    int id;
    bool estado;

    cout << "Ingrese ID de especialidad: ";
    cin >> id;
    setIDEspecialidad(id);
    cin.ignore();

    cout << "Ingrese nombre de la especialidad: ";
    getline(cin, aux);
    setNombre(aux);

    cout << "¿La especialidad esta activa? (s/n): ";
    cin >> respuesta;
    if(respuesta == 's' || respuesta == 'S'){
        estado = true;
        setEstado(estado);
    }
    cin.ignore();
}

void Especialidad::mostrarEspecialidad() {
    cout << "ID Especialidad: " << getIDEspecialidad() << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Estado: ";
    if (_estado) {
        cout << "Activa" << endl;
    } else {
        cout << "Inactiva" << endl;
    }
}

