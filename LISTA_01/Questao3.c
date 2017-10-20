#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, "Portuguese");
    int tamanhoA, tamanhoC, i;
    int *vetorA, *vetorB, *vetorC;
    printf("Digite o tamanho dos vetores A e B:");
    scanf("%d", &tamanhoA);
    tamanhoC = 2*tamanhoA;
    vetorA = malloc(sizeof(int)*tamanhoA);
    vetorB = malloc(sizeof(int)*tamanhoA);
    vetorC = malloc(sizeof(int)*tamanhoA*2);
    if(vetorA == NULL || vetorB == NULL || vetorC == NULL)
    {
        printf("SEM MEMÓRIA");
        return 0;
    }
    printf("#######################\n");
    printf("ELEMENTOS DO VETOR A:\n");
    for(i = 0; i < tamanhoA; i++){
        printf("Digite o número %d:\n", i);
        scanf("%d", vetorA+i);
    }
    printf("#######################\n");
    printf("ELEMENTOS DO VETOR B:\n");
    for(i = 0; i < tamanhoA; i++){
        printf("Digite o número %d:\n", i);
        scanf("%d", vetorB+i);
    }


    printf("##### Vetor A #####\n");
    mostraVetor(vetorA, tamanhoA);
    printf("##### Vetor B #####\n");
    mostraVetor(vetorB, tamanhoA);
    tamanhoC = 0;
    for(i = 0; i < tamanhoA; i++){
        *(vetorC+tamanhoC) = *(vetorA+i);
        *(vetorC+tamanhoC+1) = *(vetorB+i);
        tamanhoC += 2;
    }
    printf("#######################\n");
    printf("##### Vetor C #####\n");
    mostraVetor(vetorC, tamanhoC);

    return 0;
}

void mostraVetor(int *vetor, int tamanho){
	int i;
	for(i = 0; i < tamanho; i++)
		printf("Elemento [%d]: %d\n", i, vetor[i]);
}
