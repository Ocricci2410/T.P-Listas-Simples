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
void MostrarLista(const tlista &lista) {
pnodo aux = lista.inicio;
cout << "Lista: ";
while (aux != NULL) {
cout << aux->dato << " ";
aux = aux->sig;}
cout << endl;}
void DecimalABinario(int numero, tlista &lista) {
IniciarLista(lista);
if (numero == 0) {
pnodo nuevo;
CrearNodo(nuevo, 0);
AgregarInicio(lista, nuevo);
return;}
while (numero > 0) {
int bit = numero % 2;
pnodo nuevo;
CrearNodo(nuevo, bit);
AgregarInicio(lista, nuevo);
numero /= 2;}}
int main() {
tlista binario;
int numero;
cout << "Ingrese un numero decimal: ";
cin >> numero;
DecimalABinario(numero, binario);
cout << "Numero en binario: ";
MostrarLista(binario);
return 0;}
