#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i, j, linhaA, colunaA, linhaB, colunaB, x;
    linhaA=5;
    colunaA=4;
    linhaB=4;
    colunaB=3;
    float matrizC[linhaA][colunaB],Aux=0;
    float A[5][4] = {
       {5, 76, 32, 54},
       {67, 90, 12, 67},
       {54, 43, 11, 98},
       {22, 7, 13, 22},
       {10, 56, 03, 45}
       };

    float B[4][3] = {
       {55, 84, 51},
       {5, 19, 78},
       {16, 91, 65},
       {62, 20, 52}
   };



    printf("#### Multiplicação de Matrizes! ####\n");

    printf("############ MATRIZ A: #####################\n\n");
    for(i=0; i<linhaA; i++){
         for(j=0; j<colunaA; j++){
             printf("%6.f", A[i][j]);
         }
         printf("\n\n");
     }
    printf("############ MATRIZ B: #####################\n\n");
    for(i=0; i<linhaB; i++){
         for(j=0; j<colunaB; j++){
             printf("%6.f", B[i][j]);
         }
         printf("\n\n");
     }
    for(i=0; i<5; i++){
        for(j=0; j<3; j++){
            matrizC[i][j]=0;
            for(x=0; x<4; x++){
                Aux+= A[i][x] * B[x][j];
                //x significa que a quantidade de colunas da Matriz A é a mesma que as linhas da Matriz B
                }
                matrizC[i][j]=Aux; //var aux é para guardar valor pra n ser perdido durante o algoritmo
                Aux=0;

         }
     }
    printf("\n\n");
    printf("############ MATRIZ C: #####################\n\n");
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            printf("%6.f", matrizC[i][j]);
         }
         printf("\n\n");
     }
    printf("\n\n");
    system("pause");


    return 0;
}
