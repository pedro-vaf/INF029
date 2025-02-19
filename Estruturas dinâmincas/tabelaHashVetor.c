/* Tabela Hash - Vetor (Resolvendo colisão avaçando em cada índice) */

#include <stdio.h>
#include <stdlib.h>
#define tamanho 31

/* Tamanho -> M = 2 * 'tamanho' = (passe o resultado para o primo mais próximo) */
/* Utilizando o exemplo de 15 elementos -> M = 2 * 15 = 30 -> 31 (primo mais próximo) */

/* Fator de carga -> fc = 'tamanho' / (primo mais próximo, descoberto anteriormente) */
/* Fator de carga -> fc = 15 / 31 = 0,48 (Quanto mais próximo de 1 ou 0 menos eficiente se torna a tabela)*/
/* O 0,48 significa que a tabela terá 48% de ocupação */

/* Função de espalhamento = chave % M */

void inicializarTabelaHash(int tabela[]){
    for (int icont = 0; icont < tamanho; icont = icont + 1){
        tabela[icont] = -1;
    }
}

int funcaoHash(int chave){
    return chave % tamanho;
}

void inserirTabela(int tabela[], int chave){
    int id = funcaoHash(chave);

    while (tabela[id] != -1) {
        id = funcaoHash(id + 1);
    }
    tabela[id] = chave;
}

void buscarTabela(int tabela[], int chave){
    
    int id = funcaoHash(chave);

    while (tabela[id] != -1) {
        if (tabela[id] == chave) {
            printf("\nO valor %d encontrado na tabela Hash na posição %d\n", chave, tabela[id]);
            return;
        } else { id = funcaoHash(id + 1); }  
    }

    if (tabela[id] == -1){
        printf("\nO valor %d não encontrado na tabela Hash\n", chave);
    } 
}

void imprimirTabela(int tabela[]){
    printf("\nImprimindo tabela\n");
    
    for (int icont = 0; icont < tamanho; icont = icont + 1){
        printf("%d = %d\n", icont, tabela[icont]);
    }
}

int menuTabelaHash(int opcaoMenu){
    printf("\n*** Tabela Hash ***\n");
    printf("0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Buscar\n");
    printf("3 - Imprimir\n");
    printf("Insira o numero referente -> ");
    scanf("%d", &opcaoMenu);
    return opcaoMenu;
}


int main (){

    int tabela[tamanho]; /* Se todos os elementos forma maior ou igual a zero */
    int opcaoMenu;
    
    inicializarTabelaHash(tabela);
    
    do {
        opcaoMenu = menuTabelaHash(opcaoMenu);

        switch (opcaoMenu) {
            case 1:
                int chave;
                printf("\nInsira o valor -> ");
                scanf("%d", &chave);
                inserirTabela(tabela, chave);
            break;

            case 2:
                printf("\nInsira o valor -> ");
                scanf("%d", &chave);
                buscarTabela(tabela, chave);
            break;

            case 3:
                imprimirTabela(tabela);
            break;

            default:
                printf("\nOpção inválida!");
            break;
        }
    } while (opcaoMenu != 0);
    
}