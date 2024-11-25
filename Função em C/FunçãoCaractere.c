/* Crie um programa que tenha uma função ler3Letras. Essa função deve ler três letras do usuário
e retornar as três letras. A função main deve imprimir essas três letras. */
#include <stdio.h>
#include <stdlib.h>

void ler3Letras(char str[3]);
void imprimir3Letras(char str[3]);

int main(){
    char str[3];

    printf("Digite os caracteres\n");
    ler3Letras(str);

    printf("Os caracteres digitados foram\n");
    imprimir3Letras(str);
}

void ler3Letras(char str[3]){
    for (int icont = 0; icont < 3; icont = icont + 1){
        printf("Posicao %d -> ", icont+1);
        scanf(" %c", &str[icont]);
    }
    printf("\n");
}

void imprimir3Letras(char str[3]){
    for(int icont = 0; icont < 3; icont = icont + 1){
        printf("posicao %d -> %c\n", icont+1, str[icont]);
    }
}