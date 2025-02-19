/* Tabela Hash - Vetor (Resolvendo colis�o ava�ando em cada �ndice) */

/* Tamanho -> M = 2 * 'tamanho' = (passe o resultado para o primo mais pr�ximo) */
/* Utilizando o exemplo de 15 elementos -> M = 2 * 15 = 30 -> 31 (primo mais pr�ximo) */

/* Fator de carga -> fc = 'tamanho' / (primo mais pr�ximo, descoberto anteriormente) */
/* Fator de carga -> fc = 15 / 31 = 0,48 (Quanto mais pr�ximo de 1 ou 0 menos eficiente se torna a tabela)*/
/* O 0,48 significa que a tabela ter� 48% de ocupa��o */

/* Fun��o de espalhamento = chave % M */

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
        novo -> proximo = lista -> inicio; // Insere no in�cio da lista.
        lista -> inicio = novo;
        lista -> tamanhoLista++;
    } else {
        printf("\nErro ao alocar mem�ria\n");
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
        return -1; // Valor n�o encontrado.
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
            temp = temp -> proximo; // Move para o pr�ximo n�.
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
    printf("Insira o n�mero referente -> ");
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
                    printf("\nChave %d n�o encontrada na tabela\n", chave);
                }
                break;

            case 3:
                imprimirTabela(tabela);
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOp��o inv�lida!\n");
                break;
        }
    } while (opcaoMenu != 0);

    return 0;
}