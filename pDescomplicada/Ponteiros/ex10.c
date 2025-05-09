#include <stdio.h>

/*Crie um programa que contenha um array de inteiros contendo 5 elementos. Utilizando
apenas aritmetica de ponteiros, leia esse array do teclado e imprima o dobro de cada ´
valor lido.*/

int main(){

    int array[5], *p_array = array;

    for( int i = 0; i < 5; i++){
        scanf("%d", p_array);
        p_array++;
    }
        
     p_array = p_array - 5;

    for( int i = 0; i < 5; i++){
        *p_array = *p_array * 2;
        printf(" %d |", *p_array);
        p_array++;
    }

    return 0;
}