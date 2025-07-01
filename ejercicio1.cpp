/*De acuerdo a la definición de TDA lista simple, implemente el TDA y sus
operaciones fundamentales considerando que la lista solo tiene un puntero con la
dirección del primer nodo de la lista (HEAD). Luego, implemente la operación
mínimo que permita extraer el menor valor almacenado en una lista desordenada*/
#include<bits/stdc++.h>
using namespace std;
typedef struct tnodo *pnodo;
typedef struct tnodo{
 int dato;
 pnodo siguiente;};
 void crearnodo(pnodo &nuevo){
 nuevo = new tnodo;
 if(nuevo != NULL){
 cout << "Ingrese valor: ";
 cin >> nuevo -> dato;
 nuevo -> siguiente = NULL;}
 else{
 cout << "Memoria insuficiente" <<
endl;}}
void iniciarlista(pnodo &lista){
 lista = NULL;}
 void agregarinicio(pnodo &lista, pnodo nuevo){
 nuevo -> siguiente = lista;
 lista = nuevo;}
void agregarfinal(pnodo &lista, pnodo nuevo){
pnodo i;
if(lista == NULL){
lista = nuevo;}
else{
for(i = lista; i->siguiente != NULL;
i=i->siguiente);
i->siguiente = nuevo;}}
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
 pnodo eliminarinicio(pnodo &lista){
 pnodo borrado;
 if(lista==NULL){
 borrado = NULL;}
 else{
 borrado = lista;
 lista = lista->siguiente;
 borrado->siguiente = NULL;}
 return borrado;}
pnodo eliminarfinal(pnodo &lista){
 pnodo borrado, i;
 if(lista == NULL){
 borrado = NULL;}
 else{
 if(lista->siguiente == NULL){
 borrado=lista;
 lista=NULL;}
 else{
 for(i=lista; (i->siguiente)->siguiente != NULL;
i=i->siguiente);
 borrado = i->siguiente;
 i->siguiente = NULL;}}
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
void mostrar(pnodo lista){
 pnodo i;
 if(lista != NULL){
 for(i = lista; i != NULL; i = i->siguiente){
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
pnodo extraerMinimo(pnodo &lista) {
pnodo mini,antmin,actual,anterior;
if (lista==nullptr) {
cout << "La lista está vacía." << endl;
return nullptr;}
mini=lista;
antmin=nullptr;
actual=lista;
anterior=nullptr;
while (actual != nullptr) {
if (actual->dato < mini->dato) {
mini = actual;
antmin = anterior;}
anterior = actual;
actual=actual->siguiente;}
if (antmin==nullptr) {
lista=mini->siguiente;}
else {
antmin->siguiente=mini->siguiente;}
mini->siguiente=nullptr;
return mini;}
main()
{pnodo lista;
int a;
iniciarlista(lista);
pnodo nuevo;
cout<<"Ingrese la cantidad de nodos"<<endl;
cin>>a;
for(int i=0;i<a;i++){
crearnodo(nuevo);
agregarinicio(lista,nuevo);}
cout<<"Primera lista:"<<endl;
mostrar(lista);
pnodo minnodo=extraerMinimo(lista);
if(minnodo!=nullptr)
cout<<"Minimo ="<<minnodo->dato<<endl;
delete minnodo;}
