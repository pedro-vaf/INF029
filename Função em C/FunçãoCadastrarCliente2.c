/* Evolua o programa que tem a função cadastrarCliente, para fazer as validações dos dados. Cada
validação deve ser feita em uma função diferente, conforme lista abaixo. A função cadastrarCliente
deve chamar cada uma dessas funções. A função main deve imprimir se o cadastro foi realizado
com sucesso ou se houve erro, informando onde foi o erro:
• função validarNome: recebe o nome digitado, e valida se nome tem até 20 caracteres;
• função validarSexo: recebe o sexo digitado, e valida é um sexo válido (opções: m e M para
masculino; f e F para feminino, o e O para outro).
• função validarCPF: recebe o cpf digitado, e valida é um cpf válido;
• função validarNacimento: recebe o data digitada, e valida é uma data válida. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define erroNome -1
#define erroSexo -2
#define erroCPF -3
#define erroDataNascimento -4

typedef struct Data{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Cliente{
    char nome[50];
    Data dataNascimento;
    char cpf[12];
    char sexo[2];
} Cliente;

Cliente cadastrarCliente();
void imprimirDadosCliente(Cliente dados);
int validarNome(Cliente dados);
int validarSexo(Cliente dados);
int validarCPF(Cliente dados);
int validarDataNascimento(Cliente dados);

int main(){
    Cliente dados;
    int retorno1 = 0, retorno2 = 0, retorno3 = 0, retorno4 = 0;
    bool sucesso = true;
    
    dados = cadastrarCliente();

    retorno1 = validarNome(dados);
    if (retorno1 == erroNome){ sucesso = false; printf("Nome inválido!\n"); }
    retorno2 = validarSexo(dados);
    if (retorno2 == erroSexo){ sucesso = false; printf("Sexo inválido!\n"); } 
    retorno3 = validarCPF(dados);
    if (retorno3 == erroCPF){ sucesso = false; printf("CPF inválido!\n"); }
    retorno4 = validarDataNascimento(dados);
    if (retorno4 == erroDataNascimento){ sucesso = false; printf("Data invática!\n"); } 
    
    if(sucesso == true){ imprimirDadosCliente(dados); }
}

Cliente cadastrarCliente (){
    Cliente dados;
    printf ("Insira o seu nome -> ");
    fgets(dados.nome, 50, stdin);
    printf("Insira o sexo -> ");
    fgets(dados.sexo, 2, stdin);
    printf("Insira o dia do seu nascimento -> ");
    scanf(" %d", &dados.dataNascimento.dia);
    printf("Insira o mes do seu nascimento -> ");
    scanf(" %d", &dados.dataNascimento.mes);
    printf("Insira o ano do seu nascimento -> ");
    scanf(" %d", &dados.dataNascimento.ano);
    getchar();
    printf("Insira o seu CPF -> ");
    fgets(dados.cpf, 12, stdin);
    printf("\n");
    return dados;
}

void imprimirDadosCliente (Cliente dados){
    printf("\n----- Dados do Cliente -----\n");
    printf("Nome -> %s", dados.nome);
    printf("Data de nascimento -> %d/%d/%d\n", dados.dataNascimento.dia, dados.dataNascimento.mes, dados.dataNascimento.ano);
    printf("CPF -> %s\n", dados.cpf);
    printf("Sexo -> %s\n", dados.sexo);
}


int validarNome (Cliente dados){
    int tamanho = 0;
    for (int icont = 0; dados.nome[icont] != '\0'; icont = icont + 1){
        tamanho = tamanho + 1;
    }
    if (tamanho < 20){ return erroNome; }
}


int validarSexo (Cliente dados){
    for (int icont = 0; dados.sexo[icont] != '\0'; icont = icont + 1){
        if (dados.sexo[icont] >= 'a' && dados.sexo[icont] <=  'z'){
            dados.sexo[icont] = dados.sexo[icont] - 32;
        }
    }
    for (int jcont = 0; dados.sexo[jcont] != '\0'; jcont = jcont + 1){
        if ((dados.sexo[jcont] != 'M') && (dados.sexo[jcont] != 'F') && (dados.sexo[jcont] != 'O')){
            return erroSexo;
        }
    }
}

int validarCPF (Cliente dados){
    int tamanho = 0;
    for (int icont = 0; dados.cpf[icont] != '\0'; icont = icont + 1){
        tamanho = tamanho + 1;
    }
    if (tamanho != 11){ return erroCPF; }
}

int validarDataNascimento (Cliente dados){
    if (dados.dataNascimento.dia < 1 || dados.dataNascimento.dia > 31){ return erroDataNascimento; }
    if (dados.dataNascimento.mes < 1 || dados.dataNascimento.mes > 12){ return erroDataNascimento; }
    if (dados.dataNascimento.ano < 1900 || dados.dataNascimento.ano > 2024){ return erroDataNascimento; }
}