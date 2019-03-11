#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa(int matriz[5][5]);

int main(void){
	int matriz[5][5];
	int i,j;
	inicializa(matriz);

	for(i=0;i< 5 ;i++){
		for(j=0;j< 5;j++){
			printf("%d ",matriz[i][j]);
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
			num=1+rand()%(16-3);
			matriz[i][j] = num;
		}
	}
}