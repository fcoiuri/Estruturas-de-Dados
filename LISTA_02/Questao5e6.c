#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include<string.h>

typedef struct {
    char Nome[30];
    char Endereco[100];
    int Fone;
    char Situacao;
}Agenda;

void AddPessoas(Agenda *a, char *nome, char *endereco, int fone, int *contatos)
{
    strcpy(a[*contatos].Nome, nome);
    strcpy(a[*contatos].Endereco, endereco);
    a[*contatos].Fone = fone;
    a[*contatos].Situacao = 'L';
    *contatos += 1;

}

int PesquisaPessoas(Agenda *a, char *nome, int *contatos)
{
    int i = 0;
    for(i = 0; i < *contatos; i++)
    {
        if(!strcmp(a[i].Nome, nome))
            return i;
    }

    return -1;
}

void TrocarNome(Agenda *a, char *nome, int menu)
{
    strcpy(a[menu].Nome, nome);
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
        printf("-> Digite qual op��o deseja realizar: ");
        scanf("%c", &leitura);

        if(leitura == '1')
        {
            if(contatos >= 5)
                printf("#### AGENDA LOTADA!! ####\n");
            else
            {
                printf("Nome: ");
                scanf("%s", nome);
                fflush(stdin);
                printf("Endere�o: ");
                fflush(stdin);
                scanf("%s", endereco);
                printf("Telefone: ");
                scanf("%d", &fone);
                fflush(stdin);

                getchar();

                AddPessoas(a, nome, endereco, fone, &contatos);
            }
        }
        else if(leitura == '2')
        {
            printf("Nome: ");
            scanf("%s", nome);
            getchar();
            encontrou = PesquisaPessoas(a, nome, &contatos);

            if(encontrou == -1)
                printf("NOME N�O ENCONTRADO!! \n");
            else
            {
                printf("\nNome: %s\n", a[encontrou].Nome);
                printf("Endere�o: %s\n", a[encontrou].Endereco);
                printf("Telefone: %d\n", a[encontrou].Fone);
                printf("Situa��o: %c\n", a[encontrou].Situacao);
            }
        }
        else if(leitura == '3')
        {
            printf("Nome: ");
            scanf("%s", nome);
            getchar();
            encontrou = PesquisaPessoas(a, nome, &contatos);

            if(encontrou == -1)
                printf("#### NOME N�O ENCONTRADO!! ####\n");
            else
            {
                printf("\nNome: %s\n", a[encontrou].Nome);
                printf("Endere�o: %s\n", a[encontrou].Endereco);
                printf("Telefone: %d\n", a[encontrou].Fone);
                printf("Situa��o: %c\n", a[encontrou].Situacao);

                printf("Deseja Alterar o NOME? S: Sim N: N�o ");
                scanf("%c", &leitura);
                getchar();
                if(leitura == 'S')
                {
                    printf("Nome: ");
                    scanf("%s", nome);
                    getchar();
                    TrocarNome(a, nome, encontrou);
                }

                printf("Deseja Alterar o ENDERE�O? S: Sim N: N�o ");
                scanf("%c", &leitura);
                getchar();
                if(leitura == 'S')
                {
                    printf("Endere�o: ");
                    scanf("%s", endereco);
                    getchar();
                    TrocarEndereco(a, endereco, encontrou);
                }

                printf("Deseja Alterar o TELEFONE? S: Sim N: N�o ");
                scanf("%c", &leitura);
                getchar();
                if(leitura == 'S')
                {
                    printf("Telefone: ");
                    scanf("%d", &fone);
                    getchar();
                    TrocarFone(a, fone, encontrou);
                }

                printf("Deseja Alterar a SITUA��O? S: Sim N: N�o ");
                scanf("%c", &leitura);
                getchar();
                if(leitura == 'S')
                {
                    printf("Situa��o(L � Livre; X � Ocupado e * - Apagado): ");
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
