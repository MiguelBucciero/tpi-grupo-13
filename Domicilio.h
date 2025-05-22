#pragma once

class Domicilio{
public:

    Domicilio();
    Domicilio(const char* calle, int altura, const char* localidad, const char* provincia, const char* codigoPostal);

    // Getters
    char* getCalle();
    int getAltura();
    char* getLocalidad();
    char* getProvincia();
    char* getCodigoPostal();

    // Setters
    void setCalle(const char* valor);
    void setAltura(int valor);
    void setLocalidad(const char* valor);
    void setProvincia(const char* valor);
    void setCodigoPostal(const char* valor);

    //Metedos
    void cargarDomicilio();
    void mostrarDomicilio();

protected:
    char _calle [30];
    int _altura;
    char _localidad[30];
    char _provincia[30];
    char _codigoPostal[6];

};
