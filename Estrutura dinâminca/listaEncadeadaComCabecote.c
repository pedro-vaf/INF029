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

typedef struct {
    No * inicioPar;
    int tamanhoPar;
} ListaPar;

typedef struct {
    No * inicioImpar;
    int tamanhoImpar;
} ListaImpar;

void criarLista(Lista * lista){
    lista -> inicio = NULL;
    lista -> tamanho = 0;
}

void criarListaPar(ListaPar * listaPar){
    listaPar -> inicioPar = NULL;
    listaPar -> tamanhoPar = 0;
}

void criarListaImpar(ListaImpar * ListaImpar){
    ListaImpar -> inicioImpar = NULL;
    ListaImpar -> tamanhoImpar = 0;
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
    } else { printf("Erro ao alocar memória!\n"); }
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

/* Procedimento para remover o primeiro elemento da lista */
void removerLista (Lista * lista){
    No * remover = NULL;
    if (lista != NULL){
        remover = lista -> inicio;
        printf ("\nO valor %d foi removido da lista\n", remover -> valor);
        lista -> inicio = remover -> proximo;
        free(remover);
        lista -> tamanho--;
    } else { printf("\nLista Vazia\n"); }
}

/* Procedimento para remover valor especifico da lista */
void removerValorEspecifoLista(Lista * lista){
    int num;
    printf("\nInsira o valor ordenado na lista -> ");
    scanf("%d", &num);

    No * remover, * temp = NULL;
    if (lista -> inicio != NULL){
        if (lista -> inicio -> valor == num){
            remover = lista -> inicio;
            printf("\nO elemento %d foi removido da lista\n", num);
            lista -> inicio = remover -> proximo;
            free(remover);
            lista -> tamanho--;
        } else {
            temp = lista -> inicio;
            while (temp -> proximo && temp -> proximo -> valor != num) {
                temp = temp -> proximo;
            }

            if (temp -> proximo){
                remover = temp -> proximo;
                temp -> proximo = remover -> proximo;
                printf("\nO elemento %d foi removido da lista\n", remover -> valor);
                free(remover);
                lista -> tamanho--;
            } else { printf("\nO elemento %d não foi encontrado", num); }
            
        }
    } else { printf("\nLista Vazia\n"); }
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

/* Procedimento para realizar uma busca na lista */
void buscarLista(Lista * lista){
    int num;
    printf("\nInsira o valor a ser buscado na lista -> ");
    scanf("%d", &num);

    No * temp, * busca = NULL;

    temp = lista -> inicio;

    if (temp && temp -> valor != num){
        temp = temp -> proximo;
    }

    if (temp != NULL){
        busca = temp;
        printf("\nO elemento %d foi encontrado\n", busca -> valor);
    } else { printf("\nO elemento não existe na lista\n"); }
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
    printf("4 - Inserir elementos ordenado na lista\n");
    printf("5 - Imprimir elementos da lista\n");
    printf("6 - Remover o primeiro elemento da lista\n");
    printf("7 - Remover um elemento específico na lista\n");
    printf("8 - Buscar elemento na lista\n");
    printf("10 - Sair\n");
    printf("Insira o numero referente -> ");
    scanf("%d", &opcao);
    return opcao;
}
int main(){
    Lista lista;
    ListaPar listaPar;
    ListaImpar ListaImpar;

    criarLista(&lista);
    criarListaPar(&listaPar);
    criarListaImpar(&ListaImpar);

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
                removerLista(&lista);
            break;

            case 7:
                removerValorEspecifoLista(&lista);
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
