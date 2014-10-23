/**
	@file estructuras.h
	@brief Cabecera y descripcion de estructuras de datos de listas.

	Estructura de datos 'lista', con funciones TDA, se incluyen POP y PUSH, para facil manejo
	de las listas como pilas.

	@autor Sebastian Araya Vallejos.
	@date 10/2014
*/
#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

/**
	@brief renombramiento y declaracion del nodo.

	Se crean listas que tienen un dato tipo 'int' y uno de tipo 'char'.
*/
typedef struct nodoSimple nodo;

/**
	@brief Crea una lista con un dato.
	@param inDato Dato del nodo que se quiere agregar.
	@param inDato2 dato del nodo que se quiere agregar.
	@returns retorna la lista creada.
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
	@brief Inserta un elemento al comienzo de la lista.
	@param lista Lista a la que se quiere agregar.
	@param inDato dato del nodo que se quiere agregar.
	@param inDato2 dato del nodo que se quiere agregar.
	@returns Retorna la lista con el nodo agregado.
*/
nodo* push(nodo* lista, int inDato, char inDato2);

/**
	@brief Borra el primer elemento de la fila('pop' de pila).
	@param lista La lista a la que se quiere eliminar el elemento.
	@returns Retorna la lista sin el elemento borrado.

*/
nodo* pop(nodo* lista);

/**
	@brief Muestra la fila de forma elegante ({X1,X2,...,Xn}).
	@param lista Lista a imprimir.
	@returns void.
*/
void mostrarLista(nodo* lista);

/**
	@brief Borra el primer elemento que encuentra igual a "inDato".
	@param lista La lista que se quiere modificar.
	@param inDato dato del nodo que se quiere agregar.
	@ inDato2 dato del nodo que se quiere agregar.
	@returns Retorna la lista sin el primer nodo de ese tipo que se encuentra en la lista.
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