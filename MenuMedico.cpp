#include<iostream>
#include "rlutil.h"
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

int MenuMedico::menuMedico(){
    int y=0;
    int opc=1;
     do{
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(50, 3);
        cout<<" MENU MEDICO ";
        showItem(" 1. VER TURNOS ASIGNADOS ", 50, 5, y==0);
        showItem(" 2. BUSCAR TURNOS POR FECHAS ", 50, 6, y==1);
        showItem(" 3. VER HISTORIAL DE TURNOS ATENDIDOS ", 50, 7, y==2);
        showItem(" 4. BUSCAR PACIENTE POR DNI ASOCIADO AL TURNO ", 50, 8, y==3);
        showItem(" 0. CERRAR SESION ", 50, 9, y==4);

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
            if(y>4){
                y=4;
            }
        break;
        case 1: //ENTER
            if (y == 4) {
                    opc = 0;
                    rlutil::cls();
                } else {
                    rlutil::cls();
                    switch (y) {
                        case 0: /* Ver turnos asignados */
                            break;
                        case 1: /* Buscar turnos por fechas */
                            break;
                        case 2: /* Historial de turnos atendidos */
                            break;
                        case 3: /* Buscar paciente por DNI */
                            break;
                    }
                    rlutil::anykey();
                }
                break;
            default:
                break;
        }
     }while(opc!=0);

     return 0;
}
