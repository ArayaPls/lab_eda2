/**
	@file adaptadorGrafico.c
	@brief Funciones graficas por consola.
	@autor Sebastian Araya Vallejos.
	@date 10/2014
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void limpiar(){
	/*
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	/**/
	#ifdef _WIN32
	//para windows
    system("cls");
	#else
    //para linux
    system ("clear");
	#endif
}
void imprimeMenuPrincipal(){
	printf("Menu\n");
	printf("\t1- Juego nuevo\n");
	printf("\t2- Salir\n");
	printf("\n");
	printf("\n");
}

void imprimeImagenPrincipal(char* tabulado){
	printf("%s=========================\n",tabulado);
	printf("%s=========================\n",tabulado);
	printf("%s   _    _ _   _  ____\n",tabulado);
	printf("%s  | |  | | \\ | |/ __ \\ \n",tabulado);
	printf("%s  | |  | |  \\| | |  | |\n",tabulado);
	printf("%s  | |  | | . ` | |  | |\n",tabulado);
	printf("%s  | |__| | |\\  | |__| |\n",tabulado);
	printf("%s  \\_____/|_| \\_|\\____/ \n\n",tabulado);
 	printf("%s=========================\n",tabulado);
	printf("%s====================v1.0=\n",tabulado);
	printf("%s   por Sebastian Araya");

}

void pausa(){
	fflush(stdin);
	getc(stdin);
}
  