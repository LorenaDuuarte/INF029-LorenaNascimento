// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Lorena Duarte Cardoso Nascimento
//  email: lorenaduarte2005@gmail.com
//  Matrícula: 20251160035
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>
#include <string.h>

DataQuebrada quebraData(char data[]);

DataQuebrada quebraData(char data[]){
    DataQuebrada DMA = {0,0,0,1};
      int barra1 = -1, barra2 = -1;
       int i, j;

  int tamanho = strlen(data);

  //quebrar a string data em strings sDia, sMes, sAno
  
  for (i = 0; i < tamanho; i++) {
        if (data[i] == '/') {
            if (barra1 == -1)
                barra1 = i;
            else if (barra2 == -1)
                barra2 = i;
            else
                DMA.valido =0;
        }
    }
    
     for(i=0;data[i] != '/';i++){
    }

    if(data[0]>= '0' && data[0]<= '9'){
        if(data[0]== '0' && (data[1]>= '0' && data[1]<='9')){
            DMA.iDia = data[1]-'0';
        }
        else if(data[1] == '/'){
            DMA.iDia = data[0]-'0';}
        else if(data[0]!= '0' && (data[1]>= '0' && data[1]<= '9')){
            DMA.iDia = data[0]-'0';
            DMA.iDia = DMA.iDia*10;
            DMA.iDia = DMA.iDia + data[1]-'0';
        }
    }
    else{ 
        DMA.valido = 0;
        }
    
        
   if(DMA.iDia<=0 || DMA.iDia>31){
         DMA.valido = 0;
    }
        
      
    i++;
    
    if(data[i]>= '0' && data[i]<= '9'){
        if(data[i]== '0' && (data[i+1]>= '0' && data[i+1]<= '9')){
            DMA.iMes = data[i+1]-'0';
        }
        else if(data[i+1] == '/'){
            DMA.iMes = data[i]-'0';}
        else if(data[i]!= '0' && (data[i+1]>= '0' && data[i+1]<='9')){
            DMA.iMes = data[i]-'0';
            DMA.iMes = DMA.iMes*10;
            DMA.iMes = DMA.iMes + data[i+1]-'0';
        }
         else{ DMA.valido = 0;
                }
        }
        
    
    if(DMA.iMes<=0 || DMA.iMes>12){
    DMA.valido = 0;
    }
    
    int mult = 10;
 
    j = tamanho-(barra2+1);
  
   if(j==2){
   for(i=barra2+1, DMA.iAno = 2000, mult=10;i<tamanho;i++){
       DMA.iAno += (data[i]-'0')*mult;
       mult /=10;
      }
    }
    if(j == 4){
        for(i=barra2+1, mult=1000;i<tamanho;i++){
       DMA.iAno += (data[i]-'0')*mult;
       mult /=10;
      }
    }
    
    return DMA;
};

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
int q1(char data[])
{
  int datavalida = 1;
  DataQuebrada dma = quebraData(data);
  if(dma.valido ==0){
      datavalida = 0;
  }


    if(dma.iAno>2025){
        datavalida = 0;
        
    }

    if(dma.iMes == 2){
        if((dma.iAno % 400 == 0) || (dma.iAno % 4 == 0 && dma.iAno % 100 != 0)){
            if(dma.iDia>29){
                datavalida = 0;
            }
        }
        else if(dma.iDia>28){
            datavalida = 0;
        }
        }
    else if(dma.iMes == 4 ||dma.iMes == 6 || dma.iMes == 9 || dma.iMes == 11){
        if(dma.iDia>30){
                datavalida = 0;
               
        }
    }
    else if(dma.iMes == 1 || dma.iMes == 3 || dma.iMes == 5 || dma.iMes == 7 || dma.iMes == 8 || dma.iMes == 10 || dma.iMes == 12){
        if(dma.iDia>31){
                datavalida = 0;
                
        }
    }


  if (datavalida)
      return 1;
  else
      return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    int inicial, final;
    int meses[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      dma.retorno = 1;

      DataQuebrada inicial = quebraData(datainicial);
      DataQuebrada final = quebraData(datafinal);
     
      //verifique se a data final não é menor que a data inicial
      
      if(final.iAno < inicial.iAno){
        dma.retorno =4;
      }
      else if((final.iAno == inicial.iAno) && (inicial.iMes>final.iMes)){
        dma.retorno =4;
      }
      else if((final.iAno == inicial.iAno) && (inicial.iMes == final.iMes) && (inicial.iDia>final.iDia)){
      dma.retorno =4;
          }
      else{
      //calcule a distancia entre as datas
      dma.qtdAnos = final.iAno - inicial.iAno;
      dma.qtdMeses = final.iMes - inicial.iMes;
      dma.qtdDias = final.iDia - inicial.iDia;
      
    if ((final.iAno % 4 == 0 && final.iAno % 100 != 0) || (final.iAno % 400 == 0))
        meses[1] = 29;

   if (dma.qtdDias < 0) {
        dma.qtdMeses--;
        dma.qtdDias += meses[(inicial.iMes - 1 + 12) % 12];
    }
     if (dma.qtdMeses < 0) {
        dma.qtdAnos--;
        dma.qtdMeses += 12;
    }
    
      }
     
      //se tudo der certo
      return dma;
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{int i;
    int qtdOcorrencias = 0;
    
    int tamanho = strlen(texto);
    
    
    for(i=0;i<tamanho;i++){
        
        if(isCaseSensitive == 1){
            if(texto[i] == c){
                qtdOcorrencias++;
            }
        }
        else{
                
             if (texto[i] == c ||
                (texto[i] >= 'A' && texto[i] <= 'Z' && texto[i] + 32 == c) ||
                (texto[i] >= 'a' && texto[i] <= 'z' && texto[i] - 32 == c))
            {
                qtdOcorrencias++;
            }
        }

    }
        
    return qtdOcorrencias;;
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
int q4(char *strTexto, char *strBusca, int posicoes[30])
{ int qtdOcorrencias = -1;

    size_t tamTexto = strlen(strTexto);
    size_t tamBusca = strlen(strBusca);

    // Se a string de busca for vazia ou maior que o texto, ou se o texto for vazio, retorna 0.
    if (tamBusca == 0 || tamBusca > tamTexto || tamTexto == 0)
    {
        return 0;
    }

    int indicePosicoes = 0;

    qtdOcorrencias = 0; 

    for (size_t i = 0; i <= tamTexto - tamBusca; i++)
    {
        int encontrou = 1; 

        for (size_t j = 0; j < tamBusca; j++)
        {
            if (strTexto[i + j] != strBusca[j])
            {
                encontrou = 0; 
                break;         
            }
        }

        if (encontrou)
        {
            int inicio = (int)i + 1;
            int fim = inicio + (int)tamBusca - 1;
            
            posicoes[indicePosicoes++] = inicio;
            posicoes[indicePosicoes++] = fim;

            qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int unidades[100];
    int j = 0;

    for (int i = num; i > 0; i /= 10) {
        unidades[j] = i % 10;
        j++;
    }
    
    num = 0;

    for (int i = 0; i < j; i++) {
        num = num * 10 + unidades[i];
    }

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

int q6(int numerobase, int numerobusca)
{
   int base[20], busca[20];
    int tamBase = 0, tamBusca = 0;
    int qtdOcorrencias = 0;

    int nb = numerobase;
    int nbusca = numerobusca;

    if (nb == 0) {
        base[tamBase++] = 0;
    } else {
        while (nb > 0) {
            base[tamBase++] = nb % 10;
            nb /= 10;
        }
    }

    if (nbusca == 0) {
        busca[tamBusca++] = 0;
    } else {
        while (nbusca > 0) {
            busca[tamBusca++] = nbusca % 10;
            nbusca /= 10;
        }
    }

    for (int i = 0; i < tamBase / 2; i++) {
        int tmp = base[i];
        base[i] = base[tamBase - 1 - i];
        base[tamBase - 1 - i] = tmp;
    }


    for (int i = 0; i < tamBusca / 2; i++) {
        int tmp = busca[i];
        busca[i] = busca[tamBusca - 1 - i];
        busca[tamBusca - 1 - i] = tmp;
    }


    for (int i = 0; i <= tamBase - tamBusca; i++) {
        int igual = 1;
        for (int j = 0; j < tamBusca; j++) {
            if (base[i + j] != busca[j]) {
                igual = 0;
                break;
            }
        }
        if (igual)
            qtdOcorrencias++;
    }
    
    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5])
 {
        int tamPalavra = strlen(palavra);
    int achou = 0;


    int direcoes[8][2] = {
        { 0, 1 },   
        { 0, -1 },  
        { 1, 0 },   
        { -1, 0 },  
        { 1, 1 },   
        { 1, -1 },  
        { -1, 1 },  
        { -1, -1 }  
    };

   
    for (int lin = 0; lin < 8 && achou == 0; lin++)
    {
        for (int col = 0; col < 10 && achou == 0; col++)
        {
            if (matriz[lin][col] != palavra[0])
                continue;

            
            for (int d = 0; d < 8 && achou == 0; d++)
            {
                int dx = direcoes[d][0];
                int dy = direcoes[d][1];

                achou = 1;  

                for (int k = 1; k < tamPalavra; k++)
                {
                    int nx = lin + dx * k;
                    int ny = col + dy * k;

                    
                    if (nx < 0 || nx >= 8 || ny < 0 || ny >= 10)
                    {
                        achou = 0;
                        break;
                    }

                    
                    if (matriz[nx][ny] != palavra[k])
                    {
                        achou = 0;
                        break;
                    }
                }
            }
        }
    }

    return achou;
 }



/* DataQuebrada quebraData(char data[]){
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
}*/
