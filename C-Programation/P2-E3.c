#include <stdio.h>

int main(void){
	int celsius = 0;
	float faren = 0;

	printf("introduce los grados Cº: ");
	scanf("%d",&celsius);

	faren = (celsius *9/5) +32;

	printf("\nLos grados farenheith son: %f\n",faren);
}
