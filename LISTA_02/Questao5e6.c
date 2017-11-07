#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct { //criando registro
    char Nome[30];
    char Endereco[100];
    int Fone;
    char Situacao;
}Agenda;

void AddPessoas(Agenda *a, char *nome, char *endereco, int fone, int *contatos)//add contatos
{
    strcpy(a[*contatos].Nome, nome);
    strcpy(a[*contatos].Endereco, endereco);
    a[*contatos].Fone = fone;
    a[*contatos].Situacao = 'L'; //definindo todo contato como livre
    *contatos += 1;

}

int PesquisaPessoas(Agenda *a, char *nome, int *contatos)
{
    int i = 0;
    for(i = 0; i < *contatos; i++)
    {
        if(!strcmp(a[i].Nome, nome))//comparando conteudos e verificando se nome lido está no vetor
            return i;
    }

    return -1;//quando n encontra retorna valor negativo
}

void TrocarNome(Agenda *a, char *nome, int menu)
{
    strcpy(a[menu].Nome, nome); //substituindo valor
}

void TrocarEndereco(Agenda *a, char *endereco, int menu)
{
    strcpy(a[menu].Endereco, endereco);
}

void TrocarFone(Agenda *a, int fone, int menu)
{
    a[menu].Fone = fone;
}

void TrocarSituacao(Agenda *a, char situacao, int menu)
{
    a[menu].Situacao = situacao;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int tamanho = 5, contatos = 0, fone, encontrou = 0;
    Agenda a[tamanho];
    char leitura, nome[30], endereco[100], situacao;

    while(1)
    {
        printf("\n########### AGENDA ###########\n");
        printf("1- Inserir Registros.\n");
        printf("2- Pesquisar Registro pelo NOME.\n");
        printf("3- Alterar Registro.\n");
        printf("#Qualquer tecla para Sair do Programa.\n");
        printf("-> Digite qual opção deseja realizar: ");
        scanf("%c", &leitura);

        if(leitura == '1')
        {
            if(contatos >= 5) //maximo de contatos
                printf("#### AGENDA LOTADA!! ####\n");
            else //lendo informacoes
            {
                printf("Nome: ");
                scanf("%s", nome);
                fflush(stdin);
                printf("Endereço: ");
                fflush(stdin);
                scanf("%s", endereco);
                printf("Telefone: ");
                scanf("%d", &fone);
                fflush(stdin);

                getchar();

                AddPessoas(a, nome, endereco, fone, &contatos);
            }
        }
        else if(leitura == '2') //pesquisandocontatos
        {
            printf("Nome: ");
            scanf("%s", nome);
            getchar();
            encontrou = PesquisaPessoas(a, nome, &contatos);

            if(encontrou == -1) //n econtrado
                printf("NOME NÃO ENCONTRADO!! \n");
            else //mostrando informacoes
            {
                printf("\nNome: %s\n", a[encontrou].Nome);
                printf("Endereço: %s\n", a[encontrou].Endereco);
                printf("Telefone: %d\n", a[encontrou].Fone);
                printf("Situação: %c\n", a[encontrou].Situacao);
            }
        }
        else if(leitura == '3') //alterar registro
        {
            printf("Nome: ");
            scanf("%s", nome);
            getchar();
            encontrou = PesquisaPessoas(a, nome, &contatos); //pesquisa novamente

            if(encontrou == -1)
                printf("#### NOME NÃO ENCONTRADO!! ####\n");
            else
            {
                printf("\nNome: %s\n", a[encontrou].Nome);
                printf("Endereço: %s\n", a[encontrou].Endereco);
                printf("Telefone: %d\n", a[encontrou].Fone);
                printf("Situação: %c\n", a[encontrou].Situacao);

                printf("Deseja Alterar o NOME? S: Sim N: Não ");
                scanf("%c", &leitura);
                getchar();
                if(leitura == 'S')
                {
                    printf("Nome: ");
                    scanf("%s", nome);
                    getchar();
                    TrocarNome(a, nome, encontrou);
                }

                printf("Deseja Alterar o ENDEREÇO? S: Sim N: Não ");
                scanf("%c", &leitura);
                getchar();
                if(leitura == 'S')
                {
                    printf("Endereço: ");
                    scanf("%s", endereco);
                    getchar();
                    TrocarEndereco(a, endereco, encontrou);
                }

                printf("Deseja Alterar o TELEFONE? S: Sim N: Não ");
                scanf("%c", &leitura);
                getchar();
                if(leitura == 'S')
                {
                    printf("Telefone: ");
                    scanf("%d", &fone);
                    getchar();
                    TrocarFone(a, fone, encontrou);
                }

                printf("Deseja Alterar a SITUAÇÃO? S: Sim N: Não ");
                scanf("%c", &leitura);
                getchar();
                if(leitura == 'S')
                {
                    printf("Situação(L – Livre; X – Ocupado e * - Apagado): ");
                    scanf("%c", &situacao);
                    getchar();
                    TrocarSituacao(a, situacao, encontrou);
                }
            }
        }
        else
            break;
    }
    system("pause");
}
