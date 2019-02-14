#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Ler duas matrizes A e B, de duas dimensões, sendo a matriz A de 5X4 (5 linhas e 4 colunas)
e a matriz B de 4X3 (quatro linhas e três colunas). Apresentar a matriz C como resultado da
multiplicação das matrizes A e B. Condição para multiplicação: o número de colunas de A
tem que ser igual ao número de linhas de B.
 */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	int matrizA[5][4];
	int matrizB[4][3];
	int matrizC[4][4];	
	int i, j, x, c1, c2, aux = 0;
	printf("Digite o valor para os elementos da Matriz A\n\n");
	for(i=0;i<5;i++){ //matriz A
		for(j=0;j<4;j++){
			printf("Elemento [%d][%d] = ", i+1, j+1);
			scanf("%d", &matrizA[i][j]);
		}
	}
	
	
	printf("\n\n******************* MATRIZ A ********************* \n\n");
  
  	for(i=0;i<5;i++){
  		for(j=0;j<4;j++){
      		printf ("\nElemento[%d][%d] = %d \t", i, j, matrizA[i][j]);
    	}
  }
    system("pause");
	printf("\n\nDigite o valor para os elementos da Matriz B\n\n");
    for(i=0;i<4;i++){ //matriz B
		for(j=0;j<3;j++){
			printf("Elemento [%d][%d] = ", i+1, j+1);
			scanf("%d", &matrizA[i][j]);
		}
	}
	
	
	for(c1=0;c1<4;c1++){ //matriz C
		for(c2=0;c2<4;c2++){
			for(x=0;x<4;x++){
				//aux += matrizA[i][x] * matrizB [x][j];
				aux = aux + matrizA[c1][x]*matrizB[x][c2];
			}
			matrizC[c1][c2]= aux;	
			aux = 0;
		}
	}
  	printf("\n\n******************* Saída de Dados ********************* \n\n");
  
  	for(i=0;i<4;i++){
  		for(j=0;j<4;j++){
      		printf ("\nElemento[%d][%d] = %d\n", i, j, matrizC[i][j]);
    	}
	}
	return 0;
}

