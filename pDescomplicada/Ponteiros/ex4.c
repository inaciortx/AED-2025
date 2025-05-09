#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que leia 2 valores inteiros e chame uma função que receba estas 2 variáveis e troque o seu conteúdo. Ou seja, 
esta função é chamada passando duas variáveis A e B,
 por exemplo, e, após a execução da função, A conterá o valor de B e B terá o valor de A.*/

void TrocarValores(int *A, int *B);

int main(){

int num1, num2;

printf("Digite o primeiro valor: ");
    scanf("%d", &num1);
printf("Digite o segundo valor: ");
    scanf("%d", &num2);

    printf("Valor de num1 : %d || Valor de num2: %d\n", num1, num2);

TrocarValores(&num1, &num2);
printf("\nTrocando Valores...\n\n");

    printf("Valor de num1 : %d || Valor de num2: %d\n", num1, num2);

}

void TrocarValores(int *A, int *B){

int temp;

temp = *A;
*A = *B;
*B = temp;

}
