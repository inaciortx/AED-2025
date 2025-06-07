#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int Menu( void *buffer );
void* Add_People( void *buffer);
void List_All( void *buffer);
void* Search( void *buffer );
void* Remove_People( void *buffer );


int main () {

    void *pBuffer = NULL;

    pBuffer = malloc( sizeof( int ) * 3);
    int *pMenu = ( int *) pBuffer;
    int *pPeopleAmount = ( int *)( ( char *) pBuffer + sizeof(int) );
    int *pBufferSize = ( int *)( ( char *) pBuffer + 2 * sizeof(int) );
    (*pBufferSize) = sizeof(int) * 3;
    *pPeopleAmount = 0; 

    *pMenu = 0;

    while ( *pMenu != 5) {
        *pMenu = Menu( pBuffer );

        switch( *pMenu ) {

            case 1:
                pBuffer = Add_People( pBuffer );
                break;
            case 2:
                pBuffer = Remove_People( pBuffer );
                break;
            case 3:
                pBuffer = Search( pBuffer );
                break;
            case 4:
                List_All( pBuffer);
                break;

        }
    }
    free(pBuffer);
    printf("\nSaindo...\n");
}

int Menu( void *buffer ) {

    int *p = (int *) buffer; 

    printf("\n======= MENU =======\n" );
    printf("(1) Adicionar Pessoa\n(2) Remover Pessoa\n(3) Buscar Pessoa\n(4) Listar Todos\n(5) Sair\n====================\n\nEscolha uma opcao: " );
    scanf("%d", p );

    return *p;
}

void * Add_People( void *buffer ) {

    //Recuperar tamanho do Buffer 
    int *pBufferSize = ( int *)( ( char *) buffer + 2 * sizeof(int) );
 
    //Aloca memória para mais uma pessoa no Buffer
    buffer = realloc ( buffer, *pBufferSize + (sizeof(char) * 200) + (sizeof(int) * 3) );
    pBufferSize = ( int *)( ( char *) buffer + 2 * sizeof(int) );
    
    // Incrementa uma nova pessoa no contador
    int *pPeopleAmount = ( int * )((char *)buffer + sizeof(int));
    (*pPeopleAmount)++;

    //Separa um espaço para o tamanho do nome
    int *pNameSize = (int*)( (char *) buffer + (*pBufferSize) );
    *pBufferSize += sizeof(int);

    // Insere nome no Buffer
    char *pName = (char *) buffer +  (*pBufferSize );
    printf("   Nome: ");
    fgets(pName, 50, stdin);
    pName[strcspn(pName, "\n")] = '\0';

    // Arruma os valores do Buffer
    *pNameSize = strlen(pName);
    *pBufferSize += (*pNameSize + 1);

    // Insere a idade no Buffer
    int *pAge = (int *) ( (char *) buffer + (*pBufferSize ) );
    printf("   Idade: ");
    scanf("%d%*c", pAge);
    *pBufferSize += sizeof(int);

    //Separa um espaço para o tamanho do email
    int *pEmailSize = (int*)( (char *) buffer + (*pBufferSize)  );
    *pBufferSize += sizeof(int);


     // Insere email no Buffer
    char *pEmail = (char *) buffer +  (*pBufferSize );
    printf("   E-Mail: ");
    scanf(" %99[^\n]%*c", pEmail);

    // Arruma os valores do Buffer
    *pEmailSize = strlen(pEmail);
    *pBufferSize += (*pEmailSize + 1);

    //Reajusta a memória que sobrou
    buffer = realloc( buffer, *pBufferSize );
    

    return buffer;

}

void List_All( void *buffer ) {

    //Recuperar o número de pessoas e usar meu inteiro coringa como contador
    int *pPeopleAmount = (int *)((char *)buffer + sizeof(int));
    int *pCount = (int *) buffer;
    *pCount = 1;

    char *pData = (char *) buffer + (3 * sizeof(int)); // aponta pro primeiro dado após meus contadores 
    
    while ( *pCount <= *pPeopleAmount ){

        int *pNameSize = (int *) pData;
        pData += sizeof(int);

        char *pName = pData;
        pData += (*pNameSize + 1);

        int *pAge = (int *) pData;
        pData += sizeof(int);

        int *pEmailSize = (int *) pData;
        pData += sizeof(int);

        char *pEmail = pData;
        pData += (*pEmailSize + 1);

        printf("====================\n");
        printf("    Pessoa %d\n", *pCount);
        printf("Nome: %s\n", pName);
        printf("Idade: %d\n", *pAge);
        printf("E-Mail: %s\n", pEmail);
        printf("====================\n");
        
        (*pCount)++;
        
    }
    
    *pCount = 0;
}

