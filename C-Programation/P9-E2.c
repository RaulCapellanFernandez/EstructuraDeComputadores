#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa(int matriz[5][5]);
int maximo(int matrizA [5][5]);

int main(void){
	int matrizA[5][5];
	int i,j, result;

	inicializa(matrizA);
	result = maximo(matrizA);
	printf("\n\nEl maximo es %d\n",result );
	printf("\n");
	printf("\n");
	for(i=0;i< 5 ;i++){
		for(j=0;j< 5;j++){
			printf("%d ",matrizA[i][j]);
		}
		printf("\n");
	}
}

void inicializa(int matriz[5][5]){
	int i,j;
	int num;

	srand(time(NULL));
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			num=4+rand()%(10-4);
			matriz[i][j] = num;
		}
	}
}

int maximo(int matrizA [5][5]){
	int i,j;
	int max = 0;
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			if(max < matrizA[i][j])
				max = matrizA[i][j];
		}
	}
	return max;
}









