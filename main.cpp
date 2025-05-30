#include <iostream>
#include "rlutil.h"
#include "MenuAdministrador.h"
#include "MenuRecepcionista.h"
#include "MenuMedico.h"

using namespace std;

static void showItem(const char* text, int posx, int posy, bool selected){
    if(selected){
        rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
    } else{
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    }
    rlutil::locate(posx, posy);
    cout<<text<<endl;
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

//mini menu para ir probando las cosas, luego lo sacamos xd

int main(){
    int y=0;
    int opc=1;
     bool salir = false;
     do{
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(50, 3);
        cout<<" SISTEMA DE GESTION DE TURNOS ";
        showItem(" 1. INGRESAR COMO ADMINISTRADOR ", 50, 5, y==0);
        showItem(" 2. INGRESAR COMO RECEPCIONISTA ", 50, 6, y==1);
        showItem(" 3. INGRESAR COMO MEDICO ", 50, 7, y==2);
        showItem(" 4. SALIR", 50, 8, y==3);

        rlutil::locate(48, 5 + y);
        cout<<(char)175;

        switch(rlutil::getkey()){
        case 14: //UP
            rlutil::locate(48, 5 + y);
            cout<<" "<<endl;
            y--;
            if(y<0){
                y=0;
            }
        break;
        case 15: //DOWN
            rlutil::locate(48, 5 + y);
            cout<<" "<<endl;
            y++;
            if(y>3){
                y=3;
            }
        break;
        case 1: //ENTER
            rlutil::cls();
            switch(y){
            case 0:{
                MenuAdministrador menu;
                salir =(menu.menuAdministrador()==0);
                break;
            }
            case 1:{
                MenuRecepcionista menu;
                salir = (menu.menuRecepcionista() == 0);
                break;
            }
            case 2:{
                MenuMedico menu;
                salir = (menu.menuMedico() == 0);
                break;
            }
            case 3:opc=0;
                    break;
            default:
                    break;
            }
            if(opc!=0 && !salir){
                rlutil::anykey();
            }
            break;
        default:
            break;
        }
     }while(opc!=0);

    return 0;
}



