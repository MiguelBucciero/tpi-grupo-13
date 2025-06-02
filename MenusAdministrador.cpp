#include<iostream>
#include<cstdlib>
#include "rlutil.h"
#include "MenuAdministrador.h"
#include "UsuarioManager.h"


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

int MenuAdministrador::menuAdministrador() {
    int opc=1;
    int y=0;
    int salir;
    do{
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(50, 3);
        cout<<" MENU ADMINISTRADOR ";
        showItem(" 1. CARGAR NUEVO USUARIO ", 50, 5, y==0);
        showItem(" 2. ELIMINAR USUARIO ", 50, 6, y==1);
        showItem(" 3. LISTAR USUARIOS ", 50, 7, y==2);
        showItem(" 4. INFORMES ", 50, 8, y==3);
        showItem(" 5. CARGAR ESPECIALIDAD ", 50, 9, y==4);
        showItem(" 6. LISTAR ESPECIALIDAD ", 50, 10, y==5);
       // showItem(" 7. CARGAR MEDICO ", 50, 11, y==6);
        showItem(" 7. LISTAR MEDICOS ", 50, 11, y==6);
        showItem(" 0. CERRAR SESION ", 50, 12, y==7);
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
            if(y>7){
                y=7;
            }
        break;
        case 1: //ENTER
            rlutil::cls();
            switch(y){
            case 0: _usuarioManager.cargarUsuario();
                break;
            case 1:
                break;
            case 2: _usuarioManager.mostrarUsuario();
                break;
            case 3:
                salir = menuInformesAdministrador();
                if(salir != 0){
                    rlutil::anykey();
                }
                break;
            case 4:
               _espManager.cargarEspecialidad();
                break;
            case 5:
                _espManager.mostrarEspecialidad();
                break;
            //case 6:
              //  _medicoManger.cargarMedico();
               // break;
            case 6:
                _medicoManger.mostrarMedico();
                break;
            case 7:opc=0;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
     }while(opc!=0);
     return 0;
}

int MenuAdministrador::menuInformesAdministrador(){
    int y=0;
    int opc=1;
    do{
        rlutil::cls();
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(55, 3);
        cout<<" - INFORMES ADMINISTRADOR - ";
        showItem(" 1. CANTIDAD DE TURNOS POR MEDICO ", 50, 5, y==0);
        showItem(" 2. CANTIDAD DE TURNOS POR PACIENTE ", 50, 6, y==1);
        showItem(" 3. CANTIDAD DE TURNOS CANCELADOS POR MES ", 50, 7, y==2);
        showItem(" 4. CANTIDAD DE TURNOS REPROGRAMADOS POR MES ", 50, 8, y==3);
        showItem(" 5. CANTIDAD DE TURNOS POR ESPECIALIDAD ", 50, 9, y==4);
        showItem(" 6. CANTIDAD DE USURIOS ACTIVOS ", 50, 10, y==5);
        showItem(" 0. VOLVER AL MENU ANTERIOR ", 50, 11, y==6);

        rlutil::locate(48, 5 + y);
        cout<<(char)175;

        switch(rlutil::getkey()){
        case 14: //UP
            rlutil::locate(53, 5 + y);
            cout<<" "<<endl;
            y--;
            if(y<0){
                y=0;
            }
        break;
        case 15: //DOWN
            rlutil::locate(53, 5 + y);
            cout<<" "<<endl;
            y++;
            if(y>6){
                y=6;
            }
        break;
        case 1: //ENTER
            rlutil::cls();
            switch(y){
            case 0:
                    break;
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
            case 6: opc=0;
                    break;
            default:
                    break;
            }
            if(opc!=0){
                rlutil::anykey();
            }
            break;
        }
    }while(opc!=0);
    return 0;
}
