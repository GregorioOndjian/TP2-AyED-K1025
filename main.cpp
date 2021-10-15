#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <cstring>

#define LONG_NOMBRE 28
#define LONG_APELLIDO 40
#define LONG_PATENTE 10
#define LONG_CALLE 25
#define ARCHIVO_INCIDENTE "procesados.bak"

using namespace std;

struct Incidente
{
    int Codigo, Fecha, DniAsegurado, DniOtroConductor, NumeroPoliza, Altura;
    char Calle[LONG_CALLE];
};

struct NodoIncidente
{
    Incidente Info;
    NodoIncidente *sgte;
};

struct Asegurado
{
    int NumeroPoliza, Dni, CantidadIncidentes;
    char Nombre[LONG_NOMBRE], Apellido[LONG_APELLIDO], Patente[LONG_PATENTE];
    bool CuotaAlDia, Activa;
};

struct NodoAsegurado
{
    Asegurado Info;
    NodoAsegurado *sgte;
};

void InsertarSiguienteAsegurado(NodoAsegurado *&nodo, Asegurado poliza)
{
    NodoAsegurado *nuevo = new NodoAsegurado();
    nuevo->Info = poliza;

    if (nodo)
    {
        nuevo->sgte = nodo->sgte;
        nodo->sgte = nuevo;
    }
    else
    {
        nuevo->sgte = nodo;
        nodo = nuevo;
    }

    return;
}

void GuardarDatosPrueba(NodoAsegurado *&raiz)
{
    Asegurado poliza;

    strcpy(poliza.Nombre, "Juan");
    strcpy(poliza.Apellido, "Bazques");
    strcpy(poliza.Patente, "44aa4455aa");
    poliza.Dni = 44748938;
    poliza.NumeroPoliza = 8888;
    poliza.CantidadIncidentes = 2;
    poliza.Activa = 1;
    poliza.CuotaAlDia = 1;

    InsertarSiguienteAsegurado(raiz, poliza);

    strcpy(poliza.Nombre, "Pedro");
    strcpy(poliza.Apellido, "Bazques");
    strcpy(poliza.Patente, "4ee4ee55e5");
    poliza.Dni = 44567865;
    poliza.NumeroPoliza = 7898;
    poliza.CantidadIncidentes = 8;
    poliza.Activa = 1;
    poliza.CuotaAlDia = 1;

    InsertarSiguienteAsegurado(raiz, poliza);

    strcpy(poliza.Nombre, "Ulizes");
    strcpy(poliza.Apellido, "kil");
    strcpy(poliza.Patente, "456555aa44");
    poliza.Dni = 45656745;
    poliza.NumeroPoliza = 7898;
    poliza.CantidadIncidentes = 7;
    poliza.Activa = 1;
    poliza.CuotaAlDia = 1;

    InsertarSiguienteAsegurado(raiz, poliza);

    strcpy(poliza.Nombre, "Pedra");
    strcpy(poliza.Apellido, "newzle");
    strcpy(poliza.Patente, "789a7s8da9");
    poliza.Dni = 56585457;
    poliza.NumeroPoliza = 1233;
    poliza.CantidadIncidentes = 02;
    poliza.Activa = 1;
    poliza.CuotaAlDia = 1;

    InsertarSiguienteAsegurado(raiz, poliza);
}

char menu()
{
    cout << "1. Cargar una nueva poliza" << endl;
    cout << "2. Desactivar poliza existente" << endl;
    cout << "3. Buscar poliza (DNI o Nro. de poliza)" << endl;
    cout << "4. Listar polizas activas" << endl;
    cout << "5. Procesar lostes de incidentes" << endl;
    cout << "6. Mostrar polizas que no tengan la cuota al dia" << endl;
    cout << "7. Finalizar jornada" << endl;
    cout << "Esc. Salir" << endl;
    char opcion;
    do
    {
        opcion = getch();
    } while ((opcion != '1') && (opcion != '2') && (opcion != '3') && (opcion != '4') && (opcion != '5') && (opcion != '6') && (opcion != '7') && (opcion != 27));
    return opcion;
}

