/**
	@file estructuras.c
	@brief Estructuras de datos de listas.

	Estructura de datos 'lista', con funciones TDA, se incluyen POP y PUSH, para facil manejo
	de las listas como pilas.

	@autor Sebastian Araya Vallejos.
	@date 10/2014
*/
#include <stdio.h>
#include <stdlib.h>
#include "elementosJuego.h"

/**
	@brief renombramiento y declaracion del nodo.

	Se crean listas que tienen un dato tipo 'int' y uno de tipo 'char'.
*/
typedef struct nodoSimple{
	int dato;
	char dato2;
	struct nodoSimple* sig;
}nodo;

nodo* crearLista(int inDato, char inDato2){
	nodo* nueva = (nodo*)malloc(sizeof(nodo));
	if(nueva == NULL){
		printf("No se pudo crear nodo, error memoria!");
		return NULL;
	}
	nueva -> sig = NULL;
	nueva -> dato = inDato;
	nueva -> dato2 = inDato2;
	return nueva;
}

nodo* anular(nodo* lista){
	if(lista == NULL){
		printf("No se puedo anular, ya estaba vacia!\n");
		return NULL;
	}
	if(lista -> sig == NULL){
		free(lista);
		lista = NULL;
		return lista;
	}
	nodo* actual = lista;
	nodo* auxSig = lista;
	while(auxSig != NULL){
		auxSig = actual -> sig;
		free(actual);
		actual = NULL;
		actual = auxSig;
	}
	free(lista);
	lista = NULL;
	return lista;
}

nodo* insertar(nodo* lista, int inDato, char inDato2, int indice){
	if(lista == NULL){
		return crearLista(inDato, inDato2);
	}
	if(indice < 0){
		printf("Error insertar fuera de limites!, indice=%d\n",indice);
		return lista;
	}
	nodo* nuevo = crearLista(inDato, inDato2);
	if(indice == 0){
		nuevo -> sig = lista;
		return nuevo;
	}
	//insertamos en una indice de la lista.
	nodo* actual = lista;
	int contador = 1;
	while(actual != NULL){
		if(indice == contador){
			nuevo ->sig = actual->sig;
			actual->sig = nuevo;
			return lista;
		}
		actual=actual->sig;
		contador++;
	}	
	free(nuevo);
	nuevo = NULL;
	printf("Error insertar fuera de limites!, indice=%d.\n",indice);
	return lista;
}

nodo* push(nodo* lista, int inDato, char inDato2){
	nodo* nueva = crearLista(inDato, inDato2);
	if(lista == NULL){
		return nueva;
	}
	nueva -> sig = lista;
	return nueva;
}

nodo* pop(nodo* lista){
	if(lista == NULL){
		printf("Error pop, no habia elementos!\n");
		return lista;
	}
	if(lista-> sig == NULL){
		free(lista);
		lista = NULL;
		return lista;
	}
	nodo* nueva = lista->sig;
	free(lista);
	lista = NULL;
	return nueva;
}

void mostrarLista(nodo* lista){
	
	if(lista == NULL){
		printf("{} Vacia!\n");
		return;
	}
	nodo* actual = lista;
	printf("{");
	while(actual != NULL){
		printf("(%d,%d)",actual -> dato,actual->dato2);
		if(actual->sig == NULL){
			printf("}\n");
			return;
		}
		else{
			printf(",");
			
		}
		actual = actual-> sig;
	}
}

nodo* borrarTipo(nodo* lista, int inDato, char inDato2){
	//si es vacia
	if(lista == NULL){
		printf("Error borrarTipo, ya estaba vacia!\n");
		return NULL;
	}
	//si solo hay un elemento
	if(lista -> sig == NULL && (lista -> dato == inDato && lista-> dato2 == inDato2)){
		free(lista);
		lista = NULL;
		return lista;
	}
	//cuando hay mas de un elemento
	nodo* actual = lista;
	nodo* aux = NULL;
	//para el primer elemento
	if(actual -> dato == inDato && actual -> dato2 == inDato2){
		aux = actual->sig;
		free(actual);
		actual = NULL;
		return aux;
	}
	while(actual -> sig != NULL){
		//si el elemento a borrar esta en el siguiente, borramos y conectamos.
		if(actual->sig ->dato == inDato && actual->sig->dato2 == inDato2){
			aux = actual->sig->sig;
			free(actual->sig);
			actual->sig = aux;
			return lista;
		}
		actual = actual -> sig;
	}
	printf("Error borrar, no estaba en la lista!\n");
	return lista;
}

int largo(nodo* lista){
	int contador = 0;
	nodo* actual = lista;
	while(actual != NULL){
		contador++;
		actual = actual->sig;
	}
	return contador;
}

nodo* obtener(nodo* lista, int indice){
	if(indice < 0){
		printf("Error obtener, fuera de lista!, indice=%d\n",indice);
		return NULL;
	}
	int i;
	nodo* actual = lista;
	for(i=0;i<indice;i++){
		if(actual -> sig != NULL){
			actual = actual->sig;
		}
		else{
			printf("Error obtener, fuera de lista!, indice=%d\n",indice);
			return NULL;
		}
	}
	return actual;
}
