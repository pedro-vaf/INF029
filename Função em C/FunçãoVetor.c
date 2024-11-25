/* Crie um programa que tenha uma função ler3Numeros. Essa função deve ler três números do
usuário e retornar os três números. A função main deve imprimir esses três números. Utilize vetor
para fazer o retorno. */
#include <stdio.h>
#include <stdlib.h>

void Ler3Numeros(int vetor[3]);
void Imprimir3Numeros(int vetor[3]);

int main(){
    int vetor[3];

    printf("Insira 3 Números\n");
    Ler3Numeros(vetor);

    printf("Os números foram\n");
    Imprimir3Numeros(vetor);
}

void Ler3Numeros (int vetor[3]){
    for(int icont = 0; icont < 3; icont++){
        printf("Numero %d -> ", icont+1);
        scanf("%d", &vetor[icont]);
    }
    printf("\n");
}

void Imprimir3Numeros(int vetor[3]){
    for (int icont = 0; icont < 3; icont++){
        printf("Numero %d -> %d\n", icont+1, vetor[icont]);
    }
}