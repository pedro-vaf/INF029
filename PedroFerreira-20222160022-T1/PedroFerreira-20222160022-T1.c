// ################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Pedro Vitor Aquino Ferreira
//  email: pedro.aquino.ct@gmail.com
//  Matrícula: 20222160022
//  Semestre: 2024/2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// ################################################

#include <stdio.h>
#include "PedroFerreira-20222160022-T1.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
  int soma;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
  calcular o fatorial de um número
@entrada
  um inteiro x
@saida
  fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
  fat = fat * i;
    
  return fat;
}

int teste(int a)
{
  int val;
  if (a == 2)
    val = 3;
  else
    val = 4;

  return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]) {
    
  int datavalida = 1; // Inicialmente, assume-se que a data é válida

  char sDia[3], sMes[3], sAno[5]; // Vetores para armazenar dia, mês e ano como strings
  int iDia, iMes, iAno;
  int icont, jcont = 0, kcont = 0;

  // Separar o dia
  for (icont = 0; data[icont] != '/' && data[icont] != '\0'; icont++) {
    sDia[jcont++] = data[icont];
  }
  if (data[icont] != '/') return 0; // Falta separador '/'
  sDia[jcont] = '\0';
  iDia = atoi(sDia); // Converte o dia para inteiro

  // Separar o mês
  kcont = icont + 1;
  jcont = 0;
  for (icont = kcont; data[icont] != '/' && data[icont] != '\0'; icont++) {
    sMes[jcont++] = data[icont];
  }
  if (data[icont] != '/') return 0; // Falta separador '/'
  sMes[jcont] = '\0';
  iMes = atoi(sMes); // Converte o mês para inteiro

  // Separar o ano
  kcont = icont + 1;
  jcont = 0;
  for (icont = kcont; data[icont] != '\0'; icont++) {
    sAno[jcont++] = data[icont];
  }
  sAno[jcont] = '\0';
  iAno = atoi(sAno); // Converte o ano para inteiro

  // Ajuste para anos de dois dígitos
  if (strlen(sAno) == 2) {
    iAno += (iAno >= 50) ? 1900 : 2000;
  }

  // Verificação de validade do mês
  if (iMes < 1 || iMes > 12) {
    return 0;
  }

  // Verificação de validade do dia com base no mês
  if (iDia < 1 || iDia > 31) {
    return 0;
  }

  // Ajusta dias máximos para fevereiro, incluindo bissextos
  if (iMes == 2) {
    int bissexto = ((iAno % 4 == 0 && iAno % 100 != 0) || (iAno % 400 == 0));
    if ((bissexto && iDia > 29) || (!bissexto && iDia > 28)) {
      return 0;
    }
  }

  // Ajusta dias máximos para meses com 30 dias
  if ((iMes == 4 || iMes == 6 || iMes == 9 || iMes == 11) && iDia > 30) {
    return 0;
  }

  // Se passou por todas as verificações, a data é válida
  return 1;
}

