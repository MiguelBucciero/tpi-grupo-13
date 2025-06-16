#pragma once
#include <string>
#include "Fecha.h"
#include "Domicilio.h"

class Persona {
public:
    Persona();
    Persona(std::string apellido, std::string nombre, int dni, Fecha fechaNacimiento, std::string genero,
            std::string email, std::string telefono, Domicilio domicilio);

    // Getters
    const std::string getApellido() const;
    const std::string getNombre() const;
    int getDni();
    Fecha getFechaNacimiento() const;
    const std::string getGenero() const;
    const std::string getEmail() const;
    const std::string getTelefono() const;
    Domicilio getDomicilioCompleto() const;

    // Setters
    void setApellido(const std::string &apellido);
    void setNombre(const std::string &nombre);
    void setDni(int dni);
    void setFechaNacimiento(const Fecha &fecha);
    void setGenero(const std::string &genero);
    void setEmail(const std::string &email);
    void setTelefono(const std::string &telefono);
    void setDomicilio(const Domicilio &domicilio);

private:
    char _apellido[50];
    char _nombre[50];
    int _dni;
    Fecha _fechaNacimiento;
    char _genero[10];
    char _email[50];
    char _telefono[15];
    Domicilio _domicilio;
};
