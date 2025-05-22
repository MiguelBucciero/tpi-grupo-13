#pragma once
#include "Fecha.h"
#include "Domicilio.h"

class Persona {
public:

    Persona();
    Persona(const char* apellido, const char* nombre, int dni, Fecha fechaNacimiento, const char* genero,
            const char* email, const char* telefono, Domicilio domicilio);

    // Getters
    char* getApellido();
    char* getNombre();
    int getDni();
    Fecha getFechaNacimiento();
    char* getGenero();
    char* getEmail();
    char* getTelefono();
    Domicilio getDomicilioCompleto();

    // Setters
    void setApellido(const char* valor);
    void setNombre(const char* valor);
    void setDni(int valor);
    void setFechaNacimiento(Fecha valor);
    void setGenero(const char* valor);
    void setEmail(const char* valor);
    void setTelefono(const char* valor);
    void setDomicilio(Domicilio valor);

    // Métodos
    void cargarDatos();
    void mostrarDatos();

protected:
    char _apellido[50];
    char _nombre[50];
    int _dni;
    Fecha _fechaNacimiento;
    char _genero[10];
    char _email[50];
    char _telefono[15];
    Domicilio _domicilio;
};
