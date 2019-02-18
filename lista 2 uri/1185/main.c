#include <stdio.h>
#include <stdlib.h>

int main()
{
    double sum=0, media=0, M[12][12];
    int i, j, k, l, aux=10;
    char O[2];
	scanf("%s", &O);
    for(i=0;i<=11;i++){ //preenchendo matriz
		for(j=0;j<=11;j++){
			scanf("%lf", &M[i][j]);
		}	
	}
    for(k=0; k<=10;k++){ //encontrando diagonal secundaria
        for(l=0; l<=aux;l++){
          sum += M[k][l]; // adiciona elementos até a diagonal
    }
    aux--; 
    }
    if(O[0]=='S'){
      printf("%.1lf\n", sum);
    }
        
    else if(O[0]=='M'){
        media = sum /66.0; //66 = quantidade de elementos acima da diagonal Secundaria
        printf("%.1lf\n", media);
    }
    return 0;
}

