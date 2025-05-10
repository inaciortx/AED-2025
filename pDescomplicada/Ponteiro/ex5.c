#include <stdio.h>
#include <stdlib.h>

/*Fac¸a um programa que leia dois valores inteiros e chame uma func¸ao que receba estes ˜
2 valores de entrada e retorne o maior valor na primeira variavel e o menor valor na ´
segunda variavel. Escreva o conte ´ udo das 2 vari ´ aveis na tela. */

void DefinirMaior(int *A, int *B);

int main(){

    int num1, num2;

    printf("Digite dois valores: ");
    scanf("%d %d", &num1, &num2);

    DefinirMaior(&num1, &num2);

    printf("==== Independente da entrada num1 sempre armazenará o maior ====\nnum1: %d\nnum2: %d\n============================", num1, num2);

    return 0;
}

void DefinirMaior(int *A, int *B){
    if ( *A < *B ) {
        int temp = *A;
        *A = *B;
        *B = temp;
    }
}