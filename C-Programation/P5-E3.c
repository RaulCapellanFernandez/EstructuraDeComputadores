#include <stdio.h>

int main(void){
	int m, n, boolean = 0, resultado = 0;

	printf("Introduce un numero m:\n");
	scanf("%d",&m);
	printf("Introduce un numero n: \n");
	scanf("%d",&n);

	if(m > n){
		while(boolean == 0){
			if(m!=n){
				resultado = resultado +m;
				m--;
			}else if( m == n){
				resultado = resultado +m;
				printf("La suma del intervalo es: %d\n",resultado);
				boolean = 1;
			}
		}

	}else
		printf("Error m debe ser mayor que n\n");
}