void CargarPoliza(Asegurado &x)
{
    char nom[LONG_NOMBRE + 1], ape[LONG_APELLIDO + 1], Patente[LONG_PATENTE], Dni[8], nro_poliza[4];

    // ****************************************lo del while no anda por ahora
    // strlen = para saber cuantos caracteres hay llenos dentro del char
    // atoi = convertir el char en int

    cout << "Ingrese el nombre del asegurado" << endl;
    cin >> nom;
    while (strlen(nom) > sizeof(char[LONG_NOMBRE]))
    {
        cout << "Su nombre es demasiado largo, por favor ingrese una abreviacion" << endl;
        cin >> nom;
    }
    strcpy(x.Nombre, nom);
    //***********************************************Despues se descomenta***********************************************

    cout << "Ingrese el Apellido del asegurado" << endl;
    cin >> ape;
    while (strlen(ape) > sizeof(char[LONG_APELLIDO]))
    {
        cout << "Su apellido es demasiado largo, por favor ingrese una abreviacion" << endl;
        cin >> ape;
    }
    strcpy(x.Apellido, ape);
    cout << "Ingrese la patente del asegurado" << endl;
    cin >> Patente;
    while (strlen(Patente) != sizeof(char[LONG_PATENTE]))
    {
        cout << "Por favor ingrese una patente valida" << endl;
        cin >> Patente;
    }
    strcpy(x.Patente, Patente);
    cout << "Ingrese el DNI del asegurado" << endl;
    cin >> Dni;
    int k = strlen(Dni);
    while (k != sizeof(char[8]))
    {
        cout << strlen(Dni) << " " << sizeof(char[8]) << endl;
        cout << "Por favor ingrese un DNI valido" << endl;
        cin >> Dni;
        k = strlen(Dni);
    }
    x.Dni = atoi(Dni);
    cout << "Ingrese el numero de poliza del asegurado" << endl;
    cin >> nro_poliza;
    int l = strlen(nro_poliza);
    while (l != sizeof(char[4]))
    {
        cout << "Por favor ingrese una poliza valida" << endl;
        cin >> nro_poliza;
        l = strlen(nro_poliza);
    }
    x.NumeroPoliza = atoi(nro_poliza);
    cout << "Ingrese la cantidad de incidentes del asegurado" << endl;
    cin >> x.CantidadIncidentes;
    cout << "Indique si el asegurado esta activo (1 = activa // 0 = no activa)" << endl;
    // 1 true 0 false
    cin >> x.Activa;
    x.CuotaAlDia = 1;
    return;
}

NodoAsegurado *ObtenerUltimaPoliza(NodoAsegurado *raiz)
{
    if (raiz)
        while (raiz->sgte)
            raiz = raiz->sgte;
    return raiz;
}

void InsertarNuevaPoliza(NodoAsegurado *&raiz)
{
    Asegurado asegurado;
    CargarPoliza(asegurado);

    NodoAsegurado *nuevo = new NodoAsegurado();
    NodoAsegurado *ultimo = NULL;

    nuevo->Info = asegurado;
    nuevo->sgte = NULL;

    if (raiz)
    {
        ultimo = ObtenerUltimaPoliza(raiz);
        ultimo->sgte = nuevo;
    }
    else
    {
        raiz = nuevo;
    }

    return;
}

int ObtenerCantidadPolizas(NodoAsegurado *p)
{
    int cont;
    if (p)
    {
        while (p)
        {
            cont++;
            p = p->sgte;
        }
    }
    return cont;
}

void DesactivarPoliza(NodoAsegurado *&raiz, int num)
{
    NodoAsegurado *aux = raiz;
    while (aux && aux->Info.NumeroPoliza != num)
    {
        aux = aux->sgte;
    }

    if (aux)
    {
        aux->Info.Activa = false;
        cout << "Poliza desactivada correctamente" << endl;
    }

    return;
}

