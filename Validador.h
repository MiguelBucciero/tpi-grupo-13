#pragma once
#include <string>

class Validador {
public:
    // Constructor
    Validador();

    // M�todos
    bool esTextoValido(const std::string &texto);
    bool esNumeroValido(const std::string &texto);
    bool esEnteroPositivo(int numero);
    bool esFechaValida(int dia, int mes, int anio);
};
