#include <iostream>
#include "rlutil.h"
#include "MenuAdministrador.h"
#include "MenuRecepcionista.h"

using namespace std;

int main(){
    int opcion;
//mini menu para ir probando las cosas, luego lo sacamos xd
    do {
        cout<<"=================================="<<endl;
        cout<<"    SISTEMA DE GESTION DE TURNOS  "<<endl;
        cout<<"=================================="<<endl;
        cout<<"1. Ingresar como Administrador"<<endl;
        cout<<"2. Ingresar como Recepcionista"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion;
        cin.ignore();  // limpia el \n del buffer

        switch (opcion) {
            case 1: {
                MenuAdministrador menu;
                menu.menuAdministrador();
                break;
            }
            case 2: {
                MenuRecepcionista menu;
                menu.menuRecepcionista();
                break;
            }
            case 0:
                cout<<"Saliendo del sistema..."<<endl;
                break;
            default:
                cout<<"Opcion invalida. Intente nuevamente."<<endl;
                rlutil::anykey();
        }

        cout<<endl;
    } while (opcion != 0);
    return 0;
}

/*int main(){
    //int opcion;
               MenuRecepcionista menu;
                menu.menuRecepcionista();
              // MenuAdministrador menu;
               //menu.menuAdministrador();
    return 0;
}*/

