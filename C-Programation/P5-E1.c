#include <stdio.h>

int main (void){
	int segundos, min, horas, dias;
	printf("Introduce un numero de segundos: \n");
	scanf("%d",&segundos);

	dias = segundos /86400;
	segundos = segundos%86400;
	horas = segundos /3600;
	segundos = segundos % 3600;
	min = segundos/60;
	segundos = segundos%60;

	printf("Dias %d horas %d minutos %d segundos %d\n",dias,horas,min,segundos );


}