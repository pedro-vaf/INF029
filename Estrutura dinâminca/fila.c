/* Fila */

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
        printf("%d\n", fila -> valor);
        fila = fila -> proximo;
    } 
    printf("**** Fim da fila ****\n");
}

int menuFila(int opcao){
    printf("\n**** Menu da fila ****\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Remover elemento\n");
    printf("3 - Imprimir elemento\n");
    printf("4 - Sair\n");
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
                removerFila(&fila);
            break;

            case 3: 
                imprimirfila(fila);
            break;

            case 4: 
                printf("\nSaindo...\n");
            break;

            default:
                printf("\nErro!\n");
            break;
        }
    } while (opcao != 4);
     
    return 0;
}