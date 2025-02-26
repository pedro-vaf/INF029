/* Fa�a uma fun��o recursiva que receba um n�mero inteiro positivo par N e imprima 
todos os n�meros pares de 0 at� N em ordem decrescente. */

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
