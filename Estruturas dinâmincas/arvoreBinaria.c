#include <stdio.h>
#include <stdlib.h>

/* 
O código abaixo terá três formas de inserir em uma árvore binária 

Forma 1 - Usando o método de recursão, chamando a função dentro de si mesmo e retornado o resultado
para um ponteiro 

Forma 2 - Usando o método de recursão, chamando a função dentro de si mesmo mas não retornando o 
resultado, mudando o valor original pelo endereço da variável 

Forma 3 - Não usa recursão, insere de forma interativa 

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

        } else { printf("Erro ao alocar mémoria.\n"); }

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
        printf("1 - Inserir na árvore\n");
        printf("2 - Imprimir árvore\n");
        printf("3 - Buscar elemento na árvore\n");
        printf("Opção referente -> ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 0:
                printf("\nSaindo...\n");
            break;

            case 1:
                printf("\nQual elemento irá ser inserido -> ");
                scanf("%d", &elemento);
                /*  raiz = inserirForma1(raiz, elemento); */
                /*  inserirForma2(raiz, elemento); */
                /*  inserirForma3(&raiz, elemento); */
            break;
            
            case 2:
                printf("\n*** Impressão em pré-ordem ***\n");
                imprimirPreOrdem(raiz);

                printf("\n*** Impressão em in-ordem ***\n");
                imprimirInOrdem(raiz);

                printf("\n*** Impressão em pós-ordem ***\n");
                imprimirPosOrdem(raiz);

                printf("\n");
            break;

            case 3:
                printf("\nQual elemento irá ser buscado -> ");
                scanf("%d", &elemento);
                /* busca = buscaRecursiva(raiz, elemento); */
                /* busca = buscaInterativa(raiz, elemento); */

                if (busca){
                    printf("\nValor %d foi encontrado na árvore!\n", busca -> valor);
                } else { printf("\nO valor não existe na árvore!\n"); }
            break;

            default:
                printf("\nErro!\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}