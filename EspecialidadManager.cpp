#include "EspecialidadManager.h"
#include "Especialidad.h"
#include <iostream>
#include <string>
using namespace std;


void EspecialidadManager::cargarEspecialidad() {
    Especialidad registro;
    string nombre;
    int id = _archivo.IDdisponible();

    cout<<"ID: "<<id<<endl;
    cin.ignore();
    cout<<"Ingrese nombre de la especialidad: ";
    getline(cin, nombre);

    registro=Especialidad(id,nombre, true);

    int pos=_archivo.Buscar(id);
    bool verificar;
    if(pos!=-1){
        verificar=_archivo.guardar(registro, pos);
    }else{
        verificar=_archivo.guardar(registro);
    }

    if(verificar){
        cout<<"Especialidad cargada correctamente."<<endl;
    }else{
        cout<<"No se pudo guardar la especialidad"<<endl;
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
        if(vecEspecialidad[i].getEstado()){
            cout<<"----------------------------------------------"<<endl;
            cout<< "ID de la especialidad: "<<vecEspecialidad[i].getIDEspecialidad()<<endl;
            cout<< "Nombre de la especialidad: "<<vecEspecialidad[i].getNombre()<<endl;
            cout << "Estado de la especialidad: Activo"<<endl;
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
        system ("pause");
        system("cls");
        return;
    }
    Especialidad esp=_archivo.Leer(pos);
    if(!esp.getEstado()){
        cout<<"Especialidad ya dada de baja"<<endl;
        system ("pause");
        system("cls");
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

void EspecialidadManager::ModificarEspecialidad(){
    int id;
    cout<<"Ingrese el ID de la especialidad que desea modificar: ";
    cin>>id;

    int pos=_archivo.Buscar(id);
    if(pos==-1){
        cout<<"Especialidad no encontrada"<<endl;
        system ("pause");
        system("cls");
        return;
    }
    Especialidad esp=_archivo.Leer(pos);
    if(!esp.getEstado()){
        cout<<"Especialidad esta dada de baja, no se puede modificar"<<endl;
        system ("pause");
        system("cls");
        return;
    }
    string nombre;
    cin.ignore();
    cout<<"Nombre actual de la especialidad: "<<esp.getNombre()<<endl;
    cout<<"Ingrese el nuevo nombre de la especialidad: ";
    getline(cin, nombre);

    esp.setNombre(nombre);
    if(_archivo.guardar(esp, pos)){
        cout<<"Especialidad modificada correctamente"<<endl;
    }else{
        cout<<"No se pudo modificar el archivo"<<endl;
    }
    system ("pause");
    system("cls");
}
