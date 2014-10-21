/**
	@file elementosJuego.h
	@brief Cabecera y descripcion de elementos del juego.
	@autor Sebastian Araya Vallejos.
	@date 10/2014
*/
#ifndef ELEMENTOS_JUEGO_H
#define ELEMENTOS_JUEGO_H
#include "estructuras.h"

//codigo de color
#define AZUL 1
#define ROJO 2
#define VERDE 3
#define AMARILLO 4
#define NOCOLOR 5

//codigo de tipo 
#define CARTA_0 0
#define CARTA_1 1
#define CARTA_2 2
#define CARTA_3 3
#define CARTA_4 4
#define CARTA_5 5
#define CARTA_6 6
#define CARTA_7 7
#define CARTA_8 8
#define CARTA_9 9
//codigo especiales
#define CARTA_INVERTIR 10
#define CARTA_SALTA_TURNO 11
#define CARTA_SUMA_2 12
#define CARTA_CAMBIA_COLOR 13
#define CARTA_SUMA_4 14

//jugador
#define JUGADOR_CPU 15
#define JUGADOR_HUMANO 16

#define MANO_INICIAL 7

typedef char boolean;
#define TRUE 1
#define FALSE 0

/**
	Muestra las cartas de forma comrensible.
*/
void mostrarCartas(nodo* lista);

/**
	Muestra mano del jugador.
*/
void mostrarMano(nodo* lista);

/**
	Lista las cartas.
*/
void listarCartas(nodo* lista);

/**
	Muestra turnos.
*/
void muestraTurnos(nodo* lista);

/**
	Imprime por consola el color del codigo de forma elegante.
*/
void imprimeColor(int cod);

/**
	Imprime por consola el tipo del codigo de forma elegante.
*/
void imprimeTipo(int cod);


/**
	Espera un 'enter'
*/
void pausa(void);

/**
	@brief Crea el mazo con cartas de forma aleatoria.

*/
nodo* crearMazo(void);

/**
	imprime la carta que se ve del pozo.
*/
void imprimeEstadoJuego(nodo* mazo, nodo* pozo);

/**
	Cuenta los turnos.
*/
int estableceTurno(char cantidadJugadores[], int turno, char sentido);

/**
	@brief Efectos de las acciones de la interaccion con el jugador.

	Ejecuta las acciones y limita las jugadas del jugador humano
	para que no rompa las reglas del juego.

	@param mano
	@param mazo
	@param nodo
	@returns void
*/
void logicaTurno(nodo** mano, nodo** mazo, nodo** pozo, int* turno, char opcion[]);

/**
*/
boolean reglaBotarCarta(nodo* carta, nodo* pozo);

#endif