void MostrarAsegurado(Asegurado x)
{
    cout << "El nombre del asegurado es " << x.Nombre << endl;
    cout << "El Apellido del asegurado es " << x.Apellido << endl;
    cout << "El Patente del asegurado es " << x.Patente << endl;
    cout << "El Dni del asegurado es " << x.Dni << endl;
    cout << "El nro de poliza del asegurado es " << x.NumeroPoliza << endl;
    cout << "La cantidad de incidentes del asegurado es " << x.CantidadIncidentes << endl;
}

void BuscarPolizaPorNumero(NodoAsegurado *raiz, int num)
{
    while (raiz && raiz->Info.NumeroPoliza != num)
        raiz = raiz->sgte;

    if (raiz)
        MostrarAsegurado(raiz->Info);
    else
        cout << "No se encontro al asegurado" << endl;

    return;
}

void OrdenarPolizas(NodoAsegurado *nodo)
{
    NodoAsegurado *actual, *siguiente;
    Asegurado aux;

    actual = nodo;

    while (actual->sgte)
    {
        siguiente = actual->sgte;

        while (siguiente)
        {
            if (actual->Info.NumeroPoliza > siguiente->Info.NumeroPoliza)
            {
                aux = siguiente->Info;
                siguiente->Info = actual->Info;
                actual->Info = aux;
            }
            siguiente = siguiente->sgte;
        }
        actual = actual->sgte;
        siguiente = actual->sgte;
    }
}

void BuscarPolizaPorDNI(NodoAsegurado *raiz, int dni)
{
    while (raiz && raiz->Info.Dni != dni)
        raiz = raiz->sgte;

    if (raiz)
        MostrarAsegurado(raiz->Info);
    else
        cout << "No se encontro al asegurado" << endl;

    return;
}

void MostrarPolizasActivas(NodoAsegurado *nodo)
{
    int cont = 0;
    cout << "Lista de polizas activas" << endl;
    OrdenarPolizas(nodo);

    while (nodo)
    {
        if (nodo->Info.Activa)
        {
            cont++;
            MostrarAsegurado(nodo->Info);
            cout << endl;
        }
        nodo = nodo->sgte;
    }

    if (cont == 0)
        cout << "> No hay polizas activas";
}

void MostrarPolizas(NodoAsegurado *nodo)
{
    while (nodo)
    {
        MostrarAsegurado(nodo->Info);
        nodo = nodo->sgte;
    }
}

int main(int argc, char const *argv[])
{

    NodoAsegurado *ListaAsegurados = nullptr;
    int NumeroBusqueda;
    char OpcionElegida, num[5], OpcionBusqueda;

    GuardarDatosPrueba(ListaAsegurados);

    do
    {

        OpcionElegida = menu();

        switch (OpcionElegida)
        {

        case '1':
            InsertarNuevaPoliza(ListaAsegurados);
            break;

        case '2':
            cout << "Ingrese el numero de poliza a desactivar/borrar" << endl;
            cin >> num;
            while (strlen(num) != sizeof(char[4]))
            {
                cout << "Por favor ingrese una poliza valida (4 digitos)" << endl;
                cin >> num;
            }
            DesactivarPoliza(ListaAsegurados, atoi(num));
            break;

        case '3':
            cout << "¿Por que medio quiere buscar al asegurado?" << endl;
            cout << "1.DNI" << endl;
            cout << "2.Nro de Poliza" << endl;
            OpcionBusqueda = getch();
            if (OpcionBusqueda == '1')
            {
                cout << "Indique el DNI del asegurado" << endl;
                cin >> NumeroBusqueda;
                BuscarPolizaPorDNI(ListaAsegurados, NumeroBusqueda);
            }
            else if (OpcionBusqueda == '2')
            {
                cout << "Indique el Nro de poliza del/los asegurado/os" << endl;
                cin >> NumeroBusqueda;
                BuscarPolizaPorNumero(ListaAsegurados, NumeroBusqueda);
            }
            break;
        
        case '4':
            MostrarPolizasActivas(ListaAsegurados);
            break;
        }

        cout << "Presione una tecla para continuar" << endl;
        getch();
        system("cls");
    } while (OpcionElegida != 27);

    return 0;
}
