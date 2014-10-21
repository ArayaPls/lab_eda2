#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "estructuras.h"


typedef char boolean;

	typedef struct nodoSimple{
		int dato;
		char dato2;
		struct nodoSimple* sig;
	}nodo;

void main(){

	

	nodo* wea = NULL;

	int i;
	for(i=0; i< 999999; i++){
		wea = push(wea,i,2);
		printf("%d\n",i);

	}
	wea = anular(wea);

}