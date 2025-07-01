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
void enigma(Nodo* nodo) {
    if (nodo != nullptr) {
        if (nodo->getSiguiente() == nullptr)
            cout << nodo->getDato() << endl;
        else {
            enigma(nodo->getSiguiente());
            cout << nodo->getDato() << endl;
        }
    }
}
int main() {
Nodo* nodo1 = new Nodo(1);
Nodo* nodo2 = new Nodo(2);
Nodo* nodo3 = new Nodo(3);
Nodo* nodo4 = new Nodo(4);
nodo1->setSiguiente(nodo2);
nodo2->setSiguiente(nodo3);
nodo3->setSiguiente(nodo4);
cout << "Salida de la funcion enigma:" << endl;
enigma(nodo1);
delete nodo4;
delete nodo3;
delete nodo2;
delete nodo1;
return 0;}
//Este imprime los elementos de una lista enlazada desde el ultimo nodo hasta el primero
