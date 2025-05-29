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

void showItem(const char* text, int posx, int posy, bool selected){
    if(selected){
        rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
    } else{
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    }
    rlutil::locate(posx, posy);
    cout<<text<<endl;
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

void MenuRecepcionista::menuRecepcionista() {
int y=0;
int opc=1;
 do{
    system("cls");
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(55, 3);
    cout<<" MENU RECEPCIONISTA ";
    showItem(" 1. REGISTRAR PACIENTE ", 55, 5, y==0);
    showItem(" 2. LISTAR PACIENTES ", 55, 6, y==1);
    showItem(" 3. ASIGNAR NUEVO TURNO ", 55, 7, y==2);
    showItem(" 4. REPROGRAMAR TURNO ", 55, 8, y==3);
    showItem(" 5. CANCELAR TURNO ", 55, 9, y==4);
    showItem(" 6. CONSULTAS ", 55, 10, y==5);
    showItem(" 7. INFORMES ", 55, 11, y==6);
    showItem(" 8. LISTAR TURNOS ", 55, 12, y==7);
    showItem(" 0. CERRAR SESION ", 55, 13, y==8);

    rlutil::locate(53, 5 + y);
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
        if(y>8){
            y=8;
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
            _turnoManager.cargarTurno();
                break;
        case 3:
            _turnoManager.reprogramarTurno();
                break;
        case 4:
            _turnoManager.cancelarTurno();
                break;
        case 5:
            menuConsultasRecepcionista();
                break;
        case 6:
            menuInformesRecepcionista();
                break;
        case 7:
            _turnoManager.mostrarTurno();
                break;
        case 8: opc=0;
                break;
        default:
                break;
        }
        if(opc!=0){
            rlutil::anykey();
        }
        break;
    default:
        break;
    }
 }while(opc!=0);
}

void MenuRecepcionista::menuConsultasRecepcionista(){
int y=0;
int opc=1;
do{
    system("cls");
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(55, 3);
    cout<<" - CONSULTAS RECEPCIONISTA - ";
    showItem(" 1. BUSCAR TURNO POR ESTADO (ACTIVO, CANCELADO, REPROGRAMADO, NO ASISTIDO) ", 55, 5, y==0);
    showItem(" 2. BUSCAR MEDICOS POR ESPECIALIDAD ", 55, 6, y==1);
    showItem(" 3. VER TURNOS DEL DIA ", 55, 7, y==2);
    showItem(" 4. VER TURNOS DE LA SEMANA ", 55, 8, y==3);
    showItem(" 0. VOLVER AL MENU ANTERIOR ", 55, 9, y==4);
    rlutil::locate(53, 5 + y);
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
        if(opc!=0){
            rlutil::anykey();
        }
        break;
    }
}while(opc!=0);
}

void MenuRecepcionista::menuInformesRecepcionista(){
int y=0;
int opc=1;
do{
    system("cls");
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(55, 3);
    cout<<" - INFORMES RECEPCIONISTA - ";
    showItem(" 1. CANTIDAD TURNO POR ESPECIALIDAD ", 55, 5, y==0);
    showItem(" 2. CANTIDAD DE TURNOS NO ASISTIDOS POR MEDICO ", 55, 6, y==1);
    showItem(" 0. VOLVER AL MENU PRINICPAL ", 55, 7, y==2);
    rlutil::locate(53, 5 + y);
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
        if(y>2){
            y=2;
        }
    break;
    case 1: //ENTER
        rlutil::cls();
        switch(y){
        case 0:
                break;
        case 1:
                break;
        case 2: opc=0;
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
}

/*int MenuRecepcionista::menuRecepcionista() {
int opc;
 while(true){
    system("cls");
    cout<<"- MENU RECEPCIONISTA - "<<endl;
    cout<<"- 1.Registrar paciente "<<endl;
    cout<<"- 2.Listar pacientes "<<endl;
    cout<<"- 3.Asignar nuevo turno "<<endl;
    cout<<"- 4.Reprogramar turno "<<endl;
    cout<<"- 5.Cancelar turno "<<endl;
    cout<<"- 6.Consultas "<<endl;
    cout<<"- 7.Informes "<<endl;
    cout<<"- 8.Lista de turnos "<<endl;
    cout<<"- 0.Cerrar sesion "<<endl;
    cout<<endl;
    cout<<"Seleccione la opcion que busca..."<<endl;
    cin>>opc;
    system("cls");
    switch(opc){
    case 1: _pacienteManager.cargarPaciente();
        break;
    case 2: _pacienteManager.mostrarPaciente();
        break;
    case 3: _turnoManager.cargarTurno();
        break;
    case 4: _turnoManager.reprogramarTurno();
        break;
    case 5: _turnoManager.cancelarTurno();
        break;
    case 6: menuConsultasRecepcionista();
        break;
    case 7: menuInformesRecepcionista();
        break;
    case 8: _turnoManager.mostrarTurno();
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
    case 1: _turnoManager.BuscarTurnoEstado();
        break;
    case 2:_medicoManager.buscarMedicoPorEspecialidad();
        break;
    case 3: _turnoManager.TurnosDelDia();
        break;
    case 4: _turnoManager.TurnosDeLaSemana();
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
}*/

