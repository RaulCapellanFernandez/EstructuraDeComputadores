#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Cantidad de barcos de cada tipos
#define NUMBARCOS1 4
#define NUMBARCOS2 2
#define NUMBARCCOS3 1

int menu();
void inicializaTableros(int filas, int colums, int **tablero);
void rellenaTableroAuto(int filas, int colums, int **tablero);
void rellenaTableroManual(int filas, int colums, int **tablero);
int calculoAleatorio(int max, int min);
void imprimirTablero(int **tablero, int filas, int colums);
int compruebaDisparo(int **tablero, int filas, int colums, int dispFila, int dispColums);
void juegoAutomatico(int **tJ1J1,int **tJ1J2,int **tJ2J1,int **tJ2J2, int filas, int colums);
void juegoManual(int **tJ1J1,int **tJ1J2,int **tJ2J1,int **tJ2J2, int filas, int colums);
int compruebaGanador(int **tablero, int filas, int colums);



int main(int argc, char *argv[]){
	srand(time(NULL));
	//Argumentos para el tamanio del tablero
	if(argc != 3){
		printf("\n-----------------El numero de argumentos introducidos es incorrecto-------------\n\n");
		exit(0);

	}else{
		if(atoi(argv[1]) < 5 || atoi(argv[2]) < 5){
			printf("\n-----------------El numero de argumentos introducidos es incorrectdo-------------\n\n");
			exit(0);
		}

	}
	int opcion,i,k;
	int filas = atoi(argv[1]);
	int colums = atoi(argv[2]);

	//Declara los punteros
	int **tJ1J1;//Tablero J1
	int **tJ1J2;//Tablero J1 apunta el tablero J2
	int **tJ2J2;//Tablero J2
	int **tJ2J1;//Tablero J2 apunta el tablero J1

	//Reserva espacio para los punteros
	tJ1J1 = (int **)malloc(filas*sizeof(int *));
	for(i = 0; i < filas; i++){
		tJ1J1[i] = (int *)malloc(colums*sizeof(int));
	}

	tJ1J2 = (int **)malloc(filas*sizeof(int *));
	for(i = 0; i < filas; i++){
		tJ1J2[i] = (int *)malloc(colums*sizeof(int));
	}

	tJ2J1 = (int **)malloc(filas*sizeof(int *));
	for(i = 0; i < filas; i++){
		tJ2J1[i] = (int *)malloc(colums*sizeof(int));
	}

	tJ2J2 = (int **)malloc(filas*sizeof(int *));
	for(i = 0; i < filas; i++){
		tJ2J2[i] = (int *)malloc(colums*sizeof(int));
	}


	inicializaTableros(filas, colums,tJ1J1);
	inicializaTableros(filas, colums,tJ1J2);
	inicializaTableros(filas, colums,tJ2J1);
	inicializaTableros(filas, colums,tJ2J2);

	opcion = menu();

	if(opcion == 1){
		printf("\n     ---------Ordenador VS Jugador---------\n");
		printf("     1.Colocar los barcos de forma automatica\n");
		printf("     2.Colocar los barcos de forma manual\n");
		printf("     3.Volver\n");
		printf("     ----------------------------------------\n");
		scanf("%d",&opcion);

		do{
			switch(opcion){
				case 1: printf("BARCOS DEL ORDENADOR");
						rellenaTableroAuto(atoi(argv[1]), atoi(argv[2]), tJ2J2);
						printf("\nTUS BARCOS");
						rellenaTableroAuto(atoi(argv[1]), atoi(argv[2]), tJ1J1);

						printf("\n\n/////////////////////////////////////////\n");
						printf("////////INICIA EL JUEGO//////////////////////\n");
						printf("/////////////////////////////////////////////\n");
						juegoManual(tJ1J1,tJ1J2,tJ2J1,tJ2J2,atoi(argv[1]), atoi(argv[2]));
						return(-1);
					break;
				case 2: printf("BARCOS DEL ORDENADOR");
						rellenaTableroAuto(atoi(argv[1]), atoi(argv[2]), tJ2J2);
						printf("\nTUS BARCOS\n");
						rellenaTableroManual(atoi(argv[1]), atoi(argv[2]), tJ1J1);

						printf("\n\n/////////////////////////////////////////\n");
						printf("////////INICIA EL JUEGO//////////////////////\n");
						printf("/////////////////////////////////////////////\n");
						juegoManual(tJ1J1,tJ1J2,tJ2J1,tJ2J2,atoi(argv[1]), atoi(argv[2]));
						return(-1);
					break;
				case 3: printf("\n     -----Volver-----\n");
						menu();
					break;
			}
		}while(1);

	}else if(opcion == 2){
		printf("\n     -----Ordenador VS Ordenador-----\n");
		printf("BARCOS JUGADOR1");
		rellenaTableroAuto(atoi(argv[1]), atoi(argv[2]), tJ1J1);
		printf("\nBARCOS JUGADOR2");
		rellenaTableroAuto(atoi(argv[1]), atoi(argv[2]), tJ2J2);
		
		printf("\n\n/////////////////////////////////////////\n");
		printf("////////INICIA EL JUEGO AUTOMATICO///////\n");
		printf("/////////////////////////////////////////\n");
		juegoAutomatico(tJ1J1,tJ1J2,tJ2J1,tJ2J2,atoi(argv[1]), atoi(argv[2]));
	}
}

