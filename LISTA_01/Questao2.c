//Leia um vetor X de N elementos e que:
//Crie outro vetor Y contendo os elementos de X que estão na faixa entre 10 e 40;
//Crie outro vetor W contendo os números que estão nas posições pares;
//Pesquise a existência de um determinado elemento Z no vetor X;
//Escreva o menor e maior elemento do vetor X


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 100
#define FALSE 0
#define TRUE !FALSE

int main()
{
  	setlocale(LC_ALL, "Portuguese");
	int tamanhox, tamanhoy, tamanhow, i, menorX, maiorX, elementoz, achou;
	int vetorX[N], vetorY[N], vetorW[N];
	printf("Digite o tamanho do vetor X (máximo %d):", N);
	scanf("%d", &tamanhox);
	for(i = 0; i < tamanhox; i++){
		printf("Número %d:\n", i);
		scanf("%d", &vetorX[i]);
	}

	tamanhoy = 0;
	tamanhow = 0;
	menorX = vetorX[0];
	maiorX = vetorX[0];
	for(i = 0; i < tamanhox; i++){

		if(vetorX[i] > maiorX)
			maiorX = vetorX[i];
		if(vetorX[i] < menorX)
			menorX = vetorX[i];
		if(vetorX[i] > 10 && vetorX[i] < 40){
			vetorY[tamanhoy] = vetorX[i];
			tamanhoy++;
		}
		//Posicoes pares
		if(!(i%2)){
			vetorW[tamanhow] = vetorX[i];
			tamanhow++;
		}
	}
  
 	printf("\n###################\n");
	printf("Vetor X:\n");
	mostraVetor(vetorX, tamanhox);
	printf("###################\n");
	printf("Vetor Y(Números de X que estão na faixa entre 10 e 40):\n");
	mostraVetor(vetorY, tamanhoy);
	printf("###################\n");
	printf("Vetor W(Números que estão nas posições pares):\n");
	mostraVetor(vetorW, tamanhow);
	printf("###################\n");

	printf("Maior número do Vetor X: %d\n", maiorX);
	printf("Menor número do vetor X: %d\n", menorX);

	do{
		printf("Digite o número Z que deseja pesquisar: ");
		scanf("%d", &elementoz);
		achou = FALSE;
		for(i = 0; i < tamanhox; i++){
			if(vetorX[i]== elementoz){
				achou = TRUE;
				printf("Número %d encontrado na posição %d. ", vetorX[i], i);
				return 0;
			}
		}
	}while(!achou);
	return 0;
}


void mostraVetor(int *vetor, int dimensao){
	int i;
	for(i = 0; i < dimensao; i++)
		printf("Número [%d]: %d\n", i, vetor[i]);
}
