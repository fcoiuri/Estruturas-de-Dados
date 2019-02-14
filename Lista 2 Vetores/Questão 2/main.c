#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Elabore um algoritmo que armazene 30 valores inteiros num vetor; segundo a
seguinte lei de formação: Se o índice do vetor for par, o valor digitado deverá ser
multiplicado por 2, caso contrário por 5. A seguir efetue uma pesquisa binária no
vetor.
*/


int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	int tamanho, i, vetor, pesq;
	int inicio, meio, fim, controle=1;
	int Vetor1[30];
	
	for(i=0;i<30;i++){ //preenchendo o vetor 
		printf("Número %d: ", i);
		scanf(" %d", &Vetor1[i]);
		if(i%2 == 0){//indice par
			Vetor1[i] = Vetor1[i] * 2;
		}
		else{//indice impar
			Vetor1[i] = Vetor1[i] * 5;
		}			
	}
	printf("\n\n---------------\n\n");	
	mostraVetor(Vetor1);
	
	
	printf("\nDigite o elemento que deseja pesquisar: ");
	scanf("%d", &pesq);
	inicio = 0;
	fim = 30 - 1; //vetor considera o 0
	while(inicio <= fim){
		meio = (inicio + fim) / 2;
		if(pesq == Vetor1[meio]){
			controle = 0; //caso o numero encontrado seja o meio
			break;			
		}
		else if(pesq < Vetor1[meio]){
			fim = meio - 1; //caso o numero encontrado seja menor que o meio do vetor 
			continue;
		}
		else if(pesq > Vetor1[meio]){
			inicio = meio + 1; //caso o numero encontrado seja maior que o meio do vetor
			continue;
		}
		else{
			controle = 1; //se a pesquisa não encontrar nenhum define como 1
			break;
		}
		
		
		
		
	}
	if(controle == 0){
		printf("\nO elemento %d foi encontrado na posição %d!", pesq, meio);
	}
	else{
		printf("\nO elemento %d NÃO foi encontrado!", pesq);
	}
	

	
	return 0;
}
void mostraVetor(int *vetor, int tamanho){
	int i;
	for(i = 0; i < 30; i++)
		printf("Número [%d]: %d\n", i, vetor[i]);
}

