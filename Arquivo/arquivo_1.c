#include <stdio.h>
#include <stdlib.h>

/* Escrever arquivo texto com a função fputc - ler arquivo texto com a função fgetc

    Modos de abertura de arquivos
    w -> escrita
    r -> leitura
    a -> anexar
    r+ -> leitura e escrita
    w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
    a+ -> leitura e escrita (adciona ao final do arquivo)
*/

void escrever(char f[]){
    FILE * file = fopen(f, "w");
    char letra;

    if(file){
        printf("Insira um texto no arquivo! ");
        scanf("%c", &letra);
        while (letra != '\n')
        {
            fputc(letra, file);
            scanf("%c", letra);
        }

        fclose(file);
    } else { printf("Erro ao abrir arquivo!"); }
}

void ler(char f[]){
    FILE * file = fopen(f, "r");
    char letra;

    if (file){
       while (!feof(file))
       {
            letra = fgetc(file);
            printf("%c", letra);
       }

       fclose(file);
    } else { printf("Erro ao abrir arquivo!"); }

}

int main(){
    char nome[] = ("arquivo.txt");

    escrever(nome);
    ler(nome);
}