/* O superfatorial de um n�mero N � definida pelo produto dos N primeiros fatoriais 
de N. Assim, o superfatorial de 4 � 
sf(4) = 1! * 2! * 3! * 4! = 288 
Fa�a  uma  fun��o  recursiva  que  receba  um  n�mero  inteiro  positivo  N  e  retorne  o 
superfatorial desse n�mero. */

#include <stdio.h>

// Fun��o recursiva para calcular o fatorial de um n�mero
int fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Caso base: 0! = 1! = 1
    } else {
        return n * fatorial(n - 1); // Chamada recursiva para calcular o fatorial
    }
}

// Fun��o recursiva para calcular o superfatorial de um n�mero
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
    printf("Digite um n�mero inteiro positivo: ");
    scanf("%d", &numero);

    if (numero > 0) {
        printf("O superfatorial de %d �: %d\n", numero, superFatorial(numero));
    } else {
        printf("Por favor, digite um n�mero inteiro positivo.\n");
    }

    return 0;
}