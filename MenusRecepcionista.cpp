#include<iostream>
#include<cstdlib>
#include "MenuRecepcionista.h"

using namespace std;



int MenuRecepcionista::menuRecepcionista() {
int opc;
 while(true){
    system("cls");
    cout<<"- MENU RECEPCIONISTA - "<<endl;
    cout<<"- 1.Registrar paciente "<<endl;
    cout<<"- 2.Asignar nuevo turno "<<endl;
    cout<<"- 3.Reprogramar turno "<<endl;
    cout<<"- 4.Cancelar turno "<<endl;
    cout<<"- 5.Consultas "<<endl;
    cout<<"- 6.Informes "<<endl;
    cout<<"- 0.Cerrar sesion "<<endl;
    cout<<endl;
    cout<<"Seleccione la opcion que busca..."<<endl;
    cin>>opc;
    system("cls");
    switch(opc){
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5: menuConsultasRecepcionista();
        break;
    case 6: menuInformesRecepcionista();
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

int MenuRecepcionista::menuConsultasRecepcionista(){
int opc;
while(true){
    system("cls");
    cout<<" - CONSULTAS RECEPCIONISTA - "<<endl;
    cout<<"- 1.Buscar turnos por estado (activo, cancelado, reprogramado, no asistido)"<<endl;
    cout<<"- 2.Buscar medicos por especialidad"<<endl;
    cout<<"- 3.Ver turnos del dia"<<endl;
    cout<<"- 4.Ver turnos de la semana"<<endl;
    cout<<"- 0.Volver al menu anterior"<<endl;
    cout<<endl;
    cout<<"Seleccione la opcion que busca..."<<endl;
    cin>>opc;
    system("cls");
    switch(opc) {
    case 1: cout<<"Hola"<<endl;
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
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

int MenuRecepcionista::menuInformesRecepcionista(){
int opc;
while(true){
    system("cls");
    cout<<" - INFORMES RECEPCIONISTA - "<<endl;
    cout<<"- 1.Cantidad de por especialidad"<<endl;
    cout<<"- 2.Cantidad de turnos no asistidos por medico"<<endl;
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
