#include <stdio.h>
#include <math.h>

int potencias(int base, int exponente);

int main(void){
	int num1, num2;

	printf("Introduce un numero: \n");
	scanf("%d",&num1);
	printf("Introduce otro numero: \n");
	scanf("%d",&num2);

	if(num1 > 0 && num2 > 0){
		printf("El resultado es: %d\n",potencias(num1, num2));
	}else 
		printf("Los dos numeros deben ser positivos\n");
}

int potencias(int base, int exponente){
	int resultado;
	
	resultado = pow(base,exponente);
	return resultado;
}
///NO ENTIENDO POQUE HAY QUE PONER LM PARA EJECUTARLO