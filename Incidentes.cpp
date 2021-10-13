#include "Incidentes.h"

using namespace std;

void ListarIncidentes(NodoIncidente *nodo)
{
    while (nodo)
    {
        cout << nodo->Info.NumeroPoliza << " " << nodo->Info.DniAsegurado << endl;
        nodo = nodo->Siguiente;
    }
}

void LeerArchivoIncidentes(NodoIncidente *&nodo)
{
    FILE *Archivo = NULL;
    Incidente incidente;
    if (Archivo = fopen(ARCHIVO_INCIDENTE, "r"))
    {
        fread(&incidente, sizeof(Incidente), 1, Archivo);
        while (!feof(Archivo))
        {
            InsertarSiguienteIncidente(nodo, incidente);
            fread(&incidente, sizeof(Incidente), 1, Archivo);
        }
        fclose(Archivo);
    }
}

void InsertarSiguienteIncidente(NodoIncidente *&nodo, Incidente incidente)
{
    NodoIncidente *nuevo = new NodoIncidente();
    nuevo->Info = incidente;

    if (nodo)
    {
        nuevo->Siguiente = nodo->Siguiente;
        nodo->Siguiente = nuevo;
    }
    else
    {
        nuevo->Siguiente = nodo;
        nodo = nuevo;
    }

    return;
}
