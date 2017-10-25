#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int primo(int num){

    if(num==1){//1 não é primo
      return 0;
    }
    
    int i;
    for(i=2; i<num; i++){//para numeros maiores que 2 verifica se é par e fim da funcao
        if(num%i==0){
          return 0;
        }
        }
    return 1;
}
int main(){
    setlocale(LC_ALL, "Portuguese");
    int num, i, total=0;
    printf("NÚMEROS PRIMOS!!\n");
    do{
        printf("Digite um número: ");
        scanf("%d", &num);

        if(!primo(num)){ // !operador lógico para negação
            printf("O número %d NÃO é primo\n", num);
        }
        
       
        if(primo(num)){
            printf("O número %d É primo\n", num);
            printf("Primos sucessores de %d: ", num);
            for(i=num+1; total<2; i++){ //mostrando os dois proximos primos
                if(primo(i)){
                    total++;
                    printf("%d, ", i);
                }
            }

            total=0;
            printf("\nPrimos antecessores de %d: ", num); //mostrando os dois primos anteriores
            for(i = num-1; i > 0; i--){
            if(primo(i))
            {
                printf("%d\n", i);
                total++;
            }
            if(total >= 2){ //dois n tem antecessor
                break;
            }

  
            }

    };
    }while(num%2 == 0);
    printf("\n");
    system("pause");
    return 0;
}
