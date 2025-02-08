#include <stdio.h>
#include <stdlib.h>

/* �rvore bin�ria - Vers�o 1 (Sem retorno e sem recurs�o) */

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
        imprimirPreOrdem(raiz -> esquerda); /* Imprimir � esquerda */
        imprimirPreOrdem(raiz -> direita); /* Imprimir � direita */
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
        imprimirPreOrdem(raiz -> esquerda); /* Imprimir � esquerda */
        imprimirPreOrdem(raiz -> direita); /* Imprimir � direita */
        printf("%d ", raiz -> valor);
    } 
}


int main() {
    NoArvore * raiz = NULL;
    int opcao, elemento;

    do {
        printf("\n");
        printf("1 - Inserir na �rvore\n");
        printf("2 - Imprimir �rvore\n");
        printf("3 - Sair\n");
        printf("Op��o referente -> ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                printf("\nQual elemento ir� ser inserido -> ");
                scanf("%d", &elemento);
                inserir(&raiz, elemento);
            break;
            
            case 2:
                printf("\n*** Impress�o em pr�-ordem ***\n");
                imprimirPreOrdem(raiz);

                printf("\n*** Impress�o em in-ordem ***\n");
                imprimirInOrdem(raiz);

                printf("\n*** Impress�o em P�s-ordem ***\n");
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