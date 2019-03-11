#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa(int matriz[9][9]);

int main(void){
	int matriz[9][9];
	int i,j;
	inicializa(matriz);

	for(i=0;i< 9 ;i++){
		for(j=0;j< 9;j++){
			printf("%d",matriz[i][j]);
		}
		printf("\n");
	}
}

void inicializa(int matriz[9][9]){
	int i,j;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			if(i == j)
				matriz[i][j] = 1;
			else
				matriz[i][j] = 0;
		}
	}
}