/**
	@file main.c
	@brief Archivo principal del trabajo N2.
	@autor Sebastian Araya Vallejos.
	@date 10/2014
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "estructuras.h"
#include "elementosJuego.h"
#include "adaptadorGrafico.h"


#define TRUE 1
#define FALSE 0 
#define STRING_MAX 10
#define STRING_CHICO 4

typedef char boolean;

typedef struct nodoSimple{
	int dato;
	char dato2;
	struct nodoSimple* sig;
}nodo;

typedef struct retorno{
	struct nodo* mano;
	struct nodo* mazo;
	struct nodo* pozo;
}retorno;



void main(){
	printf("juego UNO!\n");
	
	srand(time(NULL));
	int r = rand();	
	
	char opcion[STRING_MAX];
	char opcionJuego[STRING_MAX];

	boolean menu = TRUE; //variable del bucle del menu de opciones inicial
	boolean juego = FALSE; //variable del bucle del juego
	boolean buclePreJuego = TRUE; //variable del bucle de las opciones del juego
	boolean bucleTurnosJuego = FALSE; //variable del bucle de las jugadas

	//bucle menu principal
	while(menu){
		//limpia la consola
		limpiar();
		imprimeMenuPrincipal();
		fflush(stdin);
		fgets(opcion, STRING_MAX, stdin);
		//opcion 1: entrar a un juego nuevo.
		if(atoi(opcion) == 1){
			juego = TRUE;
		}
		//opcion 2: salir
		if(atoi(opcion) == 2){
			menu = FALSE;
		}
		
		
		//bucle juego
		while(juego){

			buclePreJuego = TRUE;			
			//variables de juego
			char cantidadJugadores[STRING_MAX];
			nodo* jugadores = NULL; //jugadores
			nodo** manos = NULL; // cartas de los jugadores (puntero doble porque es un malloc de nodo*)
			nodo* mazo = NULL; //mazo del juego
			nodo* pozo = NULL; //donde se tiran las cartas

			while(buclePreJuego){
				//condiciones pre juego...
				limpiar();
				printf("Condiciones pre-juego.\n");
				
				//cuantos jugadores (incluyendo el humano)
				printf("ingrese la cantidad de jugadores [2-10]: ");
				fflush(stdin);
				fgets(cantidadJugadores,STRING_MAX, stdin);
				printf("jugadores: %d\n", atoi(cantidadJugadores));

				if(atoi(cantidadJugadores) < 2){
					juego = FALSE;
					buclePreJuego = FALSE;
				}
				else{
					//agrega jugadores a turnos (el jugador humano es el primero)
					manos = (nodo**)malloc(sizeof(nodo*)*atoi(cantidadJugadores));

					//int m;
					//for(m=0;m<atoi(cantidadJugadores);m++){
					//	manos[m] = NULL;
					//}
					
					//generamos el mazo del juego con orden aleatorio
					mazo = crearMazo();

					//colocamos una carta del mazo en el pozo.
					nodo* cartaInicial = obtener(mazo,0); //sacamos la primera carta 
					pozo = push(pozo, cartaInicial->dato, cartaInicial->dato2);
					mazo = borrarTipo(mazo, cartaInicial->dato,cartaInicial->dato2);


					//agregamos los jugadores a una lista
					//los cpus
					int t;
					for(t=0;t<atoi(cantidadJugadores)-1;t++)
					{
						jugadores = push(jugadores, JUGADOR_CPU,-1);
						//sacamos del mazo 7 cartas para la mano de cada jugador...
					}
					//humano
					jugadores = push(jugadores, JUGADOR_HUMANO,-1);

					//agregamos las manos
					int j,m;
					for(j=0;j<atoi(cantidadJugadores);j++){
						manos[j] = NULL;
						for(m=0; m<MANO_INICIAL;m++){
							//numero random
							
							//vemos una carta
							cartaInicial = obtener(mazo,0); //sacamos la primera carta
							//se coloca en la mano
							manos[j]= push(manos[j],cartaInicial->dato,cartaInicial->dato2);
							//se borra del mazo
							mazo = borrarTipo(mazo, cartaInicial->dato,cartaInicial->dato2);
						}
					}
					
					
					muestraTurnos(jugadores);
				//borrar
					printf("largo del mazo: %d\n", largo(mazo));
					listarCartas(mazo);
				//fin borrar
					printf("\nPresione ENTER para comenzar la partida...");
					pausa();

					//terminamos condiciones pre-juego
					buclePreJuego = FALSE;
					//y vamos al bucle de turnos...
					bucleTurnosJuego = TRUE;
				}
			}
			//turnos..
			limpiar();
			int turno=-1;
			char opcionJuego[STRING_MAX];
			nodo* jugadorActual;
			nodo* robada;
			//sentido del juego (para cartas invertir)
			char sentido = 1;
			retorno ret;
			while(bucleTurnosJuego){

				turno = estableceTurno(cantidadJugadores,turno, sentido);
				//imprime estado del juego
				imprimeEstadoJuego(mazo,pozo);
				//obtiene el jugador que le corresponde el turno.
				jugadorActual = obtener(jugadores,turno);

				if( jugadorActual->dato == JUGADOR_HUMANO){
					printf("Tu turno!\n");
					//muestra la mano del jugador
					mostrarMano(manos[turno]);

					//interaccion en turno
					printf("Opcion:");
					fflush(stdin);
					fgets(opcionJuego,STRING_MAX,stdin);
					//reaccion a la opcion
						//==================================================
						// Logica de jugada
						//**************************************************
						logicaTurno(&manos[turno], &mazo, &pozo, &turno, opcionJuego);
												
						//para salir
						if(atoi(opcionJuego) == -1){
							bucleTurnosJuego = FALSE;
							juego = FALSE;
						}
						//**************************************************
						//==================================================
						
					limpiar();
				}
				else{
					printf("Turno CPU %d\n", turno);
					//aqui hacer jugada automatica de bots.
				}
			}

			//liberamos lista de jugadores
			jugadores = anular(jugadores);
			//libera el mazo
			mazo = anular(mazo);
			//libarar el pozo
			pozo = anular(pozo);
			//libramos manos
			if(manos != NULL){
				int d;
				for(d=0; d < atoi(cantidadJugadores);d++){
					manos[d] = anular(manos[d]);
				}
				free(manos);	
			}
		}
	}
}