#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
//Declaracion de clases
//Clase Atraccion
class Atraccion{
private:
    string nombre;
    int hora;
    int minutoM;
    int minutom;
    int afluencia;
    int mEdad;
public:
    Atraccion(){
        nombre = generarNombre();
        hora = generarHora();
        minutoM = generarMinutoM();
        minutom = generarMinutom();
        afluencia = 0;
        mEdad=0;
    }
    int getmEdad(){
        return mEdad;
    }
    void setmEdad(int ed){
        mEdad = ed;
    }
    string getNombre(){
        return nombre;
    }
    void setAfluencia(int afl){
        afluencia = afl;
    }
    void aumentarAfluencia(){
        afluencia = afluencia+1;
    }
    int getAfluencia(){
        return afluencia;
    }
    int getMinutoM() {return minutoM;}
    int getMinutom() {return minutom;}
    int getHora() const {return hora;}
    void cambiarHora(){
        hora = generarHora();
    }
    void cambiarMinutoM(){
        minutoM = generarMinutoM();
    }
    void cambiarMinutom(){
        minutom = generarMinutom();
    }
    string generarNombre(){
        string nombres[34] = {"HURAKAN-CONDOR", "AMAZONIA", "BATMAN",
                            "STUNT-FALL","TORNADO", "CICLON","SUPERMAN",
                            "LA-MAQUINA","LANZADERA","AUTOPIA","ABISMO","LOS-FIORDOS","TIO-VIVO","COCHES-DE-CHOQUE",
                            "LEX-LUTHOR","GUARDIANES-DE-LA-GALAXIA","CINE4D","SHAMBHALA","CASA-DEL-TERROR","ZEPPELIN","BOOMERANG",
                            "RATON-VACILON","TUTUKI-SPLASH","TAMI-TAMI","COASTER-EXPRESS","TOM-JERRY","RIO-BRAVO","TOP-SPIN","ROTOR",
                            "TIFON","LASER-BLAST","LIBERTY-ARCADE","ORBITRON","RC-RACER"};
        string n = "";
        int numaleat;
        numaleat = rand()%(34);
        n = nombres[numaleat];
        return n;
    }
    int generarHora(){
        int numaleat;
        numaleat = 12+rand()%(22-12);
        return numaleat;
    }
    int generarMinutoM(){
        int numaleat;
        numaleat = rand()%(5);
        return numaleat;
    }
    int generarMinutom(){
        int numaleat;
        numaleat = rand()%(9);
        return numaleat;
    }
    void verDatosAtr(){
        cout<<"NOMBRE ATRACCION:"<<nombre<<endl;
        cout<<"HORA:"<<hora<<":"<<minutoM<<minutom<<endl;
    }
    void verStats(){
        cout<<"VECES VISITADO:"<<afluencia<<endl;
        cout<<"MEDIA DE EDAD:"<<mEdad/20<<" ANNOS"<<endl;
    }
};
//Clase NodoL(Nodo de Lista)
typedef Atraccion Dato;
class NodoL{
protected:
    Dato dato;
    NodoL* enlace;
    friend class Lista;
public:

