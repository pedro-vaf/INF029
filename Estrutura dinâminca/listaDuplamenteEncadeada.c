/* Lista duplamente encadeada, utiliza dois ponteiros um para pr�ximo e um para anterior */

/* Fun��es da Lista Encadeada sem cabecote 

1 - Procedimento para inserir no inicio da lista
2 - Procedimento para inserir no final da lista
3 - Procedimento para inserir no meio da lista
4 - Procedimento para inserir ordendado na lista
5 - Procedimento para imprimir a lista encadeada
6 - Procedimento para imprimir a lista de tr�s para frente	
7 - Procedimento para remover o primeiro elemento da lista
8 - Procedimento para remover um valor especifico da lista
9 - Procedimento para realizar uma busca na lista
10 - Procedimento para liberar mem�ria aloacada */

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *proximo;
    struct No *anterior;
} No;

No *lista = NULL;
No *inversoLista = NULL;

/* Procedimento para inserir no inicio */
void inserirInicioLista(No **lista){
    int num;
    printf("\nInsira o valor no inicio da lista -> ");
    scanf("%d", &num);

    No *novo = malloc(sizeof(No));
    if (novo){
        novo -> valor = num;
        novo -> proximo = *lista;
        novo -> anterior = NULL;

        if(*lista != NULL){
            (*lista) -> anterior = novo;
        }

        *lista = novo;
    } else { printf("Erro ao alocar mem�ria!\n"); }
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

        if (*lista == NULL) /* � o primeiro? */ {
            *lista = novo;
            novo -> anterior = NULL;
        } else {
            temp = *lista;
            while (temp -> proximo){
                temp = temp -> proximo;
            }
            temp -> proximo = novo;
            novo -> anterior = temp;
        }

    } else { printf("Erro ao alocar mem�ria!\n"); }
}

/* Procedimento para inserir no meio da lista */
void inserirMeioLista(No **lista){
    int num;
    printf("\nInsira o valor no meio da lista -> ");
    scanf("%d", &num);

    int chave;
    printf("\nAp�s qual chave deseja inserir -> ");
    scanf("%d", &chave);

    No *temp, *novo = malloc(sizeof(No));
    if (novo){
        novo -> valor = num;
        if (*lista == NULL) /* � o primeiro? */ {
            novo -> proximo = NULL;
            novo -> anterior = NULL;
            *lista = novo;
        } else {
            temp = *lista;
            while (temp->valor != chave && temp->proximo) {
                temp = temp->proximo;
            }

            if (temp->valor == chave) {
                novo->proximo = temp->proximo;
                if (temp->proximo) {
                    temp->proximo->anterior = novo;
                }
                novo->anterior = temp;
                temp->proximo = novo;
            
            } else {
                printf("Chave %d n�o encontrada na lista.\n", chave);
                free(novo);
            }
        }
    } else { printf("Erro ao alocar mem�ria!\n"); }
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
            novo -> anterior = NULL;
            *lista = novo;
        } else if (novo -> valor < (*lista) -> valor){
            novo -> proximo = (*lista);
            (*lista) -> anterior = novo;
            *lista = novo;
        } else {
            temp = *lista;
            while (temp -> proximo && novo -> valor > temp -> proximo -> valor){
                temp = temp -> proximo;
            }
            novo -> proximo = temp -> proximo;
            
            temp -> proximo = novo;
        }

    } else { printf("Erro ao alocar mem�ria!\n"); }
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
        *lista = remover -> proximo;
        (*lista) -> anterior = NULL;
        printf("\nO elemento %d foi removido da lista\n", remover -> valor);
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
            *lista = remover -> proximo;

            if (*lista){
                (*lista) -> anterior = NULL;
            }

            printf("\nO elemento %d foi removido da lista\n", remover -> valor);
            free(remover);
        } else {
            temp = *lista;

            while (temp -> proximo && temp -> proximo -> valor != num) {
                temp = temp -> proximo;
            }

            if (temp -> proximo){
                remover = temp -> proximo;
                temp -> proximo = remover -> proximo;

                if (temp -> proximo){
                    temp -> proximo -> anterior = temp;
                }
        
                printf("\nO elemento %d foi removido da lista\n", remover -> valor);
                free(remover);
            } else { printf("\nO elemento %d n�o foi encontrado", num); }
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
    } else { printf("\nO elemento n�o existe na lista\n"); }
}

/* Procedimento para imprimir a lista de tr�s para frente */
No * ultimoNo(No **lista, No **inversoLista){
    No * temp = *lista;

    while (temp -> proximo) {
      temp = temp -> proximo;
    }
    
    (*inversoLista) = temp;
    return (*inversoLista);
}

void imprimirContrario(No **inversoLista, No **lista) {
    if (*lista != NULL) {
        printf("\n**** Elementos da lista (inverso) ****\n");
        No *temp = ultimoNo(lista, inversoLista);
        while (temp != NULL) {
            printf("%d ", temp->valor);
            temp = temp->anterior;
        }
        printf("\n**** Fim da lista ****\n");
    } else {
        printf("\nLista Vazia\n");
    }
}


void liberarLista(No **lista) {
    No *temp;
    while (*lista) {
        temp = *lista; /* Salva a refer�ncia ao n� atual */
        *lista = (*lista) -> proximo; /* Avan�a para o pr�ximo n� */
        free(temp);  /* Libera o n� atual */       
    }
}

int menuLista(int opcao){
    printf("\n**** Menu da lista ****\n");
    printf("1 - Inserir elemento no inicio da lista\n");
    printf("2 - Inserir elemento no meio da lista\n");
    printf("3 - Inserir elemento no final da lista\n");
    printf("4 - Inserir elementos ordenado na lista\n");
    printf("5 - Imprimir elementos da lista\n");
    printf("6 - Imprimir o inverso da lista\n");
    printf("7 - Remover o primeiro elemento da lista\n");
    printf("8 - Remover um elemento espec�fico na lista\n");
    printf("9 - Buscar elemento na lista\n");
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
                imprimirContrario(&inversoLista, &lista);
            break;

            case 7:
                removerLista(&lista);
            break;

            case 8:
                removerValorEspecificoLista(&lista);
            break;

            case 9:
                buscarLista(&lista);
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