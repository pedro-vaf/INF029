using estagioMaxiprod.Entities.Enum;

namespace estagioMaxiprod.Entities;

public class Calculo
{
    public void ExibirTransacoes(List<Transacao> transacao, List<Pessoa> pessoa)
    {
        foreach (var p in pessoa) {
            
            double totalReceita = 0, totalDespesa = 0, saldo = 0;
            
            foreach (var t in transacao)
            {
                if (p.idPessoa == t.idPessoaTransacao)
                {
                    if (t.tipo == TipoStatus.receita)
                        totalReceita += t.valor;
                    else if (t.tipo == TipoStatus.despesa)
                        totalDespesa += t.valor;
                }
            }
            
            saldo = totalReceita - totalDespesa;
            if (p.idade >= 18) {
                Console.WriteLine($"\nNome: {p.nome} | Idade: {p.idade} | Id: {p.idPessoa}");
                Console.WriteLine($"Total de Receitas: {totalReceita:C} | Total de Despesas: {totalDespesa:C} | Saldo: {saldo:C}");
                if (saldo == 0)
                    Console.WriteLine($"Olá {p.nome} suas economias estão zeradas.");
                else if (saldo < 0)
                    Console.WriteLine($"Olá {p.nome} há um déficit nas suas economias.");
                else
                    Console.WriteLine($"Parabéns {p.nome} suas economias estão com saldo positivo.");   
            } else {
                Console.WriteLine($"\nNome: {p.nome} | Idade: {p.idade} | Id: {p.idPessoa}");
                Console.WriteLine($"Total de Despesas: {totalDespesa:C}");
            }
                
        }
    }
    
    public void ExibirTotalGeral(List<Transacao> transacao)
    {
        double totalReceita = 0, totalDespesa = 0, saldo = 0;

        foreach (var t in transacao)
        {
            if (t.tipo == TipoStatus.receita)
                totalReceita += t.valor;
            else
                totalDespesa += t.valor;
        }

        saldo = totalReceita - totalDespesa;
        Console.WriteLine("\n*** Total geral das transações ****");
        Console.WriteLine($"Total de Receitas: {totalReceita:C} | Total de Despesas: {totalDespesa:C} | Saldo: {saldo:C}\n");
    }

}