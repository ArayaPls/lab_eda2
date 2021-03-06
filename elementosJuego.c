/**
	@file elementosJuego.c
	@brief Cabecera y descripcion de elementos del juego.
	@autor Sebastian Araya Vallejos.
	@date 10/2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elementosJuego.h"
#include "estructuras.h"
#include "adaptadorGrafico.h"
	
#define TRUE 1
#define FALSE 0
typedef char boolean;

typedef struct nodoSimple{
	int dato;
	char dato2;
	struct nodoSimple* sig;
}nodo;

void imprimirCartitas(int numero){
	int i;
	
	for(i=0;i<numero;i++){
		if(i==0){
			printf("[");
		}
		if(i>=0)
			printf("]");
	}
}

void imprimeEstadoJugadores(nodo* jugador, nodo** mano){
	int i;
	int nTurnos = largo(jugador);
	nodo* aux; 
	printf("\n ____________________________________\n");
    printf("|(turno)  -  (jugador)  |  (cartas)   /\n");
    printf("|____________________________________/\n");
    //por cada carta...
	for(i=0; i<nTurnos;i++){
		 aux = obtener(jugador,i);
		 printf("  [%2d]    - ",i+1);
		 //imprime el tipo de jugador
		 if(aux->dato == JUGADOR_HUMANO){
		 	printf("Player      | ");
		 }
		 else if(aux->dato == JUGADOR_CPU){
		 	printf("Computadora | ");
		 }
		 imprimirCartitas(largo(mano[i]));
		 printf("\n");
	}	
	printf(" ____________________________________\n");
	printf("|____________________________________\\\n");
}

void mostrarMano(nodo* lista, char* tab){

	printf("%s/==< Mi Mano >===================\\\n",tab);
	printf("%s  0- Robar carta.\n", tab);
	listarCartas(lista, tab);
	printf("%s\\================================/\n",tab);
}

void listarCartas(nodo* lista, char* tab){

	int i;
	int nCartas = largo(lista);
	nodo* aux;
	//por cada carta...
	for(i=0; i<nCartas;i++){
		 aux = obtener(lista,i);
		 printf("%s %2d- ",tab, i+1);
		 //imprime el color de la carta
		 imprimeColor(aux->dato2);
		 //imprimer el tipo de carta (numero o especial)
		 imprimeTipo(aux->dato);
		 printf("\n");
	}
}

void muestraTurnos(nodo* jugador){

	int i;
	int nTurnos = largo(jugador);
	nodo* aux;
	//por cada carta...
	     printf("(turnos)    (jugador)\n");
	for(i=0; i<nTurnos;i++){
		 aux = obtener(jugador,i);
		 printf("  [%d]   - ",i+1);
		 //imprime el tipo de jugador
		 if(aux->dato == JUGADOR_HUMANO){
		 	printf("Player");
		 }
		 else if(aux->dato == JUGADOR_CPU){
		 	printf("Computadora");
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

	//randomiza el mazo colocando cartas en una pila de forma aleatoria
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
	printf("  Cartas en mazo: %d |",largo(mazo));
	printf("  Carta en pozo: "); 
	imprimeColor(obtener(pozo,0)->dato2); 
	imprimeTipo(obtener(pozo,0)->dato);
	printf("\n\n");
}

int estableceTurno(int cantidadJugadores, int turno, char sentido){

	int turnoNuevo;
	if(sentido){
			turnoNuevo = turno+1;
	}
	else{
			turnoNuevo = turno-1;
	}
	if(turnoNuevo < 0){
		turnoNuevo = cantidadJugadores-1;
	}
	else if(turnoNuevo > cantidadJugadores-1){
		turnoNuevo = 0;
	}
	return turnoNuevo;
}

boolean logicaTurno(nodo** mano, nodo** mazo, nodo** pozo, int* turno, char opcion[]){
	int largoMano = largo(*mano);
	int opcionNumerica = atoi(opcion);
	
	//robar carta
	if(opcionNumerica == 0 && reglaRobarCarta(*mano, *pozo)){
		//saca carta de arriba del mazo
		nodo* robada = obtener(*mazo, 0);
		//la pone en la mano
		*mano = push(*mano, robada->dato, robada->dato2);
		//borramos carta del mazo
		*mazo = borrarTipo(*mazo, robada->dato, robada->dato2);
		return FALSE;
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
			//notifica que temrina su turno
			return TRUE;
		}
		else{
			printf("No puede botar esa carta! [ENTER]\n");
			pausa();
			return FALSE;
		}
	}
	//condicion de borde para tirar carta
	else if(opcionNumerica > largoMano){
		return FALSE;
	}
	return FALSE;
}

boolean reglaBotarCarta(nodo* carta, nodo* pozo){
	//si...
	if(carta->dato2 != obtener(pozo,0)->dato2 //los colores son diferentes
		&& (carta->dato2 != NOCOLOR && obtener(pozo,0)->dato2 != NOCOLOR) //si no hay SIN COLOR
		&& carta->dato != obtener(pozo,0)->dato 	// si tienen codigo diferente
																		){
		//notifica que no puede botar carta
		return FALSE;
	}
	//notifica que puede botar carta
	return TRUE;
}

boolean reglaRobarCarta(nodo* mano, nodo* pozo){
	//por cada carta de la mano se aplica regla "reglaBotarCarta()"
	int i, largoMano = largo(mano);
	for(i=0;i<largoMano;i++){
		if(reglaBotarCarta(obtener(mano,i),pozo)){
			//notifica que no puede robar carta
			return FALSE;
		}
	}
	//notifica que puede robar carta
	return TRUE;
}

boolean jugadaAutomatica(nodo** mano, nodo** mazo, nodo** pozo, int* turno){
	//por cada carta de la mano se aplica regla "reglaBotarCarta()"
	int i, largoMano = largo(*mano);
	nodo* descarta; 

	//busca una carta en la mano y tira la primera que puede
	for(i=0;i<largoMano;i++){
		//la carta que se quiere descartar...
		descarta = obtener(*mano, i);
		//chequeo si se puede botar carta...
		if(reglaBotarCarta(descarta,*pozo)){
			*pozo = push(*pozo, descarta->dato, descarta->dato2);
			//la borra de la mano...
			*mano = borrarTipo(*mano, descarta->dato, descarta->dato2);	
			//notifica que su turno ha terminado
			printf(", ha botado carta...\n");
			return TRUE;
		}
	}
	//si no pudo botar una carta roba...
	//saca carta de arriba del mazo
	nodo* robada = obtener(*mazo, 0);
	//la pone en la mano
	*mano = push(*mano, robada->dato, robada->dato2);
	//borramos carta del mazo
	*mazo = borrarTipo(*mazo, robada->dato, robada->dato2);
	//notifica que su turno aun no termina
	printf(", ha robado una carta...\n");
	return FALSE;
}

nodo* volteaPozo(nodo** mazo, nodo** pozo){

	//randomiza el mazo colocando cartas en una pila de forma aleatoria
	nodo* mazoRandom = NULL;
	int largoPozo = largo(*pozo);
	int i;
	int indiceRandom;
	nodo* elemento;
	for(i=0;i<largoPozo; i++){

		indiceRandom = rand()%(largo(*pozo)-1);
		elemento = obtener(*pozo, indiceRandom);
		mazoRandom = push(mazoRandom, elemento->dato, elemento->dato2);
	}
	//luego la primera carta pasa a ser el pozo..
	*pozo = obtener(mazoRandom, 0);
	mazoRandom = pop(mazoRandom);

	return mazoRandom;
}
