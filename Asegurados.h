#ifndef ASEGURADOS_H
#define INCIDENTES_H

#include <stdio.h>
#include <iostream>
#include <cstring>

#define LONG_NOMBRE 28
#define LONG_APELLIDO 40
#define LONG_PATENTE 10

struct Asegurado
{
    int NumeroPoliza, Dni, CantidadIncidentes;
    char Nombre[LONG_NOMBRE], Apellido[LONG_APELLIDO], Patente[LONG_PATENTE];
    bool CuotaAlDia, Activa;
};

struct NodoAsegurado
{
    Asegurado Info;
    NodoAsegurado *Siguiente;
};

#endif