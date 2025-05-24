#include "EspecialidadArchivo.h"

using namespace std;

EspecialidadArchivo::EspecialidadArchivo(std::string nombreArchivo){
    _nombreArchivo=nombreArchivo;
}
bool EspecialidadArchivo::guardar(Especialidad registro){
    bool resultado;
    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(),"ab");

    if(pFile == nullptr){
        return false;
    }

    resultado=fwrite(&registro,sizeof(Especialidad), 1, pFile);

    fclose(pFile);

    return resultado;
}
bool EspecialidadArchivo::Guardar(Especialidad registro, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Especialidad) * posicion, SEEK_SET);
    bool ok = fwrite(&registro, sizeof(Especialidad), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int EspecialidadArchivo::Buscar(int IDEspecialidad){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Especialidad registro;
    int i = 0;
    while(fread(&registro, sizeof(Especialidad), 1, pArchivo)){
        if(registro.getIDEspecialidad() == IDEspecialidad){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Especialidad EspecialidadArchivo::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Especialidad();
    }
    Especialidad registro;
    fseek(pArchivo, sizeof(Especialidad) * posicion, SEEK_SET);
    fread(&registro, sizeof(Especialidad), 1, pArchivo);
    fclose(pArchivo);
    return registro;
}

int EspecialidadArchivo::getCantidadRegistros(){
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return 0;
    }

    fseek(pArchivo, 0, SEEK_END);

    int cantidadRegistros = ftell(pArchivo) / sizeof(Especialidad);

    fclose(pArchivo);

    return cantidadRegistros;
}

void EspecialidadArchivo::Leer(int cantidadRegistros, Especialidad *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Especialidad), 1, pArchivo);
    }
    fclose(pArchivo);
}

bool EspecialidadArchivo::leerMuchos(Especialidad reg[], int cantidad){
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return false;
    }

    fread(reg,sizeof(Especialidad), cantidad, pArchivo);

    fclose(pArchivo);

    return true;
}
