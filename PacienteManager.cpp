#include "PacienteManager.h"
#include <iostream>
#include <string>
using namespace std;


Paciente PacienteManager::cargarPaciente(){
    Paciente paciente;
    int entero;
    cout<<"INGRESO DE UN NUEVO PACIENTE"<<endl;
    paciente.cargarDatos();
    paciente.setIDPaciente(paciente.getDni());
    cout<<"Ingrese en carnet: "<<endl;
    cin>>entero;
    paciente.setCarnet(entero);
    paciente.setEstado(true);
    cin.ignore();
    return paciente;
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

