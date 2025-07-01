#include <iostream>
using namespace std;
class NodoDoble {
public:
int dato;
NodoDoble* anterior;
NodoDoble* siguiente;
NodoDoble(int valor) {
dato = valor;
anterior = nullptr;
siguiente = nullptr;}};
class ListaDoble {
private:
NodoDoble* cabeza;
NodoDoble* cola;
public:
ListaDoble() {
cabeza = nullptr;
cola = nullptr;}
void inicializar() {
while (cabeza != nullptr) {
extraerInicio();}}
NodoDoble* crearNodo(int valor) {
return new NodoDoble(valor);}
void insertarInicio(int valor) {
NodoDoble* nuevo = crearNodo(valor);
if (cabeza == nullptr) {
cabeza = cola = nuevo;
} else
{nuevo->siguiente = cabeza;
cabeza->anterior = nuevo;
cabeza = nuevo;}}
void insertarFinal(int valor) {
NodoDoble* nuevo = crearNodo(valor);
if (cola == nullptr) {
cabeza = cola = nuevo;
} else
{cola->siguiente = nuevo;
nuevo->anterior = cola;
cola = nuevo;}}
void insertarOrdenado(int valor) {
NodoDoble* nuevo = crearNodo(valor);
if (cabeza == nullptr) {
cabeza = cola = nuevo;
} else
if (valor < cabeza->dato) {
insertarInicio(valor);
} else
if (valor > cola->dato) {
insertarFinal(valor);
} else
{NodoDoble* actual = cabeza;
while (actual != nullptr && actual->dato < valor) {
actual = actual->siguiente;}
NodoDoble* anterior = actual->anterior;
anterior->siguiente = nuevo;
nuevo->anterior = anterior;
nuevo->siguiente = actual;
actual->anterior = nuevo;}}
void extraerInicio() {
if (cabeza == nullptr) return;
NodoDoble* temp = cabeza;
if (cabeza == cola) {
cabeza = cola = nullptr;
} else
{cabeza = cabeza->siguiente;
cabeza->anterior = nullptr;}delete temp;}
void extraerFinal() {
if (cola == nullptr) return;
NodoDoble* temp = cola;
if (cabeza == cola) {
cabeza = cola = nullptr;
} else
{cola = cola->anterior;
cola->siguiente = nullptr;}
delete temp;}
void extraerValor(int valor) {
NodoDoble* actual = cabeza;
while (actual != nullptr && actual->dato != valor) {
actual = actual->siguiente;}
if (actual == nullptr) return;
if (actual == cabeza) {
extraerInicio();
} else
if (actual == cola) {
extraerFinal();
} else
{actual->anterior->siguiente = actual->siguiente;
actual->siguiente->anterior = actual->anterior;
delete actual;}}
bool buscar(int valor) {
NodoDoble* actual = cabeza;
while (actual != nullptr) {
if (actual->dato == valor) return true;
actual = actual->siguiente;}
return false;}
void mostrar() {
NodoDoble* actual = cabeza;
cout << "Lista: ";
while (actual != nullptr) {
cout << actual->dato << " ";
actual = actual->siguiente;}
cout << endl;}};
int main() {
ListaDoble lista;
lista.inicializar();
lista.insertarOrdenado(5);
lista.insertarOrdenado(2);
lista.insertarOrdenado(8);
lista.mostrar();
NodoDoble* nodo = lista.crearNodo(10);
cout << "Nodo creado: " << nodo->dato << endl;
delete nodo;
lista.insertarInicio(1);
lista.insertarFinal(9);
lista.mostrar();
return 0;}
