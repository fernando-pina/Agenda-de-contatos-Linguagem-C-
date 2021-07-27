#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct{

    char nome[MAX][30];
    char endereco[MAX][50];
    char telefone[MAX][15];
    int fim;

}Tcontato;

void menu();

int inserir(Tcontato *ag, char nomeTemp[30], char enderecoTemp[50], char telefoneTemp[15]);

int buscaBinaria(Tcontato ag, char nomeTemp[30]);

void mostrar(Tcontato ag);

void altera(Tcontato *ag, char nomeTemp[30]);

int main()
{

    Tcontato agenda;
    agenda.fim = -1;

    int op;
    int flag;
    char nomeTemp[30], enderecoTemp[50], telefoneTemp[15];

    do{
        menu();
        scanf("%d",&op);
        switch(op){
            case 1: system("cls");
                    printf("\n\n* * * * * * * * * * * * * * *     I N S E R I R    * * * * * * * * * * * * * * * \n\n");

                    if(agenda.fim >= (MAX - 1))
                        printf("\n\nImpossivel inserir contato.\n\nAgenda cheia!!!\n\n\n");
                    else{
                        printf("\nNome..........:  ");
                        fflush(stdin);
                        gets(nomeTemp);
                        printf("\nEndereco......:  ");
                        fflush(stdin);
                        gets(enderecoTemp);
                        printf("\nTelefone......:  ");
                        fflush(stdin);
                        gets(telefoneTemp);

                        inserir(&agenda, nomeTemp, enderecoTemp, telefoneTemp);
                    }
                    printf("\n\n\n");
                    system("pause");
                    break;

            case 2: system("cls");
                    printf("\n\n* * * * * * * * * * * * * *     C O N S U L T A    * * * * * * * * * * * * * *\n\n");
                    if((agenda.fim) < 0)
                        printf("\n\nAgenda vazia!!!\n\n\n");
                    else
                    {
                        printf("\n\nConsulta por nome. Por favor, digite um nome.");
                        printf("\n\nNome da consulta..........:  ");
                        fflush(stdin);
                        gets(nomeTemp);
                        buscaBinaria(agenda,nomeTemp);
                    }
                    system("pause");
                    break;

            case 3: system("cls");
                    printf("\n\n* * * * * * * * * * * * * * *      M O S T R A     * * * * * * * * * * * * * * * \n\n");
                    if ((agenda.fim) < 0)
                        printf("\n\nAgenda vazia!!!\n\n\n");
                    else
                        mostrar(agenda);
                    system("pause");
                    break;

            case 4: system("cls");
                    printf("\n\n* * * * * * * * * * * * * * *      A L T E R A     * * * * * * * * * * * * * * * \n\n");
                    if ((agenda.fim) < 0)
                        printf("\n\nImpossivel!!!\n\nAgenda vazia!!!\n\n\n");
                    else
                        printf("\n\nNome do contato a ser alterado..........:  ");
                        fflush(stdin);
                        gets(nomeTemp);
                        altera(&agenda,nomeTemp);
                    system("pause");
                    break;

            case 5: system("cls");
                    printf("\n\n* * * * * * * * * * * * * * *      E X C L U I R     * * * * * * * * * * * * * * * \n\n");
                    if ((agenda.fim) < 0)
                        printf("\n\nImpossivel excluir!!!\n\nAgenda vazia!!!\n\n\n");
                    else
                        printf("\n\nNome do contato a ser excluido..........:  ");
                        fflush(stdin);
                        gets(nomeTemp);
                        excluir(&agenda,nomeTemp);
                    system("pause");
                    break;
        }
    }while(op != 9);

    return 0;
}

void menu(){
    system("cls");
    printf("\n\n* * * * * * * * * * * * * * * *     M E N U     * * * * * * * * * * * * * * * *\n\n\n");
    printf("\n1 - Inserir (ordenado)");
    printf("\n2 - Consultar (por nome)");
    printf("\n3 - Mostrar (todos os contatos)");
    printf("\n4 - Alterar");
    printf("\n5 - Excluir");
    printf("\n9 - Sair");
    printf("\n\nEscolha uma das opcoes..........:  ");
}

