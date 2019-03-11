#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void inicializa(int vector[10]);
int maximo(int vector[10]);

int main(void){
	int vector[10];
	int max;

	inicializa(vector);
	max = maximo(vector);
	printf("\n\n\n--------%d----------- es el maximo\n\n\n", max);
}

void inicializa(int vector[10]){
	int num;
	for(int i = 0; i < 10; i++){
		printf("Introduce un numero al vector en la posicion %d:\n",i+1 );
		scanf("%d",&num);
		vector[i] = num;
	}

	
}

int maximo(int vector[10]){
	int maximo = 0;

	for(int i = 0; i < 10; i++){
		if(vector[i] > maximo){
			maximo = vector[i];
		}
	}
	return maximo;
}
