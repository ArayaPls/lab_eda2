/**
	@file estructuras.h
	@brief Cabecera y descripcion de estructuras de datos de listas.

	Se crean listas que tienen un dato tipo 'int' y uno de tipo 'char'.

	@autor Sebastian Araya Vallejos.
	@date 10/2014
*/

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

//typedef struct nodoSimple nodo;
typedef struct nodoSimple nodo;

/**
	crea una lista con un dato...
*/
nodo* crearLista(int inDato, char inDato2);

/**
	@brief Borra la lista. liberando la memoria de cada nodo.
	@param lista Lista a modificar.
	@returns nodo* Retorna NULL, que es una lista vacia.
*/
nodo* anular(nodo* lista);

/**
	@brief Inserta un elemento en cierta posicion 'indice' de la lista.

	Inserta un elemento en la lista, en la posicion deseada.
	El indice, puede estar entre [0,largo(lista)].
	Ej: {a,b,c,d,e}, cuando se inserta un elemento X en posicion largo(lista),
	queda {a,b,c,d,e,X}, ya que el indice de la lista comienza en 0.

	@param lista Lista que se desea modificar.
	@param inDato Dato que se ingresa a la lista.
	@param inDato2
	@param indice Indice de posicion de insercion, debe estar entre 0 y n+1; n = el
	indice del ultimo elemento de la lista.
	@returns Retorna puntero a la lista (nodo*) luego de que se inserta el elemento.
*/
nodo* insertar(nodo* lista, int inDato, char inDato2, int indice);

/**
	Inserta un elemento al comienzo de la lista.
*/
nodo* push(nodo* lista, int inDato, char inDato2);

/**
	Borra el primer elemento de la fila.
*/
nodo* pop(nodo* lista);

/**
	@brief Muestra la fila de forma elegante ({X1,X2,...,Xn}).
	@param lista Lista a imprimir.
	@returns void.
*/
void mostrarLista(nodo* lista);
void mostrarLista2(nodo* lista);

/**
	Borra el primer elemento que encuentra igual a "inDato".
*/
nodo* borrarTipo(nodo* lista, int inDato, char inDato2);

/**
	@brief Retorna cuantos elementos hay en la lista.

	Retorna la cantidad de elementos que hay en la lista, NO el indice.

	@param lista Lista a contar el largo.
	@param inDato
	@param
	@returns Retorna entero con la cantidad de elementos que tiene la lista.
*/
int largo(nodo* lista);

/**
	@brief Obtiene el elemento buscado en la posicion 'indice'.
	@param lista Lista en que se busca el elemento.
	@param indice Indice en que se busca el elemento, debe ser un valor
	entre [0,n], con n: indice del ultimo elemento de la lista.
	@returns Retorna el elemento, si no puede encontrarlo retorna NULL.
*/
nodo* obtener(nodo* lista, int indice);



#endif