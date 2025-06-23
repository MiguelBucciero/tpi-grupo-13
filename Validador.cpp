#include "Validador.h"
#include "rlutil.h"
#include <iostream>
using namespace std;


Validador::Validador() {
}

bool Validador::esTextoValido(const std::string &texto) {
    int cantidadLetras = 0;
    char caracter;

    for (int i = 0; texto[i] != '\0'; i++) {
        caracter = texto[i];

        // Si no es letra ni espacio, inválido
        if (!((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z') || caracter == ' ')) {
            return false;
        }

        // Si es letra, contarla
        if ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z')) {
            cantidadLetras++;
        }
    }

    // Debe haber al menos una letra para que no sea solo espacios
    if (cantidadLetras > 0) {
        return true;
    }
    return false;
}

bool Validador::esNumeroValido(const std::string &texto) {
    int cantidadDigitos = 0;
    char caracter;

    for (int i = 0; texto[i] != '\0'; i++) {
        caracter = texto[i];

        // Si no está entre '0' y '9', no es un número
        if (caracter < '0' || caracter > '9') {
            return false;
        }

        cantidadDigitos++;
    }

    // Debe tener al menos un dígito
    if (cantidadDigitos > 0) {
        return true;
    }
    return false;
}

bool Validador::esEnteroPositivo(int numero) {
    if(numero > 0){
        return true;
    }else{
        return false;
    }
}

bool Validador::esFechaValida(int dia, int mes, int anio) {
    if (dia < 1 || dia > 31){
        return false;
    }
    if (mes < 1 || mes > 12){
        return false;
    }
    if (anio < 1900 || anio > 2100){
        return false;
    }
    return true;
}

bool Validador::esConfirmacionSN(char c) {
    // Verifica si es letra y si es 's' o 'n' (en mayuscula o minuscula)
    if(c == 's' || c == 'S' || c == 'n' || c == 'N'){
        return true;
    }
    return false;
}

bool Validador::esTextoSinEspacios(const std::string &texto) {
    int cantidadLetras = 0;
    char caracter;

    for (int i = 0; texto[i] != '\0'; i++) {
        caracter = texto[i];

        // Si no es letra, inválido
        if (caracter == ' ' || !((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z'))) {
            return false;
        }

        cantidadLetras++;
    }
    if(cantidadLetras > 0){
        return true;
    }
    else{
        return false;
    }
}

bool Validador::esEmailValido(const std::string &email) {
    int cantidadArrobas = 0;

    // Verificar que no este vacio
    if (email[0] == '\0') {
        return false;
    }

    // Contar las arrobas
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            cantidadArrobas++;
        }
    }

    // Debe tener un @
    if(cantidadArrobas == 1){
        return true;
    }else{
        return false;
    }
}

bool Validador::validarHora(int &horas, int &minutos, int fila) {
    rlutil::cls();


    while (true) {
        rlutil::locate(30, fila);
        cout << "Hora - Horas (0-23): ";
        rlutil::locate(55, fila);
        cin >> horas;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            rlutil::locate(30, fila + 1);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Debe ingresar un numero entero para las horas. Presione una tecla.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::cls();
            continue;
        }

        rlutil::locate(30, fila + 1);
        cout << "Minutos (0-59): ";
        rlutil::locate(55, fila + 1);
        cin >> minutos;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            rlutil::locate(30, fila + 2);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Debe ingresar un numero entero para los minutos. Presione una tecla.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::cls();
            continue;
        }

        if (horas < 0 || horas > 23 || minutos < 0 || minutos > 59) {
            rlutil::locate(30, fila + 2);
            rlutil::setColor(rlutil::COLOR::RED);
            cout << "Hora invalida. Presione una tecla para volver a intentar.";
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::anykey();
            rlutil::cls();
            continue;
        }

        // Si pasó todas las validaciones
        return true;
    }
}