int menu(){
	int opcion;
	do{
		printf("\n\n--------------------------------------\n");
		printf("         HUNDIR LA FLOTA\n");
		printf("--------------------------------------\n");
		printf("1.Ordenador VS Jugador\n");
		printf("2.Ordenador VS Ordenador\n");
		printf("3.Salir\n");
		printf("--------------------------------------\n");

		scanf("%d",&opcion);
		switch(opcion){
			case 1: return 1;
				break;
			case 2: return 2;
				break;
			case 3: printf("\n     -----Salir-----\n");
					exit(0);
				break;
		}
	}while(1);
}


void inicializaTableros(int filas, int colums, int **tablero){
	int i,k;
	//Se le da valor al las matrices
	for(i = 0; i < filas; i++){
		for(k = 0; k <colums; k++){
			tablero[i][k] = 0;
		}
	}

}

void rellenaTableroAuto(int filas, int colums, int **tablero){
	int i, k;
	int orient;
	int f,c;

	//Introduce el barco de tamanio 3
	orient = calculoAleatorio(1,0);//orientacion del barco
		f = calculoAleatorio(filas-1,0);
		c= calculoAleatorio(colums-1, 0);
		if(orient == 0){//Se coloca en horizonal
			tablero[f][c] = 3;
			if(c+1 < colums && c+2 < colums){
				tablero[f][c+1] = 3;
				tablero[f][c+2] = 3;
			}
			else if(c-1 >= 0 && c-2 >= 0){
				tablero[f][c-1] = 3;
				tablero[f][c-2] = 3;
			}else{
				tablero[f][c+1] = 3;
				tablero[f][c-1] = 3;
			}
		}
		if(orient == 1){//Se coloca en vertical
			tablero[f][c] = 3;
			if(f+1 < filas && f+2 < filas){
				tablero[f+1][c] = 3;
				tablero[f+2][c] = 3;
			}
			else if(f-1 >= 0 && f-2 >= 0){
				tablero[f-1][c] = 3;
				tablero[f-2][c] = 3;
			}else{
				tablero[f+1][c] = 3;
				tablero[f-1][c] = 3;
			}
		}
		printf("--\n");
	//Introduce el barco de tamanio 2
	for(i = 0; i < NUMBARCOS2; i++){
		orient = calculoAleatorio(1,0);//orientacion del barco
		do{
			f = calculoAleatorio(filas-1,0);
			c= calculoAleatorio(colums-1, 0);
		}while(tablero[f][c] != 0);

		tablero[f][c] = 2;
		if(orient == 0){//Los colocas en horizontal
			
			if(c+1 < colums && tablero[f][c+1] == 0)
				tablero[f][c+1] = 2;
			else if(c-1 >= 0 && tablero[f][c-1] == 0)
				tablero[f][c-1] = 2;
		}else if(orient ==1){
			
			if(f+1 < filas && tablero[f+1][c] == 0){
				tablero[f+1][c] = 2;
				
			}
			else if(f-1 >= 0 && tablero[f-1][c] == 0){
				tablero[f-1][c] = 2;

			}
		}
	}
	//Introduce los barcos de tamaño 1
	for(i = 0; i < NUMBARCOS1; i++){
		do{
			f = calculoAleatorio(filas-1,0);
			c= calculoAleatorio(colums-1, 0);
		}while(tablero[f][c] != 0);
		tablero[f][c] = 1;
	}
	//imprime la matriz de los barcos
	printf("\n\n");
	imprimirTablero(tablero,filas,colums);

}

