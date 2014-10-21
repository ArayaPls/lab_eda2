/**
	@file elementosJuego.c
	@brief Cabecera y descripcion de elementos del juego.
	@autor Sebastian Araya Vallejos.
	@date 10/2014
*/

#include <stdio.h>
#include <stdlib.h>
#include "elementosJuego.h"
#include "estructuras.h"

#define TRUE 1
#define FALSE 0
typedef char boolean;

typedef struct nodoSimple{
	int dato;
	char dato2;
	struct nodoSimple* sig;
}nodo;

void mostrarCartas(nodo* lista){
	
	printf("/--< CARTAS >-----------------------\\\n");
	listarCartas(lista);
	
}

void mostrarMano(nodo* lista){

	printf("/--< Mi Mano >-----------------------------\\\n");
	printf("  0- Robar carta.\n");
	listarCartas(lista);
	printf("\\-----------------------------------------/\n");
	printf("Botar carta: ");
}

void listarCartas(nodo* lista){

	int i;
	int nCartas = largo(lista);
	nodo* aux;
	//por cada carta...
	for(i=0; i<nCartas;i++){
		 aux = obtener(lista,i);
		 printf(" %2d- ",i+1);
		 //imprime el color de la carta
		 imprimeColor(aux->dato2);
		 //imprimer el tipo de carta (numero o especial)
		 imprimeTipo(aux->dato);
		 printf("\n");
	}
}

void muestraTurnos(nodo* lista){

	int i;
	int nTurnos = largo(lista);
	nodo* aux;
	//por cada carta...
	     printf("(turnos)    (jugador)\n");
	for(i=0; i<nTurnos;i++){
		 aux = obtener(lista,i);
		 printf("  [%d]   Jugador - ",i+1);
		 //imprime el tipo de jugador
		 if(aux->dato == JUGADOR_HUMANO){
		 	printf("Player");
		 }
		 else if(aux->dato == JUGADOR_CPU){
		 	printf("CPU");
		 }
		 printf("\n");
	}	
}


void imprimeColor(int cod){
	if(cod == VERDE){
		printf("[  VERDE /");
	}
	else if(cod == AZUL){
		printf("[  AZUL  /");
	}
	else if(cod == ROJO){
		printf("[  ROJO  /");
	}
	else if(cod == AMARILLO){
		printf("[AMARILLO/");
	}
	else if(cod == NOCOLOR){
		printf("[  ----  /");	
	}
	else{
		printf("#CORRUPTO#");
	}
}

void imprimeTipo(int cod){
	
	if(cod == CARTA_0){
		printf("     0         ]");	
	}
	else if(cod == CARTA_1){
		printf("     1         ]");	
	}
	else if(cod == CARTA_2){
		printf("     2         ]");	
	}
	else if(cod == CARTA_3){
		printf("     3         ]");	
	}
	else if(cod == CARTA_4){
		printf("     4         ]");	
	}
	else if(cod == CARTA_5){
		printf("     5         ]");	
	}
	else if(cod == CARTA_6){
		printf("     6         ]");	
	}
	else if(cod == CARTA_7){
		printf("     7         ]");	
	}
	else if(cod == CARTA_8){
		printf("     8         ]");	
	}
	else if(cod == CARTA_9){
		printf("     9         ]");	
	}
	else if(cod == CARTA_SUMA_2){
		printf("   < +2 >      ]");	
	}
	else if(cod == CARTA_SUMA_4){
		printf("   < +4 >      ]");	
	}
	else if(cod == CARTA_INVERTIR){
		printf("   Invertir!   ]");	
	}
	else if(cod == CARTA_SALTA_TURNO){
		printf("  Salta Turno! ]");	
	}
	else if(cod == CARTA_CAMBIA_COLOR){
		printf(" Cambia Color! ]");	
	}
	else{
		printf("#corrupto#");	
	}

}

