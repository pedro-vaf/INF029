/* Fa�a  uma  fun��o  recursiva  que  receba  um  n�mero  inteiro  positivo  N  e  imprima 
todos os n�meros naturais de 0 at� N em ordem decrescente. */

#include <stdio.h>
#include <stdlib.h>

void impressaoDecrescente(int numero){
    
    printf(" %d", numero);
    if(numero > 0) {
        impressaoDecrescente(numero - 1);
    }
}
int main(){

    int numero;

    printf("Digite um n�mero inteiro: ");
    scanf("%d", &numero);

    if (numero > 0){
        impressaoDecrescente(numero);
    }
}