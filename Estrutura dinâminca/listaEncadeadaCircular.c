/* Lista encadeada circular */

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
} No;

typedef struct {
    No * inicio;
    No * final;
    int tamanho;
} Lista;

void criarLista(Lista * lista){
    lista -> inicio = NULL;
    lista -> final = NULL;
    lista -> tamanho = 0;
} 

void inserirInicio (Lista * lista){
    int num;
    printf("\nInsira o valor para o inicio da lista -> ");
    scanf("%d", &num);

    No * novo = malloc(sizeof(No));

    if(novo){
        novo -> valor = num;
        novo -> proximo = lista -> inicio;
        lista -> inicio = novo;
        
        if (lista -> final == NULL){
            lista -> final = novo;
        } else {
            lista -> final -> proximo = lista -> inicio;
        }
    
        lista -> tamanho++;
    } else { printf("Erro ao alocar memória!\n"); }
}

void inserirFim(Lista * lista){
    int num;
    printf("\nInsira o valor para o fim da lista -> ");
    scanf("%d", &num);

    No * novo = malloc(sizeof(No));

    if (novo){
        novo -> valor = num;

        if (lista -> inicio == NULL){
            lista -> inicio = novo;
            lista -> final = novo;
            lista -> final -> proximo = lista -> inicio;
        } else {
            lista -> final -> proximo = novo;
            lista -> final = novo;
            lista -> final -> proximo = lista -> inicio; /* 1° forma */
            /* novo -> proximo = lista -> inicio;  2° forma */
        }

        lista -> tamanho++;
    } else { printf("Erro ao alocar memória!\n"); }
}

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

void inserirOrdenado(Lista * lista){
    int num;
    printf("\nInsira o valor que será ordenado -> ");
    scanf("%d", &num);

    No * temp, * novo = malloc(sizeof(No));

    if (novo){
        No * novo = malloc(sizeof(malloc));
        if (lista -> inicio == NULL){
            /* Insere no inicio */
            novo -> proximo = lista -> inicio;
            lista -> inicio = novo;
        
            if (lista -> final == NULL){
                lista -> final = novo;
            } else {
                lista -> final -> proximo = lista -> inicio;
            }

        } else if (novo -> valor < lista -> inicio -> valor){
            /* Insere também no incio por ser o menor valor da lista */
            novo -> proximo = lista -> inicio;
            lista -> inicio = novo;
        
            if (lista -> final == NULL){
                lista -> final = novo;
            } else {
                lista -> final -> proximo = lista -> inicio;
            }

        } else {
            temp = lista -> inicio;
            while (temp -> proximo != lista -> inicio && novo -> valor > temp -> proximo -> valor){
                temp = temp -> proximo;
            }

            if (temp -> proximo == lista -> inicio){
                /* Insere no final */
                lista -> final -> proximo = novo;
                lista -> final = novo;
                lista -> final -> proximo = lista -> inicio; /* 1° forma */
                /* novo -> proximo = lista -> inicio;  2° forma */
            } else {
                novo -> proximo = temp -> proximo;
                temp -> proximo = novo;
            }
            
            
            lista -> tamanho++;
        }
    } else { printf("Erro ao alocar memória !\n"); }
}

void removerInicioLista (Lista * lista){
    No * remover = NULL;

    if (lista != NULL){
        if (lista -> inicio == lista -> final){
            remover = lista -> inicio;
            lista -> inicio = NULL;
            lista -> final = NULL;
            lista -> tamanho--;

        } else {
            remover = lista -> inicio;
            lista -> inicio = remover -> proximo;
            lista -> final -> proximo = lista -> inicio;
            lista -> tamanho--;
        }

        printf ("\nO valor %d foi removido da lista\n", remover -> valor);
        free(remover);

    } else { printf("\nLista Vazia\n"); }
}

void removerValorEspecifico(Lista * lista){
    int num;
    printf("\nInsira o valor que será removido da lista -> ");
    scanf("%d", &num);

    No * temp, * remover = NULL;

    if (lista != NULL){
        if (lista -> inicio == lista -> final && lista -> inicio -> valor == num){
            remover = lista -> inicio;
            lista -> inicio = NULL;
            lista -> final = NULL;
           
        } else if (lista -> inicio -> valor == num){
            remover = lista -> inicio;
            lista -> inicio = remover -> proximo;
            lista -> final -> proximo = lista -> inicio;

        } else {
            temp = lista -> inicio;
            while (temp -> proximo != lista -> inicio && temp -> proximo -> valor != num){
                temp = temp -> proximo;
            }
            
            if (temp -> proximo -> valor == num){
                if (lista -> final == temp -> proximo){
                    remover = temp -> proximo;
                    temp -> proximo = remover -> proximo;
                    lista -> final = temp;
                } else {
                    remover = temp -> proximo;
                    temp -> proximo = remover -> proximo;
                }
            }
            
        }

        lista -> tamanho--;
        printf ("\nO valor %d foi removido da lista\n", remover -> valor);
        free(remover);
        
    } else { printf("\nLista Vazia\n"); }

}

void buscarElemento(Lista * lista){
    int num;
    printf("\nInsira o valor que deseja buscar na lista -> ");
    scanf("%d", &num);

    No * temp, * busca = NULL;

    temp = lista -> inicio;

    if (lista != NULL) {
        if (temp -> valor == num){
            printf("\nValor %d encontrado\n", num);
        } else {
            while (temp -> proximo != lista -> inicio && temp -> proximo -> valor != num) {
                temp = temp -> proximo;
            }
            
            if (temp -> proximo != lista -> inicio){
                printf("\nValor %d encontrado\n", num);
            } else { printf("\nO elemento não existe na lista\n"); }
        }
        
    } else { printf("\nLista Vazia\n"); }
}

void imprimirLista(Lista lista){
    No * no = lista.inicio;

    printf("\nA lista tem %d elementos\n", lista.tamanho);
    if (no != NULL){
        printf("\n**** Elementos da lista ****\n");
        do{
            printf("%d ", no -> valor);
            no = no -> proximo;
        } while (no != lista.inicio);
        printf("\n**** Fim da lista ****\n");
    } else { printf("\nLista Vazia\n"); }
}

void liberarLista(Lista *lista) {
    if (lista == NULL || lista->inicio == NULL) {
        return; // Lista já está vazia
    }

    No *atual = lista -> inicio;
    No *temp;

    // Quebra o ciclo ao final da lista
    lista -> final -> proximo = NULL;

    // Libera os nós um a um
    while (atual != NULL) {
        temp = atual;              // Salva a referência ao nó atual
        atual = atual -> proximo;    // Avança para o próximo nó
        free(temp);                // Libera o nó atual
    }

    // Reinicia os atributos da lista
    lista -> inicio = NULL;
    lista -> final = NULL;
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
    printf("9 - Sair\n");
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
                inserirInicio(&lista);
            break;

            case 2:
                inserirMeioLista(&lista);
            break;

            case 3: 
                inserirFim(&lista);
            break;

            case 4:
                inserirOrdenado(&lista);
            break;

            case 5:
                imprimirLista(lista);
            break;

            case 6:
                removerInicioLista(&lista);
            break;

            case 7:
                removerValorEspecifico(&lista);
            break;

            case 8:
                buscarElemento(&lista);
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