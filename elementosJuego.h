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

//codigo cartas numericas
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
	
//codigo de cartas especiales
#define CARTA_INVERTIR 10
#define CARTA_SALTA_TURNO 11
#define CARTA_SUMA_2 12
#define CARTA_CAMBIA_COLOR 13
#define CARTA_SUMA_4 14

//tipo de jugador
#define JUGADOR_CPU 15
#define JUGADOR_HUMANO 16

//cantidad de cartas de mano inicial
#define MANO_INICIAL 7

/**
	@brief Renombramiento de char para hacer booleanos.
*/
typedef char boolean;
//definiciones de booleanos
#define TRUE 1
#define FALSE 0

/**
	@brief Imprime cartas miniaturas para reconocimiento visual.
	@param numero Numero de cartas a dibujar.
	@returns void
*/
void imprimirCartitas(int numero);

/**
	@brief Imprime el tipo del jugador y cuantas cartas tiene.
	@param jugador Jugadores a mostrar
	@param mano Manos de cartas a mostrar
	@returns void 
*/
void imprimeEstadoJugadores(nodo* jugador, nodo** mano);

/**
	@brief Muestra las cartas de forma comrensible.
	@param lista Lista de cartas a mostrar
	@returns void
*/
void mostrarCartas(nodo* lista);

/**
	@brief Muestra mano del jugador.
	@param lista Mano a mostrar
	@param tab Espaciado para mostrar.
	@returns void
*/
void mostrarMano(nodo* lista, char* tab);

/**
	@brief Lista las cartas.
	@param lista lista de cartas a mostrar
	@param tab espaciado para mostrar
	@returns void
*/
void listarCartas(nodo* lista, char* tab);

/**
	@brief Muestra el orden de turnos
	@param lista Lista con turnos de jugadores.
	@returns void
*/
void muestraTurnos(nodo* lista);

/**
	@brief Imprime por consola el color del codigo de forma elegante.
	@param cod Codigo de color.
	@returns void
*/
void imprimeColor(int cod);

/**
	@brief Imprime por consola el tipo del codigo de forma elegante.
	@param cod Codigo de tipo.
	@returns void
*/
void imprimeTipo(int cod);


/**
	@brief Espera un 'enter' para continuar.
	@returns void
*/
void pausa(void);

/**
	@brief Crea el mazo con cartas de forma aleatoria.
	@returns Retorna lista con el mazo.

*/
nodo* crearMazo(void);

/**
	@brief Imprime la carta que se ve del pozo.
	@returns void
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

	@param jugadores
	@param mano
	@param mazo
	@param nodo
	@param turno
	@param sentido
	@param cambioColor
	@returns Retorna verdadero si la jugada fue exitosa, falso de lo contrario.
*/
boolean logicaTurno(nodo** jugadores, nodo** mano, nodo** mazo, nodo** pozo, int* turno, char* sentido,char opcion[], char colorCambio);

/**
	@brief Regla que limita cuando se pude botar una carta.
	@param carta
	@param pozo
	@param colorCambio
	@returns Retorna TRUE si se puede botar carta, FALSE de lo contrario.
*/
boolean reglaBotarCarta(nodo* carta, nodo* pozo, char colorCambio);

/**
	@brief Regla que limita cuando se puede robar una carta.
	@param carta 
	@param pozo
	@param colorCambio
	@returns Retorna TRUE si se puede botar carta, FALSE de lo contrario.
*/
boolean reglaRobarCarta(nodo* mano, nodo* pozo, char colorCambio);

/**
	@brief Logica de la jugada de la computadora.
	@param jugadores
	@param mano
	@param mazo
	@param nodo
	@param turno
	@param sentido
	@param cambioColor
	@returns Retorna verdadero si la jugada fue exitosa, falso de lo contrario.
*/
boolean jugadaAutomatica(nodo** jugadores, nodo** mano, nodo** mazo, nodo** pozo, int* turno, char* sentido,char colorCambio);

/**
	@brief Da vuelta las cartas del pozo al mazo y coloca una carta en el pozo.
	@param mazo
	@param pozo
	@returns Retorna el mazo nuevo.
*/
nodo* volteaPozo(nodo** mazo, nodo** pozo);

#endif