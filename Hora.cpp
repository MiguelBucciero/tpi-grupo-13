#include "Hora.h"

Hora::Hora(){
    _hora=0;
    _minutos=0;
}

Hora::Hora(int hora, int minutos) {
    setHora(hora);
    setMinutos(minutos);
}

// Getters
int Hora::getHora() const{
    return _hora;
}

int Hora::getMinutos() const{
    return _minutos;
}

// Setters
void Hora::setHora(int hora) {
    if (hora >= 0 && hora <= 23) {
        _hora = hora;
    }
    else{
        _hora = 0;
    }
}

void Hora::setMinutos(int minutos) {
    if (minutos >= 0 && minutos <= 59) {
        _minutos = minutos;
    }
    else{
        _minutos = 0;
    }
}

// M�todos
bool Hora::esIgual(Hora &otra){
    return (_hora==otra.getHora()&&_minutos==otra.getMinutos());
}