    const Atraccion& getAtr()  {return dato;}
    void setAtr( Atraccion& atr) {this->dato = atr;}
    NodoL(Dato t){
        dato = t;
        enlace = NULL;
    }
    NodoL(Dato p, NodoL*n){
        dato = p;
        enlace = n;
    }
    Dato datoNodo() {
        return dato;
    }
    NodoL* enlaceNodo(){
        return enlace;
    }
    void ponerEnlace(NodoL* sgte){
        enlace = sgte;
    }
};
//Clase Lista
class Lista{
protected:
    NodoL* primero;
public:
    Lista(){
        primero = NULL;
    }
    void insertar(Atraccion atr);
    void ordenarLista();
    void verLista();
    NodoL* buscarListaP(int posicion);
    NodoL* buscarLista(string destino);
    NodoL* getPrimero(){
        return primero;
    }
    void modificarAfluencia(Atraccion destino);
    void modificarEdad(int edad, Atraccion destino);
    int longitudLista();
};
//clase Cliente
class Cliente{
private:
    string nombre;
    int edad;
    int nDni;
    int iden;
    int nAtracciones;
    string fecha;
    Lista listaAtr;
public:
    Cliente(){
        nombre = generarNombre();
        nDni = generarDNI();
        edad = generarEdad();
        iden = generarIden();
        nAtracciones = generarnAtracciones();
        fecha = "11-1-2019";
        listaAtr = Lista();
    }
    int getEdad(){
        return edad;
    }
    void setNAtracciones(int n){
        nAtracciones = n;
    }
    Lista getListaAtracciones(){
        return listaAtr;
    }
    int getNAtracciones(){
        return nAtracciones;
    }
    int getDni(){
        return nDni;
    }
    void generarLista(Lista listaParque, int maxi);
    string generarNombre(){
        string nombres[20] = {"Oscar", "Estela", "Cristina" ,"Lola", "Leandro", "Loli", "Mamen", "Carlos", "Pepe", "Carolina", "Miguel", "Adan", "Adela", "Carla", "Carina", "Yolanda", "Isidro", "David", "Chris", "Groot"};
        string n = "";
        int numaleat;
        numaleat = rand()%(20);
        n = nombres[numaleat];
        return n;
    }
    int generarDNI(){
        int numaleat;
        numaleat = 10000000+rand()%(99999999-10000000);
        return numaleat;
    }
    int generarEdad(){
        int numaleat;
        numaleat = 9+rand()%(80-9);
        return numaleat;
    }
    int generarnAtracciones(){
        int numaleat;
        numaleat = 2+rand()%(5);
        return numaleat;
    }
    int generarIden(){
        int numaleat;
        numaleat = 1000+rand()%(9999-1000);
        return numaleat;
    }
    void verDatos(){
        cout<<nombre<<endl;
        cout<<"EDAD:"<<edad<<endl;
        cout<<"DNI:"<<nDni<<endl;
        cout<<fecha<<endl;
        cout<<"NUMERO ATRACCIONES:"<<nAtracciones<<endl;
        cout<<"Numero IDENTIFICADOR:"<<iden<<endl;
        listaAtr.verLista();
    }
};
//////////////////////
//CLASE NODO DEL ARBOL
//////////////////////
typedef Cliente TipoElemento;
/////
class Nodo{
protected:
    TipoElemento dato;
    Nodo* izquierda;
    Nodo* derecha;
public:
    Nodo(TipoElemento valor){
        dato = valor;
        izquierda = derecha = NULL;
    }
    Nodo(TipoElemento valor, Nodo* ramaIzqu, Nodo* ramaDer){
        dato = valor;
        izquierda = ramaIzqu;
        derecha = ramaDer;
    }
    //operaciones de acceso
    TipoElemento valorNodo(){
        return dato;
    }
    Nodo* ramaDerecha(){
        return derecha;
    }
    Nodo* ramaIzquierda(){
        return izquierda;
    }
    //operaciones de modificacion
    void nuevoValor(TipoElemento d){
        dato = d;
    }
    void ramaIzq(Nodo* n){
        izquierda = n;
    }
    void ramaDere(Nodo* n){
        derecha = n;
    }
    void visitar(Lista listaAtr){
        int c=0;
        while(c!=dato.getNAtracciones()){
            listaAtr.buscarLista(dato.getListaAtracciones().buscarListaP(c)->datoNodo().getNombre())->datoNodo().setAfluencia(+1);
            c++;
        }
        listaAtr.buscarLista(dato.getListaAtracciones().buscarListaP(c)->datoNodo().getNombre())->datoNodo().setAfluencia(+1);
    }
};
///CLASE ARBOL
class ArbolBinario{
protected:
    Nodo* raiz;
private:
    void preorden(Nodo* r, Lista listaAtr){
        if(r!=NULL){
            r->visitar(listaAtr);
            preorden(r->ramaDerecha(), listaAtr);
            preorden(r->ramaIzquierda(), listaAtr);
        }
    }
public:
    void preorden(Lista listaAtr){
        preorden(raiz, listaAtr);
    }
    
    ArbolBinario(){
        raiz = NULL; //Se crea arbol vacio
    }
    ArbolBinario(Nodo* r){
        raiz = r;
    }
    void Praiz(Nodo* r){
        raiz = r;
    }
    Nodo * Oraiz(){
        return raiz;
    }
    Nodo raizArbol(){
        if(esVacio()==false){
            return *raiz;
        }
        else{
            throw "Arbol Vacio";
        }
    }
    bool esVacio(){
        return raiz==NULL;
    }
    Nodo * hijoIzq(){
        if(!esVacio()){
            return raiz->ramaIzquierda();
        }
        else{
            throw "Arbol Vacio";
        }
    }
    Nodo * hijoDer(){
        if(!esVacio()){
            return raiz->ramaDerecha();
        }
        else{
            throw "Arbol Vacio";
        }
    }
    Nodo * nuevoArbol(Nodo* ramaIzqda, Nodo* ramaDerec, TipoElemento dato){
        return new Nodo(dato, ramaIzqda, ramaDerec);
    }
    //operaciones exclusivas arboles binarios de busqueda
    Nodo* buscar(int buscado);
    void insertarR(TipoElemento valor);
    Nodo* insertar(Nodo* raizSub, TipoElemento dato);
    void eliminarR(TipoElemento dato);
    Nodo* eliminar(Nodo* raizSub, TipoElemento dato);
    Nodo* reemplazar(Nodo* act);
};