DiasMesesAnos q2(char datainicial[], char datafinal[]) {
    
  DiasMesesAnos dma;

  int diaInicial, mesInicial, anoInicial; // Componentes da data inicial.
  int diaFinal, mesFinal, anoFinal;       // Componentes da data final.
  int difDia = 0, difMes = 0, difAno = 0; // Diferenças de dias, meses e anos.

  // Verifica se as datas são válidas
  if (q1(datainicial) == 0) {
    dma.retorno = 2; // Data inicial inválida
    return dma;
  }
  if (q1(datafinal) == 0) {
    dma.retorno = 3; // Data final inválida
    return dma;
  }

  // Quebra as datas em dia, mês e ano
  DataQuebrada dqInicial = quebraData(datainicial);
  DataQuebrada dqFinal = quebraData(datafinal);

  diaInicial = dqInicial.iDia;
  mesInicial = dqInicial.iMes;
  anoInicial = dqInicial.iAno;

  diaFinal = dqFinal.iDia;
  mesFinal = dqFinal.iMes;
  anoFinal = dqFinal.iAno;

  // Verifica se a data inicial é maior que a data final
  if ((anoInicial > anoFinal) || (anoInicial == anoFinal && mesInicial > mesFinal) || (anoInicial == anoFinal && mesInicial == mesFinal && diaInicial > diaFinal)) {
    dma.retorno = 4; // Data inicial maior que a data final
    return dma;
  }

  // Calcula a diferença de dias
  difDia = diaFinal - diaInicial;
  if (difDia < 0) {
    // Ajusta os dias para o mês anterior
    int diasNoMesAnterior;
    int mesAnterior = mesFinal - 1;
    if (mesAnterior < 1) {
      mesAnterior = 12;
      anoFinal--; // Volta para o ano anterior, se necessário
    }
    if (mesAnterior == 2) {
      diasNoMesAnterior = (anoFinal % 4 == 0 && (anoFinal % 100 != 0 || anoFinal % 400 == 0)) ? 29 : 28;
    } else if (mesAnterior == 4 || mesAnterior == 6 || mesAnterior == 9 || mesAnterior == 11) {
      diasNoMesAnterior = 30;
    } else {
      diasNoMesAnterior = 31;
    }
    difDia += diasNoMesAnterior;
    mesFinal--; // Ajusta o mês final
  }

  // Calcula a diferença de meses
  difMes = mesFinal - mesInicial;
  if (difMes < 0) {
    difMes += 12;
    anoFinal--; // Ajusta o ano final
  }

  // Calcula a diferença de anos
  difAno = anoFinal - anoInicial;

  // Preenche os valores na estrutura
  dma.qtdDias = difDia;
  dma.qtdMeses = difMes;
  dma.qtdAnos = difAno;
  dma.retorno = 1; // Sucesso no cálculo

  return dma;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0. */
 
int q3(char *texto, char c, int isCaseSensitive)
{
  int qtdOcorrencias = 0;
  int length = 0;

  for (int icont = 0; texto[icont] != '\0'; icont++){
    length++;
  }

  if (isCaseSensitive != 1){
    c = tolower(c);
    for (int icont = 0; icont < length; icont++){
      if (tolower(texto[icont]) == c){
        qtdOcorrencias++;
      }
    }
  } else {
    for (int icont = 0; icont < length; icont++){
      if (texto[icont] == c){
        qtdOcorrencias++;
      }
    }
  }

  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
    posicoes[0] = 13;
    posicoes[1] = 16;
    Observe que o índice da posição no texto deve começar ser contado a partir de 1.
    O retorno da função, n, nesse caso seria 1;

*/

int converterString(char *string, char *newString) {
  char comAcento[][4] = {"Ä", "Á", "Â", "À", "Ã", "ä", "á", "â", "à", "ã",
                          "É", "Ê", "Ë", "È", "é", "ê", "ë", "è",
                          "Í", "Î", "Ï", "Ì", "í", "î", "ï", "ì",
                          "Ö", "Ó", "Ô", "Ò", "Õ", "ö", "ó", "ô", "ò", "õ",
                          "Ü", "Ú", "Û", "Ù", "ü", "ú", "û", "ù",
                          "Ç", "ç"};
  char semAcento[] = "AAAAAaaaaaEEEEeeeeIIIIiiiiOOOOOoooooUUUUuuuuCc";

  int i = 0, j=0, k = 0, encontrado;
  while (string[i] != '\0'){
    encontrado = 0;

    // Verifica se é um caractere multibyte (UTF-8)
    if((unsigned char)string[i] >= 192){ // Se for multibyte (maior que 192)
      char temp[4] = {string[i], string[i + 1], '\0'}; // Captura 2 bytes (ex: 'a' e '~')
      for (j=0; j < 46; j++){
        if(strcmp(temp, comAcento[j]) == 0){
          newString[k++] = semAcento[j];
          encontrado = 1;
          break;
        }
      }
      i++;
    }

    // Caso seja caractere simples (ASCII) ou não mapeado
    if (encontrado != 1){
      newString[k++] = string[i];
    }
    i++;
  }

  newString[k] = '\0'; // Finaliza a nova string
  return k;            // Retorna o tamanho da nova string
}

int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  int qtdOcorrencias = 0;
  int i, j, k = 0;
  int tamTexto = 0, tamBusca = 0;

  char newStrTexto[250];
  char newStrBusca[50];

  // Converte as strings com caracteres especiais
  converterString(strTexto, newStrTexto);
  converterString(strBusca, newStrBusca);

  // Calcula o tamanho das strings convertidas
  for (i = 0; newStrTexto[i] != '\0'; i++){
    tamTexto++;
  }

  for (i = 0; newStrBusca[i] != '\0'; i++){
    tamBusca++;
  }

  // Busca pela ocorrência de strBusca na strTexto
  for (i = 0; i <= tamTexto - tamBusca; i++){
    int encontrado = 1;
    for (j = 0; j < tamBusca; j++){
      if (newStrBusca[j] != newStrTexto[j+i]){
        encontrado = 0;
        break;
      }
    }

    if (encontrado){
      qtdOcorrencias++;
      posicoes[k] = i + 1;
      posicoes[k+1] = i + tamBusca;
      k += 2;
    }
  }

  return qtdOcorrencias;
}


/*
Q5 = inverte número
@objetivo
  Inverter número inteiro
@entrada
    strbusca[icont] = 'i';
    break;
  case 'ó': case 'ò': case 'ô': case 'õ': case 'ö': case 'Ó': case 'Ò': case 'Ô': case 'Õ': case 'Ö':
    strbusca[icont] = 'o';
    break;
  case 'ú': case 'ù': case 'û': case 'ü': case 'Ú': case 'Ù': case 'Û': case 'Ü':
    strbusca[icont] = 'u';
    break;
  uma int num.
@saida
  Número invertido
*/

int q5(int num)
{

  int numAux = num;
  int numInvertido = 0;
  int digito = 0;

  while (numAux != 0) {
    digito = numAux % 10;
    numInvertido *= 10;
    numInvertido += digito;
    numAux = numAux/10;
  }

  num = numInvertido;

  return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca) {
  int qtdOcorrencias = 0;

  char numerobaseAux[1000000];
  char numerobuscaAux[1000000];

  // Converte os números para strings
  sprintf(numerobaseAux, "%d", numerobase);
  sprintf(numerobuscaAux, "%d", numerobusca);

  for (int icont = 0; numerobaseAux[icont] != '\0'; icont = icont + 1) {
    int jcont = 0;
    // Verifica se há correspondência contínua
    while (numerobuscaAux[jcont] != '\0' && numerobaseAux[icont + jcont] == numerobuscaAux[jcont]) {
      jcont = jcont + 1;
    }

    // Se `jcont` percorreu todo `numerobuscaAux`, é uma ocorrência
    if (numerobuscaAux[jcont] == '\0') {
      qtdOcorrencias = qtdOcorrencias + 1;
    }
  }

  return qtdOcorrencias;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}