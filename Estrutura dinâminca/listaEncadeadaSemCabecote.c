/* Lista Encadeada - Simples 1° versão utilizando ponteiro para ponteiro */

/* Funções da Lista Encadeada sem cabecote 

1 - Procedimento para inserir no inicio da lista
2 - Procedimento para inserir no final da lista
3 - Procedimento para inserir no meio da lista
4 - Procedimento para inserir ordendado na lista
5 - Procedimento para imprimir a lista encadeada
6 - Procedimento para remover o primeiro elemento da lista
7 - Procedimento para remover um valor especifico da lista
8 - Procedimento para realizar uma busca na lista
9 - Procedimento para dividir uma lista em Par e Impar
10 - Procedimento para liberar memória aloacada */

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct  No *proximo;
} No;

No *lista = NULL;
No *listaPar = NULL;
No *listaImpar = NULL;

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

    if (lista != NULL){
        printf("\n**** Elementos da lista ****\n");
        No * temp = lista;
        while (temp != NULL) {
            printf("%d ", temp -> valor);
            temp = temp -> proximo;
        }
        printf("\n**** Fim da lista ****\n");
    } else { printf("\nLista Vazia\n"); }
    
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

/*Procedimento para dividir uma lista em duas (Par e Impar) - Esta função é mais detalhada para uma melhor compreensão */
void dividirLista(No **lista, No **listaPar, No **listaImpar) {
    No * temp = *lista;      /* Ponteiro para percorrer a lista original */
    No * parAtual = NULL;    /* Ponteiro para o final da listaPar */
    No * imparAtual = NULL;  /* Ponteiro para o final da listaImpar */

    if (*lista != NULL) {
        while (temp != NULL) {

            No *novo = malloc(sizeof(No));
            if (novo){
                novo -> valor = temp -> valor;
                novo -> proximo = NULL;

                if (temp -> valor > 0){
                    if (temp -> valor % 2 == 0) {  
                        if (*listaPar == NULL) {
                            *listaPar = novo;
                            parAtual = novo;
                        } else {
                            parAtual->proximo = novo;
                            parAtual = novo;
                        }
                    } else {  
                        if (*listaImpar == NULL) {
                            *listaImpar = novo;
                            imparAtual = novo;
                        } else {
                            imparAtual->proximo = novo;
                            imparAtual = novo;
                        }
                    }
                }
                
            } else { printf("\nErro ao alocar memória para um novo nó.\n"); }

            temp = temp -> proximo;  
        }        
    } else { printf("\nLista vazia\n"); }   
}

void ImprimirListaParImpar (No *listaPar, No *listaImpar){

    if (listaPar != NULL){
        printf("\n**** Elementos da lista Par ****\n");
        No * tempPar = listaPar;
        while (tempPar != NULL) {
            printf("%d ", tempPar -> valor);
            tempPar = tempPar -> proximo;
        }
        printf("\n**** Fim da lista Par ****\n");
    } else { printf("\nSem elementos pares na lista\n"); }
    
    
    if (listaImpar != NULL){
        printf("\n**** Elementos da lista Impar ****\n");
        No * tempImpar = listaImpar;
        while (tempImpar != NULL) {
            printf("%d ", tempImpar -> valor);
            tempImpar = tempImpar -> proximo;
        }
        printf("\n**** Fim da lista Impar ****\n");
    } else { printf("\nSem elementos impares na lista\n"); }
    
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
    printf("9 - Dividir e imprimir a lista em Par e Impar\n");
    printf("10 - Sair\n");
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
                dividirLista(&lista, &listaPar, &listaImpar);
                ImprimirListaParImpar(listaPar, listaImpar);
            break;

            case 10:
                printf("\nSaindo...\n");
            break;
        
            default:
                printf("\nErro!\n");
            break;
        }

    } while (opcao != 10);

    liberarLista(&lista);
    return 0;
}