void rellenaTableroManual(int filas, int colums, int **tablero){
	int f,c, o, s,i,k;
	int posIniF, posIniC, posUp, posDown;

	printf("/////////////////////////////\n");
	printf("///BARCO 3 POSICIONES://///// \n");
	printf("/////////////////////////////\n\n");

	do{
		printf("Introduce una fila: (de 0 a %d)\n", filas-1);
		scanf("%d",&f);
		printf("Introduce una columna: (de 0 a %d)\n", colums-1);
		scanf("%d",&c);
		
	}while(f < 0 || f >= filas || c < 0 || c >= colums);
	tablero[f][c] = 3;

	printf("introduce la orientacion del barco: \n");
	do{
		printf("1: Vertical\n");
		printf("2: Horizontal\n");
		scanf("%d",&o);
	}while(o < 0 || o > 2);
	posIniF = f;
	posIniC = c;

	if(o == 1){
		printf("--Introduce la segunda posicion del barco: \n");
		do{
			printf("1.Posicion superior \n");
			printf("2.Posicion inferior\n");
			scanf("%d",&o);
		}while(o < 0 || o > 2);
		if(o == 1){
			if(posIniF-1 >= 0){
				tablero[posIniF-1][c] = 3;
				posUp = posIniF-1;
				posDown = posIniF;
			}
			else{
				printf("No hay posiciones por encima se introduce la posicion inferior\n");
				tablero[posIniF+1][c] = 3;
				posUp = posIniF;
				posDown = posIniF+1;
			}
		}else{
			if(posIniF+1 < filas-1){
				tablero[posIniF+1][c] = 3;
				posUp = posIniF;
				posDown = posIniF+1;
			}
			else{
				printf("No hay posiciones por debajo se introduce la posicion superior\n");
				tablero[posIniF-1][c] = 3;
				posUp = posIniF-1;
				posDown = posIniF;
			}
		}

		printf("--Introduce la tercera posicion del barco\n");
		do{
			printf("1.Posicion superior \n");
			printf("2.Posicion inferior\n");
			scanf("%d",&o);
		}while(o < 0 || o > 2);
		if(o == 1){
			if(posUp-1 >= 0)
				tablero[posUp-1][c] = 3;
			else{
				printf("No hay posiciones por encima se introduce la posicion inferior\n");
				tablero[posDown+1][c] = 3;
			}
		}else{
			if(posDown+1 < filas-1)
				tablero[posDown+1][c] = 3;
			else{
				printf("No hay posiciones por debajo se introduce la posicion superior\n");
				tablero[posUp-1][c] = 3;
			}
		}
	}else{

		printf("--Introduce la segunda posicion del barco: \n");
		do{
			printf("1.Posicion izquierda \n");
			printf("2.Posicion derecha\n");
			scanf("%d",&o);
		}while(o < 0 || o > 2);
		if(o == 1){
			if(posIniC-1 >= 0){
				tablero[f][posIniC-1] = 3;
				posUp = posIniC;
				posDown = posIniC-1;
			}
			else{
				printf("No hay posiciones por encima se introduce la posicion derecha\n");
				tablero[f][posIniC+1] = 3;
				posUp = posIniC+1;
				posDown = posIniC;
			}
		}else{
			if(posIniC+1 < colums-1){
				tablero[f][posIniC+1] = 3;
				posUp = posIniC+1;
				posDown = posIniC;
			}
			else{
				printf("No hay posiciones por debajo se introduce la posicion izquierda\n");
				tablero[f][posIniC-1] = 3;
				posUp = posIniC;
				posDown = posIniC-1;
			}
		}
		
		printf("--Introduce la tercera posicion del barco\n");
		do{
			printf("1.Posicion izquierda \n");
			printf("2.Posicion derecha\n");
			scanf("%d",&o);
		}while(o < 0 || o > 2);
		printf("posUp -> %d\n",posUp);
		printf("posDown-> %d\n",posDown);
		if(o == 1){
			if(posDown-1 >= 0)
				tablero[f][posDown-1] = 3;
			else{
				printf("No hay posiciones por encima se introduce la posicion derecha\n");
				tablero[f][posUp+1] = 3;
			}
		}else{
			if(posUp+1 < filas-1)
				tablero[f][posUp+1] = 3;
			else{
				printf("No hay posiciones por debajo se introduce la posicion izquierda\n");
				tablero[f][posDown-1] = 3;
			}
		}
	}
	printf("\n///////////////////////////////////////////////////////////////////\n\n\n");
	

	for(i = 0; i < 2; i++){
		printf("/////////////////////////////\n");
		printf("///BARCO 2 POSICIONES://///// \n");
		printf("/////////////////////////////\n\n");

		do{
			printf("Introduce una fila: (de 0 a %d)\n", filas-1);
			scanf("%d",&f);
			printf("Introduce una columna: (de 0 a %d)\n", colums-1);
			scanf("%d",&c);
			
		}while(f < 0 || f >= filas || c < 0 || c >= colums || tablero[f][c] != 0);
		tablero[f][c] = 2;
		posIniF = f;
		posIniC = c;
		do{
			printf("--Introduce la siguiente posicion del barco: \n");
			do{
				printf("1.Posicion izquierda \n");
				printf("2.Posicion derecha\n");
				printf("3.Posicion arriba\n");
				printf("4.Posicion abajo\n");
				scanf("%d",&o);
			}while(o < 0 || o > 4);

			s = 0;
		
			printf("Introduce una de las opciones: \n");
			scanf("%d",&o);
			switch(o){
				case 1: if(posIniC-1 >= 0 && tablero[f][posIniC-1] == 0){
							tablero[f][posIniC-1] = 2;
							s = -1;
						}else
							printf("No se puede esa posicion\n");
					break;
				case 2: if(posIniC+1 < filas-1 && tablero[f][posIniC+1] == 0){
							tablero[f][posIniC+1] = 2;
							s= -1;
						}else
							printf("No se puede esa posicion\n");
					break;
				case 3: if(posIniF-1 >= 0 && tablero[posIniF-1][c] == 0){
							s = -1;
							tablero[posIniF-1][c] = 2;
						}else
							printf("No se puede esa posicion\n");
					break;
				case 4: if(posIniC+1 < filas-1 && tablero[posIniF+1][c] == 0){
							s = -1;
							tablero[posIniF+1][c] = 2;
						}else
							printf("No se puede esa posicion\n");
					break;
			}

		}while(s != -1);
		printf("\n///////////////////////////////////////////////////////////////////\n\n\n");
	}

	for(i = 0; i < 4; i++){
		printf("/////////////////////////////\n");
		printf("///BARCO 1 POSICIONES://///// \n");
		printf("/////////////////////////////\n\n");
		do{
			printf("Introduce una fila: (de 0 a %d)\n", filas-1);
			scanf("%d",&f);
			printf("Introduce una columna: (de 0 a %d)\n", colums-1);
			scanf("%d",&c);
		}while(f < 0 || f >= filas || c < 0 || c >= colums || tablero[f][c] != 0);
		tablero[f][c] = 1;
		printf("\n///////////////////////////////////////////////////////////////////\n\n\n");
	}

	//imprime la matriz de los barcos
	printf("\n\n");
	imprimirTablero(tablero, filas, colums);
	
}
void imprimirTablero(int **tablero, int filas, int colums){
	int i,k;
	for(i = 0; i < filas; i++){
		for(k = 0; k <colums; k++){
			printf("%d ", tablero[i][k]);
		}
		printf("\n");
	}
}
int compruebaDisparo(int **tablero, int filas, int colums, int dispFila, int dispColums){
	if(tablero[dispFila][dispColums] == 1){
		printf("---!!TOCADO BARCO DE 1!!----\n");
		return 1;
	}else if(tablero[dispFila][dispColums] == 2){
		printf("---!!TOCADO BARCO DE 2!!----\n");
		return 2;
	}else if(tablero[dispFila][dispColums] == 3){
		printf("---!!TOCADO BARCO DE 3!!----\n");
		return 3;
	}else if(tablero[dispFila][dispColums] == 0){
		printf("----!!AGUA!!-----\n");
		return -1;
	}
	else
		printf("!YA HABIA UN BARCO¡\n");
	return -9;
}
void juegoAutomatico(int **tJ1J1,int **tJ1J2,int **tJ2J1,int **tJ2J2, int filas, int colums){
	int dFila, dColums;
	int i,k,win;
	int cont = 0;
	while(1){
		cont++;
		printf("¿Donde quieres disparar J1? Filas y columnas\n");
		dFila = calculoAleatorio(filas-1 , 0);
		dColums = calculoAleatorio(colums-1 , 0);
		printf("Fila--> %d\n", dFila );
		printf("Columna--> %d\n\n", dColums);

		printf("Jugada %d JUGADOR1: \n", cont);
		i = compruebaDisparo(tJ2J2, filas, colums, dFila, dColums);
		if(i == 1 || i == 2 || i == 3){
			tJ1J2[dFila][dColums] = 9;
			tJ2J2[dFila][dColums] = 9;
		}else if(i == -1){
			tJ1J2[dFila][dColums] = 8;
		}
		printf("////////////////////////////////\n");
		printf("///TABLERO DISPAROS JUGADOR 1///\n");
		printf("////////////////////////////////\n");
		imprimirTablero(tJ1J2, filas, colums);
		//imprimirTablero(tJ2J2, filas, colums);
		//Comprueba si ha ganado
		win = compruebaGanador(tJ1J2,filas,colums);
		if(win == 1){
			printf("            !!!!!!!!!!! ERES EL GANADOR JUGADOR 1¡¡¡¡¡¡¡¡¡¡¡¡\n");
			exit(0);
		}

		printf("////////////////////////////////\n");

		printf("¿Donde quieres disparar J2? Filas y columnas\n");
		dFila = calculoAleatorio(filas-1 , 0);
		dColums = calculoAleatorio(colums-1 , 0);
		printf("Fila--> %d\n", dFila );
		printf("Columna--> %d\n\n", dColums);

		i = compruebaDisparo(tJ1J1, filas, colums, dFila, dColums);
		if(i == 1 || i == 2 || i == 3){
			tJ2J1[dFila][dColums] = 9;
			tJ1J1[dFila][dColums] = 9;
		}else if(i == -1){
			tJ2J1[dFila][dColums] = 8;
		}
		printf("////////////////////////////////\n");
		printf("///TABLERO DISPAROS JUGADOR 2///\n");
		printf("////////////////////////////////\n");
		imprimirTablero(tJ2J1, filas, colums);
		//imprimirTablero(tJ2J2, filas, colums);
		printf("////////////////////////////////\n");
		win = compruebaGanador(tJ2J1,filas,colums);
		if(win == 1){
			printf("            !!!!!!!!!!! ERES EL GANADOR JUGADOR 2¡¡¡¡¡¡¡¡¡¡¡¡\n");
			exit(0);
		}
	}
}

