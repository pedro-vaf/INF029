/* Fa�a uma fun��o recursiva que permita inverter um n�mero inteiro N. Ex: 123 - 321 */

#include <stdio.h>

int inverterNumero(int n, int invertido) {
    if (n == 0) {
        return invertido;
    }
    return inverterNumero(n / 10, invertido * 10 + n % 10);
}

int main() {
    int numero;

    printf("Digite um n�mero inteiro: ");
    scanf("%d", &numero);

    printf("N�mero invertido: %d\n", inverterNumero(numero, 0));

    return 0;
}
