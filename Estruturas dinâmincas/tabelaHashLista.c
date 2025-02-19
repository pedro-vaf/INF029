/* Tabela Hash - Vetor (Resolvendo colisão avaçando em cada índice) */

/* Tamanho -> M = 2 * 'tamanho' = (passe o resultado para o primo mais próximo) */
/* Utilizando o exemplo de 15 elementos -> M = 2 * 15 = 30 -> 31 (primo mais próximo) */

/* Fator de carga -> fc = 'tamanho' / (primo mais próximo, descoberto anteriormente) */
/* Fator de carga -> fc = 15 / 31 = 0,48 (Quanto mais próximo de 1 ou 0 menos eficiente se torna a tabela)*/
/* O 0,48 significa que a tabela terá 48% de ocupação */

/* Função de espalhamento = chave % M */

#include <stdio.h>
#include <stdlib.h>

#define tamanho 31

typedef struct no {
    int valor;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
    int tamanhoLista;
} Lista;

void criarLista(Lista *lista) {
    lista -> inicio = NULL;
    lista -> tamanhoLista = 0;
}

void inserirNaLista(Lista *lista, int chave) {
    No *novo = malloc(sizeof(No));

    if (novo) {
        novo -> valor = chave;
        novo -> proximo = lista -> inicio; // Insere no início da lista.
        lista -> inicio = novo;
        lista -> tamanhoLista++;
    } else {
        printf("\nErro ao alocar memória\n");
    }
}

int buscarLista(Lista *lista, int chave) {
    No *temp = lista -> inicio;

    while (temp && temp -> valor != chave) {
        temp = temp -> proximo;
    }

    if (temp) {
        return temp -> valor;
    } else {
        return -1; // Valor não encontrado.
    }
}

void imprimirLista(Lista *lista) {
    No *temp = lista -> inicio;

    printf("Tamanho da lista: %d\n", lista->tamanhoLista);
    if (temp) {
        while (temp) {
            if (temp -> proximo != NULL) {
                printf("%d -> ", temp -> valor);
            } else {
                printf("%d", temp -> valor);
            }
            temp = temp -> proximo; // Move para o próximo nó.
        }
    } else {
        printf("Lista vazia");
    }
    printf("\n");
}

void inicializarTabelaHash(Lista tabela[]) {
    for (int i = 0; i < tamanho; i++) {
        criarLista(&tabela[i]);
    }
}

int funcaoHash(int chave) {
    return chave % tamanho;
}

void inserirTabela(Lista tabela[], int chave) {
    int id = funcaoHash(chave);
    inserirNaLista(&tabela[id], chave);
}

int buscarTabela(Lista tabela[], int chave) {
    int id = funcaoHash(chave);
    return buscarLista(&tabela[id], chave);
}

void imprimirTabela(Lista tabela[]) {
    printf("\nImprimindo tabela\n");
    for (int i = 0; i < tamanho; i++) {
        printf("\n%d -> ", i);
        imprimirLista(&tabela[i]);
    }
}

int menuTabelaHash() {
    int opcaoMenu;
    printf("\n*** Tabela Hash ***\n");
    printf("0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Buscar\n");
    printf("3 - Imprimir\n");
    printf("Insira o número referente -> ");
    scanf("%d", &opcaoMenu);
    return opcaoMenu;
}

int main() {
    Lista tabela[tamanho];
    int opcaoMenu, busca, chave;

    inicializarTabelaHash(tabela);

    do {
        opcaoMenu = menuTabelaHash();

        switch (opcaoMenu) {
            case 1:
                printf("\nInsira o valor -> ");
                scanf("%d", &chave);
                inserirTabela(tabela, chave);
                break;

            case 2:
                printf("\nInsira o valor -> ");
                scanf("%d", &chave);
                busca = buscarTabela(tabela, chave);

                if (busca != -1) {
                    printf("\nChave %d encontrada na tabela\n", chave);
                } else {
                    printf("\nChave %d não encontrada na tabela\n", chave);
                }
                break;

            case 3:
                imprimirTabela(tabela);
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
                break;
        }
    } while (opcaoMenu != 0);

    return 0;
}