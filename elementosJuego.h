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
*/
void imprimirCartitas(int numero);

/**
	@imprime el tipo del jugador y cuantas cartas tiene.
*/
void imprimeEstadoJugadores(nodo* jugador, nodo** mano);

/**
	Muestra las cartas de forma comrensible.
*/
void mostrarCartas(nodo* lista);

/**
	Muestra mano del jugador.
*/
void mostrarMano(nodo* lista, char* tab);

/**
	Lista las cartas.
*/
void listarCartas(nodo* lista, char* tab);

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
	@brief Avanza los turnos.
	@param cantidadJugadores Cantidad de jugadores.
	@param turno Turno actual.
	@param sentido Direccion en la cual los turnos avanzan.
	@returns Retorna el turno que corresponde.
*/
int estableceTurno(int cantidadJugadores, int turno, char sentido);

/**
	@brief Efectos de las acciones de la interaccion con el jugador.

	Ejecuta las acciones y limita las jugadas del jugador humano
	para que no rompa las reglas del juego.

	@param mano
	@param mazo
	@param nodo
	@returns Retorna falso cuando el turno no fue exitoso.
*/
boolean logicaTurno(nodo** jugadores, nodo** mano, nodo** mazo, nodo** pozo, int* turno, char* sentido,char opcion[], char colorCambio);

/**
	@brief Regla que limita cuando se pude botar una carta.
*/
boolean reglaBotarCarta(nodo* carta, nodo* pozo, char colorCambio);

/**
	@brief Regla que limita cuando se puede robar una carta.
*/
boolean reglaRobarCarta(nodo* mano, nodo* pozo, char colorCambio);

/**
	@brief Logica de la jugada de la computadora.
*/
boolean jugadaAutomatica(nodo** jugadores, nodo** mano, nodo** mazo, nodo** pozo, int* turno, char* sentido,char colorCambio);

/**
	@brief Da vuelta las cartas del pozo al mazo y coloca una carta en el pozo.

	@returns Retorna el mazo nuevo.
*/
nodo* volteaPozo(nodo** mazo, nodo** pozo);

#endif