void* Search( void *buffer ) {

    //Recuperar tamanho do Buffer 
    int *pBufferSize = ( int *)( ( char *) buffer + 2 * sizeof(int) );

    buffer = realloc(buffer, *pBufferSize + sizeof(char) * 50 );
    pBufferSize = ( int *)( ( char *) buffer + 2 * sizeof(int) );

    int *pPeopleAmount = (int *)((char *)buffer + sizeof(int));
    int *pCount = (int *) buffer;
    *pCount = 0;

    char *pSearched = ( char *) buffer + *pBufferSize;
    printf("  Pesquisa (NOME): ");
    scanf(" %49[^\n]", pSearched);
   
    char *pData = (char *) buffer + (3 * sizeof(int)); // aponta pro primeiro dado após meus contadores 
    
    while ( *pCount < *pPeopleAmount ) {

        int *pNameSize = (int *) pData;
        pData += sizeof(int);

        char *pName = pData;
        pData += (*pNameSize + 1);
        
        int *pAge = (int *) pData;
        pData += sizeof(int);

        int *pEmailSize = (int *) pData;
        pData += sizeof(int);

        char *pEmail = pData;
        pData += (*pEmailSize + 1);

        if ( strcmp(pName, pSearched) == 0 ){
          
            printf("\n==================\n");
            printf("    Pessoa Encontrada!\n");
            printf("Nome: %s\n", pName);
            printf("Idade: %d\n", *pAge);
            printf("E-Mail: %s\n", pEmail);
            printf("==================\n");

            *pCount = 0;
            buffer = realloc(buffer, *pBufferSize);
            return buffer;
        }
        (*pCount)++;
    }
    printf("Pessoa nao encontrada!");

    *pCount = 0;
    buffer = realloc(buffer, *pBufferSize);
    return buffer;
}       

void* Remove_People( void *buffer ){ 

int *pBufferSize = ( int *)( ( char *) buffer + 2 * sizeof(int) );

buffer = realloc(buffer, *pBufferSize + sizeof(char) * 54 );
pBufferSize = ( int *)( ( char *) buffer + 2 * sizeof(int) );


int *pPeopleAmount = (int *)((char *)buffer + sizeof(int));
int *pCount = (int *) buffer;
*pCount = 0;

char *pRemoved = ( char *) buffer + *pBufferSize;
printf("  Remover (NOME): ");
scanf(" %50[^\n]", pRemoved);

char *pData = (char *) buffer + (3 * sizeof(int));
char *pPreviousData = (char *) buffer + (3 * sizeof(int));

 while ( *pCount < *pPeopleAmount ) {

        pPreviousData = (char *)pData;

        int *pNameSize = (int *) pData;
        pData += sizeof(int);
        char *pName = pData;
        pData += (*pNameSize + 1);

        pData += sizeof(int);

        int *pEmailSize = (int *) pData;
        pData += sizeof(int);
        pData += (*pEmailSize + 1);

        if ( strcmp(pName, pRemoved) == 0 ){
       
            *pCount = (sizeof(int) + (*pNameSize + 1) + sizeof(int) + sizeof(int) + (*pEmailSize + 1));

            memmove((void *)pPreviousData, (void *)pData, ((char *)buffer + *pBufferSize) - (char *)pData);

            (*pPeopleAmount)--;
            *pBufferSize -= *pCount;

            buffer = realloc(buffer, *pBufferSize );
            *pCount = 0;
            printf("Pessoa removida com sucesso!");
            return buffer;
            
        }
        (*pCount)++;
}
    printf(" Nome nao encontrado!");
    buffer = realloc(buffer, *pBufferSize );
    *pCount = 0;
    return buffer;
}
 
    