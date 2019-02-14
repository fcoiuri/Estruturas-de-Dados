#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Elabore um algoritmo que armazene 30 valores inteiros num vetor; segundo a
seguinte lei de forma��o: Se o �ndice do vetor for par, o valor digitado dever� ser
multiplicado por 2, caso contr�rio por 5. A seguir efetue uma pesquisa bin�ria no
vetor.
*/


int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	int tamanho, i, vetor, pesq;
	int inicio, meio, fim, controle=1;
	int Vetor1[30];
	
	for(i=0;i<30;i++){ //preenchendo o vetor 
		printf("N�mero %d: ", i);
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
			controle = 1; //se a pesquisa n�o encontrar nenhum define como 1
			break;
		}
		
		
		
		
	}
	if(controle == 0){
		printf("\nO elemento %d foi encontrado na posi��o %d!", pesq, meio);
	}
	else{
		printf("\nO elemento %d N�O foi encontrado!", pesq);
	}
	

	
	return 0;
}
void mostraVetor(int *vetor, int tamanho){
	int i;
	for(i = 0; i < 30; i++)
		printf("N�mero [%d]: %d\n", i, vetor[i]);
}

