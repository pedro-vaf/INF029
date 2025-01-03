#ifndef PRODUTO_H
#define PRODUTO_H

#include <stdbool.h> /* Biblioteca usada para uso do booleano (True - False) */

#define listaVazia -1
#define cadastroRealizado -2

/* Para esse código o melhor seria usar a estrutura dinâmica de lista encadeada, mas demada tempo
e um conhecimento que ainda não dominei por completo, usarei array */

#define quantidade 1000 /* Quantidade máxima de produtos */

typedef struct {
    char nome[50];
    char sinopse[500];
    float valor;
    bool status;
} Produto;

int cadastro(Produto listaProduto[], int *totalProduto);
void ordenarListagem(Produto listaProduto[], int *totalProduto);
int listagem(Produto listaProduto[], int  *totalProduto, int *opcao);

#endif