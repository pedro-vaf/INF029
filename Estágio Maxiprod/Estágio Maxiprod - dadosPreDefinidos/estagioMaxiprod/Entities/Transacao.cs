namespace estagioMaxiprod.Entities;

public class Transacao
{
    private static int contadorIdTransacao = 0; 
    /* static para representar individualidade, a variável servirá
     * para gerar o Id automático e sequencial, pois sempre será
     * incrementado mais um no construtor */

    public int idTransacao { get; private set; }
    public string descricao { get;  set; }
    public double valor { get; private set; }
    public string tipo { get;  set; }
    public int idPessoaTransacao { get;  private set; }

    /* Construtor com parametros (argumentos) para instanciar dados das pessoas */
    /* O this,  Passar o próprio objeto como argumento na chamada de um método ou construtor
     * diferencia atributos de variáveis */
    public Transacao (string descricao, double valor, string tipo, int idPessoaTransacao) {
        idTransacao = ++contadorIdTransacao;
        this.descricao = descricao;
        this.valor = valor;
        this.tipo = tipo;
        this.idPessoaTransacao = idPessoaTransacao;
    }
}