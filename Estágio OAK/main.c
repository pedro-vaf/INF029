#include <stdio.h>
#include <locale.h>
#include "produto/produto.h"

/*
    Por: Pedro Vitor Aquino Ferreira
    Data: 03/01/2025
    Estudante do Instituto Federal de Educação, Ciência e Tecnologia da Bahia - Campus Salvador
    Curso: Análise e Desenvolvimento de Sistemas
    Link do repositório: https://github.com/pedro-vaf
    Link do LinkedIn: https://www.linkedin.com/in/pedrovaf/

    Obs.: Basta clicar duas vezes no arquivo compilador.bat para executar o programa
    Criei um script bat para facilitar a execução
*/

int main(){

    setlocale(LC_ALL, "pt_BR.ISO-8859-1"); // Configura o programa para usar ISO 8859-1

    Produto listaProduto[quantidade]; // Declara o array para armazenar os produtos
    int totalProduto = 0; // Inicializa o contador de produtos cadastrados
    int retorno;

    int opcao = 0;

    do {
        printf("\n**** Menu Principal ****\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        getchar(); // Remove o '\n' do buffer do teclado após o scanf

        switch (opcao) {
            case 1:
                retorno = cadastro(listaProduto, &totalProduto);
                if (retorno == cadastroRealizado) {
                    ordenarListagem(listaProduto, &totalProduto);
                    listagem(listaProduto, &totalProduto, &opcao);
                }   
            break;

            case 2:
                ordenarListagem(listaProduto, &totalProduto);
                listagem(listaProduto, &totalProduto, &opcao);
            break;

            case 3:
                printf("\nSaindo do programa...\n");
            break;

            default:
                printf("\nOpção inválida. Tente novamente.\n");
            break;
        }
        
    } while (opcao != 3);
}
