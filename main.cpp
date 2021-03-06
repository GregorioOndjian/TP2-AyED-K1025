#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
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
void ListarIncidentes(NodoIncidente *nodo)
{
    while (nodo)
    {
        cout << nodo->Info.NumeroPoliza << " " << nodo->Info.DniAsegurado << endl;
        nodo = nodo->sgte;
    }
}
// Esto despues se borra
void InsertarSiguienteIncidente(NodoIncidente *&nodo, Incidente incidente)
{
    NodoIncidente *nuevo = new NodoIncidente();
    nuevo->Info = incidente;

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
void cargar_poliza(Asegurado &x){
    char nom[LONG_NOMBRE+1], ape[LONG_APELLIDO+1], Patente[LONG_PATENTE], Dni[8], nro_poliza[4];

    // ****************************************lo del while no anda por ahora
    //strlen = para saber cuantos caracteres hay llenos dentro del char
    //atoi = convertir el char en int

    cout << "Ingrese el nombre del asegurado" << endl;
    cin>> nom;
    while(strlen(nom) > sizeof(char[LONG_NOMBRE])){
        cout << "Su nombre es demasiado largo, por favor ingrese una abreviacion" << endl;
        cin >> nom;
    }
    strcpy(x.Nombre,nom);
    //***********************************************Despues se descomenta***********************************************

    cout << "Ingrese el Apellido del asegurado" << endl;
    cin>> ape;
    while(strlen(ape) > sizeof(char[LONG_APELLIDO])){
        cout << "Su apellido es demasiado largo, por favor ingrese una abreviacion" << endl;
        cin >> ape;
    }
    strcpy(x.Apellido,ape);
    cout << "Ingrese la patente del asegurado" << endl;
    cin>> Patente;
    while(strlen(Patente) != sizeof(char[LONG_PATENTE])){
        cout << "Por favor ingrese una patente valida" << endl;
        cin >> Patente;
    }
    strcpy(x.Patente,Patente);
    cout << "Ingrese el DNI del asegurado" << endl;
    cin>> Dni;
    int k = strlen(Dni);
    while( k != sizeof(char[8])){
        cout << strlen(Dni) << " " << sizeof(char[8])<< endl;
        cout << "Por favor ingrese un DNI valido" << endl;
        cin >> Dni;
        k = strlen(Dni);
    }
    x.Dni = atoi(Dni);
    cout << "Ingrese el numero de poliza del asegurado" << endl;
    cin>> nro_poliza;
    int l = strlen(nro_poliza);
    while(l != sizeof(char[4])){
        cout << "Por favor ingrese una poliza valida" << endl;
        cin >> nro_poliza;
        l = strlen(nro_poliza);
    }
    x.NumeroPoliza = atoi(nro_poliza);
    cout << "Ingrese la cantidad de incidentes del asegurado" << endl;
    cin>> x.CantidadIncidentes;
    cout << "Indique si el asegurado esta activo (1 = activa // 0 = no activa)" << endl;
    //1 true 0 false
    cin>> x.Activa;
    x.CuotaAlDia = 1;
    return;

}

NodoAsegurado *encontrar_ultimo(NodoAsegurado *p){
    if (p)
    {
        while (p->sgte)
        {
            p = p->sgte;
        }
    }
    return p;
}

void insertar_poliza(NodoAsegurado *&p){
    Asegurado asegurado;
    cargar_poliza(asegurado);
    NodoAsegurado *nuevo= new NodoAsegurado();
    NodoAsegurado *ultimo= NULL;
    nuevo->Info=asegurado;
    nuevo->sgte= NULL;

	if (p!=NULL)
    {
        ultimo = encontrar_ultimo(p);
        ultimo->sgte = nuevo;
    }
    else
    {
        p= nuevo;

    }

    return;
}



void insertar_manual(NodoAsegurado *&p, Asegurado v[], int j){
        Asegurado asegurado;
        asegurado = v[j];
        NodoAsegurado *nuevo= new NodoAsegurado();
        NodoAsegurado *ultimo= NULL;
        nuevo->Info=asegurado;
        nuevo->sgte= NULL;

        if (p!=NULL)
        {
            ultimo = encontrar_ultimo(p);
            ultimo->sgte = nuevo;
        }
        else
        {
            p= nuevo;

        }

        return;

}


char menu(){
     cout << "1. Cargar una nueva poliza" << endl;
     cout << "2. Desactivar poliza existente" << endl;
     cout << "3. Buscar poliza(DNI o Nro. de poliza)" << endl;
     cout << "4. Listar polizas activas" << endl;
     cout << "5. Procesar lostes de incidentes" << endl;
     cout << "6. Mostrar polizas que no tengan la cuota al dia" << endl;
     cout << "7. Finalizar jornada" << endl;
     cout << "Esc. Salir"<< endl;
    char opcion;
    do
    {
       opcion=getch();
    } while ((opcion!='1') && (opcion!='2') && (opcion!='3') && (opcion!='4') && (opcion!='5') && (opcion!='6') && (opcion!='7')&& (opcion!=27));
    return opcion;
}

int cantNodos(NodoAsegurado *p){
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

void descactivar_poliza(NodoAsegurado *&x, int num ){
    NodoAsegurado *aux = x;
    int i = 0;
    while(aux && aux->Info.NumeroPoliza != num && i<cantNodos(x)){
        i++;
        aux = aux->sgte;
    }
    if(aux == NULL){
        cout << "Lista vacia" << endl;
    }else{
    aux->Info.Activa = false;
    cout << "Poliza desactivada correctamente" << endl;
    }
    if(i>= cantNodos(x)){
         cout << "No existe ningun asegurado que tenga ese numero de poliza" << endl;
    }
    return;


}

void mostrar_asegurado(Asegurado x){
cout << "El nombre del asegurado es "<< x.Nombre << endl;
cout << "El Apellido del asegurado es "<< x.Apellido << endl;
cout << "El Patente del asegurado es "<< x.Patente << endl;
cout << "El Dni del asegurado es "<< x.Dni << endl;
cout << "El nro de poliza del asegurado es "<< x.NumeroPoliza << endl;
cout << "La cantidad de incidentes del asegurado es "<< x.CantidadIncidentes << endl;
}

void buscar_dni(NodoAsegurado *x, int dni){
    int i = 0;
    while(x && x->Info.Dni != dni && i < cantNodos(x) ) {
        i++;
        x = x->sgte;
    }
    Asegurado encontrado = x->Info;

   mostrar_asegurado(encontrado);

   return;

}

void buscar_nro_poliza(NodoAsegurado *x, int nro_p){
    Asegurado encontrado[10];
    int i;
    for(int j = 0; j < cantNodos(x); j++){

            i = 0;
            if(x->Info.NumeroPoliza == nro_p){
                encontrado[i] = x->Info ;

                i++;

            }
            cout << &x << endl;
            x = x->sgte; //esto de ak hace que no funciona, no incrementa, no se porque

           //cout << encontrado[1].Nombre<< endl;

    }

    for(int j = 0; j <  i; j++){

        mostrar_asegurado(encontrado[j]);
    }


   return;
}


int main()
{
    NodoIncidente *ListaIncidentes = NULL;
    NodoAsegurado *Lista_Asegurado = NULL;
    char elegida;
    Asegurado v[4];
//ingreso de polizas (despues se borra)
strcpy(v[0].Nombre, "Juan");
strcpy(v[0].Apellido , "Bazques");
strcpy(v[0].Patente , "44aa4455aa");
v[0].Dni = 44748938;
v[0].NumeroPoliza = 4456;
v[0].CantidadIncidentes =2;
v[0].Activa = 1;
v[0].CuotaAlDia = 1;

strcpy(v[1].Nombre, "Pedro");
strcpy(v[1].Apellido , "Bazques");
strcpy(v[1].Patente , "4ee4ee55e5");
v[1].Dni = 44567865;
v[1].NumeroPoliza = 7898;
v[1].CantidadIncidentes =8;
v[1].Activa = 1;
v[1].CuotaAlDia = 1;

strcpy(v[2].Nombre, "Ulizes");
strcpy(v[2].Apellido , "kil");
strcpy(v[2].Patente , "456555aa44");
v[2].Dni = 45656745;
v[2].NumeroPoliza = 7898;
v[2].CantidadIncidentes =7;
v[2].Activa = 1;
v[2].CuotaAlDia = 1;

strcpy(v[3].Nombre, "Pedra");
strcpy(v[3].Apellido , "newzle");
strcpy(v[3].Patente , "789a7s8da9");
v[3].Dni = 56585457;
v[3].NumeroPoliza = 1233;
v[3].CantidadIncidentes =02;
v[3].Activa = 1;
v[3].CuotaAlDia = 1;
//**************************************


int z, num_p, p ;
char num[5];
char opcion1;
insertar_manual(Lista_Asegurado, v, 0);
insertar_manual(Lista_Asegurado, v, 1);
insertar_manual(Lista_Asegurado, v, 2);
insertar_manual(Lista_Asegurado, v, 3);
    do
    {

    elegida = menu();

    switch(elegida){

            case '1':
                insertar_poliza(Lista_Asegurado);
            break;
            case '2':
                cout << "Ingrese el numero de poliza a desactivar/borrar" << endl;
                cin >> num;
                z = strlen(num);
                while(z != sizeof(char[4])){
                        cout << "Por favor ingrese una poliza valida(4 digitos)" << endl;
                        cin >> num;
                        z = strlen(num);
                }
                num_p = atoi(num);
                descactivar_poliza(Lista_Asegurado, num_p);
            break;
            case '3':

                cout << "??Por que medio quiere buscar al asegurado?" << endl;
                cout << "1.DNI"<< endl;
                cout << "2.Nro de Poliza"<<endl;
                opcion1 = getch();
                if(opcion1 == '1' ){
                    cout << "Indique el DNI del asegurado" << endl;
                    cin >> p;
                    buscar_dni(Lista_Asegurado, p);
                }else if(opcion1 == '2') {
                    cout << "Indique el Nro de poliza del/los asegurado/os" << endl;
                    cin>> p;
                    buscar_nro_poliza(Lista_Asegurado, p);
                }
            break;
        }
        cout << "Presione una tecla para continuar" << endl;
        getch();
        system("cls");
    } while (elegida!=27);



}
