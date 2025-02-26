/* Fa�a uma fun��o recursiva que receba um n�mero inteiro positivo par N e imprima 
todos os n�meros pares de 0 at� N em ordem crescente. */

#include <stdio.h>
#include <stdlib.h>

void crescentePar(int temp, int elemento){
    
    if (temp > elemento){
        return;
    } else {
        printf("%d ", temp);
        crescentePar(temp + 2, elemento);
    }
}

int main(){

    int elemento;

    printf("Insira um elemento par -> ");
    scanf("%d", &elemento);

    if (elemento % 2 == 0){
        crescentePar(0, elemento);
    }
}