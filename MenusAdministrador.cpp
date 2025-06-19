#include<iostream>
#include<cstdlib>
#include "rlutil.h"
#include "MenuAdministrador.h"
#include "UsuarioManager.h"


using namespace std;

int MenuAdministrador::menuAdministrador() {
    int opc=1;
    int y=0;

    do{
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(50, 3);
        cout << " MENU ADMINISTRADOR ";

        //Opciones
        if (y == 0) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 5);
        cout << " 1. CARGAR NUEVO USUARIO ";

        if (y == 1) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 6);
        cout << " 2. MODIFICAR USUARIO ";

        if (y == 2) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 7);
        cout << " 3. ELIMINAR USUARIO ";

        if (y == 3) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 8);
        cout << " 4. REACTIVAR USUARIO ";

        if (y == 4) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 9);
        cout << " 5. LISTAR USUARIOS ";

        if (y == 5) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 10);
        cout << " 6. INFORMES ";

        if (y == 6) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 11);
        cout << " 7. CARGAR ESPECIALIDAD ";

        if (y == 7) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 12);
        cout << " 8. MODIFICAR ESPECIALIDAD ";

        if (y == 8) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 13);
        cout << " 9. ELIMINAR ESPECIALIDAD ";

        if (y == 9) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 14);
        cout << "10. LISTAR ESPECIALIDAD ";

        if (y == 10) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 15);
        cout << "11. REACTIVAR ESPECIALIDAD ";

        if (y == 11) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 16);
        cout << "12. MODIFICAR MEDICO ";

        if (y == 12) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 17);
        cout << "13. ELIMINAR MEDICO ";

         if (y == 13) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 18);
        cout << "14. REACTIVAR MEDICO ";


        if (y == 14) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 19);
        cout << "15. LISTAR MEDICOS ";

        if (y == 15) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 20);
        cout << " 0. CERRAR SESION ";

        //Flecha
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
                if(y>15){
                    y=15;
                }
            break;
            case 1: //ENTER
                rlutil::cls();
                switch(y){
                case 0:
                    _usuarioManager.cargarUsuario();
                    break;
                case 1:
                    _usuarioManager.modificarUsuario();
                    break;
                case 2:
                    _usuarioManager.DarBajaUsuario();
                    break;
                case 3:
                    _usuarioManager.reactivarUsuario();
                    break;
                case 4:
                    _usuarioManager.mostrarUsuario();
                    break;
                case 5:
                    menuInformesAdministrador();
                    break;
                case 6:
                   _espManager.cargarEspecialidad();
                    break;
                case 7:
                    _espManager.ModificarEspecialidad();
                    break;
                case 8:
                    _espManager.DarBajaEspecialidad();
                    break;
                case 9:
                    _espManager.mostrarEspecialidad();
                    break;
                case 10:
                    _espManager.ReactivarEspecialidad();
                    break;
                case 11:
                    _medicoManger.modificarMedico();
                    break;
                case 12:
                    _medicoManger.DarBajaMedico();
                    break;
                case 13:
                    _medicoManger.reactivarMedico();
                    break;
                case 14:
                    _medicoManger.mostrarMedico();
                    break;
                case 15:
                    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    rlutil::setColor(rlutil::COLOR::YELLOW);
                    rlutil::locate(50, 13);
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
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(55, 3);
        cout << " INFORMES ADMINISTRADOR ";

        //Opciones
        if (y == 0) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 5);
        cout << " 1. CANTIDAD DE TURNOS POR MEDICO ";

        if (y == 1) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 6);
        cout << " 2. CANTIDAD DE TURNOS POR PACIENTE ";

        if (y == 2) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 7);
        cout << " 3. CANTIDAD DE TURNOS CANCELADOS POR MES ";

        if (y == 3) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 8);
        cout << " 4. CANTIDAD DE TURNOS REPROGRAMADOS POR MES ";

        if (y == 4) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 9);
        cout << " 5. CANTIDAD DE TURNOS POR ESPECIALIDAD EN EL ANIO ";

        if (y == 5) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 10);
        cout << " 6. CANTIDAD DE USUARIOS ACTIVOS ";

        if (y == 6) {
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        }
        else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }
        rlutil::locate(50, 11);
        cout << " 0. VOLVER AL MENU ANTERIOR ";

        //Flecha
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
            if(y>6){
                y=6;
            }
        break;
        case 1: //ENTER
            rlutil::cls();
            switch(y){
            case 0:
                _turnoManager.cantidadTurnosPorMedico();
                    break;
            case 1:
                _turnoManager.cantidadTurnosPorPaciente();
                    break;
            case 2:
                _turnoManager.cantidadTurnosCanceladosPorMes();
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
            break;
        }
    }while(opc!=0);
    return 0;
}
