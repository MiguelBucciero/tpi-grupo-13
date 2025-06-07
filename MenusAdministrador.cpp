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
        system("cls");
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(50, 3);
        cout<<" MENU ADMINISTRADOR ";
        showItem(" 1. CARGAR NUEVO USUARIO ", 50, 5, y==0);
        showItem(" 2. MODIFICAR USUARIO ", 50, 6, y==1) ;
        showItem(" 3. ELIMINAR USUARIO ", 50, 7, y==2);
        showItem(" 4. LISTAR USUARIOS ", 50, 8, y==3);
        showItem(" 5. INFORMES ", 50, 9, y==4);
        showItem(" 6. CARGAR ESPECIALIDAD ", 50, 10, y==5);
        showItem(" 7. MODIFICAR ESPECIALIDAD ", 50, 11, y==6);
        showItem(" 8. ELIMINAR ESPECIALIDAD ", 50, 12, y==7);
        showItem(" 9. LISTAR ESPECIALIDAD ", 50, 13, y==8);
        showItem(" 10. MODIFICAR MEDICO ", 50, 14, y==9);
        showItem(" 11. ELIMINAR MEDICO ", 50, 15, y==10);
        showItem(" 12. LISTAR MEDICOS ", 50, 16, y==11);
        showItem(" 0. CERRAR SESION  ", 50, 17, y==12);
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
                if(y>12){
                    y=12;
                }
            break;
            case 1: //ENTER
                rlutil::cls();
                switch(y){
                case 0: _usuarioManager.cargarUsuario();
                    break;
                case 1:
                     _usuarioManager.modificarUsuario();
                    break;
                case 2:
                    _usuarioManager.DarBajaUsuario();
                    break;
                case 3: _usuarioManager.mostrarUsuario();
                    break;
                case 4:
                    salir = menuInformesAdministrador();
                    if(salir != 0){
                        rlutil::anykey();
                    }
                    break;
                case 5:
                   _espManager.cargarEspecialidad();
                    break;
                case 6: _espManager.ModificarEspecialidad();
                    break;
                case 7: _espManager.DarBajaEspecialidad();
                    break;
                case 8:
                    _espManager.mostrarEspecialidad();
                    break;
                case 9:
                    //FALTA HACER EL MODIFICAR MEDICO Flor
                    break;
                case 10:
                    //FALTA HACER EL ELIMINAR MEDICO (BAJA LOGICA) Flor
                    break;
                case 11:
                    _medicoManger.mostrarMedico();
                    break;
                case 12:
                    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    rlutil::setColor(rlutil::COLOR::YELLOW);
                    rlutil::locate(50, 12);
                    cout << "Cerrando sesion..." << endl;
                    rlutil::setColor(rlutil::COLOR::WHITE);
                    rlutil::anykey();
                    opc = 0;
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
        showItem(" 5. CANTIDAD DE TURNOS POR ESPECIALIDAD EN EL ANIO ", 50, 9, y==4);//lo cambie un poco porque era igual que el de menu recepcionista
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
                //Miguel
                    break;
            case 1:
                //Miguel
                    break;
            case 2:
                //Miguel
                    break;
            case 3:
                _turnoManager.CantidadTurnosReprogramadosMes();
                    break;
            case 4:
                _turnoManager.CantidadTurnosPorEspecialidadAdmin(2025);
                break;
            case 5:
                //CANTIDAD DE USURIOS ACTIVOS
                _usuarioManager.CantidadUsuariosActivos();
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
