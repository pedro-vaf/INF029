/* Crie um programa que tenha uma função ler3Palavras. Essa função deve ler três palavras do
usuário e retornar as três palavras. A função main deve imprimir essas três palavras. */
#include <stdio.h>
#include <stdlib.h>

void ler3Palavras(char str[3][50]);
void imprimir3Palavras(char str[3][50]);

int main(){
    char str[3][50];

    ler3Palavras(str);
    imprimir3Palavras(str);
}

void ler3Palavras(char str[3][50]){
    int jcont = 0;
    for (int icont = 0; icont < 3; icont = icont + 1){
        printf("Insira a palavra %d -> ", icont + 1);
        scanf(" %s", str[icont]);
    }
    printf("\n");
}

void imprimir3Palavras(char str[3][50]){
    int jcont = 0;
    for (int icont = 0; icont < 3; icont = icont + 1){
        printf("Palavra %d -> %s\n", icont + 1, str[icont]);
    }
}