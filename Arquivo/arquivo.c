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

int main(){
    FILE * file;
    char letra;

    file = fopen("C:\\Users\\pedro\\Downloads\\arquivo\\arquivo.txt", "w+");

    if(file){
        printf("\nDigite um texto e pressione Enter ao finalizar: ");
        scanf("%c", &letra);
        while (letra != '\n') {
            fputc(letra, file);
            scanf("%c", &letra);
        }

        rewind(file); 
        
        printf("\nTexto lido do arquivo\n");
        while (!feof(file))
        {
            letra = fgetc(file);
            printf("%c", letra);
        }
        
        fclose(file);
        
    } else { printf("Erro ao abrir arquivo!\n"); }

    return 0;
}