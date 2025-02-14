namespace estagioMaxiprod.Entities;

public class Pessoa
{
    private static int contadorIdPessoa = 0; 
    /* static para representar individualidade, a variável servirá
    * para gerar o Identificador automático e sequencial, pois sempre será
    * incrementado mais um no construtor */

    /* Criação das variáveis para os dados do tipo Pessoa */
    /* Os gets e sets servem respetivamente para pegar e modificar os dados passados
     * para cada variável, estou a usar um método chamado Autoproperties, mas há diversas
     * formas de fazer isso - Encapsulamento */
    public int idPessoa { get; } /* O private impede que o identificador seja modificado pelo usuário */
    public string nome { get; }
    public int idade { get; }


    /* Construtor padrão (vazio) caso necessário */

    /* Construtor com parâmetros (argumentos) para instanciar dados das pessoas */
    /* O this, Passar o próprio objeto como argumento na chamada de um método ou construtor
     * diferencia atributos de variáveis */
    public Pessoa(string nome, int idade) {
        idPessoa = ++contadorIdPessoa; /* Incrementa primeiro e atribui ao argumento */
        this.nome = nome;
        this.idade = idade;
    }
    
    // Método estático para cadastrar uma nova pessoa
    public static Pessoa CadastrarPessoa()
    {
        Console.WriteLine("\n*** Insira os dados da pessoa ***");
        Console.Write("Insira o nome da pessoa -> ");
        string nome = Console.ReadLine();
        Console.Write("Insira a idade -> ");
        int idade = int.Parse(Console.ReadLine());

        // Criar e retornar a instância de Pessoa
        return new Pessoa(nome, idade);
    }
}