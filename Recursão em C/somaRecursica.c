/* Crie uma fun��o recursiva que receba um n�mero inteiro positivo N e calcule o 
somat�rio dos n�meros de 1 a N. */

#include <stdio.h>
#include <stdlib.h>

int somaAcumulativa(int elemento){

    if (elemento == 0){
        return 0;
    }

    return elemento + somaAcumulativa(elemento - 1);
}

int main(){

    int elemento;

    printf("*** Digite um elemento e visualize a soma acumulativa de 1 a N ***\n");
    printf("Insira o elemento (inteiro positivo) -> ");
    scanf("%d", &elemento);

    if (elemento >= 0){
        printf("A soma acumulativa � : %d", somaAcumulativa(elemento));
    }

    return 0;
}