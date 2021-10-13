#include <iostream>
#include <stdio.h>

#include "Incidentes.h"
#include "Asegurados.h"

using namespace std;

int main(int argc, char const *argv[])
{
    NodoIncidente *ListaIncidentes = NULL;
    LeerArchivoIncidentes(ListaIncidentes);
    MostrarIncidentes(ListaIncidentes);
    return 0;
}
