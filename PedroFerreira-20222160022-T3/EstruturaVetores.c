#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 10

#include "EstruturaVetores.h"

int vetorPrincipal[tam];

typedef struct EstruturaAuxiliar {
    int *elementos;
    int quantidade;
    int tamanho;
} EstruturaAuxiliar;

EstruturaAuxiliar estruturaAuxiliar[tam];

void inicializar(){
    for(int icont = 0; icont < tam; icont = icont + 1) {
        estruturaAuxiliar[icont].elementos = NULL;
        estruturaAuxiliar[icont].quantidade = 0;
        estruturaAuxiliar[icont].tamanho = 0;
    }
}


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

int inserirNumeroEmEstrutura(int posicao, int valor)
{
    posicao = posicao - 1;
    
    int quantidade = estruturaAuxiliar[posicao].quantidade;

    if ((posicao < 0) || (posicao >= tam)) { return POSICAO_INVALIDA; }
    if (estruturaAuxiliar[posicao].elementos == NULL) { return SEM_ESTRUTURA_AUXILIAR; }
    if (estruturaAuxiliar[posicao].quantidade >= estruturaAuxiliar[posicao].tamanho) { return SEM_ESPACO; }

    estruturaAuxiliar[posicao].elementos[quantidade] = valor; 
    estruturaAuxiliar[posicao].quantidade = estruturaAuxiliar[posicao].quantidade + 1;

    salvarArquivo("dados.txt");
    return SUCESSO;
}

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

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{   
    posicao = posicao - 1;
    
    int encontrado = -1;
    int tamanho = estruturaAuxiliar[posicao].quantidade;

    if (posicao < 0 || posicao >= tam){
        return POSICAO_INVALIDA;
    } else {
        if (estruturaAuxiliar[posicao].elementos != NULL){
            if (tamanho == 0) {
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

int ehPosicaoValida(int posicao)
{   
    posicao = posicao - 1;
    if (posicao < 0 || posicao >= tam) { return POSICAO_INVALIDA; } else { return SUCESSO; }    
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    posicao = posicao - 1;
    if ((posicao < 0) || (posicao >= tam)) { return POSICAO_INVALIDA; }
    if (estruturaAuxiliar[posicao].elementos == NULL) { return SEM_ESTRUTURA_AUXILIAR; }
    if (estruturaAuxiliar[posicao].quantidade == 0){ return ESTRUTURA_AUXILIAR_VAZIA; }


    for (int icont = 0; icont < estruturaAuxiliar[posicao].quantidade; icont = icont + 1) {
        vetorAux[icont] = estruturaAuxiliar[posicao].elementos[icont];
    }
    return SUCESSO;
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{   
    posicao = posicao - 1;
    int auxiliar = 0;
    int tamanho = estruturaAuxiliar[posicao].quantidade;

    if ((posicao < 0) || (posicao >= tam)) { return POSICAO_INVALIDA; }
    if (estruturaAuxiliar[posicao].elementos == NULL) { return SEM_ESTRUTURA_AUXILIAR; }
    if (estruturaAuxiliar[posicao].quantidade == 0) { return ESTRUTURA_AUXILIAR_VAZIA; }

    for (int icont = 0; icont < estruturaAuxiliar[posicao].quantidade; icont = icont + 1){
        vetorAux[icont] = estruturaAuxiliar[posicao].elementos[icont];
    }

    for (int icont = 0; icont < tamanho; icont = icont + 1) {
        for (int jcont = 0; jcont < tamanho - icont - 1; jcont = jcont + 1) {
            if (vetorAux[jcont] > vetorAux[jcont + 1]) {
                auxiliar = vetorAux[jcont];
                vetorAux[jcont] = vetorAux[jcont + 1];
                vetorAux[jcont + 1] = auxiliar;
            }
        }
    }

    return SUCESSO;   
}


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

    if (vazio == 10){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    
    return SUCESSO;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int kcont = 0;
    int vazio = 0;
    int auxiliar = 0;

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


    if (vazio == 10){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    for (int icont = 0; icont < kcont; icont = icont + 1) {
        for (int jcont = 0; jcont < kcont - icont - 1; jcont = jcont + 1) {
            if (vetorAux[jcont] > vetorAux[jcont + 1]) {
                auxiliar = vetorAux[jcont];
                vetorAux[jcont] = vetorAux[jcont + 1];
                vetorAux[jcont + 1] = auxiliar;
            }
        }
    }

    return SUCESSO;
}

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    posicao = posicao - 1;

    if ((posicao < 0) || (posicao >= tam)){ return POSICAO_INVALIDA; }
    if (estruturaAuxiliar[posicao].elementos == NULL){ return SEM_ESTRUTURA_AUXILIAR; }

    int tamanhoInicial = estruturaAuxiliar[posicao].tamanho;
    int tamanhoFinal = tamanhoInicial + novoTamanho;

    if (tamanhoFinal < 1) { return NOVO_TAMANHO_INVALIDO; }

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

int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    posicao = posicao - 1;

    if (posicao < 0 || posicao >= tam) { return POSICAO_INVALIDA; }
    if (estruturaAuxiliar[posicao].elementos == NULL) { return SEM_ESTRUTURA_AUXILIAR; }
    if (estruturaAuxiliar[posicao].quantidade == 0) { return ESTRUTURA_AUXILIAR_VAZIA; }

    return estruturaAuxiliar[posicao].quantidade;
}

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

void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    int icont = 0;
    No *valor = inicio->prox;

    while (valor != NULL){
        vetorAux[icont = icont + 1] = valor -> conteudo;
        valor = valor -> prox;
    }    
}

void destruirListaEncadeadaComCabecote(No **inicio)
{   
    int icont = 0;
    No *value = *inicio;

    while (value != NULL){
        No *prox = value -> prox;
        free(value);
        value = value ->prox;
    }
}

void finalizar()
{   
    for(int icont = 0; icont < tam; icont = icont + 1){
        free(estruturaAuxiliar[icont].elementos);
        estruturaAuxiliar[icont].elementos = NULL; 
    }
}

int carregarArquivo(const char *dados) {
    FILE * arquivo = fopen(dados, "r");

    if(arquivo == NULL){
        return ERRO;
    }

    int posicao, tamanho, numero, retorno;
    char line[7000];

    while (fgets(line, sizeof(line), arquivo) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        char * slice = strtok(line, ";");
        if(slice == NULL) continue;

        posicao = atoi(slice) - 1;
        slice = strtok(NULL, ";");
        if(slice == NULL) continue;

        tamanho = atoi(slice);
        retorno = criarEstruturaAuxiliar(posicao, tamanho);

        if(retorno != SUCESSO){
            fclose(arquivo);
            return retorno;
        }

        while((slice = strtok(NULL, ";")) != NULL){
            retorno = inserirNumeroEmEstrutura(posicao, atoi(slice));
            if(retorno != SUCESSO){
                fclose(arquivo);
                return retorno;
            }
        }
    }

    fclose(arquivo);

    return SUCESSO;
}

void salvarArquivo(const char *dados){
    FILE *arquivo = fopen(dados, "w");

    if (arquivo != NULL) {
        for(int icont = 0; icont < tam; icont = icont + 1){

            EstruturaAuxiliar * temp = &estruturaAuxiliar[icont];
    
            if (temp -> elementos != NULL && temp -> quantidade > 0 && temp -> tamanho > 0) {
                fprintf(arquivo, "%d;%d", icont + 1, temp -> tamanho);
    
                for(int jcont = 0; jcont < temp -> quantidade; jcont = jcont + 1){
                    fprintf(arquivo, ";%d", temp -> elementos[jcont]);
                }

                fprintf(arquivo, "\n");
            }
        }
    }
    
    fclose(arquivo);
}
