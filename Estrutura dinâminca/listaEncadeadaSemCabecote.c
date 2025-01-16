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

/* Procedimento para inserir ordenado na lista*/
void inserirOrdenado (No **lista){
    int num;
    printf("\nInsira o valor ordenado na lista -> ");
    scanf("%d", &num);

    No * temp, * novo = malloc(sizeof(No));

    if (novo){
        novo -> valor = num;
        if (*lista == NULL){
            novo -> proximo = NULL;
            *lista = novo;
        } else if (novo -> valor < (*lista) -> valor){
            novo -> proximo = (*lista);
            *lista = novo;
        } else {
            temp = *lista;
            while (temp -> proximo && novo -> valor > temp -> proximo -> valor){
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

/* Procedimento para remover o primeiro elemento da lista */
void removerLista (No **lista){
    No * remover = NULL;
    if (*lista != NULL){
        remover = *lista;
        printf("\nO elemento %d foi removido da lista\n", remover -> valor);
        *lista = remover -> proximo;
        free(remover);
    } else { printf("\nLista Vazia\n"); }
}


/* Procedimento para remover valor especifico da lista */
void removerValorEspecificoLista(No **lista){
    int num;
    printf("\nInsira o valor ordenado na lista -> ");
    scanf("%d", &num);

    No * remover, * temp = NULL;
    if (*lista != NULL){
        if ((*lista) -> valor == num){
            remover = *lista;
            printf("\nO elemento %d foi removido da lista\n", remover -> valor);
            *lista = remover -> proximo;
            free(remover);
        } else {
            temp = *lista;
            while (temp -> proximo && temp -> proximo -> valor != num) {
                temp = temp -> proximo;
            }

            if (temp -> proximo){
                remover = temp -> proximo;
                temp -> proximo = remover -> proximo;
                printf("\nO elemento %d foi removido da lista\n", remover -> valor);
                free(remover);
            } else { printf("\nO elemento %d não foi encontrado", num); }
        }
    } else { printf("\nLista Vazia\n"); }
}

/* Procedimento para realizar uma busca na lista */
void buscarLista(No **lista){
    int num;
    printf("\nInsira o valor a ser buscado na lista -> ");
    scanf("%d", &num);

    No * temp, * busca = NULL;

    temp = *lista;

    if (temp && temp -> valor != num){
        temp = temp -> proximo;
    }

    if (temp != NULL){
        busca = temp;
        printf("\nO elemento %d foi encontrado\n", busca -> valor);
    } else { printf("\nO elemento não existe na lista\n"); }
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
    printf("4 - Inserir elementos ordenado na lista\n");
    printf("5 - Imprimir elementos da lista\n");
    printf("6 - Remover o primeiro elemento da lista\n");
    printf("7 - Remover um elemento específico na lista\n");
    printf("8 - Buscar elemento na lista\n");
    printf("9 - Sair\n");
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
                inserirOrdenado(&lista);
            break;

            case 5:
                imprimirLista(lista);
            break;

            case 6:
                removerLista(&lista);
            break;

            case 7:
                removerValorEspecificoLista(&lista);
            break;

            case 8:
                buscarLista(&lista);
            break;

            case 9:
                printf("\nSaindo...\n");
            break;
        
            default:
                printf("\nErro!\n");
            break;
        }

    } while (opcao != 9);

    liberarLista(&lista);
    return 0;
}
