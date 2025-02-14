namespace estagioMaxiprod.Entities;

public class Pessoa
{
    private static int contadorIdPessoa = 0;
    /* static para representar individualidade, a variável servirá
    * para gerar o Id automático e sequencial, pois sempre será
    * incrementado mais um no construtor */

    /* Criação das variáveis para os dados do tipo Pessoa */
    /* Os get's e set's servem respectivamente para pegar e modificar os dados passados 
     * para cada variável, estou usando um método chamado Auto Properties, mas há diversas
     * formas de fazer isso - Encapsulamento */
    public int idPessoa { get; private set; } /* O private impede que o identificador seja modificado pelo usuário */
    public string nome { get; set; }
    public int idade { get; set; }
    

    /* Construtor padrão (vazio) caso necessário */

    /* Construtor com parametros (argumentos) para instanciar dados das pessoas */
    /* O this,  Passar o próprio objeto como argumento na chamada de um método ou construtor
     * diferencia atributos de variáveis */
    public Pessoa (string nome, int idade) {
        idPessoa = ++contadorIdPessoa; /* Incrementa primeiro e atribui ao argumento */
        this.nome = nome;
        this.idade = idade;
    }
}