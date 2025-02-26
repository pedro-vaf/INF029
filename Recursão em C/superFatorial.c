/* O superfatorial de um número N é definida pelo produto dos N primeiros fatoriais 
de N. Assim, o superfatorial de 4 é 
sf(4) = 1! * 2! * 3! * 4! = 288 
Faça  uma  função  recursiva  que  receba  um  número  inteiro  positivo  N  e  retorne  o 
superfatorial desse número. */

#include <stdio.h>

// Função recursiva para calcular o fatorial de um número
int fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Caso base: 0! = 1! = 1
    } else {
        return n * fatorial(n - 1); // Chamada recursiva para calcular o fatorial
    }
}

// Função recursiva para calcular o superfatorial de um número
int superFatorial(int n) {
    if (n == 1) {
        return fatorial(1); // Caso base: sf(1) = 1! = 1
    } else {
        return fatorial(n) * superFatorial(n - 1); // Chamada recursiva para calcular o superfatorial
    }
}

int main() {
    int numero;

    printf("*** Calculadora de Superfatorial ***\n");
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);

    if (numero > 0) {
        printf("O superfatorial de %d é: %d\n", numero, superFatorial(numero));
    } else {
        printf("Por favor, digite um número inteiro positivo.\n");
    }

    return 0;
}