#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
                    int dato;
                    pnodo sig;
                    pnodo ant;
                    };
typedef struct tlista{
                    pnodo inicio;
                    pnodo fin;
                    };

void IniciarLista(tlista &lista)
{
    lista.inicio = NULL;
    lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor)
{
    nuevo = new tnodo;
    if(nuevo != NULL)
    {
        nuevo -> dato = valor;
        nuevo -> sig = NULL;
        nuevo -> ant = NULL;
    }
}

void AgregarInicio(tlista &lista, pnodo nuevo)
{
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        nuevo->sig = lista.inicio;
        lista.inicio->ant = nuevo;
        lista.inicio = nuevo;
    }
}

void AgregarFinal(tlista &lista, pnodo nuevo){
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        lista.fin->sig = nuevo;
        nuevo->ant = lista.fin;
        lista.fin = nuevo;
    }
}
void QuitarInicio(tlista &lista){
if (lista.inicio == NULL)
return;
pnodo temp = lista.inicio;
if (lista.inicio == lista.fin) {
lista.inicio = NULL;
lista.fin = NULL;
} else
{lista.inicio = lista.inicio->sig;
lista.inicio->ant = NULL;}
delete temp;}

void QuitarFinal(tlista &lista){
if (lista.fin == NULL)
return;
pnodo temp = lista.fin;
if (lista.inicio == lista.fin) {
lista.inicio = NULL;
lista.fin = NULL;
} else
{lista.fin = lista.fin->ant;
lista.fin->sig = NULL;}
delete temp;}
//Se agrega mostrar para observar los cambios realizados por las operaciones anteriores
void MostrarLista(const tlista &lista) {
pnodo aux = lista.inicio;
cout << "Lista: ";
while (aux != NULL) {
cout << aux->dato << " ";
aux = aux->sig;}
cout << endl;}
//Le agregue un main para probar las operaciones
int main() {
tlista lista;
pnodo nuevo;
IniciarLista(lista);
CrearNodo(nuevo, 3);
AgregarInicio(lista, nuevo);
CrearNodo(nuevo, 2);
AgregarInicio(lista, nuevo);
CrearNodo(nuevo, 1);
AgregarInicio(lista, nuevo);
MostrarLista(lista);
CrearNodo(nuevo, 4);
AgregarFinal(lista, nuevo);
CrearNodo(nuevo, 5);
AgregarFinal(lista, nuevo);
MostrarLista(lista);
QuitarInicio(lista);
MostrarLista(lista);
QuitarFinal(lista);
MostrarLista(lista);
return 0;}
