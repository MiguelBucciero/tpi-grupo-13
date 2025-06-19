#include<iostream>
#include "rlutil.h"
#include "MenuMedico.h"

using namespace std;

int MenuMedico::menuMedico(Usuario usuarioLogeado){
    int y = 0;
    int opc = 1;

    do {
        rlutil::cls();
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(50, 3);
        cout << " MENU MEDICO ";

        // OPCIONES DEL MENÚ
        if (y == 0) rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        else rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::locate(50, 5);
        cout << " 1. VER TURNOS ASIGNADOS ";

        if (y == 1) rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        else rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::locate(50, 6);
        cout << " 2. BUSCAR TURNOS POR FECHAS ";

        if (y == 2) rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        else rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::locate(50, 7);
        cout << " 3. VER HISTORIAL DE TURNOS ATENDIDOS ";

        if (y == 3) rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        else rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::locate(50, 8);
        cout << " 4. BUSCAR PACIENTE POR DNI ASOCIADO AL TURNO ";

        if (y == 4) rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        else rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::locate(50, 9);
        cout << " 5. REACTIVAR MEDICO ";

        if (y == 5) rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        else rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::locate(50, 10);
        cout << " 0. CERRAR SESION ";

        // FLECHA DE SELECCIÓN
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::locate(48, 5 + y);
        cout << (char)175;

        switch(rlutil::getkey()) {
        case 14: // UP
            rlutil::locate(48, 5 + y); cout << " ";
            y--;
            if (y < 0) y = 0;
            break;
        case 15: // DOWN
            rlutil::locate(48, 5 + y); cout << " ";
            y++;
            if (y > 5) y = 5;
            break;
        case 1: // ENTER
            rlutil::cls();
            switch (y) {
                case 0:
                    _medicoManager.verTurnosAsignados(usuarioLogeado.getIDMedico());
                    break;
                case 1: {
                    int idMedico = usuarioLogeado.getIDMedico();
                    _turnoManger.buscarTurnosPorFecha(idMedico);
                    break;
                }
                case 2: {
                    int idMedico = usuarioLogeado.getIDMedico();
                    _turnoManger.HistorialTurnosAtendidos(idMedico);
                    break;
                }
                case 3:
                    _medicoManager.buscarPacientePorDNI();
                    break;
                case 4:
                    _medicoManager.reactivarMedico();
                    break;
                case 5:
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

    } while (opc != 0);

    return 0;
}
