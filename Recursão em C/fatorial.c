/* Fa�a uma fun��o recursiva que calcule e retorne o fatorial de um n�mero inteiro N. */

#include <stdio.h>
#include <stdlib.h>

int fatorial (int elemento){

    int vfatorial;

    if (elemento > 1) {
        vfatorial = elemento * fatorial(elemento - 1);
        return vfatorial;
    } 
}

int main(){

    int elemento;

    printf("*** Digite um elemento e visualize o seu fatorial ***\n");
    printf("Insira o elemento (inteiro positivo) -> ");
    scanf("%d", &elemento);

    if (elemento > 0) {
        printf("\nO fatorial de %d � %d", elemento, fatorial(elemento));
    }

    return 0;
}