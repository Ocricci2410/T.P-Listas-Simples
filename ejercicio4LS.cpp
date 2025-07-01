#include <iostream>
using namespace std;
typedef struct tnodo *pnodo;
typedef struct tnodo {
int dato;
pnodo siguiente;
}tnodo;
struct tpila {
pnodo tope;
int contador;
};
void iniciarPila(tpila &pila) {
pila.tope = nullptr;
pila.contador = 0;}
bool pilaVacia(tpila pila) {
return pila.tope == nullptr;}
void apilar(tpila &pila, pnodo nuevo) {
nuevo->siguiente = pila.tope;
pila.tope = nuevo;
pila.contador++;}
pnodo desapilar(tpila &pila) {
if (pilaVacia(pila)) return nullptr;
pnodo borrado = pila.tope;
pila.tope = pila.tope->siguiente;
borrado->siguiente = nullptr;
pila.contador--;
return borrado;}
void mostrarPila(tpila pila) {
pnodo actual = pila.tope;
cout << "Pila (tope -> fondo): ";
while (actual != nullptr) {
cout << actual->dato << " ";
actual = actual->siguiente;}
cout << "Cantidad: " << pila.contador;}
struct tcola {
pnodo inicio;
pnodo fin;
int contador;};
void iniciarCola(tcola &cola) {
cola.inicio = nullptr;
cola.fin = nullptr;
cola.contador = 0;}
bool colaVacia(tcola cola) {
return cola.inicio == nullptr;}
void encolar(tcola &cola, pnodo nuevo) {
nuevo->siguiente = nullptr;
if (colaVacia(cola)) {
cola.inicio = cola.fin = nuevo;}
else {
cola.fin->siguiente = nuevo;
cola.fin = nuevo;}
cola.contador++;}
pnodo desencolar(tcola &cola) {
if (colaVacia(cola)) return nullptr;
pnodo borrado = cola.inicio;
cola.inicio = cola.inicio->siguiente;
if (cola.inicio == nullptr) {
cola.fin = nullptr;}
borrado->siguiente = nullptr;
cola.contador--;
return borrado;}
void mostrarCola(tcola cola) {
pnodo actual = cola.inicio;
cout << "Cola (inicio -> fin): ";
while (actual != nullptr) {
cout << actual->dato << " ";
actual = actual->siguiente;}
cout << "\nCantidad: " << cola.contador << "\n";}
void crearnodo(pnodo &nuevo) {
nuevo = new tnodo;
if (nuevo != nullptr) {
cout << "Ingrese valor: ";
cin >> nuevo->dato;
nuevo->siguiente = nullptr;}
else {
cout << "Memoria insuficiente" << endl;}}
main() {
pnodo nuevo;
tpila pila;
iniciarPila(pila);
cout << "CARGANDO PILA";
for (int i = 0; i < 3; ++i) {
crearnodo(nuevo);
apilar(pila, nuevo);}
mostrarPila(pila);
cout << "\nDesapilando un nodo...\n";
pnodo eliminadoPila = desapilar(pila);
if (eliminadoPila) cout << "Eliminado: " << eliminadoPila->dato << "\n";
mostrarPila(pila);
tcola cola;
iniciarCola(cola);
cout << "\n--- CARGANDO COLA ---\n";
for (int i = 0; i < 3; ++i) {
crearnodo(nuevo);
encolar(cola, nuevo);}
mostrarCola(cola);
cout << "\nDesencolando un nodo...\n";
pnodo eliminadoCola = desencolar(cola);
if (eliminadoCola) cout << "Eliminado: " << eliminadoCola->dato << "\n";
mostrarCola(cola);}
