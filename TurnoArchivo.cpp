#include "TurnoArchivo.h"
#include "TurnoManager.h"
#include <iostream>

using namespace std;

TurnoArchivo::TurnoArchivo(std::string nombreArchivo){
    _nombreArchivo=nombreArchivo;
}
bool TurnoArchivo::guardar(Turno registro){
    bool resultado;
    FILE *pFile;
    pFile=fopen(_nombreArchivo.c_str(),"ab");

    if(pFile==nullptr){
        return false;
    }

    resultado=fwrite(&registro,sizeof(Turno), 1, pFile);

    fclose(pFile);

    return resultado;
}
bool TurnoArchivo::guardar(Turno registro, int posicion){
    bool resultado;
    FILE *pArchivo;
    pArchivo=fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo==NULL){
        return false;
    }

    fseek(pArchivo, sizeof(Turno) * posicion, SEEK_SET);
    resultado = fwrite(&registro, sizeof(Turno), 1, pArchivo);

    fclose(pArchivo);

    return resultado;
}

int TurnoArchivo::Buscar(int IDTurno){
    FILE *pArchivo;
    pArchivo=fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo==NULL){
        return -1;
    }

    Turno registro;
    int i=0;
    while(fread(&registro, sizeof(Turno), 1, pArchivo)){
        if(registro.getIDTurno()==IDTurno){
            fclose(pArchivo);
            return i;
        }
        i++;
    }

    fclose(pArchivo);

    return -1;
}

Turno TurnoArchivo::Leer(int posicion){
    FILE *pArchivo;
    pArchivo=fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo==NULL){
        return Turno();
    }

    Turno registro;
    fseek(pArchivo, sizeof(Turno) * posicion, SEEK_SET);
    fread(&registro, sizeof(Turno), 1, pArchivo);

    fclose(pArchivo);

    return registro;
}

int TurnoArchivo::getCantidadRegistros(){
    FILE *pArchivo;
    pArchivo=fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo==NULL){
        return 0;
    }

    fseek(pArchivo, 0, SEEK_END);

    int cantidadRegistros=ftell(pArchivo)/sizeof(Turno);

    fclose(pArchivo);

    return cantidadRegistros;
}

bool TurnoArchivo::leerMuchos(Turno reg[], int cantidad){
    FILE *pArchivo;
    pArchivo=fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo==NULL){
        return false;
    }

    fread(reg, sizeof(Turno), cantidad, pArchivo);

    fclose(pArchivo);

    return true;
}

int TurnoArchivo::getNuevoID(){
    return getCantidadRegistros()+1;
}

bool TurnoArchivo::existeTurno(int idMedico, Fecha fecha, Hora hora){
    FILE *pArchivo;
    pArchivo=fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo==NULL){
        return false;
    }

    Turno turno;
    while(fread(&turno, sizeof(Turno), 1, pArchivo)){
        if(turno.getIDMedico()==idMedico&&turno.getFechaTurno().esIgual(fecha)&&turno.getHoraTurno().esIgual(hora)&&(turno.getEstado()==1 || turno.getEstado()==3)){
            fclose(pArchivo);
            return true; //existe un turno para medico, con la misma fecha y hora.
        }
    }
    fclose(pArchivo);
    return false; //no se encontro turno superpuesto
}

bool TurnoArchivo::modificar(Turno turno, int pos){
    FILE *pArchivo;
    pArchivo=fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo==NULL){
        return false;
    }

    fseek(pArchivo, sizeof(Turno)*pos, SEEK_SET);
    bool Escribir=fwrite(&turno, sizeof(turno),1, pArchivo);

    fclose(pArchivo);
    return Escribir;
}
