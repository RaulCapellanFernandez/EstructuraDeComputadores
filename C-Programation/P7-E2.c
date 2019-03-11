#include <stdio.h>
#include <math.h>
#include <stdlib.h>


float media(int vector[15]);
float varianza(int vector[15]);
float desviacion(int vector[15]);

int main(void){
	int vector[15];
	int num; 
	float result;

	for(int i = 0; i < 15; i++){
		printf("Introduce un numero al vector en la posicion %d:\n",i+1 );
		scanf("%d",&num);
		vector[i] = num;
	}

	result = media(vector);
	printf("\nLa media es: %f\n",result);
	result = varianza(vector);
	printf("\nLa varainza es: %f\n",result);
	result = desviacion(vector);
	printf("\nLa desviacion es: %f\n",result);

}
float media(int vector[15]){
	float media = 0;
	for(int i = 0; i < 15; i++){
		media += vector[i];
	}
	media = media/15;
	return media;
}
float varianza(int vector[15]){
	float med = media(vector);
	float varianza = 0;

	for(int i = 0; i < 15; i++){
		varianza += pow((vector[i]-med),2);
	}
	varianza = varianza/15;

	return varianza;
}
float desviacion(int vector[15]){
	float des;
	float var = varianza(vector);

	des = sqrt(var);
	return des;

}