#include "UsuarioManager.h"
#include "MenuRecepcionista.h"
#include "MenuAdministrador.h"
#include "MenuMedico.h"
#include "MedicoManager.h"
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

    char nombre[50]= {}, contrasenia[50]= {};

    cout<<"======Login======"<<endl;
    cout<<"Usuario: ";
    cin.getline(nombre, 50);
    cout<<"Contrasenia: ";
    cin.getline(contrasenia, 50);
    /*// DEBUG - ver códigos ASCII
    cout << "DEBUG usuario ingresado: ";
    for(int i=0; i < strlen(nombre); i++){
        cout << (int)nombre[i] << " ";
    }
    cout << endl;

    cout << "DEBUG contraseña ingresada: ";
    for(int i=0; i < strlen(contrasenia); i++){
        cout << (int)contrasenia[i] << " ";
    }
    cout << endl;
*/
    for(int i=0; i<cantidad; i++)
    {
        Usuario usuario=archiU.Leer(i);
        if(strcmp(usuario.getNombreUsuario(), nombre)==0&&
           strcmp(usuario.getContrasenia(), contrasenia)==0&&
           usuario.getEstado()==true)
        {
            cout<<"Acceso concedido"<<endl;
            system ("pause");
            system("cls");
            int tipoRol=usuario.getRol().getRol();
            if(tipoRol==-1)
            {
                menuA.menuAdministrador();
            }
            else if(tipoRol==0)
            {
                menuR.menuRecepcionista();
            }
            else
            {
                menuM.menuMedico();
            }
            encontrado=true;
            break;
        }
    }
    if(!encontrado)
    {
        cout<<"Usuario y/o contrasenia incorrecta"<<endl;
    }
    system ("pause");
    system("cls");
}

bool UsuarioManager::VerificarLoginDuplicados(const char *nombre, const char *contrasenia){
    int cantidad=_archivo.getCantidadRegistros();
    for(int i=0; i<cantidad; i++){
        Usuario usuario=_archivo.Leer(i);
        if(strcmp(usuario.getNombreUsuario(), nombre)==0&&
           strcmp(usuario.getContrasenia(), contrasenia)==0){
            return true;
        }
    }
    return false;
}

void UsuarioManager::cargarUsuario(){
    char nombre[50]= {}, constrasenia[50]= {};
    int tipoRol;

    cout<<"======CARGA DE NUEVO USUARIO======"<<endl;
    cout<<"Nombre del usuario: ";
    cin.getline(nombre, 50);
    cout<<"Contrasenia: ";
    cin.getline(constrasenia, 50);
    cout<<"Tipo de Rol: ";
    cin>>tipoRol;
    cin.ignore();

    if(VerificarLoginDuplicados(nombre, constrasenia)){
        cout<<"Ya existe un usuario con ese mismo nombre y contrasenia"<<endl;
        system ("pause");
        system("cls");
        return;
    }

    Usuario usuario;
    const char *nombreRol;
    if(tipoRol==-1){
        nombreRol="Administrador";
    }else if(tipoRol==0){
        nombreRol="Recepcionista";
    }else{
        nombreRol="Medico";
        cout<<endl;
        MedicoManager medicM;
        int idMedico=medicM.cargarMedico(); //se carga directo
        if(idMedico==-1){
            cout<<"No se pudo cargar correctamente el id Medico"<<endl;
            system ("pause");
            system("cls");
            return;
        }
        usuario.setIDMedico(idMedico);
    }
    Rol rol(tipoRol, nombreRol);

    usuario.setNombreUsuario(nombre);
    usuario.setContrasenia(constrasenia);
    usuario.setTipoRol(rol);
    usuario.setEstado(true);

    if(_archivo.guardar(usuario)){
        cout<<"Usuario guardado con exito"<<endl;
    }else{
        cout<<"Error al guardar el usuario"<<endl;
    }
    system ("pause");
    system("cls");
}


void UsuarioManager::mostrarUsuario()
{
    int cantidad = _archivo.getCantidadRegistros();
    if (cantidad == 0)
    {
        cout << "No hay Usuarios cargados." << endl;
        system ("pause");
        system("cls");
        return;
    }

    Usuario* vecUsuarios = new Usuario[cantidad];
    _archivo.leerMuchos(vecUsuarios, cantidad);

    cout << "------- LISTADO DE USUARIOS -------" << endl;
    for (int i = 0; i < cantidad; i++)
    {
        cout << "----------------------------------" << endl;
        cout << "Nombre de Usuario: " << vecUsuarios[i].getNombreUsuario() << endl;
        cout << "Contrasenia: " << vecUsuarios[i].getContrasenia() << endl;
        cout << "Rol: ";
        if (vecUsuarios[i].getRol().getRol() < 0)
        {
            cout << "Administrador" << endl;
        }
        else if (vecUsuarios[i].getRol().getRol()==0)
            {
                cout << "Recepcionista" << endl;
            }

        else
        {
            cout << " Medico " << endl;
        };
        cout<<endl;


        cout << "Estado: ";
        if (vecUsuarios[i].getEstado())
        {
            cout << "Activo" << endl;
        }
        else
        {
            cout << "Inactivo" << endl;
        }
        cout << "----------------------------------" << endl;
    }

    delete[] vecUsuarios;
    system ("pause");
    system("cls");
}
