#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Escrever arquivo texto com a função fputs - Ler aquivo texto com a função fgets

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
    char texto[500];

    if (file){
       printf("Digite uma frase ou 1 caracter para finalizar: ");
       scanf("%500[^\n]", texto); 
       getchar();

       while (strlen(texto) > 1)
       {
            fputs(texto, file);
            fputc('\n', file);
            scanf("%500[^\n]", texto); 
            getchar();
       }
       
       fclose(file);
    } else { printf("Erro ao abrir arquivo!"); }
}

void ler (char f[]){
    FILE * file = fopen(f, "r");
    char texto[500];

    if(file){
        printf("\nTexto lido do arquivo:\n");
        while (!feof(file))
        {
            if(fgets(texto, 500, file)){
                /* onde salvar - quantidade máxima - em qual arquivo salvar */
                printf("\n -> %s", texto);
            }
        }
        
        
        
        fclose(file);
    } else { printf("Erro ao abrir arquivo!\n"); }
}

int main(){
    char arquivo[] = ("arquivo.txt");

    escrever(arquivo);
    ler(arquivo);
}