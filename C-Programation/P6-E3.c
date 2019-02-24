#include <stdio.h>

void imprime(int num1, int num2);

int main(void){
	int num1, num2;
	printf("---------------------\n");
	printf("Introduce un numero: \n");
	scanf("%d",&num1);
	printf("Introduce otro numero: \n");
	scanf("%d",&num2);
	printf("------------------------------------------\n");

	if(num1 >= num2)
		imprime(num1,num2);
	else
		printf("El numero 1 debe ser mayor que el numero 2\n");
}

void imprime(int num1, int num2){
	int i;
	
	printf("Los numero pares son:\n");
	printf("------------------------------------------\n");
	for(i = num1 ; i >= num2; i--){
		if(i%2 == 0)
			printf("%d\n",i);
	}
}