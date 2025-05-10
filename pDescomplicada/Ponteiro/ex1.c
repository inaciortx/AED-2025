#include <stdio.h>

/*Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de ´
cada variavel usando os ponteiros. Imprima os valores das vari ´ aveis antes e ap ´ os a ´
modificac¸ao.*/

int main(){

int inteiro = 5, *p_inteiro = NULL;
char character = 'I', *p_char = NULL;

p_inteiro = &inteiro;
p_char = &character;

printf("%d || %c\n", inteiro, character);

*p_inteiro = 7;
*p_char = 'N';

printf("%d || %c", inteiro, character);


}