int calculoAleatorio(int max, int min){
	int numeroAleatorio = rand()%((max+1)-min)+min;
	return numeroAleatorio;
}
int compruebaGanador(int **tablero, int filas, int colums){
	int i ,k, cont = 0;

	for(i = 0; i < filas; i++){
		for(k = 0; k < colums; k++){
			if(tablero[i][k] == 9)
				cont++;
		}
	}
	if(cont == 11)
		return 1;
	else
		return 0;
}
void juegoManual(int **tJ1J1,int **tJ1J2,int **tJ2J1,int **tJ2J2, int filas, int colums){
	int dFila, dColums;
	int i,k,win;
	int cont = 0;
	while(1){
		cont++;
		do{
			printf("¿Donde quieres disparar J1? Filas y columnas\n");
			printf("     Introduce una fila: \n");
			scanf("%d",&dFila);
			printf("     Introduce una fila: \n");
			scanf("%d",&dColums);
		}while((dFila < 0 || dFila >= filas || dColums < 0 || dColums >= colums));

		printf("Jugada %d JUGADOR1: \n", cont);
		i = compruebaDisparo(tJ2J2, filas, colums, dFila, dColums);
		if(i == 1 || i == 2 || i == 3){
			tJ1J2[dFila][dColums] = 9;
			tJ2J2[dFila][dColums] = 9;
		}else if(i == -1){
			tJ1J2[dFila][dColums] = 8;
		}
		printf("////////////////////////////////\n");
		printf("///TABLERO DISPAROS JUGADOR/ ///\n");
		printf("////////////////////////////////\n");
		imprimirTablero(tJ1J2, filas, colums);
		//imprimirTablero(tJ2J2, filas, colums);
		//Comprueba si ha ganado
		win = compruebaGanador(tJ1J2,filas,colums);
		if(win == 1){
			printf("            !!!!!!!!!!! ERES EL GANADOR JUGADOR¡¡¡¡¡¡¡¡¡¡¡¡\n");
			exit(0);
		}

		printf("////////////////////////////////\n");

		printf("¿Donde quieres disparar J2? Filas y columnas\n");
		dFila = calculoAleatorio(filas-1 , 0);
		dColums = calculoAleatorio(colums-1 , 0);
		printf("Fila--> %d\n", dFila );
		printf("Columna--> %d\n\n", dColums);

		i = compruebaDisparo(tJ1J1, filas, colums, dFila, dColums);
		if(i == 1 || i == 2 || i == 3){
			tJ2J1[dFila][dColums] = 9;
			tJ1J1[dFila][dColums] = 9;
		}else if(i == -1){
			tJ2J1[dFila][dColums] = 8;
		}
		printf("////////////////////////////////\n");
		printf("///TABLERO DISPAROS ORDENADOR///\n");
		printf("////////////////////////////////\n");
		imprimirTablero(tJ2J1, filas, colums);
		//imprimirTablero(tJ2J2, filas, colums);
		printf("////////////////////////////////\n");
		win = compruebaGanador(tJ2J1,filas,colums);
		if(win == 1){
			printf("            !!!!!!!!!!! ERES EL GANADOR ORDENADOR¡¡¡¡¡¡¡¡¡¡¡¡\n");
			exit(0);
		}
	}
}