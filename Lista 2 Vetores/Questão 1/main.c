#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*Suponha que existam 02 vetores A e B do tipo inteiro com 25 elementos inteiros
cada. Elabore um algoritmo que construa um vetor C a partir da junção de A e B. A
seguir efetue uma pesquisa sequencial no vetor no vetor C.
*/
	setlocale(LC_ALL, "Portuguese");
	int A[25], B[25], C[50];
	int i, tamanho, tamanhoC, vetor, pesq;
	
	printf("Digite o tamanho dos Vetores A e B: ");
	scanf("%d", &tamanho);
	tamanhoC = tamanho * 2;
	
	for(i=0;i<tamanho;i++){ //preenchendo vetor A
		printf("Número %d: ", i);
		scanf("%d", &A[i]);			
	}
	printf("-------------------\n");
	mostraVetor(A);
	printf("Preencha o Vetor B\n"); 
 	for(i=0;i<tamanho;i++){ //preenchendo vetor B
		printf("Número %d: ", i);
		scanf("%d", &B[i]);			
	
	}
	printf("-------------------\n");
	mostraVetor(B);
	printf("\n\nVetor C: ");
	for(i = 0; i < tamanhoC; i++){ //preenchendo vetor C
		C[i*2] = A[i];
		C[i*2+1] = B[i];
	}
	printf("-------------------\n\n");
	mostraVetor(C, tamanhoC);
	
	
	printf("Digite o valor a ser pesquisado: ");
	scanf("%d", &pesq);
	//i = 0;
	for(i=0; i<tamanhoC; i++){
		if(C[i]== pesq){
			printf("%d encontrado na posição %d\n", pesq, i);
			break;
		}
	}
	if(i == tamanhoC){
		printf("%d elemento não encontrado.", pesq);
	}
	

	
	return 0;
}
void mostraVetor(int *vetor, int tamanho){
	int i;
	for(i = 0; i < tamanho; i++)
		printf("Número [%d]: %d\n", i, vetor[i]);
}
