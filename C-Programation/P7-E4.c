#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void posNeg(int vector[15], int result[2]);

int main(void){
	int vector[15], result[2];
	int num; 


	for(int i = 0; i < 15; i++){
		printf("Introduce un numero al vector en la posicion %d:\n",i+1 );
		scanf("%d",&num);
		vector[i] = num;
	}

	posNeg(vector, result);

	for(int i = 0; i < 3; i++){
		if(i == 0)
			printf("\nHay %d par\n",result[i]);
		if(i == 1)
			printf("\nHay %d impar\n",result[i]);
	}
}

void posNeg(int vector[15], int result[3]){
	result[0] = 0;
	result[1] = 0;
	result[2] = 0;

	for(int i = 0; i < 15; i++){
		if(vector[i]%2 == 0)
			result[0]++;
		else
			result[1]++;
	}
}