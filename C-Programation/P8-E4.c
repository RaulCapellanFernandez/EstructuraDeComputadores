#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa(int matriz[6][6]);
int suma(int matriz[6][6]);

int main(void){
	int matriz[6][6];
	int i,j;
	int result;

	inicializa(matriz);
	result = suma(matriz);

	for(i=0;i< 6 ;i++){
		for(j=0;j< 6;j++){
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}

	printf("La suma es: %d\n", result);
}

void inicializa(int matriz[6][6]){
	int i,j;
	int num;

	srand(time(NULL));
	for(i = 0; i < 6; i++){
		for(j = 0; j < 6; j++){
			num=1+rand()%(10-1);
			matriz[i][j] = num;
		}
	}
}

int suma(int matriz[6][6]){
	int result = 0;
	int i,j;

	for(i = 0; i < 6; i++){
		for(j = 0; j < 6; j++){
			result += matriz[i][j];
		}
	}

	return result;
}