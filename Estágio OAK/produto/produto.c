#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "produto.h"

int cadastro(Produto listaProduto[], int *totalProduto){

    float valor_c;
    char status_c[4];
    size_t tamanhoString; /* obs.: usado para auxiliar o cálculo do tamanho da string */

    printf("\n**** Cadastro do Produto ****\n");
    
    printf("Insira o nome do produto -> ");
    fgets(listaProduto[*totalProduto].nome, 50, stdin);
    tamanhoString = strlen(listaProduto[*totalProduto].nome) - 1;
    /* O strlen retorna o tamanho da string e o  -1 para remover o caractere de nova linha */
    if (listaProduto[*totalProduto].nome[tamanhoString] == '\n'){
        listaProduto[*totalProduto].nome[tamanhoString] = '\0';
    }
    /* O if acima garante que o nome inserido tenha o terminador padrão de string em C */

    printf("Insira a descrição do Produto (máximo 500 caracteres) -> ");
    fgets(listaProduto[*totalProduto].sinopse, 500, stdin);
    tamanhoString = strlen(listaProduto[*totalProduto].sinopse) - 1;
    if (listaProduto[*totalProduto].sinopse[tamanhoString] == '\n'){
        listaProduto[*totalProduto].sinopse[tamanhoString] = '\0';
    }

    printf("Insira o valor do produto -> ");
    scanf("%f", &valor_c);
    listaProduto[*totalProduto].valor = valor_c;
    getchar(); // Remove o '\n' residual no buffer do teclado

    printf("Produto disponível para venda? [sim] \\ [não] -> ");
    fgets(status_c, 4, stdin);

    // Remover o '\n' que o fgets pode capturar
    tamanhoString = strlen(status_c);
    if (status_c[tamanhoString - 1] == '\n') {
        status_c[tamanhoString - 1] = '\0';
    }

    if (strcmp(status_c, "sim") == 0) {
        listaProduto[*totalProduto].status = true;
    } else if (strcmp(status_c, "não") == 0 || strcmp(status_c, "nao") == 0) {
        listaProduto[*totalProduto].status = false;
    } else {
        printf("Entrada inválida para o status do produto. será marcado como 'não'.\n");
        listaProduto[*totalProduto].status = false;
    }

    *totalProduto = *totalProduto + 1;
    return cadastroRealizado;
}   

/* Ordena a listagem de produtos em ordem crescente de valor, usando o bubble sort */ 
/* Poderia usar outras formas de ordenar, mas a escolha foi baseada no complexidade mais eficientes, há outras
maneiras que podem ser usadas como o quick sort ou mergesort, com complexidade O(nlogn) */
void ordenarListagem(Produto listaProduto[], int *totalProduto){
    for (int icont = 0; icont < *totalProduto - 1; icont = icont + 1){
        for (int jcont = 0; jcont < *totalProduto - icont - 1; jcont = jcont + 1){
            if (listaProduto[jcont].valor > listaProduto[jcont + 1].valor){
                // Trocar os produtos de posições
                Produto temp = listaProduto[jcont];
                listaProduto[jcont] = listaProduto[jcont + 1];
                listaProduto[jcont + 1] = temp;
            }
        }
    }
}

int listagem (Produto listaProduto[], int *totalProduto, int *opcao){

    if (*totalProduto <= 0){
        printf("\nAinda não há produtos cadastrados\n");
        return listaVazia;
    }

    printf("\nListagem inciada...\n");
    for (int icont = 0; icont < *totalProduto; icont = icont + 1){
        printf("Nome: %s | Valor: %.2f\n", listaProduto[icont].nome, listaProduto[icont].valor);
    }

    char status_c[4];
    size_t tamanhoString;

    /* O if só irá aparecer quando o usuário desejar listar novamente os produtos */
    if (*opcao == 2) {
        printf("\nDeseja cadastrar um novo produto agora? [sim] \\ [não] -> ");

        // Limpar o buffer de entrada antes de capturar a resposta do usuário
        fflush(stdin);  // Limpa o buffer para evitar capturar caracteres antigos

        fgets(status_c, 4, stdin);
        getchar();

        // Remover o '\n' que o fgets pode capturar e remover espaços em branco
        tamanhoString = strlen(status_c);
        if (status_c[tamanhoString - 1] == '\n') {
            status_c[tamanhoString - 1] = '\0';
        }

        // Verificar se a resposta é "sim" ou "não" (considerando "nao" como uma alternativa sem acento)
        if (strcmp(status_c, "sim") == 0) {
            cadastro(listaProduto, totalProduto);
            ordenarListagem(listaProduto, totalProduto);
            listagem(listaProduto, totalProduto, opcao);
        } else if (strcmp(status_c, "não") == 0 || strcmp(status_c, "nao") == 0) {
            printf("Voltando ao menu principal.\n");
            *opcao = 0; /* Para voltar ao menu principal e continuar o programa */
        } else {
            // Caso a entrada seja inválida
            printf("Entrada inválida. Por favor, digite 'sim' ou 'não'.\n");
        }
    }
}
