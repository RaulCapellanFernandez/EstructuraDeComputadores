#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void inicializa(char vector[26]);

int main(void){
    char vector[26];
    char password[8];
    int num;

    inicializa(vector);

    srand(time(NULL));

    for(int i = 0; i < 9; i++){
        
        num = rand()%26;
        password[i] = vector[num];
        printf("%c ", password[i]);
    }
}

void inicializa(char vector[26]){
    int x=26, i=0;
    char letra = 'a';

    do
    {  
        vector[i] = letra;
        //printf("%c ",letra);
        letra++;
        i++;
        x--;
    }while(x!=0);
}