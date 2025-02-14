using estagioMaxiprod.Entities;

namespace estagioMaxiprod;

class Program
{
    static void Main(string[] args)
    {
        int opcaoPessoa;
        int opcaoTransacao = 0;
        /* Essa variável servirá se o utilizador deseja cadastrar uma nova pessoa ao término
        da anterior no método de repetição - do While - */

        bool validador = false; 
        /* Essa variável servirá para verificar se o tipo de transação
            existe na class Enum */
        
         /* As listas armazenará as informações, estabelecendo uma estrutura dinâmica flexível, diferente de 
         * um array que é uma estrutura estática.
         * - Entenda mais sobre essa diferença no meu artigo -
         * Link: https://medium.com/@pedro.vaf/estruturas-de-dados-est%C3%A1ticas-vs-estruturas-de-dados-din%C3%A2micas-e92e1d29b8f5/ */

        /* Criação de Lista vazia para armazenar os dados das pessoas passadas pelo utilizador no terminal */
        List<Pessoa> pessoa = new List<Pessoa>();

        /* Criação de Lista vazia para armazenar os dados das transações passadas pelo utilizador no terminal */
        List<Transacao> transacao = new List<Transacao>();

        do {
            Pessoa dadosPessoa = Pessoa.CadastrarPessoa();
            pessoa.Add(dadosPessoa);

            do {
                Console.WriteLine($"\n*** Cadastrar dados de Transação - {dadosPessoa.nome} ***");
                Transacao dadosTransacao = Transacao.CadastrarTransacao(dadosPessoa);
                transacao.Add(dadosTransacao);
                
                Console.Write("Deseja cadastrar uma nova transação -> ");
                string temp2 = Console.ReadLine();

                if (temp2.ToLower() == "sim") {
                    opcaoTransacao = 1;
                } else { opcaoTransacao = 0; }
            } while (opcaoTransacao != 0);
            
            Console.Write("\nDeseja cadastrar uma nova pesssoa -> ");
            string temp = Console.ReadLine();
            
            if (temp.ToLower() == "sim") {
                opcaoPessoa = 1;
            } else { opcaoPessoa = 0; }
        } while (opcaoPessoa != 0);
        
        /* Criando uma instância da classe Cálculo */
        Calculo imprimirCalculo = new Calculo();
        
        imprimirCalculo.ExibirTransacoes(transacao, pessoa);
        /* Passando parâmetro das listas para impressão das informações */
        
        imprimirCalculo.ExibirTotalGeral(transacao);
    }
}