//Leia  uma  lista  de  no  máximo  100  números  inteiros,  carregando os  em  um  vetor. 
//Os números lidos maiores ou iguais que 256 deverão ser ignorados. Ordene os números lidos em ordem decrescente 
//Informar quantos são ímpares e quantos são pares. Apresente a média dos números ímpares maiores que 50.


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define FALSE 0
#define TRUE !FALSE


int main(){
	setlocale(LC_ALL, "Portuguese");
	int lista[100];
	int tamanho, i, trocou, aux, impar, par, media;
	printf("Digite o tamanho da lista(Máximo 100):");
	scanf("%d", &tamanho);
	for(i = 0; i < tamanho; i++){//lendo números da lista
		printf("Número %d:\n", i);
		scanf("%d", &lista[i]);
		if(lista[i] > 256)
			i--;
	}
	printf("\nLista normal:\n ");
	mostraVetor(lista,tamanho);

	//Ordem decrescente
	do{
		trocou = FALSE;
		for(i = 0; i < (tamanho - 1); i++){
			if(lista[i] < lista[i+1]){
				aux = lista[i];
				lista[i] = lista[i+1];
				lista[i+1] = aux;
				trocou = TRUE;
			}
		}
	}while(trocou);
	printf("\nOrdem Decrescente:\n ");
	mostraVetor(lista, tamanho);
	impar = 0;
	par = 0;
	aux = 0;
	media = 0;
  
	for(i = 0; i < tamanho; i++){
		if(lista[i]%2){
			impar++;
			if(lista[i] > 50)
			{
				media += lista[i];
				aux++;
			}
		}
		else
			par++;
	}
	printf("#####################\n");
	if(aux)
        media = media/aux;
	printf("Ímpares: %d\n", impar);
	printf("Pares: %d\n", par);
	printf("Média dos ímpares maiores que 50: %d\n", media);
	return 0;
}

void mostraVetor(int *vetor, int tamanho){
	int i;
	for(i = 0; i < tamanho; i++)
		printf("Número [%d]: %d\n", i, vetor[i]);
}
