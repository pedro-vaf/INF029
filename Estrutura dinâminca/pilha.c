/* Pilha */

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *proximo;
} No;

int menu(int opcao);
void imprimir(); /* Função que imprime a pilha */
void push(); /* Função que empilha um dado na pilha */
void pop(); /* Função que elimina um dado da pilha */

No *topo = NULL; /* A pilha se inicia vazia */

int main (){
    int opcao;
    
    do {
        opcao = menu(opcao);
        switch (opcao)
        {
            case 1:
            push();
            break;
            
            case 2:
            pop();
            break;

            case 3:
            imprimir();
            break;

            case 4:
            printf("Saindo...");
            break;

            default:
            printf("Opção inválida!");
            break;
        }
    } while (opcao != 4);
    
}

int menu(int opcao){
    printf("\n*** Stack Menu ***\n");
    printf("1 -> Empilhar\n");
    printf("2 -> Desempilhar\n");
    printf("3 -> Imprimir\n");
    printf("4 -> Sair\n");
    printf("Opcão -> ");
    scanf("%d", &opcao);
    return opcao;
}

void push(){
    int valor;

    printf("\nInsira o valor na pilha -> ");
    scanf("%d", &valor);

    printf("*** Empilhando ***\n");
    No *novoValor = malloc(sizeof(No));
    novoValor -> dado = valor;
    novoValor -> proximo = topo;
    topo = novoValor;

    printf("Valor %d Empilhado\n", novoValor -> dado);
}

void pop(){
    printf("\n*** Desempilhando ***\n");
    if (topo == NULL){
        printf("A pilha se encontra vazia\n");
    } else {
        No *temp; /* Ponteiro temporário */
        temp = topo;
        topo = topo -> proximo;
        printf("\nO valor %d foi desempilhado\n", temp -> dado);
        free(temp); /* Liberar o espaço de memória */
    }
}

void imprimir(){
    No *temp; /* Ponteiro temporário */
    temp = topo;
    printf("\n*** Imprimindo Pilha ***\n");
    if (temp == NULL){
        printf("A pilha se encontra vazia\n");
    } else {
        printf("%d\n", temp -> dado);
        temp = temp -> proximo;
    }
}