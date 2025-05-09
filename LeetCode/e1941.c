#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool areOccurrencesEqual(char* s) {

    int tamanho_string = strlen(s);
    int vetor[tamanho_string];
   
    for (int i = 0; i < tamanho_string; i++) {
        vetor[i] = 0;
    }

    for (int i = 0; i < tamanho_string; i++) {
        for (int j = 0; j < tamanho_string; j++) {
            if (s[i] == s[j]) {
                vetor[i] += 1;
            }
        }
    }

    for (int i = 0; i < tamanho_string; i++) {
        for (int j = 0; j < tamanho_string; j++) {
            if (vetor[i] != vetor[j]) {
                return false;
            } 
        }
    }

    return true;
}


int main() {
    char str1[] = "abab";     
    char str2[] = "aabbcc";   
    char str3[] = "abcabcd";  
    char str4[] = "zz";        

    printf("Resultado para \"%s\": %s\n", str1, areOccurrencesEqual(str1) ? "trae" : "false");
    printf("Resultado para \"%s\": %s\n", str2, areOccurrencesEqual(str2) ? "true" : "false");
    printf("Resultado para \"%s\": %s\n", str3, areOccurrencesEqual(str3) ? "true" : "false");
    printf("Resultado para \"%s\": %s\n", str4, areOccurrencesEqual(str4) ? "true" : "false");

    return 0;
}