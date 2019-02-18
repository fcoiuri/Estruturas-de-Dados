#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
	int n, i, j, aux;
	
	while(1){
		scanf("%d", &n);
		
		if(n==0){ //digitar 0 para
			break;
		}	
		else{
			for(i=1;i<=n;i++){ //i = linhas
				for(j=1;j<=n;j++){ //
					aux = i; 
					if(j<aux){ // 
						aux=j;
					}
					if(n-i+1<aux){
						aux= n-i+1;
					}
					if(n-j+1 < aux){
						aux = n - j + 1;
					}
					printf("%3d", aux);
					if(j<n){
						printf(" ", aux);
					}
					else{
						printf("\n");
					}
				}
			}
			printf("\n");	
		}
		
	}
	return 0;
}
