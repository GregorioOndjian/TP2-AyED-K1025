#ifndef INCIDENTES_H
#define INCIDENTES_H

#include <stdio.h>
#include <iostream>
#include <cstring>

#define ARCHIVO_INCIDENTE "procesados.bak"
#define LONG_CALLE 24

struct Incidente
{
    int Codigo, Fecha, DniAsegurado, DniOtroConductor, NumeroPoliza, Altura;
    char Calle[LONG_CALLE];
};

struct NodoIncidente
{
    Incidente Info;
    NodoIncidente *Siguiente;
};

// Funciones

void InsertarSiguienteIncidente(NodoIncidente *&nodo, Incidente incidente);

void LeerArchivoIncidentes(NodoIncidente *&nodo);

void MostrarIncidentes(NodoIncidente *nodo);

#endif
