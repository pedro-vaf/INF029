#include <stdio.h>
#include <stdlib.h>

/* Escrever arquivo texto com a função fprintf - ler arquivo texto com a função fscanf

    Modos de abertura de arquivos
    w -> escrita
    r -> leitura
    a -> anexar
    r+ -> leitura e escrita
    w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
    a+ -> leitura e escrita (adciona ao final do arquivo)
*/

void escrever (char f[]){
    FILE * file = fopen(f, "w");
    char nome[100];
    int idade, opcao;
    float altura;

    if (file){
       do {
            printf("\nDigite nome, idade e altura: \n");
            scanf("%100[^\n]%d%f", nome, &idade, &altura);
            fprintf(file, "%s %d %.2f\n", nome, idade, altura);
            printf("\nDigite 1 para escrever outro registro: ");
            scanf("%d", &opcao);
            scanf("%*c");
       } while (opcao == 1);

       fclose(file);
    } else { printf("Erro ao abrir arquivo!"); }
}

void ler (char f[]){
    FILE * file = fopen(f, "r");
    char nome[100];
    int idade;
    float altura;

    if (file){
        printf("\nDados lidos do arquivo\n");
        while (fscanf(file, "%s %d %f", nome, &idade, &altura) != -1)
            printf("\nNome: %s\nIdade: %d\nAltura: %.2f\n", nome, idade, altura);
        fclose(file);
    } else { printf("Erro ao abrir arquivo!"); }
}

int main(){
    char arquivo[] = ("arquivo.txt");

    escrever(arquivo);
    ler(arquivo);
}