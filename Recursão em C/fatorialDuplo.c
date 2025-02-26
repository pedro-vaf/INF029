/* A  função  fatorial  duplo  é  definida  como  o  produto  de  todos  os  números  naturais 
ímpares de 1 até algum número natural ímpar N. Assim, o fatorial duplo de 5 é 
5!! = 1 * 3 * 5 = 15 
Faça uma função recursiva que receba um número inteiro positivo impar N e retorne o 
fatorial duplo desse número. */

#include <stdio.h>
#include <stdlib.h>

int fatorialDuplo(int n) {
    if (n == 1) { 
        return 1;  // Caso base: fatorial duplo de 1 é 1.
    } 
    return n * fatorialDuplo(n - 2);  // Chamada recursiva reduzindo de 2 em 2.
}

int main() {
    int elemento;

    printf("Insira um elemento ímpar -> ");
    scanf("%d", &elemento);

    if (elemento % 2 != 0) {
        printf("Fatorial duplo de %d: %d\n", elemento, fatorialDuplo(elemento));
    } else { 
        printf("Número inválido! Insira um número ímpar.\n");
    }

    return 0;
}