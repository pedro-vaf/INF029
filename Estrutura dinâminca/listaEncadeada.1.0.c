/* Lista Encadeada - Simples 1° versão utilizando ponteiro para ponteiro */

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct  No *proximo;
} No;

No *lista = NULL;

/* Procedimento para inserir no inicio */
void inserirInicioLista(No **lista){
    int num;
    printf("\nInsira o valor no inicio da lista -> ");
    scanf("%d", &num);

    No *novo = malloc(sizeof(No));
    if (novo){
        novo -> valor = num;
        novo -> proximo = *lista;
        *lista = novo;
    } else { printf("Erro ao alocar memória!\n"); }
}

/* Procedimento para inserir no fim */
void inserirFinalLista(No **lista){
    int num;
    printf("\nInsira o valor no final da lista -> ");
    scanf("%d", &num);

    No *temp, *novo = malloc(sizeof(No));
    if (novo){
        novo -> valor = num;
        novo -> proximo = NULL;

        if (*lista == NULL) /* É o primeiro? */ {
            *lista = novo;
        } else {
            temp = *lista;
            while (temp -> proximo){
                temp = temp -> proximo;
            }
            temp -> proximo = novo;
        }

    } else { printf("Erro ao alocar memória!\n"); }
}

/* Procedimento para inserir no meio da lista */
void inserirMeioLista(No **lista){
    int num;
    printf("\nInsira o valor no meio da lista -> ");
    scanf("%d", &num);

    int chave;
    printf("\nApós qual chave deseja inserir -> ");
    scanf("%d", &chave);

    No *temp, *novo = malloc(sizeof(No));
    if (novo){
        novo -> valor = num;
        if (*lista == NULL) /* É o primeiro? */ {
            novo -> proximo = NULL;
            *lista = novo;
        } else {
            temp = *lista;
            while (temp -> valor != chave && temp -> proximo){
                temp = temp -> proximo;
            }
            novo -> proximo = temp -> proximo;
            temp -> proximo = novo;
        }
    } else { printf("Erro ao alocar memória!\n"); }
}

/* Procedimento para imprimir a lista encadeada */
void imprimirLista(No *lista){
    printf("\n**** Elementos da lista ****\n");
    No * temp = lista;
    while (temp != NULL) {
        printf("%d ", temp -> valor);
        temp = temp -> proximo;
    }
    printf("\n**** Fim da lista ****\n");
}

/* Procedimento para liberar memória alocada para lista */
void liberarLista(No **lista) {
    No *temp;
    while (*lista) {
        temp = *lista; /* Salva a referência ao nó atual */
        *lista = (*lista) -> proximo; /* Avança para o próximo nó */
        free(temp);  /* Libera o nó atual */       
    }
}

int menuLista(int opcao){
    printf("\n**** Menu da lista ****\n");
    printf("1 - Inserir elemento no inicio da lista\n");
    printf("2 - Inserir elemento no meio da lista\n");
    printf("3 - Inserir elemento no final da lista\n");
    printf("4 - Imprimir elementos da lista\n");
    printf("5 - Sair\n");
    printf("Insira o numero referente -> ");
    scanf("%d", &opcao);
    return opcao;
}
int main(){
    int opcao;

    do{

        opcao = menuLista(opcao);
        switch (opcao)
        {
            case 1:
                inserirInicioLista(&lista); 
            break;

            case 2:
                inserirMeioLista(&lista);
            break;

            case 3: 
                inserirFinalLista(&lista);
            break;

            case 4:
                imprimirLista(lista);
            break;
        
            default:
                printf("\nErro!\n");
            break;
        }

    } while (opcao != 5);

    liberarLista(&lista);
    return 0;
}