void pausa(){
	fflush(stdin);
	getc(stdin);
}

nodo* crearMazo(){

	nodo* mazo;
	srand(time(NULL));

	char color;
	for(color=1; color < 5; color++){
		int tipo;
		for(tipo=1; tipo< 13; tipo++){
			mazo = push(mazo, tipo, color);
			mazo = push(mazo, tipo, color);
		}
		mazo = push(mazo, CARTA_CAMBIA_COLOR, NOCOLOR);
		mazo = push(mazo, CARTA_0, color);
	}
	//cuatro cartas +4
	mazo = push(mazo, CARTA_SUMA_4, NOCOLOR);
	mazo = push(mazo, CARTA_SUMA_4, NOCOLOR);
	mazo = push(mazo, CARTA_SUMA_4, NOCOLOR);
	mazo = push(mazo, CARTA_SUMA_4, NOCOLOR);
	//cuatro cartas cambia color

	nodo* mazoRandom = NULL;
	int largoMazo = largo(mazo);
	int i;
	int indiceRandom;
	nodo* elemento;
	for(i=0;i<largoMazo; i++){

		indiceRandom = rand()%(largo(mazo)-1);
		elemento = obtener(mazo, indiceRandom);
		mazoRandom = push(mazoRandom, elemento->dato, elemento->dato2);
	}
	mazo = anular(mazo);
	return mazoRandom;
}

void imprimeEstadoJuego(nodo* mazo, nodo* pozo){
	printf("  Cartas en mazo: %3d\n",largo(mazo));
	printf("  Carta en pozo: "); 
	imprimeColor(obtener(pozo,0)->dato2); 
	imprimeTipo(obtener(pozo,0)->dato);
	printf("\n");
}

int estableceTurno(char cantidadJugadores[], int turno, char sentido){

	int turnoNuevo;
	if(sentido){
			turnoNuevo = turno+1;
	}
	else{
			turnoNuevo = turno-1;
	}
	if(turnoNuevo < 0){
		turnoNuevo = atoi(cantidadJugadores)-1;
	}
	else if(turnoNuevo > atoi(cantidadJugadores)-1){
		turnoNuevo = 0;
	}
	return turnoNuevo;
}

void logicaTurno(nodo** mano, nodo** mazo, nodo** pozo, int* turno, char opcion[]){
	int largoMano = largo(*mano);
	int opcionNumerica = atoi(opcion);
	
	//robar carta
	if(opcionNumerica == 0){
		//saca carta de arriba del mazo
		nodo* robada = obtener(*mazo, 0);
		//la pone en la mano
		*mano = push(*mano, robada->dato, robada->dato2);
		//borramos carta del mazo
		*mazo = borrarTipo(*mazo, robada->dato, robada->dato2);
	}

	//para tirar una carta
	else if(0 < opcionNumerica && opcionNumerica <= largoMano){
		//la carta que se quiere descartar...
		nodo* descartada = obtener(*mano, opcionNumerica-1);
		//chequeo si se puede botar carta...
		if(reglaBotarCarta(descartada,*pozo)){
			*pozo = push(*pozo, descartada->dato, descartada->dato2);
			//la borra de la mano...
			*mano = borrarTipo(*mano, descartada->dato, descartada->dato2);	
		}
		else
			printf("NOOOU!");
	}
	//condicion de borde para tirar carta
	else if(opcionNumerica > largoMano){
		printf("nope!\n");
	}
}

boolean reglaBotarCarta(nodo* carta, nodo* pozo){
	//si...
	
	if(carta->dato2 != obtener(pozo,0)->dato2 //los colores son diferentes
		&& (carta->dato2 != NOCOLOR && obtener(pozo,0)->dato2 != NOCOLOR) //si no hay SIN COLOR
		&& carta->dato != obtener(pozo,0)->dato 	// si tienen codigo diferente
												){
		return FALSE;
	}
	//holiasasd
	return TRUE;
	
}
