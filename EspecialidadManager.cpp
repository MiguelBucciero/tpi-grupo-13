#include "EspecialidadManager.h"
#include <iostream>
#include <string>
using namespace std;


void EspecialidadManager::cargarEspecialidad() {
    Especialidad registro;
    string nombre;
    char respuesta;
    int id;
    bool estado;

    cout << "Ingrese ID de especialidad: ";
    cin >> id;
    cin.ignore();

    cout << "Ingrese nombre de la especialidad: ";
    getline(cin, nombre);


    cout << "¿La especialidad esta activa? (s/n): ";
    cin >> respuesta;
    if(respuesta == 's' || respuesta == 'S'){
        estado = true;
    }
    cin.ignore();

    registro = Especialidad(id,nombre, estado);

    if(_archivo.guardar(registro)) {
        cout<< "Especialidad cargada correctamente."<<endl;
    }
    else{
        cout<< "No se pudo guardar la especialidad."<<endl;
    }
}

void EspecialidadManager::mostrarEspecialidad() {
    int cantidad = _archivo.getCantidadRegistros();
    Especialidad *vecEspecialidad;

    vecEspecialidad = new Especialidad[cantidad];

    _archivo.leerMuchos(vecEspecialidad, cantidad);

    for(int i=0; i <cantidad; i++){
        cout<<"----------------------------------------------"<<endl;
        cout<< "ID de la especialidad: "<<vecEspecialidad[i].getIDEspecialidad()<<endl;
        cout<< "Nombre de la especialidad: "<<vecEspecialidad[i].getNombre()<<endl;
        cout << "Estado de la especialidad: ";
        if (vecEspecialidad[i].getEstado()) {
            cout << "Activo" << endl;
        } else {
            cout << "Inactivo" << endl;
        }
    }

    delete[] vecEspecialidad;
}
