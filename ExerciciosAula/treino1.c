#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int menulista();
char* remover(char *string);
char* inserir(char *string);
void listar(char *string);


int main(){

int escolha=0;
char *listanomes = NULL;

    for(;;){

        escolha=menulista();

        switch (escolha){
            
            case 1:
               listanomes = inserir(listanomes);
                break;

            case 2:
                listanomes = remover(listanomes);
                break;

            case 3:
                listar(listanomes);
                break;
        
            case 4:
                exit(4);
                break;

        }
    }
}

int menulista(){

int option=0;

do{
    printf("\n---------MENU---------\n\n(1) Adicionar nome\n(2) Remover nome\n(3) Listar nome\n(4) Sair\n\n Escolha: ");
        scanf("%d", &option);
    printf("-------------------\n");

}while(option < 1 || option > 4);

return option;
}


char* inserir(char *string){

    if(string == NULL){
        string = malloc(1); 
        string[0] = '\0';      
    }

char nome[50];

    printf("Nome a ser inserido: ");
        scanf(" %[^\n]", nome);

string = (char *)realloc(string, strlen(string)+strlen(nome)+2);
   
strcat(string, nome);
strcat(string, "$");

return string;
}

void listar(char *string){

int i=0;

while(string[i] != '\0'){
    while(string[i] != '$'){
        printf("%c", string[i]);
        i++;
    }
        printf("\n");
        if(string[i] == '$') i++;
    }
}

char *remover(char *string){

char nome[50];
int i=0, i2=0, tamanhonome = 0, inicio = 0, encontrado = 0;

    printf("Nome a ser removido: ");
        scanf(" %[^\n]", nome);
        strcat(nome, "$");

while(string[i] != '\0'){

inicio = i;
i2 = 0;

    while(string[i] == nome[i2] && nome[i2] != '\0'){
        i2++;
        i++;
    }
        tamanhonome = strlen(nome);
        if(i2 == tamanhonome){
            encontrado = 1;
            
        int j = inicio;
        while(string[i] != '\0'){
            string[j++] = string[i++];
        }
        string[j] = '\0';

            string = realloc(string, strlen(string)+1);
            
            printf("\nNome removido!\n");
                return string;
    }
        while(string[i] != '$' && string[i] != '\0'){
            i++;
        }
        if(string[i] == '$') i++;
}
    if(encontrado == 0){
        printf("\nNome não encontrado!\n");
    }
return string;
}


