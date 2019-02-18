#include <stdio.h>
#include <stdlib.h>

/* A primeira linha de entrada contem um n�mero C (0 = C = 11) indicando a coluna que ser� considerada para opera��o. 
A segunda linha de entrada cont�m um �nico caractere Mai�sculo T ('S' ou 'M'), indicando a opera��o (Soma ou M�dia) 
que dever� ser realizada com os elementos da matriz. 
Seguem os 144 valores de ponto flutuante que comp�em a matriz. */

int main(int argc, char *argv[]) {
	float M[12][12];
	float sum = 0, media = 0;
	int c=0, i, j;
	char T[2];
	scanf("%d", &c);
	if(c>=0 && c<=11){
		scanf("%s", &T);
		for(i=0;i<=11;i++){ //preenchendo matriz
			for(j=0;j<=11;j++){
				scanf("%f", &M[i][j]);
				if(j == c){
					sum += M[i][j];
				}
			}	
		}
		if(T[0]=='S'){ // se for soma
			printf("%.1f", sum);
		}
		else if(T[0]=='M'){ // se for a media
				media = sum / 12;
				printf("%.1f\n", media);
		}
		}		 
	
	/*for(i=0;i<3;i++){
  		for(j=0;j<3;j++){
      		printf ("%.1f \t", M[i][j]);
    	}
    	printf("\n");
    */
	return 0;
}

