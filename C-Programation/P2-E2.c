//Librería que contiene las funciones scanf y printf
#include <stdio.h>
//Función principal del programa
int main (){
// Este programa convierte los km leídos en millas, yardas y pies
// mostrando el resultado por pantalla
// Declaro las variables de mi función
float Km, Millas, Yardas, Pies;
//Sustituyo la función ESCRIBA cadena por printf
printf("Escribe un número de kilómetros: ");
//Sustituyo la función LEA Km por scanf ( %f, &variableReal);
scanf(" %f", &Km); //Guarda el número leído en la variable Km
//Convierto los km a millas:
Millas = Km /1.60;
//Convierto los km a pies:
Pies = Km * 100000 / 30.48 ;
//Convierto los km a yardas:
Yardas = Km * 100000 / 91.44;
//Imprimo los resultados
/*printf("Las millas son: ");
printf(" %f", Millas);
printf("\n Los pies son: ");
printf("%f", Pies);
printf("\nLas yardas son: ");
printf(" %f", Yardas);
printf("\nFin del algoritmo");*/
printf("Las millas son: %f \nLas yardas son: %f \n Los pies son: %f\nFin dl algoritmo\n", Millas, Yardas, Pies);
//Fin del programa
return 0;
}