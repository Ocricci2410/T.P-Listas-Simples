/*Implemente una lista con puntero al inicio y al final además de un contador que
registre la cantidad de elementos actuales que hay en la lista. Realice las
modificaciones necesarias a los métodos agregar y eliminar para que actualice el
contador, además de agregar una función que retorne la cantidad de elementos
actuales de la lista*/
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
bool buscarnodo(pnodo lista, int valor){
 pnodo i;
 bool encontrado = false;
 if(lista != NULL){
 for(i=lista; i != NULL && encontrado == false;
i=i->siguiente){
 if(i->dato == valor){
 encontrado = true;}}}
 return encontrado;}
 int cantidad(tlista lista){
 return lista.contador;}
 main(){
 int a,b;
 tlista milista;
 iniciarlista(milista);
 pnodo nuevo;
 cout<<"Ingrese la cantidad de elementos a agregar por inicio:";
 cin>>a;cout<<endl;
 for(int i=0;i<a;i++){
crearnodo(nuevo);
agregarinicio(milista,nuevo);}
cout<<"Ingrese la cantidad de elementos a agregar por el final:";
 cin>>b;cout<<endl;
 for(int i=0;i<b;i++){
crearnodo(nuevo);
agregarfinal(milista,nuevo);}
cout<<"Lista Original"<<endl;
mostrar(milista);
cout<<"Cantidad de nodos="<<cantidad(milista)<<endl;
pnodo borrado=eliminarinicio(milista);
if(borrado!=nullptr){
cout<<"Nodo eliminado:"<<borrado->dato<<endl;
delete borrado;}
borrado=eliminarfinal(milista);
if(borrado!=nullptr){
cout<<"Nodo eliminado:"<<borrado->dato<<endl;
delete borrado;}
cout<<"Lista despues de eliminar:"<<endl;
mostrar(milista);
cout<<"Cantidad de nodos:"<<cantidad(milista)<<endl;}

