using estagioMaxiprod.Entities;

namespace estagioMaxiprod;

class Program
{
    static void Main(string[] args)
    {
        double totalDespesa, totalReceita, saldo;

            /* Lista com dados pré definidos para testar algoritmo futuramente, o idPessoa e idTransacao serve para
             * gerar um id automático e sequencial, pois é incrementado a cada novo dado adcionado na 
             * lista que armazenará as informações, estabelecendo uma estrutura dinâmica flexível, diferente de 
             * um array que é uma estrutura estática.
             * - Entenda mais sobre essa diferença no meu artigo -
             * Link: https://medium.com/@pedro.vaf/estruturas-de-dados-est%C3%A1ticas-vs-estruturas-de-dados-din%C3%A2micas-e92e1d29b8f5/ */

            List<Pessoa> pessoa = new List<Pessoa> {
                new Pessoa ("Pedro", 22),
                new Pessoa ("Mariana", 21),
                new Pessoa ("Lunna", 14),
                new Pessoa ("Rodrigo", 42),
                new Pessoa ("Lidiane", 40)
            };

            List<Transacao> transacao = new List<Transacao> {
                new Transacao ("Alugel de carro", 340.23, "despesa", 1),
                new Transacao ("Compras do mercado", 90.10, "receita", 1),
                new Transacao ("Venda de imovel", 1412.90, "receita", 2),
                new Transacao ("Manutencao de computador", 129.00, "receita", 3),
                new Transacao ("FGTS", 2342.12, "despesa", 4),
                new Transacao ("Deposito bancario", 290.10, "receita", 4),
                new Transacao ("Alugel de casa", 340.23, "despesa", 1),
                new Transacao ("Compras de roupa", 90.10, "receita", 1),
            };

            Console.WriteLine("*** Dados das trasanções de cada pessoa ****\n");
            /* Foreach para imprimir a lista de pessoas 
             e um Foreach interno interno para imprimir os seus dados de transação */

            /* listar todas as pessoas cadastradas, exibindo o total de receitas, despesas e o saldo (receita – despesa) de cada uma. */
            foreach (var listaPessoa in pessoa) {

                /* Variáveis que irão amarzenar os tipos de transações para gerar o saldo ao final */
                totalReceita = 0;
                totalDespesa = 0;
                saldo = 0;

                /* O if verifica se a idade da pessoa corresponde com os tipos de transação aceita,
                    * ou seja, pessoas com menos de 18 não podem ter transações do tipo receita, caso isso 
                    * ocorra retornará uma mensagem de erro */
                foreach (var listatransacao in transacao) {
                    if (listaPessoa.idPessoa == listatransacao.idPessoaTransacao) {
                        if (listatransacao.valor > 0) {
                            if (listaPessoa.idade < 18 && listatransacao.tipo == "receita") {
                                Console.WriteLine($"Erro: {listaPessoa.nome} é menor de idade e possui uma receita registrada.");
                                Console.WriteLine("As suas receitas foram zeradas para respeitar as regras de negócio");
                                totalReceita = 0;
                                /* Serve para zerar os valores e não trazer os das pessoas anterioes */
                            } else if (listatransacao.tipo == "receita") {
                                totalReceita += listatransacao.valor; // Adiciona o valor de receita
                            } else if (listatransacao.tipo == "despesa") {
                                totalDespesa += listatransacao.valor; // Adiciona o valor de despesa
                            }
                        }
                        
                    }

                }

                
                /* Variável que irá armazenar o saldo total  */
                saldo = (totalReceita - totalDespesa);
                Console.WriteLine($"Nome: {listaPessoa.nome} | Idade: {listaPessoa.idade} | Id: {listaPessoa.idPessoa}");
                Console.WriteLine($"Total de Receitas: {totalReceita:C} | Total de Despesas: {totalDespesa:C} | Saldo: {saldo:C}");
                if (saldo == 0) {
                    Console.WriteLine($"Olá {listaPessoa.nome} suas economias estão zeradas.");
                }
                else if (saldo < 0) {
                    Console.WriteLine($"Olá {listaPessoa.nome} há um déficit nas suas economias.");
                } else { Console.WriteLine($"Parabéns {listaPessoa.nome} suas economias estão com saldo positivo."); }
                Console.WriteLine("\n");
                /* O :C no Console.WriteLine é um formatador de saída em C#. 
                * Ele serve para exibir valores numéricos no formato de moeda, 
                * de acordo com as configurações regionais do sistema. */

            }

            /* Variáveis que irão amarzenar os tipos de transações para gerar o saldo ao final 
              elas foram zeradas para não retornaram os valores da impressão de transacao separada por pessoa
              do foreach anterior - e estão fora do foreach pois preciso que o valor seja acomulado, caso estivesse dentro da 
              repetição a cada nova chamada de transação os valores anteriores seriam perdidos */
            totalReceita = 0;
            totalDespesa = 0;
            saldo = 0;

            /* Exibir o total geral de todas as pessoas incluindo o total de receitas, total de despesas e o saldo líquido. */
            foreach (var listaTransacao in transacao)
            {

                if (listaTransacao.tipo == "receita") {
                    totalReceita = totalReceita + listaTransacao.valor; 
                    /* Essa linha de código também poderia ser escrita como 'totalReceita += listaTransacao.valor;' */
                } else {
                    totalDespesa = totalDespesa + listaTransacao.valor;
                    /* Essa linha de código também poderia ser escrita como 'totalDespesa += listaTransacao.valor;' */
                }
            }

            saldo = (totalReceita - totalDespesa);

            Console.WriteLine("*** Total geral das transações ****\n");
            Console.WriteLine($"Total de Receitas: {totalReceita:C} | Total de Despesas: {totalDespesa:C} | Saldo: {saldo:C}\n");
    }
}
