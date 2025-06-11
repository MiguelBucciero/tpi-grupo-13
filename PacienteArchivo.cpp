#include "PacienteArchivo.h"
#include "PacienteManager.h"
#include <iostream>
using namespace std;

PacienteArchivo::PacienteArchivo(std::string nombreArchivo){
    _nombreArchivo=nombreArchivo;
}
bool PacienteArchivo::guardar(Paciente registro){
    bool resultado;
    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(),"ab");

    if(pFile==nullptr){
        return false;
    }

    resultado=fwrite(&registro,sizeof(Paciente), 1, pFile);

    fclose(pFile);

    return resultado;
}

bool PacienteArchivo::guardar(Paciente registro, int posicion){
    bool resultado;
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == NULL){
        return false;
    }

    fseek(pArchivo, sizeof(Paciente) * posicion, SEEK_SET);
    resultado = fwrite(&registro, sizeof(Paciente), 1, pArchivo);

    fclose(pArchivo);

    return resultado;
}

int PacienteArchivo::Buscar(int IDPaciente){
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return -1;
    }

    Paciente registro;
    int i = 0;
    while(fread(&registro, sizeof(Paciente), 1, pArchivo)){
        if(registro.getIDPaciente() == IDPaciente){
            fclose(pArchivo);
            return i;
        }
        i++;
    }

    fclose(pArchivo);

    return -1;
}

Paciente PacienteArchivo::Leer(int posicion){
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return Paciente();
    }

    Paciente registro;
    fseek(pArchivo, sizeof(Paciente) * posicion, SEEK_SET);
    fread(&registro, sizeof(Paciente), 1, pArchivo);

    fclose(pArchivo);

    return registro;
}

int PacienteArchivo::getCantidadRegistros(){
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return 0;
    }

    fseek(pArchivo, 0, SEEK_END);

    int cantidadRegistros = ftell(pArchivo) / sizeof(Paciente);

    fclose(pArchivo);

    return cantidadRegistros;
}

bool PacienteArchivo::leerMuchos(Paciente reg[], int cantidad){
    FILE *pArchivo;
    pArchivo=fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo==NULL){
        return false;
    }

    fread(reg,sizeof(Paciente), cantidad, pArchivo);

    fclose(pArchivo);

    return true;
}

int PacienteArchivo::getNuevoID(){
    return getCantidadRegistros()+1;
}

bool PacienteArchivo::esPacienteActivo(int IDPaciente){
    int pos=Buscar(IDPaciente);
    if(pos==-1){
        return false;
    }
    Paciente registro=Leer(pos);
    //devuelve true=activado, false=no activado
    return registro.getEstado();
}
