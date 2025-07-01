#include<bits/stdc++.h>
using namespace std;
typedef struct tnodo *pnodo;
typedef struct tnodo{
 int dato;
 pnodo siguiente;}tnodo;
 typedef struct tlista{
 pnodo inicio;
 pnodo fin;
 int contador;};
 void crearnodo(pnodo &nuevo){
 nuevo = new tnodo;
 if(nuevo != NULL){
 cout << "Ingrese valor: ";
 cin >> nuevo -> dato;
 nuevo -> siguiente = NULL;}
 else{
 cout << "Memoria insuficiente" <<
endl;}}
void iniciarlista(tlista &lista){
 lista.inicio = nullptr;
 lista.fin=nullptr;
 lista.contador=0;}
 void agregarinicio(tlista &lista, pnodo nuevo){
 nuevo -> siguiente = lista.inicio;
 lista.inicio = nuevo;
 if(lista.fin==nullptr){
lista.fin=nuevo;}
lista.contador++;}
void agregarfinal(tlista &lista, pnodo nuevo){
if(lista.inicio==nullptr){
lista.inicio=nuevo;
lista.fin=nuevo;}
else{
lista.fin->siguiente=nuevo;
lista.fin=nuevo;}
lista.contador++;}
void agregarordenado(pnodo &lista, pnodo nuevo){
 pnodo i;
 if(lista == NULL){
 lista = nuevo;}
 else{
 if(nuevo->dato < lista->dato){
 nuevo->siguiente = lista;
 lista = nuevo;}
 else{
 for(i=lista; i->siguiente!=NULL && nuevo->dato > (i->siguiente)->dato; i=i->siguiente);
 nuevo->siguiente = i->siguiente;
 i->siguiente = nuevo;}}}
 pnodo eliminarinicio(tlista &lista){
 pnodo borrado;
 if(lista.inicio==nullptr){
 return nullptr;}
 borrado = lista.inicio;
 lista.inicio = lista.inicio->siguiente;
 if(lista.inicio==nullptr){
lista.fin=nullptr;}
borrado->siguiente=nullptr;
lista.contador --;
return borrado;}
pnodo eliminarfinal(tlista &lista){
 pnodo borrado, i;
 if(lista.inicio == nullptr){
 return nullptr;}
 if(lista.inicio==lista.fin){
borrado=lista.inicio;
lista.inicio=nullptr;
lista.fin=nullptr;}
else{
for(i=lista.inicio;i->siguiente!=lista.fin;i=i->siguiente);
borrado=lista.fin;
i->siguiente=nullptr;
lista.fin=i;}
lista.contador--;
return borrado;}
pnodo eliminarnodo(pnodo &lista, int valor){
 pnodo borrado, i;
 if(lista == NULL){
 borrado = NULL;}
 else{
 if(lista->dato == valor){
 borrado = lista;
 lista = borrado->siguiente;
 borrado->siguiente = NULL;}
 else{
 for(i=lista; i->siguiente != NULL && valor!=(i->siguiente)->dato; i=i->siguiente);
 if(i->siguiente != NULL){
 borrado = i->siguiente;
 i->siguiente = borrado->siguiente;
 borrado->siguiente = NULL;}
 else{
 borrado=NULL;}}}
 return borrado;}
void mostrar(tlista lista){
 pnodo i;
 if(lista.inicio != NULL){
 for(i = lista.inicio; i != nullptr; i = i->siguiente){
 cout << "Nodo: " << i->dato << endl;}}
 else{
 cout << "Lista vacía";}}
int buscar_indice(tlista lista, int valor) {
pnodo actual = lista.inicio;
int indice = 0;
while (actual != nullptr) {
if (actual->dato == valor) {
return indice;}
actual = actual->siguiente;
indice++;}
return -1;}
pnodo buscar_por_indice(tlista lista, int indice) {
pnodo actual = lista.inicio;
int contador = 0;
while (actual != nullptr) {
if (contador == indice) {
return actual;}
actual = actual->siguiente;
contador++;}
return nullptr;}
int main() {
tlista lista;
iniciarlista(lista);
pnodo nuevo;
for (int i = 0; i < 3; ++i) {
crearnodo(nuevo);
agregarfinal(lista, nuevo);}
cout << "Mostrando la lista:";
mostrar(lista);
int valorBuscado;
cout << "Ingrese valor a buscar (buscar_indice): ";
cin >> valorBuscado;
int pos = buscar_indice(lista, valorBuscado);
if (pos != -1)
cout << "El valor " << valorBuscado << " se encuentra en la posición logica: " << pos << endl;
else
cout << "Valor no encontrado";
int indiceBuscado;
cout << "Ingrese indice a buscar (buscar_por_indice): ";
cin >> indiceBuscado;
pnodo nodoEncontrado = buscar_por_indice(lista, indiceBuscado);
if (nodoEncontrado != nullptr)
cout << "El nodo en el indice " << indiceBuscado << " contiene: " << nodoEncontrado->dato << endl;
else
cout << "Indice fuera de rango";
return 0;}
