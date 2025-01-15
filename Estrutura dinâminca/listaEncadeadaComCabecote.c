/* Lista Encadeada - Simples 2° versão utilizando struct para armazenar o inicio da lista e o tamanho */

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct  No *proximo;
} No;

typedef struct {
   No * inicio;
   int tamanho;
} Lista;

void criarLista(Lista * lista){
    lista -> inicio = NULL;
    lista -> tamanho = 0;
}

/* Procedimento para inserir no inicio */
void inserirInicioLista(Lista *lista){
    int num;
    printf("\nInsira o valor no inicio da lista -> ");
    scanf("%d", &num);

    No *novo = malloc(sizeof(No));
    if (novo){
        novo -> valor = num;
        novo -> proximo = lista -> inicio;
        lista -> inicio = novo;
        lista -> tamanho++;
    } else { printf("Erro ao alocar memÃ³ria!\n"); }
}

/* Procedimento para inserir no fim */
void inserirFinalLista(Lista * lista){
    int num;
    printf("\nInsira o valor no final da lista -> ");
    scanf("%d", &num);

    No *temp, *novo = malloc(sizeof(No));
    if (novo){
        novo -> valor = num;
        novo -> proximo = NULL;

        if (lista -> inicio == NULL) /* É o primeiro? */ {
            lista -> inicio = novo;
        } else {
            temp = lista -> inicio;
            while (temp -> proximo){
                temp = temp -> proximo;
            }
            temp -> proximo = novo;
        }
        lista -> tamanho++;
    } else { printf("Erro ao alocar memÃ³ria!\n"); }
}

/* Procedimento para inserir no meio da lista */
void inserirMeioLista(Lista * lista){
    int num;
    printf("\nInsira o valor no meio da lista -> ");
    scanf("%d", &num);

    int chave;
    printf("\nApós qual chave deseja inserir -> ");
    scanf("%d", &chave);

    No *temp, *novo = malloc(sizeof(No));
    if (novo){
        novo -> valor = num;
        if (lista -> inicio == NULL) /* É o primeiro? */ {
            novo -> proximo = NULL;
            lista -> inicio = novo;
        } else {
            temp = lista -> inicio;
            while (temp -> valor != chave && temp -> proximo){
                temp = temp -> proximo;
            }
            novo -> proximo = temp -> proximo;
            temp -> proximo = novo;
        }
        lista -> tamanho++;
    } else { printf("Erro ao alocar memÃ³ria!\n"); }
}

/* Procedimento para inserir ordenado na lista*/
void inserirOrdenado (Lista * lista){
    int num;
    printf("\nInsira o valor ordenado na lista -> ");
    scanf("%d", &num);

    No *temp, *novo = malloc(sizeof(No));
    if (novo){
        novo -> valor = num;
        if (lista -> inicio == NULL){
            novo -> proximo = NULL;
            lista -> inicio = novo;
        } else if ( novo -> valor < lista -> inicio -> valor) {
            novo -> proximo = lista -> inicio;
            lista -> inicio = novo;
        } else {
            temp = lista -> inicio;
            while (temp -> proximo && novo -> valor > temp -> proximo -> valor){
                temp = temp -> proximo;
            }
            novo -> proximo = temp -> proximo;
            temp -> proximo = novo;
        }

        lista -> tamanho++;
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
void liberarLista(Lista * lista) {
    No *temp;
    while (lista -> inicio != NULL) {
        temp = lista -> inicio; /* Salva a referência ao nó atual */
        lista -> inicio = lista -> inicio -> proximo; /* Avança para o próximo nó */
        free(temp);  /* Libera o nó atual */       
    }
    lista -> tamanho = 0;
}

int menuLista(int opcao){
    printf("\n**** Menu da lista ****\n");
    printf("1 - Inserir elemento no inicio da lista\n");
    printf("2 - Inserir elemento no meio da lista\n");
    printf("3 - Inserir elemento no final da lista\n");
    printf("4 - Inserir ordenado na lista\n");
    printf("5 - Imprimir elementos da lista\n");
    printf("6 - Sair\n");
    printf("Insira o numero referente -> ");
    scanf("%d", &opcao);
    return opcao;
}
int main(){
    Lista lista;
    criarLista(&lista);
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
                inserirOrdenado(&lista);
            break;

            case 5:
                imprimirLista(lista.inicio);
            break;

            case 6:
                printf("\nSaindo...\n");
            break;
        
            default:
                printf("\nErro!\n");
            break;
        }

    } while (opcao != 6);

    liberarLista(&lista);
    return 0;
}
