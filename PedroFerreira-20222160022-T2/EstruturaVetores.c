#include <stdio.h>
#include <stdlib.h>
#define tam 10

#include "EstruturaVetores.h"

int vetorPrincipal[tam];

typedef struct EstruturaAuxiliar {
    int *elementos;
    int quantidade;
    int tamanho;
} EstruturaAuxiliar;

EstruturaAuxiliar estruturaAuxiliar[tam];

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/
void inicializar(){
    for(int icont = 0; icont < tam; icont = icont + 1) {
        estruturaAuxiliar[icont].elementos = NULL;
        estruturaAuxiliar[icont].quantidade = 0;
        estruturaAuxiliar[icont].tamanho = 0;
    }
}

/*
Objetivo: criar estrutura auxiliar na posi??o 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - j? tem estrutura na posi??o
    POSICAO_INVALIDA - Posi??o inv?lida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espa?o de mem?ria
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{   
    posicao = posicao - 1;

    if (tamanho < 1) { return TAMANHO_INVALIDO; }
    if ((posicao < 0) || (posicao >= tam)) { return POSICAO_INVALIDA; }
    if (estruturaAuxiliar[posicao].elementos != NULL) { return JA_TEM_ESTRUTURA_AUXILIAR; }

    estruturaAuxiliar[posicao].elementos = (int *)malloc(tamanho * sizeof(int));
    
    if (estruturaAuxiliar[posicao].elementos) {
        estruturaAuxiliar[posicao].tamanho = tamanho;
        return SUCESSO;
    } else { return SEM_ESPACO_DE_MEMORIA; }
}

/*
Objetivo: inserir n?mero 'valor' em estrutura auxiliar da posi??o 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - n?o tem espa?o
    SEM_ESTRUTURA_AUXILIAR - N?o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi??o inv?lida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    posicao = posicao - 1;
    
    int quantidade = estruturaAuxiliar[posicao].quantidade;

    if ((posicao < 0) || (posicao >= tam)) { return POSICAO_INVALIDA; }
    if (estruturaAuxiliar[posicao].elementos == NULL) { return SEM_ESTRUTURA_AUXILIAR; }
    if (estruturaAuxiliar[posicao].quantidade >= estruturaAuxiliar[posicao].tamanho) { return SEM_ESPACO; }

    estruturaAuxiliar[posicao].elementos[quantidade] = valor; 
    estruturaAuxiliar[posicao].quantidade = estruturaAuxiliar[posicao].quantidade + 1;
    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Ap?s excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta ? uma exclus?o l?gica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - N?o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi??o inv?lida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{   
    posicao = posicao - 1;
    int tamanho = estruturaAuxiliar[posicao].quantidade;

    if((posicao < 0) || (posicao >= tam)){ 
        return POSICAO_INVALIDA;
    } else {
        if (estruturaAuxiliar[posicao].elementos != NULL){
            if (estruturaAuxiliar[posicao].quantidade == 0) {
                return ESTRUTURA_AUXILIAR_VAZIA;
            } else {
                estruturaAuxiliar[posicao].quantidade--;
                return SUCESSO;
            }
        } else { return SEM_ESTRUTURA_AUXILIAR; }
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posi??o 'posicao'.
Caso seja excluido, os n?meros posteriores devem ser movidos para as posi??es anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta ? uma exclus?o l?gica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posi??o 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - N?o tem estrutura auxiliar
    NUMERO_INEXISTENTE - N?mero n?o existe
    POSICAO_INVALIDA - Posi??o inv?lida para estrutura auxiliar

*/

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{   
    posicao = posicao - 1;
    
    int encontrado = -1;
    int tamanho = estruturaAuxiliar[posicao].quantidade;

    if (posicao < 0 || posicao >= tam){
        return POSICAO_INVALIDA;
    } else {
        if (estruturaAuxiliar[posicao].elementos != NULL){
            if(tamanho == 0) {
                return ESTRUTURA_AUXILIAR_VAZIA;
            } else {
                for (int icont = 0; icont < tamanho; icont = icont + 1) {
                    if (estruturaAuxiliar[posicao].elementos[icont] == valor) {
                        encontrado = icont; 
                        break;
                    }
                }

                if (encontrado == -1) { 
                    return NUMERO_INEXISTENTE;
                }

                for (int icont = encontrado; icont < tamanho - 1; icont = icont + 1) {
                    estruturaAuxiliar[posicao].elementos[icont] = estruturaAuxiliar[posicao].elementos[icont + 1];
                }
                
                estruturaAuxiliar[posicao].quantidade--;

                return SUCESSO;
            }
        } else {
            return SEM_ESTRUTURA_AUXILIAR;
        }
    }    
}


