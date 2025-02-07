#include <stdio.h>
#include <stdlib.h>

/* �rvore bin�ria - Vers�o 1 (Usando retorno)*/

typedef struct no {
    int valor;
    struct no *esquerda;
    struct no *direita;
} NoArvore;

NoArvore * inserir(NoArvore * raiz, int elemento) {
    if (raiz == NULL) {
        NoArvore * novo = malloc(sizeof(NoArvore));
        
        if (novo) {
            novo -> valor = elemento;
            novo -> direita = NULL;
            novo -> esquerda = NULL;
            return novo;

        } else { printf("Erro ao alocar m�moria.\n"); }

    } else {
        if (elemento < raiz -> valor) {
            raiz -> esquerda = inserir(raiz -> esquerda, elemento);
        } else {
            raiz -> direita = inserir(raiz -> direita, elemento);
        }
        return raiz;
    }
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
                raiz = inserir(raiz, elemento);
            break;
            
            case 2:
                printf("\n*** Impress�o em pr�-ordem ***\n");
                imprimirPreOrdem(raiz);

                printf("\n*** Impress�o em in-ordem ***\n");
                imprimirInOrdem(raiz);
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