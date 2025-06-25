#pragma once
#include <string>

class Validador {
public:
    // Constructor
    Validador();

    // Metodos
    bool esTextoValido(const std::string &texto);
    bool esNumeroValido(const std::string &texto);
    bool esEnteroPositivo(int numero);
    bool esFechaValida(int dia, int mes, int anio);
    bool esConfirmacionSN(char c);
    bool esTextoSinEspacios(const std::string &texto);
    bool esEmailValido(const std::string &email);
    bool validarHora(int &hora, int &minutos);
};
