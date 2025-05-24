#include<iostream>
#include<cstdlib>
#include "MenuAdministrador.h"


using namespace std;

int MenuAdministrador::menuAdministrador() {
int opc;
 while(true){
    system("cls");
    cout<<"- MENU ADMINISTRADOR - "<<endl;
    cout<<"- 1.Cargar nuevo usuario "<<endl;
    cout<<"- 2.Eliminar usuario "<<endl;
    cout<<"- 3.Listado de usuarios del sistema registrados "<<endl;
    cout<<"- 4.Informes"<<endl;
    cout<<"- 5.Cargar Especialidad "<<endl;
    cout<<"- 6.Mostrar Especialidad "<<endl;
    cout<<"- 0.Cerrar sesion "<<endl;
    cout<<endl;
    cout<<"Seleccione la opcion que busca..."<<endl;
    cin>>opc;
    system("cls");
    switch(opc){
    case 1: menuInformesAdministrador();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4: menuInformesAdministrador();
        break;
    case 5:;_espManager.cargarEspecialidad();
        break;
    case 6:_espManager.mostrarEspecialidad();
        break;
    case 0: cout<<"Cerrando sesion"<<endl;
        return 0;
    default:
        cout<<"Opcion incorrecta. Vuelva a intentar"<<endl;
        break;
    }
    cout<<endl;
    system("pause");
 }
}

int MenuAdministrador::menuInformesAdministrador(){
int opc;
while(true){
    system("cls");
    cout<<" - INFORMES ADMINISTRADOR - "<<endl;
    cout<<"- 1.Cantidad de turnos por medico"<<endl;
    cout<<"- 2.Cantidad de turnos por paciente"<<endl;
    cout<<"- 3.Cantidad de turnos cancelados por mes"<<endl;
    cout<<"- 4.Cantidad de turnos reprogrados por mes"<<endl;
    cout<<"- 5.Cantidad de turnos por especialidad"<<endl;
    cout<<"- 6.Cantidad de usuarios activos"<<endl;
    cout<<"- 0.Volver al menu anterior"<<endl;
    cout<<endl;
    cout<<"Seleccione la opcion que busca..."<<endl;
    cin>>opc;
    system("cls");
    switch(opc) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 0: cout<<"Volviendo al menu principal"<<endl;
        return 0;
    default:
        cout<<"Opcion incorrecta"<<endl;
            break;
        }
        cout<<endl;
        system("pause");
}
}
