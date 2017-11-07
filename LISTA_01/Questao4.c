#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int primo(int num){

    if(num==1){
      return 0;
    }
    if(num==0){
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
    printf("Digite um número: ");
    scanf("%d", &num);

    if(!primo(num)){ // !operador lógico para negação
        printf("O número %d NÃO é primo\n", num);
    }


    if(primo(num)){
        printf("O número %d É primo\n", num);
        printf("Primos sucessores de %d: ", num);
        for(i=num+1; total<2; i++){
            if(primo(i)){ //mostrando os dois proximos primos
                total++;
                printf("%d, ", i);
            }
        }

        total=0;
        printf("\nPrimos antecessores de %d: ", num);
        for(i = num-1; i > 0; i--){
          if(primo(i)){ //mostrando os dois primos anteriores
              printf("%d, ", i);
              total++;
          }
          if(total >= 2){ //só mostrar dois antecessores
              break;
          }

          if(num == 2){
            printf("Não possui antecessor\n");
          }


        }

    };
    printf("\n");
    return 0;
}
