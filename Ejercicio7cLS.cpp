#include <iostream>
using namespace std;
class Nodo {
private:
int dato;
Nodo* siguiente;
public:
Nodo(int valor) : dato(valor), siguiente(nullptr) {}
int getDato() const { return dato; }
Nodo* getSiguiente() const { return siguiente; }
void setSiguiente(Nodo* sig) { siguiente = sig; }};
Nodo* desconocido(Nodo* nodo)
{
if(nodo == nullptr || nodo ->getSiguiente() ==
nullptr)
return nodo;
else
return desconocido(nodo->getSiguiente());
}
int main() {
Nodo* nodo1 = new Nodo(6);
Nodo* nodo2 = new Nodo(4);
Nodo* nodo3 = new Nodo(9);
Nodo* nodo4 = new Nodo(5);
Nodo* nodo5 = new Nodo(8);
nodo1->setSiguiente(nodo2);
nodo2->setSiguiente(nodo3);
nodo3->setSiguiente(nodo4);
nodo4->setSiguiente(nodo5);
Nodo* ultimo = desconocido(nodo1);
if (ultimo != nullptr)
cout << "El ultimo nodo contiene: " << ultimo->getDato() << endl;
else
cout << "La lista esta vacia." << endl;
delete nodo5;
delete nodo4;
delete nodo3;
delete nodo2;
delete nodo1;
return 0;}
//Esta funcion devuelve el ultimo nodo de una lista enlazada
