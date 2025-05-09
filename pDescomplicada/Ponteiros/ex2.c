#include <stdio.h>

/*Escreva um programa que contenha duas variaveis inteiras. Compare seus enderec¸os e ´
exiba o maior endereço.*/

int main(){

int num1, num2;

if( &num1 > &num2 ){
  
    printf("O endereço de memória de num1 é maior: %p > %p", &num1, &num2);
}else{
    printf("O endereço de memória de num2 é maior: %p > %p", &num2, &num1);
}

}