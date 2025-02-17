/* Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321 */

#include <stdio.h>

int inverterNumero(int n, int invertido) {
    if (n == 0) {
        return invertido;
    }
    return inverterNumero(n / 10, invertido * 10 + n % 10);
}

int main() {
    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    printf("Número invertido: %d\n", inverterNumero(numero, 0));

    return 0;
}
