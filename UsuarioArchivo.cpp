#include "UsuarioArchivo.h"
#include "UsuarioManager.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

UsuarioArchivo::UsuarioArchivo(std::string nombreArchivo){
    _nombreArchivo=nombreArchivo;
}

//guardar al final del archivo
bool UsuarioArchivo::guardar(Usuario registro){
   bool resultado;
    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(),"ab");

    if(pFile==nullptr){
        return false;
    }

    resultado=fwrite(&registro,sizeof(Usuario), 1, pFile);

    fclose(pFile);

    return resultado;
}

bool UsuarioArchivo::guardar(Usuario registro, int posicion){
    bool resultado;
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == NULL){
        return false;
    }

    fseek(pArchivo, sizeof(Usuario) * posicion, SEEK_SET);
    resultado = fwrite(&registro, sizeof(Usuario), 1, pArchivo);

    fclose(pArchivo);

    return resultado;
}

int UsuarioArchivo::Buscar(const char* nombreUsuario){
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return -1;
    }

    Usuario registro;
    int i = 0;
    while(fread(&registro, sizeof(Usuario), 1, pArchivo)){
        if(strcmp(registro.getNombreUsuario(), nombreUsuario)==0){
            fclose(pArchivo);
            return i;
        }
        i++;
    }

    fclose(pArchivo);

    return -1;
}

Usuario UsuarioArchivo::Leer(int posicion){
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return Usuario();
    }

    Usuario registro;
    fseek(pArchivo, sizeof(Usuario) * posicion, SEEK_SET);
    fread(&registro, sizeof(Usuario), 1, pArchivo);

    fclose(pArchivo);

    return registro;
}

int UsuarioArchivo::getCantidadRegistros(){
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return 0;
    }

    fseek(pArchivo, 0, SEEK_END);

    int cantidadRegistros = ftell(pArchivo) / sizeof(Usuario);

    fclose(pArchivo);

    return cantidadRegistros;
}

bool UsuarioArchivo::leerMuchos(Usuario reg[], int cantidad){
    FILE *pArchivo;
    pArchivo=fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo==NULL){
        return false;
    }

    fread(reg,sizeof(Usuario), cantidad, pArchivo);

    fclose(pArchivo);

    return true;
}



