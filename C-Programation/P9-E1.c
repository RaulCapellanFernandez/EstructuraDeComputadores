#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa(int matriz[3][3]);
void multiplicacion(int matrizA [3][3],int matrizB [3][3], int matrizC [3][3]);

int main(void){
	int matrizA[3][3];
	int matrizB[3][3];
	int matrizC[3][3];
	int i,j;

	inicializa(matrizA);
	sleep(1);
	inicializa(matrizB);
	multiplicacion(matrizA,matrizB,matrizC);

	printf("\n");
	printf("\n");
	for(i=0;i< 3 ;i++){
		for(j=0;j< 3;j++){
			printf("%d ",matrizA[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	for(i=0;i< 3 ;i++){
		for(j=0;j< 3;j++){
			printf("%d ",matrizB[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	for(i=0;i< 3 ;i++){
		for(j=0;j< 3;j++){
			printf("%d ",matrizC[i][j]);
		}
		printf("\n");
	}
}

void inicializa(int matriz[3][3]){
	int i,j;
	int num;

	srand(time(NULL));
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			num=1+rand()%(11-1);
			matriz[i][j] = num;
		}
	}
}

void multiplicacion(int matrizA [3][3],int matrizB [3][3], int matrizC [3][3]){
	int i,j,k;

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			matrizC[i][j] = 0;
		}
	}

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			for(k = 0; k < 3; k++)
				matrizC[i][j] += matrizA[i][k]*matrizB[k][j];
		}
	}
}