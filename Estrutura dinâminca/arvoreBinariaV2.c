#include <stdio.h>
#include <stdlib.h>

/* Árvore binária - Versão 2 (Sem retorno) */

typedef struct no {
    int valor;
    struct no *esquerda;
    struct no *direita;
} NoArvore;

NoArvore * raiz =  NULL;

void inserir (NoArvore ** raiz, int elemento){
    if (*raiz == NULL) {
        *raiz = malloc(sizeof(NoArvore));
        (*raiz) -> valor = elemento;
        (*raiz) -> direita = NULL;
        (*raiz) -> esquerda = NULL;

    } else {
        if (elemento < (*raiz) -> valor) {
            inserir(&((*raiz) -> esquerda), elemento);
        } else {
            inserir(&((*raiz) -> direita), elemento);
        }
    }
}

void imprimirPreOrdem(NoArvore * raiz) {
    if (raiz) {
        printf("%d ", raiz -> valor);
        imprimirPreOrdem(raiz -> esquerda); /* Imprimir à esquerda */
        imprimirPreOrdem(raiz -> direita); /* Imprimir à direita */
    } 
}

void imprimirInOrdem(NoArvore * raiz) {
    if (raiz) {
        imprimirInOrdem(raiz -> esquerda);
        printf("%d ", raiz -> valor);
        imprimirInOrdem(raiz -> direita);
    } 
}

void imprimirPosOrdem(NoArvore * raiz) {
    if (raiz) {
        imprimirPreOrdem(raiz -> esquerda); /* Imprimir à esquerda */
        imprimirPreOrdem(raiz -> direita); /* Imprimir à direita */
        printf("%d ", raiz -> valor);
    } 
}


int main() {
    NoArvore * raiz = NULL;
    int opcao, elemento;

    do {
        printf("\n");
        printf("1 - Inserir na árvore\n");
        printf("2 - Imprimir árvore\n");
        printf("3 - Sair\n");
        printf("Opção referente -> ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                printf("\nQual elemento irá ser inserido -> ");
                scanf("%d", &elemento);
                inserir(&raiz, elemento);
            break;
            
            case 2:
                printf("\n*** Impressão em pré-ordem ***\n");
                imprimirPreOrdem(raiz);

                printf("\n*** Impressão em in-ordem ***\n");
                imprimirInOrdem(raiz);

                printf("\n*** Impressão em Pós-ordem ***\n");
                imprimirPosOrdem(raiz);

                printf("\n");
            break;

            case 3:
                printf("\nSaindo...\n");
            break;

            default:
                printf("\nErro!\n");
            break;
        }
    } while (opcao != 3);

    return 0;
}