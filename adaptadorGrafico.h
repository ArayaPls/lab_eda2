/**
	@file adaptadorGrafico.h
	@brief Cabecera y documentacion de elementos graficos por consola.
	@autor Sebastian Araya Vallejos.
	@date 10/2014
*/
#ifndef ADAPTADOR_GRAFICO_H
#define ADAPTADOR_GRAFICO_H

/**
	@brief Limpia la consola.
	@returns Void
*/
void limpiar(void);

/**
	@brief Imprime el menu principal dle juego.
	@returns Void
*/
void imprimeMenuPrincipal(void);

/**
	@brief 
	@param tabulado Espaciado entre el borde de la pantalla y el logo del juego.
	@returns Void
*/
void imprimeImagenPrincipal(char* tabulado);

/**
	@brief Pausa el juego, esperando un ENTER.
	@returns Void
*/
void pausa(void);

#endif