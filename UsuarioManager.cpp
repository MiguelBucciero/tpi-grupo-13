#include "UsuarioManager.h"
#include "MenuRecepcionista.h"
#include "MenuAdministrador.h"
#include "MenuMedico.h"
#include <iostream>
#include <cstring>

using namespace std;

void UsuarioManager::login(){
    UsuarioArchivo archiU("Usuarios.dat");
    int cantidad=archiU.getCantidadRegistros();
    MenuRecepcionista menuR;
    MenuAdministrador menuA;
    MenuMedico menuM;
    bool encontrado=false;

    char nombre[50]={}, contrasenia[50]={};

    cout<<"======Login======"<<endl;
    cout<<"Usuario: ";
    cin.getline(nombre, 50);
    cout<<"Contrasenia: ";
    cin.getline(contrasenia, 50);

    for(int i=0; i<cantidad; i++){
        Usuario usuario=archiU.Leer(i);
        if(strcmp(usuario.getNombreUsuario(), nombre)==0&&strcmp(usuario.getContrasenia(), contrasenia)==0&&usuario.getEstado()==true){
            cout<<"Acceso concedido"<<endl;
            system ("pause");
            system("cls");
            int tipoRol=usuario.getRol().getRol();
            if(tipoRol==-1){
                menuA.menuAdministrador();
            }else if(tipoRol==0){
                menuR.menuRecepcionista();
            }else{
            menuM.menuMedico();
            }
            encontrado=true;
            break;
        }
    }
    if(!encontrado){
        cout<<"Usuario y/o contrasenia incorrecta"<<endl;
    }
    system ("pause");
    system("cls");
}

void UsuarioManager::cargarUsuario(){
    char nombre[50]={}, constrasenia[50]={};
    int tipoRol;

    cout<<"======CARGA DE NUEVO USUARIO======"<<endl;
    cout<<"Nombre del usuario: ";
    cin.getline(nombre, 50);
    cout<<"Contrasenia: ";
    cin.getline(constrasenia, 50);
    cout<<"Tipo de Rol: ";
    cin>>tipoRol;
    cin.ignore();

    const char *nombreRol;
    if(tipoRol==-1){
        nombreRol="Administrador";
    }else if(tipoRol==0){
        nombreRol="Recepcionista";
    }else{
        nombreRol="Medico";
    }
    Rol rol(tipoRol, nombreRol);

    Usuario usuario(nombre, constrasenia, rol, true);
    if(_archivo.guardar(usuario)){
        cout<<"Usuario guardado con exito"<<endl;
    }else{
        cout<<"Error al guardar el usuario"<<endl;
    }
    system ("pause");
    system("cls");
}
