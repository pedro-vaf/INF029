/* Fila de Prioridade */

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

No *fila = NULL;

void inserirFila (No **fila){
    int num;
    printf("\nInsira o valor na fila -> ");
    scanf("%d", &num);

    No *temp, *novo = malloc(sizeof(No));
    if (novo){
        novo -> valor = num;
        novo -> proximo = NULL;
        if (*fila == NULL){
            *fila = novo;
        } else {
            temp = *fila;
            while (temp -> proximo) {
                temp = temp -> proximo;
            }
            temp -> proximo = novo;
        }
    } else { printf("\nErro ao alocar\n"); }
}

void inserirFilaPrioridade(No **fila){
    int num;
    // Solicita ao usuário um número para inserir na fila
    printf("\nInsira o valor na fila -> ");
    scanf("%d", &num);

    // Declara um ponteiro temporário e aloca um novo nó
    No *temp, *novo = malloc(sizeof(No));
    if (novo) { // Verifica se a alocação de memória foi bem-sucedida
        novo->valor = num; // Atribui o valor digitado ao novo nó
        novo->proximo = NULL; // Inicializa o ponteiro 'proximo' como NULL

        if (*fila == NULL) { // Caso a fila esteja vazia
            *fila = novo; // O novo nó se torna o primeiro nó da fila
        } else {
            if (num > 59) { /* Condição para prioridade */
                // Verifica se o primeiro elemento da fila não é de prioridade
                if ((*fila)->valor < 60) {
                    novo->proximo = *fila; // Novo nó aponta para o início da fila
                    *fila = novo; // Novo nó se torna o primeiro elemento
                } else {
                    // Percorre a fila até encontrar a posição correta para o nó de prioridade
                    temp = *fila;
                    while (temp->proximo && temp->proximo->valor > 59) {
                        temp = temp->proximo;
                    }
                    // Insere o novo nó na posição correta
                    novo->proximo = temp->proximo;
                    temp->proximo = novo;
                }
            } else { // Caso o número não seja prioritário
                temp = *fila;
                // Percorre até o final da fila
                while (temp->proximo) {
                    temp = temp->proximo;
                }
                // Insere o novo nó no final da fila
                temp->proximo = novo;
            }
        }
    } else { 
        // Caso a alocação de memória falhe
        printf("\nErro ao alocar\n");
    }
}

void removerFila (No **fila){
    No *remove = NULL;
    if (*fila != NULL){
        remove = *fila;
        printf("\nO valor %d foi removido da fila\n", *remove);
        *fila = remove -> proximo;
    } else { printf("\nFila Vazia\n"); }
    free(remove);
}

void imprimirfila(No *fila){
    printf("\n**** Elementos da fila ****\n");
    while (fila != NULL) {
        printf("%d\t", fila -> valor);
        fila = fila -> proximo;
    } 
    printf("\n**** Fim da fila ****\n");
}

int menuFila(int opcao){
    printf("\n**** Menu da fila ****\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Inserir como prioridade\n");
    printf("3 - Remover elemento\n");
    printf("4 - Imprimir elemento\n");
    printf("5 - Sair\n");
    printf("Insira o numero referente -> ");
    scanf("%d", &opcao);
    return opcao;
}

int main(){
    int opcao;
    do {
        opcao = menuFila(opcao);
        switch (opcao)
        {
            case 1:
                inserirFila(&fila);
            break;

            case 2:
                inserirFilaPrioridade(&fila);
            break;

            case 3:
                removerFila(&fila);
            break;

            case 4: 
                imprimirfila(fila);
            break;

            case 5: 
                printf("\nSaindo...\n");
            break;

            default:
                printf("\nErro...\n");
            break;
        }
    } while (opcao != 5);
     
    return 0;
}