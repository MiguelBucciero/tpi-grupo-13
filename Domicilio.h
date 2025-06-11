#pragma once
#include <string>

class Domicilio{
public:

    Domicilio();
    Domicilio(std::string calle, int altura, std::string localidad, std::string provincia, std::string codigoPostal);

    // Getters
    const std::string getCalle() const;
    int getAltura()const;
    const std::string getLocalidad()const;
    const std::string getProvincia()const;
    const std::string getCodigoPostal()const;

    // Setters
    void setCalle(const std::string &calle);
    void setAltura(int altura);
    void setLocalidad(const std::string &localidad);
    void setProvincia(const std::string &provincia);
    void setCodigoPostal(const std::string &cpostal);

private:
    char _calle [30];
    int _altura;
    char _localidad[30];
    char _provincia[30];
    char _codigoPostal[6];

};
