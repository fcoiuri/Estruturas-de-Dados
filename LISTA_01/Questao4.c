#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



int primo(int num){

    if(num==1){//1 n�o � primo
      return 0;
    }
    int i;
    for(i=2; i<num; i++){//para numeros maiores que 2 verifica se � par
        if(num%i==0){
          return 0;
        }
        }
    return 1;
}
int main(){
    setlocale(LC_ALL, "Portuguese");
    int num, i, total=0;
    printf("N�MEROS PRIMOS!!\n");
    do{
        printf("Digite um n�mero: ");
        scanf("%d", &num);

        if(!primo(num)){ // !operador l�gico para nega��o
            printf("O n�mero %d N�O � primo\n", num);
        }
        else{
            printf("O n�mero %d � primo\n", num);
            printf("Primos sucessores de %d: ", num);
            for(i=num+1; total<2; i++){
                if(primo(i)){
                    total++;
                    printf("%d, ", i);
                }
            }

            total=0;
            printf("\nPrimos antecessores de %d: ", num);
            if(num > 3){
                for(i=num-1; total<2; i--){
                    if(primo(i)){
                        total++;
                        printf("%d, ", i);

            }
        }
        }
    };
    }while(num%2 == 0);
    printf("\n");
    system("pause");
    return 0;
}
