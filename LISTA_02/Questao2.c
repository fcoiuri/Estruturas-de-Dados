#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    char nome[35];
    char sexo;
    int pecas;
}Empresa;

int main()
{
    int i=0, j=0, pecasm=0, pecasf=0, maior=0, vendedormaior;
    Empresa e[5];
    setlocale(LC_ALL, "Portuguese");
    printf("######### Registro de Funcionários! #########\n");
    while(i<5){
        printf("Nome do Funcionário: ");
        fgets(e[i].nome, e[i].nome, stdin);
        fflush(stdin);
        printf("Sexo do Funcionário(M/F): ");
        scanf("%c", &e[i].sexo);
        fflush(stdin);
        printf("Quantidade de Peças Produzidas: ");
        scanf("%i", &e[i].pecas);
        fflush(stdin);
        printf("\n");
        i++;
    };
    while(j<5){
        if(e[j].sexo=='M'){
            pecasm = pecasm + e[j].pecas;
        }else{
            pecasf = pecasf + e[j].pecas;
        }
        if(e[j].pecas > maior){
            maior = e[j].pecas;
            vendedormaior = e[j].nome;
        }
        j++;


    }

    printf("\n######## RESULTADO GERAL!! ########\n");
    printf("Quantidade de Peças produzidas pelo Sexo Masculino: %d\n", pecasm);
    printf("Quantidade de Peças produzidas pelo Sexo Feminino: %d\n", pecasf);
    printf("Maior produtor: %s \n", vendedormaior);

    return 0;
}
