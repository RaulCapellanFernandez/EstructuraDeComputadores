#include <stdio.h>

int main(void){
	int factorial = 0, num, i;

	printf("Introduce un numero: \n");
	scanf("%d",&num);

	if(num != 0)
		factorial = 1;

	for(i = 1; i <= num; i++){
		factorial = factorial * i;
	}

	printf("El resultado del factorial es: %d\n", factorial);
}