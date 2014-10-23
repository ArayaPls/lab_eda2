/**
	@file main.c
	@brief Archivo principal del juego UNO.
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

typedef char boolean; //redefino chars para tener Booleanos

//estructura de lista enlazada simple
typedef struct nodoSimple{
	int dato;
	char dato2;
	struct nodoSimple* sig;
}nodo;

void main(){
	//mostramos una imagen super fancy
	imprimeImagenPrincipal("        ");
	printf("\n\n\tPulsa [ENTER] para comenzar!\n");
	pausa();
	//srand(time(NULL));
	char opcion[STRING_MAX];
	boolean menu = TRUE; //variable del bucle del menu de opciones inicial
	boolean buclePreJuego = FALSE; //variable del bucle de las opciones del juego
	boolean bucleTurnosJuego = FALSE; //variable del bucle de las jugadas

	//============================================
	// BUCLE MENU PRINCIPAL
	//--------------------------------------------
	while(menu){
		//limpia la consola
		limpiar();
		imprimeMenuPrincipal();
		fflush(stdin); //limpia buffer entrada
		fgets(opcion, STRING_MAX, stdin);

		//Opciones de entrada

		//opcion 1: entrar a un juego nuevo.
		if(atoi(opcion) == 1){
			buclePreJuego = TRUE;
		}
		//opcion 2: salir
		if(atoi(opcion) == 2){
			menu = FALSE;
		}

		//====================================================
		// BUCLE PRE-JUEGO
		//----------------------------------------------------
		
		char cantidadJugadores[STRING_MAX];
		char nJugadores;
		nodo* jugadores = NULL; //jugadores
		nodo* mazo = NULL; //mazo del juego
		nodo* pozo = NULL; //donde se tiran las cartas
		nodo** manos = NULL; // cartas de los jugadores (puntero doble porque es un malloc de nodo*)

		while(buclePreJuego){
			//====================================================
			// CONDICIONES PRE-JUEGO
			//----------------------------------------------------
			limpiar();
			printf("Condiciones pre-juego.\n");
			
			//cuantos jugadores (incluyendo el humano)
			printf("ingrese la cantidad de oponentes [1-11]: ");
			fflush(stdin);
			fgets(cantidadJugadores,STRING_MAX, stdin);
			nJugadores = atoi(cantidadJugadores)+1;
			printf("jugadores: %d\n", nJugadores);

			if(nJugadores < 2 || nJugadores > 12){
				buclePreJuego = FALSE;
			}
			else{
				//hacemos un arreglo de listas enlazadas que seran las manos.
				manos = (nodo**)malloc(sizeof(nodo*)*nJugadores);
				
				//generamos el mazo del juego con orden aleatorio
				mazo = crearMazo();

				//colocamos una carta del mazo en el pozo.
				nodo* cartaInicial = obtener(mazo,0); //sacamos la primera carta 
				pozo = push(pozo, cartaInicial->dato, cartaInicial->dato2);
				mazo = borrarTipo(mazo, cartaInicial->dato,cartaInicial->dato2);

				//agrega los jugadores a una lista...
					//...los CPU...
					int t;
					for(t=0;t<nJugadores-1;t++)
					{
						jugadores = push(jugadores, JUGADOR_CPU,-1);
					}
					//...y al humano.
					jugadores = push(jugadores, JUGADOR_HUMANO,-1);

				//agregamos las manos
				int j,m;
				for(j=0;j<nJugadores;j++){
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
				//muestra los turnos del juego antes de comenzar.
				muestraTurnos(jugadores);
			//borrar
				//printf("largo del mazo: %d\n", largo(mazo));
				//listarCartas(mazo);
			//fin borrar
				printf("\nPresione ENTER para comenzar la partida...");
				pausa();

				//terminamos condiciones pre-juego
				buclePreJuego = FALSE;
				//y vamos al bucle de turnos...
				bucleTurnosJuego = TRUE;
			}
		}
		//----------------------------------------------------------
		// FIN bucle pre-juego
		//==========================================================

		//==========================================================
		// BUCLE TURNOS DEL JUEGO
		//----------------------------------------------------------
		limpiar();
		int turno=-1; 	//turno actual
		char opcionJuego[STRING_MAX]; 	//entrada por teclado
		char sentido = 1; 	//sentido de los turnos (para cartas invertir)
		nodo* jugadorActual;	//jugador que le toca turno			

		while(bucleTurnosJuego){

			//verifica si quedan cartas en el mazo
			if(largo(mazo)<1){
				//si no hay cartas voltea el pozo
				mazo = volteaPozo(&mazo,&pozo);
			}
			turno = estableceTurno(nJugadores,turno, sentido);
			//imprime estado del juego
			imprimeEstadoJuego(mazo,pozo);
			//obtiene el jugador que le corresponde el turno.
			jugadorActual = obtener(jugadores,turno);

			if( jugadorActual->dato == JUGADOR_HUMANO){
				printf("Tu turno!\n");
				//muestra la mano del jugador
				mostrarMano(manos[turno],"  ");
				//imprimirCartitas(largo(manos[turno]));

				//interaccion en turno
				printf("  Botar carta: ");
				fflush(stdin);
				fgets(opcionJuego,STRING_MAX,stdin);
				//reaccion a la opcion
					//==================================================
					// JUGADA DEL JUGADOR HUMANO
					//--------------------------------------------------

					//si el turno no es exitoso, no se avanza al siguiente jugador...
					if(!logicaTurno(&jugadores,&manos[turno], &mazo, &pozo, &turno,&sentido, opcionJuego,0)){
						if(sentido){
							turno--;
						}
						else
							turno++;
					}
					else{
						if(largo(manos[turno])==0){
							limpiar();
							printf("\n\t\aFELICIDADES, HAS GANADO!!!\n\n");
							imprimeEstadoJugadores(jugadores,manos);
							printf("\n\t\aFELICIDADES, HAS GANADO!!!\n\n");
							bucleTurnosJuego = FALSE;
							printf("Presione [ENTER] para ontinuar...");
							pausa();
						}
					}
											
					//para salir
					if(atoi(opcionJuego) == -1){
						bucleTurnosJuego = FALSE;
					}
					//--------------------------------------------------
					// FIN jugada del jugador humano
					//==================================================
				//este "limpiar" permite que se vean solo las jugadas
				//de las CPU que se hacen hasta que le toca al usuario.
				limpiar();
			}
			else{
				//==========================================================
				//JUGADA AUTOMATICA DE COMPUTADORAS
				//----------------------------------------------------------
				printf("Turno Computadora %d, mano:", turno+1);
				imprimirCartitas(largo(manos[turno]));
				//si el turno no es exitoso, no se avanza al siguiente jugador...
				if(!jugadaAutomatica(&jugadores, &manos[turno], &mazo, &pozo, &turno, &sentido,0)){
					if(sentido){
						turno--;
					}
					else
						turno++;
				}
				else{
					if(largo(manos[turno])==0){
						limpiar();
						imprimeEstadoJuego(mazo,pozo);
						printf("\n\t\aLA COMPUTADORA %d, HA GANADO!\n",turno+1);
						imprimeEstadoJugadores(jugadores,manos);
						printf("\n\t\aLA COMPUTADORA %d, HA GANADO!\n",turno+1);
						bucleTurnosJuego = FALSE;
						printf("Presione [ENTER] para continuar...");
						pausa();
					}
				}
				//-----------------------------------------------------------
				// FIN jugada automatica de computadoras
				//===========================================================
			}
		}
		//--------------------------------------------------------------
		// FIN bucle turnos juego
		//==============================================================

		//======================================
		// LIBERACION DE MEMORIA
		//--------------------------------------
		//liberamos lista de jugadores
		jugadores = anular(jugadores);
		//libera el mazo
		mazo = anular(mazo);
		//libarar el pozo
		pozo = anular(pozo);
		//libramos manos
		if(manos != NULL){
			int d;
			for(d=0; d < nJugadores;d++){
				manos[d] = anular(manos[d]);
			}
			free(manos);	
		}
		//-------------------------------------
		// FIN liberacion memoria
		//=====================================
	}
	//--------------------------------
	// FIN bucle menu principal
	//================================
}