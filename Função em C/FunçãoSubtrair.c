/* Crie um programa que tenha uma função subtrai e a função main. A função main deve ler três
valores, enviar para a função subtrai. A função subtrai deve realizar a subtração dos três valores
(primeiro menos o segundo menos o terceiro) e retornar o valor. A Função main deve imprimir o
resultado da subtração. */
#include <stdio.h>
#include <stdlib.h>

float Subtracao(float numero1, float numero2, float numero3);

int main(){
    float numero1, numero2, numero3;

    printf("Insira o numero 1 -> ");
    scanf("%f", &numero1);
    printf("Insira o numero 2 -> ");
    scanf("%f", &numero2);
    printf("Insire o numero 3 -> ");
    scanf("%f", &numero3);

    printf("A subtracao -> %.2f", Subtracao(numero1, numero2, numero3));
}

float Subtracao(float numero1, float numero2, float numero3){
    float subtracao = 0.0;
    subtracao = (numero1 - numero2) - numero3;
    return subtracao;
}