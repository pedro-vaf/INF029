#include <stdio.h>
#include <stdlib.h>

/* 
O c�digo abaixo ter� tr�s formas de inserir em uma �rvore bin�ria 

Forma 1 - Usando o m�todo de recurs�o, chamando a fun��o dentro de si mesmo e retornado o resultado
para um ponteiro 

Forma 2 - Usando o m�todo de recurs�o, chamando a fun��o dentro de si mesmo mas n�o retornando o 
resultado, mudando o valor original pelo endere�o da vari�vel 

Forma 3 - N�o usa recurs�o, insere de forma interativa 

Por: Pedro Aquino
*/

typedef struct no {
    int valor;
    struct no *esquerda;
    struct no *direita;
} NoArvore;

NoArvore * inserirForma1(NoArvore * raiz, int elemento) { 
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
            raiz -> esquerda = inserirForma1(raiz -> esquerda, elemento);
        } else {
            raiz -> direita = inserirForma1(raiz -> direita, elemento);
        }
        return raiz;
    }
}

void inserirForma2(NoArvore ** raiz, int elemento){ 
    if (*raiz == NULL) {
        *raiz = malloc(sizeof(NoArvore));
        (*raiz) -> valor = elemento;
        (*raiz) -> direita = NULL;
        (*raiz) -> esquerda = NULL;

    } else {
        if (elemento < (*raiz) -> valor) {
            inserirForma2(&((*raiz) -> esquerda), elemento);
        } else {
            inserirForma2(&((*raiz) -> direita), elemento);
        }
    }
}

void inserirForma3(NoArvore ** raiz, int elemento){
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

NoArvore * buscaRecursiva(NoArvore * raiz, int elemento) {
    if (raiz) {
        if (elemento == raiz -> valor) {
            return raiz;
        } else if (elemento < raiz -> valor) {
            return buscaRecursiva(raiz -> esquerda, elemento);
        } else {
            return buscaRecursiva(raiz -> direita, elemento);
        }
    } 

    return NULL;
}

NoArvore * buscaInterativa(NoArvore * raiz, int elemento){
    while (raiz) {
        if (elemento == raiz -> valor) {
            return raiz;
        } else if (elemento < raiz -> valor) {
            raiz = raiz -> esquerda;
        } else {
            raiz = raiz -> direita;
        } 
    }
    
    return NULL;
}

int main() {
    NoArvore *busca, * raiz = NULL;
    int opcao, elemento;

    do {
        printf("\n");
        printf("0 - Sair\n");
        printf("1 - Inserir na �rvore\n");
        printf("2 - Imprimir �rvore\n");
        printf("3 - Buscar elemento na �rvore\n");
        printf("Op��o referente -> ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 0:
                printf("\nSaindo...\n");
            break;

            case 1:
                printf("\nQual elemento ir� ser inserido -> ");
                scanf("%d", &elemento);
                /*  raiz = inserirForma1(raiz, elemento); */
                /*  inserirForma2(raiz, elemento); */
                /*  inserirForma3(&raiz, elemento); */
            break;
            
            case 2:
                printf("\n*** Impress�o em pr�-ordem ***\n");
                imprimirPreOrdem(raiz);

                printf("\n*** Impress�o em in-ordem ***\n");
                imprimirInOrdem(raiz);

                printf("\n*** Impress�o em p�s-ordem ***\n");
                imprimirPosOrdem(raiz);

                printf("\n");
            break;

            case 3:
                printf("\nQual elemento ir� ser buscado -> ");
                scanf("%d", &elemento);
                /* busca = buscaRecursiva(raiz, elemento); */
                /* busca = buscaInterativa(raiz, elemento); */

                if (busca){
                    printf("\nValor %d foi encontrado na �rvore!\n", busca -> valor);
                } else { printf("\nO valor n�o existe na �rvore!\n"); }
            break;

            default:
                printf("\nErro!\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}