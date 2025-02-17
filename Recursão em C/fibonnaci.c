/* Fa�a uma fun��o recursiva que calcule e retorne o N-�simo termo da sequ�ncia 
Fibonacci. Alguns n�meros desta sequ�ncia s�o: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89... */

#include <stdio.h>
#include <stdlib.h>

int fibonacci (int elemento){

    int vfibonacci;
    
    if (elemento == 0){
        return 0;

    } else if (elemento == 1) {
        return 1;
        
    } else {
        vfibonacci = fibonacci(elemento - 1) + fibonacci(elemento - 2);
        return vfibonacci;
    }
}

int main (){

    int elemento;

    printf("*** Digite um elemento e visualize o seu correspondente em fibonacci ***\n");
    printf("Insira o elemento (inteiro positivo) -> ");
    scanf("%d", &elemento);

    if (elemento >= 0) {
        printf("\nO valor de fibonnaci na posi��o %d � %d", elemento, fibonacci(elemento));
    }

    return 0;
}