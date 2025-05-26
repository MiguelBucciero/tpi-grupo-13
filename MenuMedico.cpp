#include<iostream>
#include "MenuMedico.h"

using namespace std;

int MenuMedico::menu(){
int opc;
 while(true){
    system("cls");
    cout<<"- MENU MEDICO - "<<endl;
    cout<<"- 1.Ver turnos asignados "<<endl;
    cout<<"- 2.Buscar turnos por fecha "<<endl;
    cout<<"- 3.Ver historial de turnos atendidos "<<endl;
    cout<<"- 4.Buscar pacientes por DNI asociado al turno "<<endl;
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
