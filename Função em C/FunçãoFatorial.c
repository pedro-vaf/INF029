/* Faça um programa que tenha uma função que recebe um número inteiro e retorna o fatorial
deste número. Esta função deve ainda verificar se é possível calcular o fatorial, se não for, ela deve
de alguma forma retornar para a main que deu algum erro. A função main deve solicitar o valor do
usuário e imprimir o fatorial dele, ou se não é possível calcular o fatorial. */
#include <stdio.h>
#include <stdlib.h>

#define erro -1


int Fatorial(int numero);

int main(){
    int numero;
    int retorno;

    printf("Insira um numero inteiro -> ");
    scanf("%d", &numero);

    retorno = Fatorial(numero);

    if (retorno == erro){
        printf("Erro!");
    } else { printf("fatorial -> %d", Fatorial(numero)); }
    
}

int Fatorial(int numero){
    int fatorial = 1;
    if (numero > 1){
        for (int icont = numero; icont >= 1; icont--){
            fatorial = fatorial * icont;
        }
        return fatorial;
    } else { return erro; }
}