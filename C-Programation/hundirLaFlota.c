#include <stdio.h>
#include <stdlib.h>

void menuJuego(int opcion);

int main(void){
	int opcion;

	menuJuego(opcion);
}

void menuJuego(int opcion){
	printf("--------------------------------------\n");
	printf("         HUNDIR LA FLOTA\n");
	printf("--------------------------------------\n");
	printf("1.Ordenador VS Jugador\n");
	printf("2.Ordenador VS Ordenador\n");
	printf("3.Salir\n");
	printf("--------------------------------------\n");

	scanf("%d",&opcion);
	switch(opcion){
		case 1: printf("\n     ---------Ordenador VS Jugador---------\n");
				printf("     1.Colocar los barcos de forma automatica\n");
				printf("     2.Colocar los barcos de forma manual\n");
				printf("     3.Volver\n");
				printf("     ----------------------------------------\n");
				scanf("%d",&opcion);
				switch(opcion){
					case 1:
						break;
					case 2:
						break;
					case 3: printf("\n     -----Volver-----\n");
							menuJuego(opcion);
						break;
				}
			break;
		case 2: printf("\n-----Ordenador VS Ordenador-----\n");
			break;
		case 3: printf("\n-----Salir-----\n");
				exit(0);
			break;
	}
}