int inserir(Tcontato *ag, char nomeTemp[30], char enderecoTemp[50], char telefoneTemp[15]){

    int i = 0, j, trocou = 1;



    /*Inserir contato*/

    if ((ag->fim) < 0)      /*Insere contato na posição zero caso a agenda esteja vazia.*/
    {
        ag->fim = ag->fim + 1;
        strcpy(ag->nome[i],nomeTemp);
        strcpy(ag->endereco[i],enderecoTemp);
        strcpy(ag->telefone[i],telefoneTemp);
        printf("\n\nContato inserido com sucesso!!!");
        return 0;
    }
    else
    {
        while(i <= ag->fim)
        {
            if(strcmpi(nomeTemp, ag->nome[i]) > 0)
                i++;
            else
            {
                ag->fim = ag->fim + 1;
                for(j = ag->fim; j > i; j--) /*Movendo os elementos para frente para abrir posição para i*/
                {
                    strcpy(ag->nome[j],ag->nome[j-1]);
                    strcpy(ag->endereco[j],ag->endereco[j-1]);
                    strcpy(ag->telefone[j],ag->telefone[j-1]);
                }
                strcpy(ag->nome[i],nomeTemp); /*Insere na posição i*/
                strcpy(ag->endereco[i],enderecoTemp);
                strcpy(ag->telefone[i],telefoneTemp);
                printf("\n\nContato inserido com sucesso!!!");
                return 0;
            }
        }

        ag->fim = ag->fim + 1; /*Insere na última posição*/
        strcpy(ag->nome[ag->fim],nomeTemp);
        strcpy(ag->endereco[ag->fim],enderecoTemp);
        strcpy(ag->telefone[ag->fim],telefoneTemp);
        printf("\n\nContato inserido com sucesso!!!");
        return 0;
    }
}

int buscaBinaria(Tcontato ag, char nomeTemp[30]){
    int meio;
	int esquerda = -1, direita = MAX;

	while(esquerda < direita - 1)
    {
		meio = (esquerda + direita)/2;
		if(strcmpi(ag.nome[meio],nomeTemp) == 0)
        {
            printf("\n\nNome..........:  %s",ag.nome[meio]);
            printf("\nEndereco......:  %s",ag.endereco[meio]);
            printf("\nTelefone......:  %s",ag.telefone[meio]);
            printf("\n\n\n");
            return meio;
		}

		if (strcmpi(ag.nome[meio],nomeTemp) < 0)
			esquerda = meio;
		else
			direita = meio;
	}
}

void mostrar(Tcontato ag){

    int i;

    for (i = 0; i <= (ag.fim); i++)
    {
        printf("\nNome..........:  %s",ag.nome[i]);
        printf("\nEndereco......:  %s",ag.endereco[i]);
        printf("\nTelefone......:  %s",ag.telefone[i]);
        printf("\n\n\n================================================================================\n\n");
    }

    printf("\n\n\n");
}

void altera(Tcontato *ag, char nomeTemp[30]){

    char nomeAux[30];
    char novoNomeTemp[30];
    char novoEnderecoTemp[50];
    char novoTelefoneTemp[15];
    int posicao;
    Tcontato agenda;

    printf("\n\nContato a ser alterado:\n");
    strcpy(nomeAux,nomeTemp);
    posicao = buscaBinaria(agenda,nomeAux);
    printf("\n\n\nNovo contato:\n");
    printf("\nNome..........:  ");
    fflush(stdin);
    gets(novoNomeTemp);
    printf("\nEndereco......:  ");
    fflush(stdin);
    gets(novoEnderecoTemp);
    printf("\nTelefone......:  ");
    fflush(stdin);
    gets(novoTelefoneTemp);
    printf("\n\n");
    strcpy(ag->nome[posicao],novoNomeTemp);
    strcpy(ag->endereco[posicao],novoEnderecoTemp);
    strcpy(ag->telefone[posicao],novoTelefoneTemp);
    printf("\n\nContato alterado com sucesso!!!");
    printf("\n\n\n");
}

int excluir(Tcontato *ag, char nomeTemp[30])
{
    int pos, i;
    char nomeAux[30];
    Tcontato agenda;

    strcpy(nomeAux,nomeTemp);
    pos = buscaBinaria(agenda,nomeAux);
    printf("\n\nteste: posicao %d",pos);

    for(i = pos; i < ag->fim; i++)
    {
        strcpy(ag->nome[i],ag->nome[i+1]);
        strcpy(ag->endereco[i],ag->endereco[i+1]);
        strcpy(ag->telefone[i],ag->telefone[i+1]);
    }
    ag->fim = ag->fim - 1;
    printf("\n\nContato excluido com sucesso!!!\n\n\n");
    printf("\n\n\n");
}
