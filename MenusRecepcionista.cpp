#include<iostream>
#include<cstdlib>
#include "rlutil.h"
#include "MenuRecepcionista.h"
#include "PacienteManager.h"
#include "Paciente.h"
#include "TurnoManager.h"
#include "TurnoArchivo.h"
#include "MedicoManager.h"
#include "Medico.h"

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

int MenuRecepcionista::menuRecepcionista() {
    int y=0;
    int opc=1;
    int salir;

     do{
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(50, 3);
        cout<<" MENU RECEPCIONISTA ";
        showItem(" 1. REGISTRAR PACIENTE ", 50, 5, y==0);
        showItem(" 2. LISTAR PACIENTES ", 50, 6, y==1);
        showItem(" 3. MODIFICAR PACIENTE ", 50, 7, y==2);
        showItem(" 4. DAR DE BAJA PACIENTE ", 50, 8, y==3);
        showItem(" 5. ASIGNAR NUEVO TURNO ", 50, 9, y==4);
        showItem(" 6. REPROGRAMAR TURNO ", 50, 10, y==5);
        showItem(" 7. CANCELAR TURNO ", 50, 11, y==6);
        showItem(" 8. TURNO NO ASISTIDO ", 50, 12, y==7);
        showItem(" 9. CONSULTAS ", 50, 13, y==8);
        showItem(" 10. INFORMES ", 50, 14, y==9);
        showItem(" 11. LISTAR TURNOS ", 50, 15, y==10);
        showItem(" 0. CERRAR SESION ", 50, 16, y==11);

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
            if(y>11){
                y=11;
            }


        break;
        case 1: //ENTER
            rlutil::cls();
            switch(y){
            case 0:
                _pacienteManager.cargarPaciente();
                    break;
            case 1:
                _pacienteManager.mostrarPaciente();
                    break;
            case 2:
///                _pacienteManager.modificarPaciente();
                    break;
            case 3:
                _pacienteManager.DarBajaPaciente();
                    break;
            case 4:
                _turnoManager.cargarTurno();
                    break;
            case 5:
                _turnoManager.reprogramarTurno();
                    break;
            case 6:
                _turnoManager.cancelarTurno();
                    break;
            case 7:
               _turnoManager.TurnoNoAsistido();
                    break;
            case 8:
                salir = menuConsultasRecepcionista();
                if(salir != 0){
                    rlutil::anykey();
                }
                break;
            case 9:
                salir = menuInformesRecepcionista();
                if(salir != 0){
                    rlutil::anykey();
                }
                break;
            case 10:
                _turnoManager.mostrarTurno();
                    break;
            case 11:
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

int MenuRecepcionista::menuConsultasRecepcionista(){
    int y=0;
    int opc=1;
    do{
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(50, 3);
        cout<<" - CONSULTAS RECEPCIONISTA - ";
        showItem(" 1. BUSCAR TURNO POR ESTADO (ACTIVO, CANCELADO, REPROGRAMADO, NO ASISTIDO, ASISTIDO) ", 30, 5, y==0);
        showItem(" 2. BUSCAR MEDICOS POR ESPECIALIDAD ", 30, 6, y==1);
        showItem(" 3. VER TURNOS DEL DIA ", 30, 7, y==2);
        showItem(" 4. VER TURNOS DE LA SEMANA ", 30, 8, y==3);
        showItem(" 0. VOLVER AL MENU ANTERIOR ", 30, 9, y==4);

        rlutil::locate(28, 5 + y);
        cout<<(char)175;

        switch(rlutil::getkey()){
        case 14: //UP
            rlutil::locate(28, 5 + y);
            cout<<" "<<endl;
            y--;
            if(y<0){
                y=0;
            }
        break;
        case 15: //DOWN
            rlutil::locate(28, 5 + y);
            cout<<" "<<endl;
            y++;
            if(y>4){
                y=4;
            }
        break;
        case 1: //ENTER
            rlutil::cls();
            switch(y){
            case 0:
                _turnoManager.BuscarTurnoEstado();
                    break;
            case 1:
                _medicoManager.buscarMedicoPorEspecialidad();
                    break;
            case 2:
               _turnoManager.TurnosDelDia();
                    break;
            case 3:
               _turnoManager.TurnosDeLaSemana();
                    break;
            case 4: opc=0;
                    break;
            default:
                    break;
            }
            break;
        }
    }while(opc!=0);
    return 0;
}

int MenuRecepcionista::menuInformesRecepcionista(){
    int y=0;
    int opc=1;
    do{
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(55, 3);
        cout<<" - INFORMES RECEPCIONISTA - ";
        showItem(" 1. CANTIDAD TURNOS POR ESPECIALIDAD ", 50, 5, y==0);
        showItem(" 2. CANTIDAD DE TURNOS NO ASISTIDOS POR MEDICO ", 50, 6, y==1);
        showItem(" 0. VOLVER AL MENU PRINICPAL ", 50, 7, y==2);

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
            if(y>2){
                y=2;
            }
        break;
        case 1: //ENTER
            rlutil::cls();
            switch(y){
            case 0:
                _turnoManager.CantidadTurnosPorEspecialidad();
                    break;
            case 1:
                _turnoManager.CantidadTurnosNoAsistidos();
                    break;
            case 2: opc=0;
                    break;
            default:
                    break;
            }
            break;
        }
    }while(opc!=0);
    return 0;
}
