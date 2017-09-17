#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    char nome[80], status[40];
    float nota[2], media, notafinal, mediafinal;
  }Alunos;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Alunos al[35];
    int i;

    printf("DISCIPLINA ESTRUTURAS DE DADOS\n");
    for(i = 0; i < 35; i++){
        printf("Nome do Estudante: ");
        fgets(al[i].nome, al[i].nome, stdin);
        fflush(stdin);
        printf("Primeira Nota: ");
        scanf("%f", &al[i].nota[0]);
        fflush(stdin);
        printf("Segunda Nota: ");
        scanf("%f", &al[i].nota[1]);
        fflush(stdin);

        al[i].media = (al[i].nota[0] + al[i].nota[1]) / 2;

    if(al[i].media >= 7){
        printf("APROVADO COM A MÉDIA %.2f!\n", al[i].media);
        printf("Situação: ");
        scanf("%s", al[i].status);
        fflush(stdin);
        printf("\n");
    }

    if(al[i].media <= 2.99){
        printf("REPROVADO COM A MÉDIA %.2f!\n", al[i].media);
        printf("Situação: ");
        scanf("%s", al[i].status);
        fflush(stdin);
        printf("\n");
    }

    if(al[i].media < 7) {
        printf("Nota da Final: ");
        scanf("%f", &al[i].notafinal);
        fflush(stdin);
        al[i].mediafinal = (al[i].notafinal + al[i].media) / 2;
        if(al[i].mediafinal >= 5){
            printf("APROVADO COM A MÉDIA %2.f!\n", al[i].mediafinal);
            printf("Situação: ");
            fgets(al[i].status, al[i].status, stdin);
            fflush(stdin);
            printf("\n");
        }
        if(al[i].mediafinal < 5){
            printf("REPROVADO COM A MÉDIA %.2f!\n", al[i].media);
            printf("Situação: ");
            fgets(al[i].status, al[i].status, stdin);
            fflush(stdin);
            printf("\n");
        }
    }

    }

    printf("\n########## Resultado Final!! ############\n\n");
    for(i=0; i < 35; i++){
        printf("ALUNO %d: %s",i+1, al[i].nome);
        printf("Média: %.2f\n", al[i].media);
        printf("Situação: %s\n",al[i].status);
        printf("------------------\n");
  }

    return 0;
}
