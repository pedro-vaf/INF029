/* A  fun��o  fatorial  duplo  �  definida  como  o  produto  de  todos  os  n�meros  naturais 
�mpares de 1 at� algum n�mero natural �mpar N. Assim, o fatorial duplo de 5 � 
5!! = 1 * 3 * 5 = 15 
Fa�a uma fun��o recursiva que receba um n�mero inteiro positivo impar N e retorne o 
fatorial duplo desse n�mero. */

#include <stdio.h>
#include <stdlib.h>

int fatorialDuplo(int n) {
    if (n == 1) { 
        return 1;  // Caso base: fatorial duplo de 1 � 1.
    } 
    return n * fatorialDuplo(n - 2);  // Chamada recursiva reduzindo de 2 em 2.
}

int main() {
    int elemento;

    printf("Insira um elemento �mpar -> ");
    scanf("%d", &elemento);

    if (elemento % 2 != 0) {
        printf("Fatorial duplo de %d: %d\n", elemento, fatorialDuplo(elemento));
    } else { 
        printf("N�mero inv�lido! Insira um n�mero �mpar.\n");
    }

    return 0;
}