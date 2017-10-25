#include <stdio.h>
#include <stdlib.h>

typedef struct box{
        char conteudo;
        struct box *proximo;
    }Box;

void mostraLista(Box *inicio){ //exibir lista
    Box *p = inicio->proximo;
    printf("Passo: ");
    while(p != NULL){ //mostrar o conteudo a partir de cada iteracao
        printf(" %c ", p->conteudo);
        p = p->proximo;
    }
    printf("\n");
}

void inserindoFinal(Box *inicio, char aux){
    Box *novo = inicio;
    while(novo->proximo != NULL){
        novo = novo->proximo;
    }
    novo->proximo = (Box *)malloc(sizeof(Box));
    novo = novo->proximo;
    novo->conteudo = aux;
    novo->proximo = NULL;
}

void inserindoInicio(Box *inicio, char aux){
    Box *novo = (Box *) malloc(sizeof(Box));
    novo->conteudo = aux;
    novo->proximo = inicio->proximo;
    inicio->proximo = novo;
}

void inserindoEntreDois(Box *inicio, char primeiro, char aux){
    Box *temp1 = inicio;
    while(temp1->conteudo != primeiro){
        temp1 = temp1->proximo;
    }
    Box *novo = (Box*)malloc(sizeof(Box));
    novo->conteudo = aux;
    novo->proximo = temp1->proximo;
    temp1->proximo = novo;
}

void excluindo(Box *inicio, char cont){
    Box *temp1 = inicio;
    while(temp1->proximo->conteudo != cont){
        temp1 = temp1->proximo;
    }
    Box *temp2 = temp1->proximo;
    temp1->proximo = temp2->proximo;
    free(temp2);
}

int main()
{
    printf("###### LISTA ENCADEADA ######\n \n");
    Box *inicio, *temp1, *temp2;

    // criando Lista
    inicio = (Box *) malloc(sizeof(Box)); //alocando memoria
    inicio->proximo = NULL; // =proximo ainda n tem endereco valido

    // Insere A no final
    inserindoFinal(inicio, 'A');
    printf("Primeiro ");
    mostraLista(inicio);

    // Insere B no inicio
    inserindoInicio(inicio, 'B');
    printf("Segundo ");
    mostraLista(inicio);

    // Insere C no final
    inserindoFinal(inicio, 'C');
    printf("Terceiro ");
    mostraLista(inicio);

    // Insere D no final
    inserindoFinal(inicio, 'D');
    printf("Quarto ");
    mostraLista(inicio);

    // Insere E entre A e C
    inserindoEntreDois(inicio, 'A', 'E');
    printf("Quinto ");
    mostraLista(inicio);

    // Insere F no final
    inserindoFinal(inicio, 'F');
    printf("Sexto ");
    mostraLista(inicio);

    // Insere G no inicio
    inserindoInicio(inicio, 'G');
    printf("Sétimo ");
    mostraLista(inicio);

    // Exclui ultimo 
    temp1 = inicio;
    while(temp1->proximo->proximo != NULL){
        temp1 = temp1->proximo;
    }
    temp2 = temp1->proximo;
    temp1->proximo = temp2->proximo;
    free(temp2);

    printf("Oitavo ");
    mostraLista(inicio);

    // Exclui primeiro
    temp1 = inicio->proximo;
    inicio->proximo = temp1->proximo;
    free(temp1);

    printf("Nono ");
    mostraLista(inicio);

    // Insere H entre A e E
    inserindoEntreDois(inicio, 'A', 'H');
    printf("Décimo ");
    mostraLista(inicio);

    // Exclui A
    excluindo(inicio, 'A');
    printf("Décimo Primeiro ");
    mostraLista(inicio);


    // Insere I entre E e D
    inserindoEntreDois(inicio, 'E', 'I');
    printf("Décimo Segundo ");
    mostraLista(inicio);

    // Insere J no final
    inserindoFinal(inicio, 'J');
    printf("Décimo Terceiro ");
    mostraLista(inicio);

    // Insere K entre B e H
    inserindoEntreDois(inicio, 'B', 'K');
    printf("Décimo Quarto ");
    mostraLista(inicio);

    // Exclui D, K e I
    excluindo(inicio, 'D');
    excluindo(inicio, 'K');
    excluindo(inicio, 'I');
    printf("Décimo Quinto ");
    mostraLista(inicio);

    // Exclui  B
    excluindo(inicio, 'B');
    printf("Décimo Sexto ");
    mostraLista(inicio);

    // Insere L no inicio
    inserindoFinal(inicio, 'L');
    printf("Décimo Sétimo ");
    mostraLista(inicio);

    return 0;
}
