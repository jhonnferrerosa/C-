#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "pecl2.h"
using namespace std;
int menu(){
    int o = 0;
    cout<<"1.-BUSCAR CLIENTE"<<endl;
    cout<<"2.-GENERAR DNI DE CLIENTE"<<endl;
    cout<<"3.-VER ESTADISTICAS DE ATRACCION"<<endl;
    cout<<"4.-VER ATRACCIONES DISPONIBLES"<<endl;
    cout<<"5.-GENERAR NUEVA ATRACCION"<<endl;
    cout<<"6.- TOP PARQUE"<<endl;
    cout<<"ELIJA OPCION:";
    cin>>o;
    return o;
}
void atraccionMasVista(Lista l){
    Atraccion masVista;
    NodoL* aux = l.getPrimero();
    if(aux == NULL){
        throw "LISTA VACIA";
    }
    else{
        while(aux!=NULL){
            if(aux->datoNodo().getAfluencia()>=masVista.getAfluencia()){
                masVista = aux->datoNodo();
            }
            aux = aux->enlaceNodo();
        }
    }
    cout<<"ATRACCION MAS VISTA: "<<endl;
    cout<<"NOMBRE: "<<masVista.getNombre()<<endl;
    masVista.verStats();
}
int main(){
    int n=0;
    int opc = 0;
    srand(time(NULL));
    Atraccion a, b ,c,d,e,f;
    Lista l = Lista();
    Cliente clientes[20];
    ArbolBinario arbol;
    l.insertar(a);
    l.insertar(b);
    l.insertar(c);
    l.insertar(d);
    l.insertar(e);
    l.insertar(f);
    int maxi = l.longitudLista();
    srand(time(NULL));
    while(n<20){
        clientes[n].generarLista(l,maxi);
        arbol.insertarR(clientes[n]);
        n++;
    }
    //cout<<"MENU GESTION PARQUES"<<endl;
    while(opc!=7){
        opc = menu();
        if(opc == 1){
            int dni;
            cout<<"DNI: ";
            cin>>dni;
            while(arbol.buscar(dni)==NULL){
                cout<<"TECLEE NUEVO DNI: ";
                cin>>dni;
            }
            Cliente cl = arbol.buscar(dni)->valorNodo();
            cl.verDatos();
        }
        if(opc==2){
            int num = 10000000+rand()%(99999999-10000000);
            while(arbol.buscar(num)==NULL){
                num = 10000000+rand()%(99999999-10000000);
            }
            cout<<arbol.buscar(num)->valorNodo().getDni()<<endl;
        }
        if(opc==3){
            string nombre;
            cout<<"NOMBRE ATRACCION: ";
            cin>>nombre;
            l.buscarLista(nombre);
            while(l.buscarLista(nombre)==NULL){
                cout<<"NOMBRE ATRACCION ERRONEO"<<endl;
                cout<<"ESCRIBA DE NUEVO:";
                cin>>nombre;
            }
            l.buscarLista(nombre)->datoNodo().verStats();
        }
        if(opc==4){
            NodoL* aux = l.getPrimero();
            if(aux == NULL){
                throw "LISTA VACIA";
            }
            else{
                while(aux!=NULL){
                    cout<<aux->datoNodo().getNombre()<<endl;
                    aux = aux->enlaceNodo();
                }
            }
        }
        if(opc==5){
            Atraccion z;
            srand(time(NULL));
            while(l.buscarLista(z.getNombre())!=NULL){
                z.generarNombre();
            }
            l.insertar(z);
            cout<<"ATRACCION CREADA"<<endl;
            cout<<"LA NUEVA ATRACCION DE NOMBRE "<<z.getNombre()<<" ESTARA OPERATIVA A PARTIR DE AHORA"<<endl;
            int numAleat = rand()%20;
            int cont = 0;
            int num = 0;
            while(cont<numAleat){
                num = 10000000+rand()%(99999999-10000000);
                while(arbol.buscar(num)==NULL){
                    num = 10000000+rand()%(99999999-10000000);
                }
                arbol.buscar(num)->valorNodo().getListaAtracciones().insertar(z);
                l.modificarAfluencia(z);
                l.modificarEdad(arbol.buscar(num)->valorNodo().getEdad(),z);
                arbol.buscar(num)->valorNodo().setNAtracciones(arbol.buscar(num)->valorNodo().getNAtracciones()+1);
                cont++;
            }
        }
        if(opc ==6){
            atraccionMasVista(l);
        }
    }
}
