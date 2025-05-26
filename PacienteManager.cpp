#include "PacienteManager.h"
#include <iostream>
#include <string>
using namespace std;


void PacienteManager::cargarPaciente(){
    Paciente paciente;
    int carnet, id;
    bool estado;

    cout<<"INGRESO DE UN NUEVO PACIENTE"<<endl;
    cout << "-----------------------------" << endl;
    paciente.cargarDatos();
    id = _archivo.getNuevoID();
    cout<<"ID ASIGNADO: " <<id<<endl;
    paciente.setIDPaciente(id);
    cout<<"Ingrese numero de carnet: "<<endl;
    cin>>carnet;
    paciente.setCarnet(carnet);
    estado=true;
    paciente.setEstado(estado);

    if(_archivo.guardar(paciente)) {
        cout<<"Paciente guardado correctamente"<<endl;
    }
    else{
        cout<<"Error al guardar paciente"<<endl;
    }
}
void PacienteManager::mostrarPaciente(Paciente& paciente){
    PacienteArchivo archivo("pacientes.dat");

    int cantidad=archivo.getCantidadRegistros();
    if (cantidad==0) {
        cout<<"No hay pacientes cargados"<<endl;
        return;
    }
    Paciente* lista=new Paciente[cantidad];
    archivo.leerMuchos(lista, cantidad);

    for (int i=0; i<cantidad; i++) {
        lista[i].mostrarPaciente();
        cout << "----------------------" << endl;
    }
    delete[] lista;
}

void PacienteManager::mostrarPaciente() {
    int cantidad=_archivo.getCantidadRegistros();
    Paciente *vecPaciente;

    vecPaciente = new Paciente[cantidad];

    _archivo.leerMuchos(vecPaciente, cantidad);
    cout << "-------LISTADO DE PACIENTES-------" << endl;
    for(int i=0; i<cantidad; i++){
        cout << "----------------------------------" << endl;
        cout << "----------------------------------" << endl;
       vecPaciente[i].mostrarPaciente();

    }

    delete[] vecPaciente;
}

