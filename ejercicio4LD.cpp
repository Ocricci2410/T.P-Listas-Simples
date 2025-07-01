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
void MostrarMayorYMenor(const tlista &lista) {
if (lista.inicio == NULL) {
cout << "La lista está vacía." << endl;
return;}
int mayor = lista.inicio->dato;
int menor = lista.inicio->dato;
pnodo aux = lista.inicio->sig;
while (aux != NULL) {
if (aux->dato > mayor)
mayor = aux->dato;
if (aux->dato < menor)
menor = aux->dato;
aux = aux->sig;}
cout << "Valor mayor: " << mayor << endl;
cout << "Valor menor: " << menor << endl;}
void MostrarLista(const tlista &lista) {
pnodo aux = lista.inicio;
cout << "Lista: ";
while (aux != NULL) {
cout << aux->dato << " ";
aux = aux->sig;}
cout << endl;}
int main() {
tlista lista;
pnodo nuevo;
IniciarLista(lista);
CrearNodo(nuevo, 10);
AgregarFinal(lista, nuevo);
CrearNodo(nuevo, 3);
AgregarFinal(lista, nuevo);
CrearNodo(nuevo, 42);
AgregarFinal(lista, nuevo);
CrearNodo(nuevo, 7);
AgregarFinal(lista, nuevo);
MostrarLista(lista);
MostrarMayorYMenor(lista);
return 0;}
