#include <bits/stdc++.h>
using namespace std;
typedef struct tnodo *pnodo;
typedef struct tnodo {
int dato;
pnodo siguiente;
} tnodo;
void crearnodo(pnodo &nuevo) {
nuevo = new tnodo;
if (nuevo != NULL) {
cout << "Ingrese valor: ";
cin >> nuevo->dato;
nuevo->siguiente = NULL;}
else {
cout << "Memoria insuficiente" << endl;}}
void iniciarlista(pnodo &lista) {
lista = NULL;}
void agregarinicio(pnodo &lista, pnodo nuevo) {
nuevo->siguiente = lista;
lista = nuevo;}
void mostrar(pnodo lista) {
pnodo i;
if (lista != NULL) {
for (i = lista; i != NULL; i = i->siguiente) {
cout << "Nodo: " << i->dato << endl;}}
else {
cout << "Lista vacia" << endl;}}
void seleccion(pnodo &lista) {
if (lista == NULL) return;
pnodo actual = lista;
pnodo minimo;
pnodo prev_minimo;
pnodo prev_actual;
while (actual != NULL) {
minimo = actual;
prev_minimo = prev_actual = actual;
for (pnodo temp = actual->siguiente; temp != NULL; temp = temp->siguiente) {
if (temp->dato < minimo->dato) {
minimo = temp;
prev_minimo = prev_actual;}
prev_actual = temp;}
if (minimo != actual) {
int tempDato = actual->dato;
actual->dato = minimo->dato;
minimo->dato = tempDato;}
actual = actual->siguiente;}}
void combinarSinOrden(pnodo &lista1, pnodo &lista2) {
if (lista1 == NULL) {
lista1 = lista2;
return;}
pnodo temp = lista1;
while (temp->siguiente != NULL) {
temp = temp->siguiente;}
temp->siguiente = lista2;}
void combinarConOrden(pnodo &lista1, pnodo lista2) {
if (lista1 == NULL) {
lista1 = lista2;
return;}
pnodo temp = lista1;
while (temp->siguiente != NULL) {
temp = temp->siguiente;}
temp->siguiente = lista2;}
void liberarLista(pnodo &lista) {
pnodo actual = lista;
while (actual != nullptr) {
pnodo temp = actual;
actual = actual->siguiente;
delete temp;}
lista = nullptr;}
int main() {
pnodo lista1, lista2, nuevo;
int a1, a2;
iniciarlista(lista1);
iniciarlista(lista2);
cout << "Ingrese la cantidad de nodos para la primera lista: ";
cin >> a1;
for (int i = 0; i < a1; i++) {
crearnodo(nuevo);
agregarinicio(lista1, nuevo);}
cout << "Ingrese la cantidad de nodos para la segunda lista: ";
cin >> a2;
for (int i = 0; i < a2; i++) {
crearnodo(nuevo);
agregarinicio(lista2, nuevo);}
cout << "Primera lista:" << endl;
mostrar(lista1);
cout << "Segunda lista:" << endl;
mostrar(lista2);
seleccion(lista1);
cout << "Lista 1 ordenada:\n";
mostrar(lista1);
combinarSinOrden(lista1, lista2);
cout << "Lista combinada (sin orden):";
mostrar(lista1);
iniciarlista(lista2);
cout << "Ingrese la cantidad de nodos para una nueva segunda lista: ";
cin >> a2;
for (int i = 0; i < a2; i++) {
crearnodo(nuevo);
agregarinicio(lista2, nuevo);
combinarConOrden(lista1, lista2);
cout << "Lista combinada respetando orden:";
mostrar(lista1);
liberarLista(lista1);
liberarLista(lista2);}
return 0;}
