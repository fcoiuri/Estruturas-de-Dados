#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define TAMANHO 10

int *cria_vetor(int *vet, int n){
    int i=0;
    for(i=0; i<n; i++){
        vet[i] = rand()%100; //gerando numeros aleatorios para o vetor de 0 a 99
    }
    return vet;
}

void mostra_vetor(int *vet, int n){
    int i;
    printf("[ ");
    for(i=0; i<n; i++){
        printf("%d ", vet[i]);
    }
    printf("]\n");
}

void bubbleSort (int *vet, int n){
    int i, j, aux, contador=0;
    for(i=1; i<n; i++){
        for(j=0; j<n-i; j++){
            if(vet[j]>vet[j +1]){ //verifica se o j é maior que a proxima posicao
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
                contador++; //qtd de trocas
            }
        }
    }
    printf("Quantidade de trocas: %d \n", contador);
}

void insertionSort(int *vet, int n){
    int i, j, aux;
    for(i=1; i<n; i++){
        aux = vet[i];
        j = i - 1;
        while(j>=0 && aux < vet[j]){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1]=aux;
    }
}

void selectionSort(int *vet, int n){
    int i, j, min, aux, contador=0;
    for(i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++){ //indo pra proxima posicao de i
            if(vet[j] < vet[min]){
                min = j;
                contador++;
            }
        }
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
    printf("Quantidade de trocas: %d \n", contador);
}

void quickSort(int *vet, int inicio, int fim){

   int pivo, aux, i = inicio, j = fim, meio;

   meio = (i + j) / 2;
   pivo = vet[meio];

   do{
      while (vet[i] < pivo) i = i + 1; //valores menores que pivo colocados antes dele
      while (vet[j] > pivo) j = j - 1; // valores maiores que pivo colocado depois dele

      if(i <= j){
         aux = vet[i];
         vet[i] = vet[j];
         vet[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);

   if(inicio < j) quickSort(vet, inicio, j);
   if(i < fim) quickSort(vet, i, fim);
}

int main()
{
    setlocale(LC_ALL,"");
    int opcao=1, op, menu, vet[TAMANHO];
    float time;
    time_t start, finish;
    cria_vetor(vet, TAMANHO);

    do{
        printf(" ###### MENU DE ORDENAÇÃO ######\n");
        printf("1- Bubble Sort \n");
        printf("2- Insertion Sort \n");
        printf("3- Selection Sort \n");
        printf("4- Quick Sort \n");
        printf("0- Sair \n");
        printf("Digite o método de ordenação (0 para sair): ");
        fflush(stdin);
        scanf("%d", &menu);

        switch(menu){
        case 1:
            printf("\n ###### BUBBLE SORT ###### \n");
            cria_vetor(vet, TAMANHO); //criando vetor com 10 elementos
            printf("Original: "); mostra_vetor(vet, TAMANHO);
            start = clock(); //calculando tempo
            bubbleSort(vet, TAMANHO);
            finish = clock(); //fim da contagem
            printf("Ordenado: "); mostra_vetor(vet, TAMANHO);
            time = (difftime(finish, start)/CLOCKS_PER_SEC);
            printf("Tempo de execução: %.3f s \n\n", time);
            break;
        case 2:
            printf("\n ###### INSERTION SORT ######\n");
            cria_vetor(vet, TAMANHO);
            printf("Original: "); mostra_vetor(vet, TAMANHO);
            insertionSort(vet, TAMANHO);
            printf("Ordenado: "); mostra_vetor(vet, TAMANHO);
            printf("\n ");
            break;
        case 3:
            printf("\n ###### SELECTION SORT ###### \n");
            cria_vetor(vet, TAMANHO);
            printf("Original: "); mostra_vetor(vet, TAMANHO);
            start = clock(); //calculando tempo
            selectionSort(vet, TAMANHO);
            finish = clock(); ; //fim da contagem
            printf("Ordenado: "); mostra_vetor(vet, TAMANHO);
            time = (difftime(finish, start)/CLOCKS_PER_SEC);
            printf("Tempo de execução: %.4f s \n\n", time);
            break;
        case 4:
            printf("\n ###### QUICK SORT ###### \n");
            cria_vetor(vet, TAMANHO);
            printf("Original: "); mostra_vetor(vet, TAMANHO);
            quickSort(vet, 0, TAMANHO-1);
            printf("Ordenado: "); mostra_vetor(vet, TAMANHO);
            printf("\n");
            break;
        case 0:
            printf(" \nFIM...\n");
            opcao = 0;
            break;
        default:
            printf("\nOperação inválida\n\n");
            break;
        }
    }while(opcao);
    return 0;
}
