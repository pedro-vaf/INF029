/* Faça  uma  função  recursiva  que  receba  um  número  inteiro  positivo  N  e  imprima 
todos os números naturais de 0 até N em ordem decrescente. */

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

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    if (numero > 0){
        impressaoDecrescente(numero);
    }
}