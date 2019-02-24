#include <stdio.h>

float volumen_cono(float radio, float altura);
float volumen_ortoedro(float lado1, float lado2, float altura);

int PI = 3.1416;

int main(void){
	float num1, num2, num3;
	int num;

	printf("----------------MENU-----------------\n");
	printf("1-Volmen Cono\n");
	printf("2-Volumen Ortoedro\n");
	printf("-------------------------------------\n");

	scanf("%d",&num);	

	switch(num){
		case(1):
			printf("VOLUMEN CONO\n");
			printf("-------------------------------------\n");
			printf("Introduce un radio: \n");
			scanf("%f",&num1);
			printf("Introduce una altura:\n");
			scanf("%f",&num2);
			printf("-------------------------------------\n");
			printf("El resultado es: %f\n",volumen_cono(num1,num2));
		break;

		case(2):
			printf("VOLUMEN ORTOEDRO\n");
			printf("-------------------------------------\n");
			printf("Introduce un lado: \n");
			scanf("%f",&num1);
			printf("Introduce otro lado: \n");
			scanf("%f",&num2);
			printf("Introduce la altura\n");
			scanf("%f",&num3);
			printf("-------------------------------------\n");
			printf("El resultado es: %f\n",volumen_ortoedro(num1,num2,num3));
		break;
	}
}

float volumen_cono(float radio, float altura){
	float resultado;
	resultado = 0.3333*3.1416*radio*radio*altura;
	return resultado;
}

float volumen_ortoedro(float lado1, float lado2, float altura){
	int resultado;

	resultado = lado1* lado2* altura;
	return resultado;
}