#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa(int matriz[3][6]);
void suma(int matriz[3][6], int columnas[6]);

int main(void){
	int matriz[3][6];
	int columnas[6];
	int i,j;
	int result;

	inicializa(matriz);
	suma(matriz, columnas);

	for(i=0;i< 3 ;i++){
		for(j=0;j< 6;j++){
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for(j=0;j< 6;j++){
		printf("%d ",columnas[j]);
	}
	
}

void inicializa(int matriz[3][6]){
	int i,j;
	int num;

	srand(time(NULL));
	for(i = 0; i < 3; i++){
		for(j = 0; j < 6; j++){
			num=1+rand()%(10-1);
			matriz[i][j] = num;
		}
	}
}

void suma(int matriz[3][6], int columnas[6]){
	int result = 0;
	int i,j;

	for(j = 0; j < 6; j++){
		columnas[j] = 0;
	}

	for(i = 0; i < 3; i++){
		for(j = 0; j < 6; j++){
			columnas[j] += matriz[i][j];
		}
	}
}