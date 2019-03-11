#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void enteros(int vector[20], int result[3]);

int main(void){
	int vector[20], result[3];
	int num; 


	for(int i = 0; i < 20; i++){
		printf("Introduce un numero al vector en la posicion %d:\n",i+1 );
		scanf("%d",&num);
		vector[i] = num;
	}

	enteros(vector, result);

	for(int i = 0; i < 3; i++){
		if(i == 0)
			printf("\nHay %d ceros\n",result[i]);
		if(i == 1)
			printf("\nHay %d positivos\n",result[i]);
		if(i ==2)
			printf("\nHay %d negativos\n",result[i]);
	}
}

void enteros(int vector[20], int result[3]){
	result[0] = 0;
	result[1] = 0;
	result[2] = 0;

	for(int i = 0; i < 20; i++){
		if(vector[i] == 0)
			result[0]++;
		if(vector[i] > 0)
			result[1]++;
		if(vector[i] < 0)
			result[2]++;
	}
}