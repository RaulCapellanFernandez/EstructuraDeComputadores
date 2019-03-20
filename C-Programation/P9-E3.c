#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa(int matriz[8][5]);
void minimoFilas(int matrizA [8][5], int vectorResult[8]);

int main(void){
	int matrizA[8][5];
	int i,j, result;
	int vectorResult [8];

	inicializa(matrizA);
	minimoFilas(matrizA, vectorResult);

	printf("\n");
	printf("\n");
	for(i=0;i< 8 ;i++){
		for(j=0;j< 5;j++){
			printf("%d ",matrizA[i][j]);
		}
		printf("\n");
	}
}

void inicializa(int matriz[8][5]){
	int i,j;
	int num;

	srand(time(NULL));
	for(i = 0; i < 8; i++){
		for(j = 0; j < 5; j++){
			num=-10+rand()%(11-(-10));
			matriz[i][j] = num;
		}
	}
}

void minimoFilas(int matrizA [8][5], int vectorResult[8]){
	int i,j;
	int max = 0;

	for(i = 0; i < 8; i++)
		vectorResult[i] = 0;

	for(i = 0; i < 8; i++){
		for(j = 0; j < 5; j++){
			if(vectorResult[i] < matrizA[i][j])
				vectorResult[i] = matrizA[i][j];
		}
	}


	for(i = 0; i < 8; i++)
		printf("El minimo de la fila %d es : %d\n",i+1, vectorResult[i]);
}



