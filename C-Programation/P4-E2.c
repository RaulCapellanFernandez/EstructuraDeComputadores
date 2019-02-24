//Librería que contiene las funciones scanf y printf
#include <stdio.h>
//Función principal del programa
int main ()
{
// Este programa calcula la potencia de un número
// Declaro las variables de mi función
int Base, Exp, Pot, i;
//Sustituyo la función ESCRIBA cadena por printf
printf("Escribe un número (base): ");
//Sustituyo la función LEA Base por scanf ( %d, &variableEntera);
scanf("%d", &Base); //Guarda el número leído en la variable Base
//Sustituyo la función ESCRIBA cadena por printf
printf("Escribe un número (exponente): ");
//Sustituyo la función LEA Exp por scanf ( %d, &variableEntera);
scanf("%d", &Exp); //Guarda el número leído en la variable Exp
//Compruebo que la base y el exponente sean mayores que 1
if ((Base >= 1) && (Exp >= 1)){
//Inicializo las variables
Pot = 1;
i = 1;
while (Exp >= 1){
Pot = Pot * Base;
Exp = Exp - 1;
}
//Sustituyo la función ESCRIBA por printf
printf("La potencia es: %d\n", Pot);
}
else{
//Sustituyo la función ESCRIBA cadena por printf
printf("La base y el exponente han de ser mayores o igualesa 1\n");
}
//Fin del programa
return 0;
}