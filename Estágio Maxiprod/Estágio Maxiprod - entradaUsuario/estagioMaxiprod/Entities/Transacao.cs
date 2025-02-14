using estagioMaxiprod.Entities.Enum;

namespace estagioMaxiprod.Entities;

public class Transacao
{
    private static int contadorIdTransacao = 0; 
    /* static para representar individualidade, a variável servirá
     * para gerar o Identificador automático e sequencial, pois sempre será
     * incrementado mais um no construtor */

    public int idTransacao { get; }
    public string descricao { get; }
    public double valor { get; }
    public TipoStatus tipo { get; }
    public int idPessoaTransacao { get; }
    
    /* Sets para possível modificação dos dados */
    public string setDescricao (string descricao){ return descricao; }
    public double setValor (double valor){ return valor; }
    public TipoStatus setTipo (TipoStatus tipo){ return tipo; }
    

    /* Construtor com parâmetros (argumentos) para instanciar dados das pessoas */
    /* O this, Passar o próprio objeto como argumento na chamada de um método ou construtor
     * diferencia atributos de variáveis */
    public Transacao (string descricao, double valor, TipoStatus tipo, int idPessoaTransacao) {
        idTransacao = ++contadorIdTransacao;
        this.descricao = descricao;
        this.valor = valor;
        this.tipo = tipo;
        this.idPessoaTransacao = idPessoaTransacao;
    }
    
    public static Transacao CadastrarTransacao(Pessoa dadosPessoa)
    {
        int tipoInt;
        bool validador = false;
        string descricao = "";
        double valor;

        // Validação de tipo de transação
        do {
            if (dadosPessoa.idade >= 18)
            {
                Console.Write("Deseja cadastrar uma transação do tipo (1 - despesa) ou (2 - receita) -> ");
                tipoInt = int.Parse(Console.ReadLine());
                if (tipoInt == 1 || tipoInt == 2)
                    validador = true;
                else
                    Console.WriteLine("Tipo de transação inválido! Tente novamente.");
                
            } else {
                Console.WriteLine($"Por {dadosPessoa.nome} ser menor de idade só é permitido transações do tipo despesa");
                tipoInt = 1;
                validador = true;
            }
        } while (!validador);

        validador = false;
        // Solicita descrição da transação
        do {
            try {
                Console.Write("Insira uma descrição para essa transação -> ");
                descricao = Console.ReadLine();

                if (string.IsNullOrWhiteSpace(descricao))
                    throw new ArgumentException("A descrição não pode ser vazia.");
                validador = true;
            } catch (ArgumentException ex) {
                Console.WriteLine($"Erro: {ex.Message}");
            }
        } while (!validador);

        // Solicita valor da transação
        if (tipoInt == 1) 
            Console.Write($"Qual valor da transação despesa quer vincular a {dadosPessoa.nome} -> ");
        else 
            Console.Write($"Qual valor da transação receita quer vincular a {dadosPessoa.nome} -> ");
        valor = double.Parse(Console.ReadLine());

        return new Transacao(descricao, valor, (TipoStatus)tipoInt, dadosPessoa.idPessoa);
    }
    
}