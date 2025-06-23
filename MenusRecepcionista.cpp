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

int MenuRecepcionista::menuRecepcionista() {
    int y=0;
    int opc=1;
    int salir;

     do{
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(50, 3);
        cout << " MENU RECEPCIONISTA ";

        // Opciones
        if (y == 0){
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else{
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 5);
        cout << " 1. REGISTRAR PACIENTE ";

        if (y == 1){
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 6);
        cout << " 2. LISTAR PACIENTES ";

        if (y == 2) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 7);
        cout << " 3. MODIFICAR PACIENTE ";

        if (y == 3){
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else{
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 8);
        cout << " 4. DAR DE BAJA PACIENTE ";

        if (y == 4){
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else{
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 9);
        cout << " 5. REACTIVAR PACIENTE ";

        if (y == 5){
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else{
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 10);
        cout << " 6. ASIGNAR NUEVO TURNO ";

        if (y == 6){
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else{
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 11);
        cout << " 7. REPROGRAMAR TURNO ";

        if (y == 7){
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else{
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 12);
        cout << " 8. CANCELAR TURNO ";

        if (y == 8){
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else{
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 13);
        cout << " 9. TURNO NO ASISTIDO ";

        if (y == 9){
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else{
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 14);
        cout << "10. CONSULTAS ";

        if (y == 10){
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else{
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 15);
        cout << "11. INFORMES ";

        if (y == 11){
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else{
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 16);
        cout << "12. LISTAR TURNOS ";

        if (y == 12){
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else{
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 17);
        cout << " 0. CERRAR SESION ";

        // Flecha
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::locate(48, 5 + y);
        cout << (char)175;

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
            case 0:
                _pacienteManager.cargarPaciente();
                break;
            case 1:
                _pacienteManager.mostrarPaciente();
                break;
            case 2:
               _pacienteManager.modificarPaciente();
                break;
            case 3:
                _pacienteManager.DarBajaPaciente();
                break;
            case 4:
                _pacienteManager.reactivarPaciente();
                break;
            case 5:
                _turnoManager.cargarTurno();
                break;
            case 6:
                _turnoManager.reprogramarTurno();
                break;
            case 7:
                _turnoManager.cancelarTurno();
                break;
            case 8:
               _turnoManager.TurnoNoAsistido();
                break;
            case 9:
                salir = menuConsultasRecepcionista();
                if(salir != 0){
                    rlutil::anykey();
                }
                break;
            case 10:
                salir = menuInformesRecepcionista();
                if(salir != 0){
                    rlutil::anykey();
                }
                break;
            case 11:
                _turnoManager.mostrarTurno();
                break;
            case 12:
                rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                rlutil::setColor(rlutil::COLOR::YELLOW);
                rlutil::locate(50, 12);
                cout << "Cerrando sesion..." << endl;
                rlutil::locate(50, 13);
                cout << "Presione una tecla para salir.";
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
        rlutil::locate(55, 3);
        cout << " CONSULTAS RECEPCIONISTA ";

        // Opciones
        if (y == 0) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 5);
        cout << " 1. BUSCAR TURNO POR ESTADO ";

        if (y == 1) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 6);
        cout << " 2. BUSCAR MEDICOS POR ESPECIALIDAD ";

        if (y == 2) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 7);
        cout << " 3. VER TURNOS DEL DIA ";

        if (y == 3) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 8);
        cout << " 4. VER TURNOS DE LA SEMANA ";

        if (y == 4) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 9);
        cout << " 0. VOLVER AL MENU ANTERIOR ";

        // Flecha
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::locate(48, 5 + y);
        cout << (char)175;

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
        cout << " INFORMES RECEPCIONISTA ";

        // Opciones
        if (y == 0) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 5);
        cout << " 1. CANTIDAD TURNOS POR ESPECIALIDAD ";

        if (y == 1) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 6);
        cout << " 2. CANTIDAD DE TURNOS NO ASISTIDOS POR MEDICO ";

        if (y == 2) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 7);
        cout << " 0. VOLVER AL MENU PRINCIPAL ";

        // Flecha
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::locate(48, 5 + y);
        cout << (char)175;

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
