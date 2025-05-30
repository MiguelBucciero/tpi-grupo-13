#include "EspecialidadManager.h"
#include <iostream>
#include <string>
using namespace std;


void EspecialidadManager::cargarEspecialidad() {
    Especialidad registro;
    string nombre;
    char respuesta;
    int id = _archivo.getNuevoID();
    bool estado;

    cout<<"ID: "<<id<<endl;
    cin.ignore();
    cout<<"Ingrese nombre de la especialidad: ";
    getline(cin, nombre);


    cout<<"La especialidad esta activa? (s/n): ";
    cin>>respuesta;
    if(respuesta=='s'||respuesta=='S'){
        estado=true;
    }
    cin.ignore();

    registro=Especialidad(id,nombre, estado);

    if(_archivo.guardar(registro)) {
        cout<<"Especialidad cargada correctamente."<<endl;
    }
    else{
        cout<<"No se pudo guardar la especialidad."<<endl;
    }
    system ("pause");
    system("cls");
}

void EspecialidadManager::mostrarEspecialidad() {
    int cantidad=_archivo.getCantidadRegistros();
    Especialidad *vecEspecialidad;

    vecEspecialidad = new Especialidad[cantidad];

    _archivo.leerMuchos(vecEspecialidad, cantidad);

    for(int i=0; i<cantidad; i++){
        cout<<"----------------------------------------------"<<endl;
        cout<< "ID de la especialidad: "<<vecEspecialidad[i].getIDEspecialidad()<<endl;
        cout<< "Nombre de la especialidad: "<<vecEspecialidad[i].getNombre()<<endl;
        cout << "Estado de la especialidad: ";
        if (vecEspecialidad[i].getEstado()) {
            cout<< "Activo" <<endl;
        } else {
            cout<< "Inactivo" <<endl;
        }
    }

    delete[] vecEspecialidad;
    system ("pause");
    system("cls");
}

void EspecialidadManager::DarBajaEspecialidad(){
    int id;
    cout<<"Ingrese el ID de la especialidad a dar de baja: ";
    cin>>id;

    int pos=_archivo.Buscar(id);
    if(pos==-1){
        cout<<"Especialidad no encontrada"<<endl;
        return;
    }

    Especialidad esp=_archivo.Leer(pos);
    if(!esp.getEstado()){
        cout<<"Especialidad ya dada de baja"<<endl;
        return;
    }

    esp.setEstado(false);
    if(_archivo.guardar(esp, pos)){
        cout<<"Especialidad dada de baja correctamente"<<endl;
    } else{
    cout<<"No se pudo modificar el archivo"<<endl;
    }
    system ("pause");
    system("cls");
}
