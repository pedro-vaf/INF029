#include <stdio.h>
#include <stdlib.h>

/* Árvore binária - Versão 1 (Sem retorno e sem recursão) */

typedef struct no {
    int valor;
    struct no *esquerda;
    struct no *direita;
} NoArvore;

NoArvore * raiz =  NULL;

void inserir (NoArvore ** raiz, int elemento){
    NoArvore * temp = (*raiz);
    while (temp) {
        if (elemento < temp -> valor){
            raiz = &temp -> esquerda;
        } else {
            raiz = &temp -> direita;
        }

        temp = *raiz;
    }   

    temp = malloc(sizeof(NoArvore));
    temp -> valor = elemento;
    temp -> esquerda = NULL;
    temp -> direita = NULL;
    (*raiz) = temp;
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