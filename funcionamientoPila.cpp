//este programa es para ver el funcionamiento de una pila con punteros. 

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <cstdlib>

using namespace std;

struct Nodo{
	int numero;
	Nodo *sig;
};
struct Pila{
	Nodo *nodo;
};

void apilar (int numero, Pila *pila){
	Nodo *aux = new Nodo ();
	aux->numero = numero;
	aux->sig = pila->nodo;
	
	pila->nodo = aux;
}
void desapilar (Pila *pila){	
	if (pila->nodo != NULL){
		pila->nodo = pila->nodo->sig;
	}
	
}
void imprimir (Pila *&pila){
	Nodo *aux = new Nodo ();
	aux = pila->nodo;
	cout << ("Entrada de datos// ");
	while (aux != NULL){
		cout <<  ("  +") << aux->numero;
		aux = aux -> sig;
	}
}


int contadorNecesarioParaQueSeCreeAleatorio = -1;
int azar (int numeroMaximoAleatorio){
	int numero;
	srand (time(NULL));  //me proporciona un numero aleatorio cada vez que lanzo el programa de nuevo. 
	if (contadorNecesarioParaQueSeCreeAleatorio == -1){
		contadorNecesarioParaQueSeCreeAleatorio = rand()%100;
	}else{
		contadorNecesarioParaQueSeCreeAleatorio++;
	}
	srand (contadorNecesarioParaQueSeCreeAleatorio);
	numero = rand()%numeroMaximoAleatorio;
	return numero;
}

int main (){
	cout << ("Funcionamiento de una pila, las órdenes son: apilar, desapilar, cima, vacia, imprimir.");
	Pila *miPila = new Pila (); 
	miPila -> nodo = NULL;
	
	bool verdad = true;
	char orden[20];
	int numero = 0;
	
	while (verdad == true){
		cout << ("\n Escriba la orden:  ");
		cin.getline (orden, 20, '\n');
		
		if (strcmp (orden, "salir") == 0){  //este ''==0'' es porque devuelve 0 en el caso de que sean iguales, mayor a cero  en el caso de que el primer string sea mayor, y viceversa en el caso de que sea menor. 
			cout <<("\n Se va a salir del programa.");
			verdad = false;
			break;
		}else if (strcmp(orden, "apilar") == 0){
			cout << ("\n Se va a rellenar un dato.");
			numero = azar (100);
			apilar (numero, miPila);
		}else if (strcmp (orden, "desapilar") == 0){
			cout << ("\n Se desapila un dato. ");
			desapilar (miPila);		
		}else if (strcmp (orden, "imprimir") == 0){
			cout << ("\n Se va a imprimir la pila.");
			imprimir (miPila);
		}else{
			cout << ("\n No se ha entendido la orden. ");
		}	
	}
	cout << ("\n");
	return 0;
}

