/* Faça uma função recursiva que permita somar os elementos de um vetor de 
inteiros. */

#include <stdio.h>
#include <stdlib.h>
#define tamanho 10

int somaVetor (int vetor[], int indice){

    if (indice < 0){
        return 0;
    }

    return vetor[indice] + somaVetor(vetor, indice - 1);

    
}

int main(){

    int vetor[tamanho] = {42, 87, 19, 64, 3, 78, 55, 90, 11, 32};

    printf("Somátorio do vetor: %d", somaVetor(vetor, tamanho - 1));

    return 0;
}