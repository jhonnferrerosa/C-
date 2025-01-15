#include <iostream>
#include <string>
#include <stdlib.h>
#include "pecl2.h"
using namespace std;
/////////////////
//METODOS LISTA//
/////////////////
void Lista::insertar(Atraccion atr)
{
    NodoL *nuevo = new NodoL(atr);
    //nuevo->dato = atr;
    if (primero == NULL) 
    {
        primero = nuevo;
    }
    else 
    {
        if (atr.getHora()==primero->dato.getHora()){ //LAS HORAS SON IGUALES, SE COMPARAN LAS DECENAS DE MINUTO
            if (atr.getMinutoM()==primero->dato.getMinutoM()){ //LAS DECENAS DE MINUTOS SON IGUALES, COMPARAR UNIDADES DE MINUTO
                if (atr.getMinutom()<primero->dato.getMinutom()) 
                {
                    nuevo->enlace = primero;
                    primero = nuevo;
                }
                else 
                {
                    NodoL *reco = primero;
                    NodoL *atras = primero;
                    while (atr.getMinutom() >= reco->dato.getMinutom() && reco->enlace!=NULL) 
                    {
                        atras = reco;
                        reco = reco->enlace;
                    }
                    if (atr.getMinutom() >= reco->dato.getMinutom()) 
                    {
                        reco->enlace = nuevo;
                    }
                    else
                    {
                        nuevo->enlace = reco;
                        atras->enlace = nuevo;
                    }
                }
            }
            if (atr.getMinutoM()<primero->dato.getMinutoM()) 
            {
                nuevo->enlace = primero;
                primero = nuevo;
            }
            else 
            {
                NodoL *reco = primero;
                NodoL *atras = primero;
                while (atr.getMinutoM() >= reco->dato.getMinutoM() && reco->enlace!=NULL) 
                {
                    atras = reco;
                    reco = reco->enlace;
                }
                if (atr.getMinutoM() >= reco->dato.getMinutoM()) 
                {
                    reco->enlace = nuevo;
                }
                else
                {
                    nuevo->enlace = reco;
                    atras->enlace = nuevo;
                }
            }
        }
        else if (atr.getHora()<primero->dato.getHora()) 
        {
            nuevo->enlace = primero;
            primero = nuevo;
        }
        else 
        {
            NodoL *reco = primero;
            NodoL *atras = primero;
            while (atr.getHora() >= reco->dato.getHora() && reco->enlace!=NULL) 
            {
                atras = reco;
                reco = reco->enlace;
            }
            if (atr.getHora() >= reco->dato.getHora()) 
            {
                reco->enlace = nuevo;
            }
            else
            {
                nuevo->enlace = reco;
                atras->enlace = nuevo;
            }
        }
    }
}
void Lista::ordenarLista(){
    NodoL *aux, *aux1;
    aux = primero;
    Atraccion a;
    while(aux->enlace!=NULL){
        aux1 = aux->enlace;
        while(aux1!=NULL){
            if(aux1->datoNodo().getHora()<aux->datoNodo().getHora()){
                a = aux->datoNodo();
                aux->datoNodo() = aux1->datoNodo();
                aux1->datoNodo() = a;
            }
            aux1 = aux1->enlace;
        }
        aux = aux->enlace;
    }
}
void Lista::verLista(){
    NodoL* aux = primero;
    if(aux == NULL){
        throw "LISTA VACIA";
    }
    else{
        while(aux!=NULL){
            aux->datoNodo().verDatosAtr();
            aux = aux->enlaceNodo();
        }
    }
}
NodoL* Lista::buscarListaP(int posicion){
    NodoL* indice;
    int i;
    indice = primero;
    if(0>=posicion){
        return NULL;
    }
    for(i=1;(i<posicion) && (indice!=NULL);i++){
        indice = indice->enlace;
    }
    return indice;
}
NodoL* Lista::buscarLista(string destino){
    NodoL* indice;
    for(indice = primero;indice!=NULL;indice = indice->enlace){
        if(destino == indice->dato.getNombre()){
            return indice;
        }
    }
    return NULL;
}
void Lista::modificarAfluencia(Atraccion destino){
    NodoL* indice;
    for(indice = primero;indice!=NULL;indice = indice->enlace){
        if(destino.getNombre() == indice->dato.getNombre()){
            indice->dato.setAfluencia(indice->dato.getAfluencia()+1);
        }
    }
}
int Lista::longitudLista(){
    NodoL* aux;
    aux = primero;
    int cont = 0;
    /*if(aux == NULL){
        throw "LISTA VACIA";
    }*/
    if(aux!=NULL){
        while(aux!=NULL){
            cont++;
            aux = aux->enlace;
        }
    }
    return cont;
}
void Lista::modificarEdad(int edad,Atraccion destino){
    NodoL* indice;
    for(indice = primero;indice!=NULL;indice = indice->enlace){
        if(destino.getNombre() == indice->dato.getNombre()){
            indice->dato.setmEdad(indice->dato.getmEdad()+edad);
        }
    }
}
/////////////////
//METODOS Cliente
/////////////////
void Cliente::generarLista(Lista listaParque, int maxi){
    int n = 0;
    int nu = 0;
    int nAtr = nAtracciones;
    while(n<nAtr){
        nu = 1+rand()%(maxi);
        Atraccion a = listaParque.buscarListaP(nu)->datoNodo();
        listaParque.modificarAfluencia(a);
        listaParque.modificarEdad(edad,a);
        a.cambiarHora();
        a.cambiarMinutoM();
        a.cambiarMinutom();
        listaAtr.insertar(a);
        n++;
    }
}
/////////////////
//METODOS ARBOL//
/////////////////
Nodo* ArbolBinario::buscar(int buscado){
    int dato;
    bool encontrado = false;
    Nodo* raizSub = raiz;
    dato = buscado;
    while(encontrado==false && raizSub != NULL){
        if(dato == raizSub->valorNodo().getDni()){
            encontrado = true;
        }
        else if(dato < raizSub->valorNodo().getDni()){
            raizSub = raizSub->ramaIzquierda();
        }
        else if(dato > raizSub->valorNodo().getDni()){
            raizSub = raizSub->ramaDerecha();
        }
    }
    if(encontrado != false){
       return raizSub; 
    }
    else{
        return NULL;
    }
}
void ArbolBinario::insertarR(TipoElemento valor){
    raiz = insertar(raiz, valor);
}
Nodo* ArbolBinario::insertar(Nodo* raizSub, TipoElemento dato){
    if(raizSub==NULL){
        raizSub = new Nodo(dato);
    }
    else if(dato.getDni()<raizSub->valorNodo().getDni()){
        Nodo *iz;
        iz = insertar(raizSub->ramaIzquierda(), dato);
        raizSub->ramaIzq(iz);
    }
    else if(dato.getDni()> raizSub->valorNodo().getDni()){
        Nodo *dr;
        dr = insertar(raizSub->ramaDerecha(), dato);
        raizSub->ramaDere(dr);
    }
    else{
        throw "Nodo duplicado"; //tratamiento de repeticion
    }
    return raizSub;
}
void ArbolBinario::eliminarR(TipoElemento dato){
    raiz = eliminar(raiz, dato);
}
Nodo* ArbolBinario::eliminar(Nodo* raizSub, TipoElemento dato){
    if(raizSub==NULL){
        throw "No se ha encontrado el nodo con la clave";
    }
    else if(dato.getDni() < raizSub->valorNodo().getDni()){
        Nodo* iz;
        iz = eliminar(raizSub->ramaIzquierda(), dato);
        raizSub->ramaIzq(iz);
    }
    else if(dato.getDni() > raizSub->valorNodo().getDni()){
        Nodo* dr;
        dr = eliminar(raizSub->ramaDerecha(), dato);
        raizSub->ramaIzq(dr);
    }
    else{   //Nodo encontrado
        Nodo *q;
        q = raizSub; //nodo a quitar del arbol
        if(q->ramaIzquierda()==NULL){
            raizSub = q->ramaDerecha();
        }
        else if(q->ramaDerecha()==NULL){
            raizSub = q->ramaIzquierda();
        }
        else{
            q = reemplazar(q);
        }
        q = NULL;
    }
    return raizSub;
}
Nodo* ArbolBinario::reemplazar(Nodo* act){
    Nodo *a, *p;
    p = act;
    a = act->ramaIzquierda(); //rama de nodos menores
    while(a->ramaDerecha() != NULL){
        p = a;
        a = a->ramaDerecha();
    }
    //copia en act el valor del nodo apuntado por a
    act->nuevoValor(a->valorNodo());
    if(p==act){//a es el hijo izquierdo de act
        p->ramaIzq(a->ramaIzquierda()); //enlaza subarbol izquierdo
    }
    else{
        p->ramaDere(a->ramaDerecha()); //enlaza subarbol derecho
    }
    return a;
}