// se posi??o ? um valor v?lido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{   
    posicao = posicao - 1;
    if (posicao < 0 || posicao >= tam) { return POSICAO_INVALIDA; } else { return SUCESSO; }    
}

/*
Objetivo: retorna os n?meros da estrutura auxiliar da posi??o 'posicao (1..10)'.
os n?meros devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posi??o 'posicao'
    SEM_ESTRUTURA_AUXILIAR - N?o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi??o inv?lida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    posicao = posicao - 1;
    if ((posicao < 0) || (posicao >= tam)) { return POSICAO_INVALIDA; }
    if (estruturaAuxiliar[posicao].elementos == NULL) { return SEM_ESTRUTURA_AUXILIAR; }
    if (estruturaAuxiliar[posicao].quantidade == 0){ return ESTRUTURA_AUXILIAR_VAZIA; }


    for(int icont = 0; icont < estruturaAuxiliar[posicao].quantidade; icont = icont + 1) {
        vetorAux[icont] = estruturaAuxiliar[posicao].elementos[icont];
    }
    return SUCESSO;
}

/*
Objetivo: retorna os n?meros ordenados da estrutura auxiliar da posi??o 'posicao (1..10)'.
os n?meros devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posi??o 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - N?o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi??o inv?lida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{   
    posicao = posicao - 1;
    int auxiliar = 0;
    int tamanho = estruturaAuxiliar[posicao].quantidade;

    if ((posicao < 0) || (posicao >= tam)) { return POSICAO_INVALIDA; }
    if (estruturaAuxiliar[posicao].elementos == NULL) { return SEM_ESTRUTURA_AUXILIAR; }
    if (estruturaAuxiliar[posicao].quantidade == 0) { return ESTRUTURA_AUXILIAR_VAZIA; }

    for(int icont = 0; icont < estruturaAuxiliar[posicao].quantidade; icont = icont + 1){
        vetorAux[icont] = estruturaAuxiliar[posicao].elementos[icont];
    }

    for(int icont = 0; icont < tamanho; icont = icont + 1){
        for(int jcont = 0; jcont < tamanho - icont - 1; jcont = jcont + 1){
            if(vetorAux[jcont] > vetorAux[jcont + 1]){
                auxiliar = vetorAux[jcont];
                vetorAux[jcont] = vetorAux[jcont + 1];
                vetorAux[jcont + 1] = auxiliar;
            }
        }
    }

    return SUCESSO;   
}

/*
Objetivo: retorna os n?meros de todas as estruturas auxiliares.
os n?meros devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posi??o 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares est?o vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int kcont = 0;
    int vazio = 0;

    for (int icont = 0; icont < tam; icont = icont + 1) {
        if (estruturaAuxiliar[icont].quantidade == 0 || estruturaAuxiliar[icont].elementos == NULL) {
            vazio = vazio + 1;
            continue;
        }

        for (int jcont = 0; jcont < estruturaAuxiliar[icont].quantidade; jcont = jcont + 1) {
            vetorAux[kcont] = estruturaAuxiliar[icont].elementos[jcont];
            kcont = kcont + 1;
        }
    }
    
    for(int icont = 0; icont < tam; icont = icont + 1){
        for(int jcont = 0; jcont < estruturaAuxiliar[icont].quantidade; jcont = jcont + 1){
            if(estruturaAuxiliar[icont].quantidade == 0){
                vazio = vazio + 1;
            } else{
                vetorAux[kcont] = estruturaAuxiliar[icont].elementos[jcont];
                kcont = kcont + 1; 
            }
        }
    }

    if(vazio == 10){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    
    return SUCESSO;
}

/*
Objetivo: retorna os n?meros ordenados de todas as estruturas auxiliares.
os n?meros devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posi??o 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares est?o vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int kcont = 0;
    int vazio = 0;
    int auxiliar = 0;

    for (int icont = 0; icont < tam; icont = icont + 1) {
        if (estruturaAuxiliar[icont].quantidade == 0 || estruturaAuxiliar[icont].elementos == NULL) {
            vazio = vazio + 1;
            continue; // Pula para o pr?ximo ?ndice se a estrutura estiver vazia
        }

        for (int jcont = 0; jcont < estruturaAuxiliar[icont].quantidade; jcont = jcont + 1) {
            vetorAux[kcont] = estruturaAuxiliar[icont].elementos[jcont];
            kcont = kcont + 1;
        }
    }


    if(vazio == 10){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    for (int icont = 0; icont < kcont; icont = icont + 1){
        for (int jcont = 0; jcont < kcont - icont - 1; jcont = jcont + 1){
            if(vetorAux[jcont] > vetorAux[jcont + 1]){
                auxiliar = vetorAux[jcont];
                vetorAux[jcont] = vetorAux[jcont + 1];
                vetorAux[jcont + 1] = auxiliar;
            }
        }
    }

    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posi??o 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - N?o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi??o inv?lida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho n?o pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na aloca??o do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    posicao = posicao - 1;

    if((posicao < 0) || (posicao >= tam)){ return POSICAO_INVALIDA; }
    if(estruturaAuxiliar[posicao].elementos == NULL){ return SEM_ESTRUTURA_AUXILIAR; }

    int tamanhoInicial = estruturaAuxiliar[posicao].tamanho;
    int tamanhoFinal = tamanhoInicial + novoTamanho;

    if(tamanhoFinal < 1){ return NOVO_TAMANHO_INVALIDO; }

    int *newArray = (int *)realloc(estruturaAuxiliar[posicao].elementos, tamanhoFinal * sizeof(int));
    
    if (newArray == NULL) { return SEM_ESPACO_DE_MEMORIA; }

    estruturaAuxiliar[posicao].elementos = newArray;
    estruturaAuxiliar[posicao].tamanho = tamanhoFinal;

    if (novoTamanho > 0) {
        for (int icont = tamanhoInicial; icont < tamanhoFinal; icont = icont + 1) {
            estruturaAuxiliar[posicao].elementos[icont] = 0; 
        }
    }

    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posi??o 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posi??o inv?lida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um n?mero int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/


int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    posicao = posicao - 1;

    if (posicao < 0 || posicao >= tam) { return POSICAO_INVALIDA; }
    if (estruturaAuxiliar[posicao].elementos == NULL) { return SEM_ESTRUTURA_AUXILIAR; }
    if (estruturaAuxiliar[posicao].quantidade == 0) { return ESTRUTURA_AUXILIAR_VAZIA; }

    return estruturaAuxiliar[posicao].quantidade;
}


/*
Objetivo: montar a lista encadeada com cabe?ote com todos os n?meros presentes em todas as estruturas.

Retorno (No*)
    NULL, caso n?o tenha nenhum n?mero nas listas
    No*, ponteiro para o in?cio da lista com cabe?ote
*/
No *montarListaEncadeadaComCabecote()
{   
    No *cabecote = (No *)malloc(sizeof(No));
    if (cabecote == NULL) { return NULL; }

    cabecote -> prox = NULL;
    No *ultimo = cabecote; 

    
    for (int icont = 0; icont < tam; icont = icont + 1) {
        if (estruturaAuxiliar[icont].elementos != NULL) { 
            for (int jcont = 0; jcont < estruturaAuxiliar[icont].quantidade; jcont = jcont + 1) { 
                No *novo = (No *)malloc(sizeof(No)); 
                if (novo == NULL) {
                    destruirListaEncadeadaComCabecote(&cabecote);
                    return NULL;
                }
                novo -> conteudo = estruturaAuxiliar[icont].elementos[jcont]; 
                novo -> prox = NULL;
                ultimo -> prox = novo; 
                ultimo = novo; 
            }
        }
    }

    if (cabecote->prox == NULL) {
        free(cabecote); 
        return NULL;
    }

    return cabecote;
}

/*
Objetivo: retorna os n?meros da lista enceada com cabe?ote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    int icont = 0;
    No *valor = inicio->prox;

    while(valor != NULL){
        vetorAux[icont = icont + 1] = valor -> conteudo;
        valor = valor -> prox;
    }    
}

/*
Objetivo: Destruir a lista encadeada com cabe?ote a partir de in?cio.
O ponteiro inicio deve ficar com NULL. */
void destruirListaEncadeadaComCabecote(No **inicio)
{   
    int icont = 0;
    No *value = *inicio;

    while(value != NULL){
        No *prox = value -> prox;
        free(value);
        value = value ->prox;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espa?os de mem?ria das estruturas auxiliares.

*/

void finalizar()
{   
    for(int icont = 0; icont < tam; icont = icont + 1){
        free(estruturaAuxiliar[icont].elementos);
        estruturaAuxiliar[icont].elementos = NULL; 
    }
}