#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

int vetorPrincipal[TAM];
int *estruturasAuxiliares[TAM] = {NULL}; // Array de ponteiros para estruturas auxiliares
int tamanhosEstruturasAuxiliares[TAM] = {0}; // Guarda o tamanho de cada estrutura auxiliar

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho) {
    posicao = posicao - 1;

    if (posicao < 0 || posicao >= TAM) {
        return POSICAO_INVALIDA;
    }

    if (tamanho < 1) {
        return TAMANHO_INVALIDO;
    }

    if (estruturasAuxiliares[posicao] != NULL) {
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }

    estruturasAuxiliares[posicao] = (int *)malloc(tamanho * sizeof(int));
    if (!estruturasAuxiliares[posicao]) {
        return SEM_ESPACO_DE_MEMORIA;
    }

    tamanhosEstruturasAuxiliares[posicao] = tamanho;

    for (int icont = 0; icont < tamanho; icont = icont + 1) {
        estruturasAuxiliares[posicao][icont] = 0;
    }

    return SUCESSO;
}


/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES 
*/
int inserirNumeroEmEstrutura(int posicao, int valor) {
    posicao = posicao - 1;

    if (posicao < 0 || posicao >= TAM) {
        return POSICAO_INVALIDA;
    }

    if (estruturasAuxiliares[posicao] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    int elementosInseridos = 0;
    for (int icont = 0; icont < tamanhosEstruturasAuxiliares[posicao]; icont = icont + 1) {
        if (estruturasAuxiliares[posicao][icont] != 0) {
            elementosInseridos = elementosInseridos + 1;
        }
    }

    if (elementosInseridos >= tamanhosEstruturasAuxiliares[posicao]) {
        return SEM_ESPACO;
    }

    for (int icont = 0; icont < tamanhosEstruturasAuxiliares[posicao]; icont = icont + 1) {
        if (estruturasAuxiliares[posicao][icont] == 0) {
            estruturasAuxiliares[posicao][icont] = valor;
            return SUCESSO;
        }
    }

    return SUCESSO;
} 

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao) {
    posicao = posicao - 1;

    if (posicao < 0 || posicao >= TAM) {
        return POSICAO_INVALIDA;
    }

    if (estruturasAuxiliares[posicao] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    int estaVazia = 1;
    for (int icont = 0; icont < tamanhosEstruturasAuxiliares[posicao]; icont++) {
        if (estruturasAuxiliares[posicao][icont] != 0) {
            estaVazia = 0;
            break;
        }
    }

    if (estaVazia) {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    for (int icont = tamanhosEstruturasAuxiliares[posicao] - 1; icont >= 0; icont--) {
        if (estruturasAuxiliares[posicao][icont] != 0) {
            estruturasAuxiliares[posicao][icont] = 0;
            return SUCESSO;
        }
    }

    return SUCESSO;
}


/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
    posicao = posicao - 1;

    if (posicao < 0 || posicao >= TAM) {
        return POSICAO_INVALIDA;
    }

    if (estruturasAuxiliares[posicao] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    int estaVazia = 1;
    for (int icont = 0; icont < tamanhosEstruturasAuxiliares[posicao]; icont++) {
        if (estruturasAuxiliares[posicao][icont] != 0) {
            estaVazia = 0;
            break;
        }
    }

    if (estaVazia) {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    int indiceRemocao = -1;
    for (int icont = 0; icont < tamanhosEstruturasAuxiliares[posicao]; icont++) {
        if (estruturasAuxiliares[posicao][icont] == valor) {
            indiceRemocao = icont;
            break;
        }
    }

    if (indiceRemocao == -1) {
        return NUMERO_INEXISTENTE;
    }

    for (int icont = indiceRemocao; icont < tamanhosEstruturasAuxiliares[posicao] - 1; icont++) {
        estruturasAuxiliares[posicao][icont] = estruturasAuxiliares[posicao][icont + 1];
    }

    estruturasAuxiliares[posicao][tamanhosEstruturasAuxiliares[posicao] - 1] = 0;

    return SUCESSO;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    posicao = posicao - 1;

    if (posicao < 0 || posicao >= TAM) {
        return POSICAO_INVALIDA;
    }

    if (estruturasAuxiliares[posicao] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    for (int icont = 0; icont < tamanhosEstruturasAuxiliares[posicao]; icont = icont + 1) {
        vetorAux[icont] = estruturasAuxiliares[posicao][icont];
    }

    return SUCESSO;
}



/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    int retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);
    if (retorno != SUCESSO) {
        return retorno;
    }

    int tamanho = tamanhosEstruturasAuxiliares[posicao - 1];
    for (int icont = 0; icont < tamanho - 1; icont = icont + 1) {
        for (int jcont = 0; jcont < tamanho - icont - 1; jcont = jcont + 1) {
            if (vetorAux[jcont] > vetorAux[jcont + 1]) {
                int temp = vetorAux[jcont];
                vetorAux[jcont] = vetorAux[jcont + 1];
                vetorAux[jcont + 1] = temp;
            }
        }
    }

    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int indiceAux = 0;
    int todasVazias = 1;

    for (int i = 0; i < TAM; i++) {
        if (estruturasAuxiliares[i] != NULL) {
            todasVazias = 0;
            for (int j = 0; j < tamanhosEstruturasAuxiliares[i]; j++) {
                vetorAux[indiceAux++] = estruturasAuxiliares[i][j];
            }
        }
    }

    if (todasVazias) {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);
    if (retorno != SUCESSO) {
        return retorno;
    }

    int tamanhoTotal = 0;
    for (int i = 0; i < TAM; i++) {
        if (estruturasAuxiliares[i] != NULL) {
            tamanhoTotal += tamanhosEstruturasAuxiliares[i];
        }
    }

    for (int i = 0; i < tamanhoTotal - 1; i++) {
        for (int j = 0; j < tamanhoTotal - i - 1; j++) {
            if (vetorAux[j] > vetorAux[j + 1]) {
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = temp;
            }
        }
    }

    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
    posicao = posicao - 1;

    if (posicao < 0 || posicao >= TAM) {
        return POSICAO_INVALIDA;
    }

    if (estruturasAuxiliares[posicao] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    int tamanhoAtual = tamanhosEstruturasAuxiliares[posicao];
    int tamanhoFinal = tamanhoAtual + novoTamanho;

    if (tamanhoFinal < 1) {
        return NOVO_TAMANHO_INVALIDO;
    }

    int *novoArray = (int *)realloc(estruturasAuxiliares[posicao], tamanhoFinal * sizeof(int));
    if (novoArray == NULL) {
        return SEM_ESPACO_DE_MEMORIA;
    }

    estruturasAuxiliares[posicao] = novoArray;
    for (int icont = tamanhoAtual; icont < tamanhoFinal; icont++) {
        estruturasAuxiliares[posicao][icont] = 0;
    }

    tamanhosEstruturasAuxiliares[posicao] = tamanhoFinal;

    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao) {
    posicao = posicao - 1;

    if (posicao < 0 || posicao >= TAM) {
        return POSICAO_INVALIDA;
    }

    if (estruturasAuxiliares[posicao] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    int quantidade = 0;
    for (int icont = 0; icont < tamanhosEstruturasAuxiliares[posicao]; icont = icont + 1) {
        if (estruturasAuxiliares[posicao][icont] != 0) {
            quantidade = quantidade + 1;
        }
    }

    return quantidade;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote() {
    No *cabecote = (No *)malloc(sizeof(No));
    if (cabecote == NULL) {
        return NULL;
    }

    cabecote -> prox = NULL;
    No *ultimo = cabecote;

    for (int i = 0; i < TAM; i++) {
        if (estruturasAuxiliares[i] != NULL) {
            for (int j = 0; j < tamanhosEstruturasAuxiliares[i]; j++) {
                if (estruturasAuxiliares[i][j] != 0) {
                    No *novo = (No *)malloc(sizeof(No));
                    if (novo == NULL) {
                        destruirListaEncadeadaComCabecote(&cabecote);
                        return NULL;
                    }
                    novo -> conteudo = estruturasAuxiliares[i][j];
                    novo -> prox = NULL;
                    ultimo -> prox = novo;
                    ultimo = novo;
                }
            }
        }
    }

    return cabecote;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {
    No *atual = inicio->prox;
    int indice = 0;

    while (atual != NULL) {
        vetorAux[indice++] = atual->conteudo;
        atual = atual->prox;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio) {
    No *atual = *inicio;

    while (atual != NULL) {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }

    *inicio = NULL;
}
/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar() {
    for (int i = 0; i < TAM; i++) {
        estruturasAuxiliares[i] = NULL;
        tamanhosEstruturasAuxiliares[i] = 0;
    }
}
/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar() {
    for (int i = 0; i < TAM; i++) {
        if (estruturasAuxiliares[i] != NULL) {
            free(estruturasAuxiliares[i]);
            estruturasAuxiliares[i] = NULL;
        }
    }
}