/* Crie um programa que tenha uma função soma e a função main. A função main deve ler dois
valores, enviar para a função soma. A função soma deve realizar a soma e retornar o valor. A
Função main deve imprimir o resultado da soma. */
#include <stdio.h>
#include <stdlib.h>

float Soma(float numero1, float numero2);

int main(){
    float numero1, numero2;

    printf("Insira o primeiro numero -> ");
    scanf("%f", &numero1);
    printf("Insira o segundo numero -> ");
    scanf("%f", &numero2);

    printf("A soma -> %.2f\n", Soma(numero1, numero2));
}

float Soma(float numero1, float numero2){
    float soma = 0.0;
    soma = numero1 + numero2;
    return soma;
}