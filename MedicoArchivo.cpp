#include "MedicoArchivo.h"

using namespace std;


MedicoArchivo::MedicoArchivo(std::string nombreArchivo){
    _nombreArchivo=nombreArchivo;
}

bool MedicoArchivo::guardar(Medico registro){
    bool resultado;
    FILE *pFile;
    pFile=fopen(_nombreArchivo.c_str(),"ab");

    if(pFile==nullptr){
        return false;
    }

    resultado=fwrite(&registro,sizeof(Medico), 1, pFile);

    fclose(pFile);

    return resultado;
}
bool MedicoArchivo::guardar(Medico registro, int posicion){
    bool resultado;
    FILE *pArchivo;
    pArchivo=fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo==NULL){
        return false;
    }

    fseek(pArchivo, sizeof(Medico) * posicion, SEEK_SET);
    resultado=fwrite(&registro, sizeof(Medico), 1, pArchivo);

    fclose(pArchivo);

    return resultado;
}

int MedicoArchivo::Buscar(int IDMedico){
    FILE *pArchivo;
    pArchivo=fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo==NULL){
        return -1;
    }

    Medico registro;
    int i = 0;
    while(fread(&registro, sizeof(Medico), 1, pArchivo)){
        if(registro.getIDMedico()==IDMedico){
            fclose(pArchivo);
            return i;
        }
        i++;
    }

    fclose(pArchivo);

    return -1;
}

Medico MedicoArchivo::Leer(int posicion){
    FILE *pArchivo;
    pArchivo=fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo==NULL){
        return Medico();
    }

    Medico registro;
    fseek(pArchivo, sizeof(Medico) * posicion, SEEK_SET);
    if(fread(&registro, sizeof(Medico), 1, pArchivo)!=1){
        fclose(pArchivo);
        return Medico(); //o marca error
    }

    fclose(pArchivo);

    return registro;
}

int MedicoArchivo::getCantidadRegistros(){
    FILE *pArchivo;
    pArchivo=fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo==NULL){
        return 0;
    }

    fseek(pArchivo, 0, SEEK_END);

    int cantidadRegistros=ftell(pArchivo)/sizeof(Medico);

    fclose(pArchivo);

    return cantidadRegistros;
}

bool MedicoArchivo::leerMuchos(Medico reg[], int cantidad){
    FILE *pArchivo;
    pArchivo=fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo==NULL){
        return false;
    }

    fread(reg,sizeof(Medico), cantidad, pArchivo);

    fclose(pArchivo);

    return true;
}

int MedicoArchivo::getNuevoID(){ //id activo
    int cantidad=getCantidadRegistros();
    int maxID=0;
    Medico medico;
    for(int i=0; i<cantidad; i++){
        medico=Leer(i);
        if(medico.getIDMedico()>maxID){
            maxID=medico.getIDMedico();
        }
    }
    return maxID+1;
}

bool MedicoArchivo::esMedicoActivo(int IDMedico){
    int pos=Buscar(IDMedico);
    if(pos==-1){
        return false;
    }
    Medico registro=Leer(pos);
    //devuelve true=activado, false=no activado
    return registro.getEstado();
}
