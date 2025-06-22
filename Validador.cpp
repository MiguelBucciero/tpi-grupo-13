#include "Validador.h"
#include "rlutil.h"

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



