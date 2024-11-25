/* Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do
cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do cliente. A função main deve
imprimir os dados do cliente. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Cliente
{
    char nome[50];
    Data dataNascimento;
    char cpf[12];
    char sexo[2];
} Cliente;

Cliente cadastrarCliente();
void imprimirDadosCliente(Cliente dados);


int main(){
    Cliente dados;
    
    dados = cadastrarCliente();
    imprimirDadosCliente(dados);
}

Cliente cadastrarCliente (){
    Cliente dados;
    printf ("Insira o seu nome -> ");
    fgets(dados.nome, 50, stdin);
    printf("Insira o dia do seu nascimento -> ");
    scanf(" %d", &dados.dataNascimento.dia);
    printf("Insira o mes do seu nascimento -> ");
    scanf(" %d", &dados.dataNascimento.mes);
    printf("Insira o ano do seu nascimento -> ");
    scanf(" %d", &dados.dataNascimento.ano);
    printf("Insira o seu cpf -> ");
    fgets(dados.cpf, 12, stdin);
    printf("Insira o sexo -> ");
    fgets(dados.sexo, 2, stdin);
    printf("\n");
    return dados;
}

void imprimirDadosCliente (Cliente dados){
    printf("\n----- Dados do Cliente -----\n");
    printf("Nome -> %s\n", dados.nome);
    printf("Data de nascimento -> %d/%d/%d\n", dados.dataNascimento.dia, dados.dataNascimento.mes, dados.dataNascimento.ano);
    printf("CPF -> %d\n", dados.cpf);
    printf("Sexo -> %s\n", dados.sexo);
}