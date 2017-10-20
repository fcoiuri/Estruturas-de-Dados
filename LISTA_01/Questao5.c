//Escreva um algoritmo que receba um vetor de N elementos e verifique a existência  de elementos repetidos.
//Caso não existam elementos repetidos retorne um “Ok”. Caso contrário, que remova as repetições dos elementos
//e que retorne o número de elementos removidos. A seguir  efetue uma pesquisa binária no vetor sem elementos repetidos.


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define FALSE 0
#define TRUE !FALSE

void Mostrar(int *vetor, int tamanho){
	int i;
	for(i = 0; i < tamanho; i++)
		printf("Número [%d]: %d\n", i, vetor[i]);
}
void Bolha(int *lista, int tamanho){
    int trocou, i, aux;
	do{
		trocou = FALSE;
		for(i = 0; i < (tamanho - 1); i++){
			if(lista[i] > lista[i+1]){
				aux = lista[i];
				lista[i] = lista[i+1];
				lista[i+1] = aux;
				trocou = TRUE;
			}
		}
	}while(trocou);
}
int Pesquisa(int *lista, int tamanho, int pesquisa){
    int comeco = 0;
    int fim = tamanho - 1;
    int meio;


    while(comeco <= fim){
        meio = (comeco+fim)/2;
        if(pesquisa < lista[meio])
            fim = meio - 1;
        else if(pesquisa > lista[meio])
            comeco = meio + 1;
        else
            return meio;
    }
    return -1;

}
void Retirar(int *lista, int *tamanho, int posicao){
    int i;
    for(i = posicao; i < (*tamanho)-1; i++){
        *(lista+i) = *(lista+i+1);
    }
    (*tamanho)--;
}

int main()
{
    setlocale (LC_ALL, "Portuguese");
    int tamanho, i, j, removidos, pesquisado;
    int *lista;
    printf("Digite o tamanho do Vetor N:\n");
    scanf("%d", &tamanho);
    lista = malloc(sizeof(int)*tamanho);
    if(!lista){
        printf("SEM MEMÓRIA\n");
        return 0;
    }
    for(i = 0; i < tamanho; i++){
        printf("Digite o número [%d]:", i);
        scanf("%d", (lista+i));
    }
    removidos = 0;

    for(i = 0; i < tamanho; i++){
        for(j = (i+1); j < tamanho; j++){
            if(*(lista+i)== *(lista+j)){
                removidos++;
                Retirar(lista, &tamanho, i);
                i--;
                break;
            }
        }
    }
    if(!removidos){
        printf("######################\n");
        printf("Ok\n");
    }else{
        printf("%d ELEMENTOS FORAM REMOVIDO(S):\n", removidos);
    }


    printf("######################\n");
    printf("Digite o número que deseja pesquisar:\n");
    scanf("%d", &pesquisado);
    Bolha(lista, tamanho);
    printf("######################\n");
    printf("VETOR N:\n");
    Mostrar(lista, tamanho);
    i = Pesquisa(lista, tamanho, pesquisado);
    if(i != -1)
        printf("Encontrado na posição [%d]\n", i);
    else
        printf("ELEMENTO NÃO ENCONTRADO\n");

    return 0;

}
