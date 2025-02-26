/* Faça uma função recursiva que receba um número inteiro positivo par N e imprima 
todos os números pares de 0 até N em ordem decrescente. */

#include <stdio.h>
#include <stdlib.h>

void decrescentePar(int elemento){

    printf("%d ", elemento);
    if (elemento > 0){
        decrescentePar(elemento - 2);
    }
}
int main (){

    int elemento;

    printf("Insira um elemento par -> ");
    scanf("%d", &elemento);

    if (elemento % 2 == 0){
        decrescentePar(elemento);
    }
}
