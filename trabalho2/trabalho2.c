#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

typedef struct {
    int *valor;
    int qtd;
    int tamanho;
} AUX;

AUX vetorPrincipal[TAM];


void inicializar();



/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    int retorno = 0;
    
    // se posição é um valor válido {entre 1 e 10}
    if(posicao<1 || posicao>10){
        return POSICAO_INVALIDA;
    }
    // o tamanho nao pode ser menor que 1
    else if(tamanho<1){
        return TAMANHO_INVALIDO;
    }
    // a posicao pode já existir estrutura auxiliar
    if(vetorPrincipal[posicao-1].valor != NULL){
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }
    // o tamanho ser muito grande
    vetorPrincipal[posicao-1].valor = malloc(tamanho * sizeof(int));
    if (vetorPrincipal[posicao-1].valor == NULL) {
        return SEM_ESPACO_DE_MEMORIA;
    }
    
    // deu tudo certo, crie
    
    vetorPrincipal[posicao-1].qtd = 0;
    vetorPrincipal[posicao-1].tamanho = tamanho;
    
     return SUCESSO;
   
}


/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{

    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

/* Verifica se a posição é inválida */
(posicao < 1 || posicao > TAM) 
    ? (posicao_invalida = 1) 
    : (posicao_invalida = 0);

if (!posicao_invalida)
{
    existeEstruturaAuxiliar = (vetorPrincipal[posicao-1].valor != NULL);

    if (existeEstruturaAuxiliar)
    {
        temEspaco = (vetorPrincipal[posicao-1].qtd < vetorPrincipal[posicao - 1].tamanho);
    }
}

if (posicao_invalida)
{
    return POSICAO_INVALIDA;
}
else
{
    /* Testa se existe a estrutura auxiliar */
    if (existeEstruturaAuxiliar)
    {
        if (temEspaco)
        {
            /* Insere o valor */
            vetorPrincipal[posicao-1].valor[vetorPrincipal[posicao - 1].qtd] = valor;
            vetorPrincipal[posicao-1].qtd++;
            retorno = SUCESSO;
        }
        else
        {
            retorno = SEM_ESPACO;
        }
    }
    else
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
}

return retorno;

}




/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    

    int idx = posicao - 1;

    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[idx].valor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[idx].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    vetorPrincipal[idx].qtd--;

    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{

    if(posicao<1 || posicao>10){
        return POSICAO_INVALIDA;
    }
    int idx = posicao - 1;

    if (vetorPrincipal[idx].valor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[idx].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    for (int i = 0; i < vetorPrincipal[idx].qtd; i++)
    {
        if (vetorPrincipal[idx].valor[i] == valor)
        {
            for (int j = i; j < vetorPrincipal[idx].qtd - 1; j++)
            {
                vetorPrincipal[idx].valor[j] = vetorPrincipal[idx].valor[j + 1];
            }

            vetorPrincipal[idx].qtd--;
            return SUCESSO;
        }
    }

    return NUMERO_INEXISTENTE;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{

    
    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }
    else
        return SUCESSO;

}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;
  int idx = posicao - 1;

    if (vetorPrincipal[idx].valor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    for (int i = 0; i < vetorPrincipal[idx].qtd; i++)
    {
        vetorAux[i] = vetorPrincipal[idx].valor[i];
    }

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    if (posicao < 1 || posicao > TAM)
            return POSICAO_INVALIDA;
    int idx = posicao - 1;
    if (vetorPrincipal[idx].valor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    for (int i = 0; i < vetorPrincipal[idx].qtd; i++)
    {
        vetorAux[i] = vetorPrincipal[idx].valor[i];
    }

    // ordenar o vetorAux
    for (int i = 0; i < vetorPrincipal[idx].qtd - 1; i++)
    {
        for (int j = 0; j < vetorPrincipal[idx].qtd - i - 1; j++)
        {
            if (vetorAux[j] > vetorAux[j + 1])
            {
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = temp;
            }
        }
    }               

    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int pos = 0;
    int vazias = 1;

    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i].valor != NULL && vetorPrincipal[i].qtd > 0)
        {
            vazias = 0;
            for (int j = 0; j < vetorPrincipal[i].qtd; j++)
            {
                vetorAux[pos] = vetorPrincipal[i].valor[j];
                pos++;
            }
        }
    }

    if (vazias)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int pos = 0;
    int vazias = 1;

    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i].valor != NULL && vetorPrincipal[i].qtd > 0)
        {
            vazias = 0;
            for (int j = 0; j < vetorPrincipal[i].qtd; j++)
            {
                vetorAux[pos] = vetorPrincipal[i].valor[j];
                pos++;
            }
        }
    }
    if (vazias)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    // ordenar o vetorAux
    for (int i = 0; i < pos - 1; i++)
    {
        for (int j = 0; j < pos - i - 1; j++)
        {
            if (vetorAux[j] > vetorAux[j + 1])
            {
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = temp;
            }
        }
    }
    

    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;
    int idx = posicao - 1;

    if (vetorPrincipal[idx].valor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    int tamanhoAtual = vetorPrincipal[idx].tamanho;
    int tamanhoResultante = tamanhoAtual + novoTamanho;

    if (tamanhoResultante < 1)
        return NOVO_TAMANHO_INVALIDO;

    int *novoVetor = realloc(vetorPrincipal[idx].valor, tamanhoResultante * sizeof(int));
    if (novoVetor == NULL)
        return SEM_ESPACO_DE_MEMORIA;
    vetorPrincipal[idx].valor = novoVetor;
    vetorPrincipal[idx].tamanho = tamanhoResultante;

    if (vetorPrincipal[idx].qtd > tamanhoResultante)
    {
        vetorPrincipal[idx].qtd = tamanhoResultante;
    }
    
    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{   
    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;
    int idx = posicao - 1;

    if (vetorPrincipal[idx].valor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[idx].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;


   return vetorPrincipal[idx].qtd;

}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

// ate aqui!!

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/



No *montarListaEncadeadaComCabecote()
{
    No *cabecote = (No *) malloc(sizeof(No));
    if (cabecote == NULL)
        return NULL;

    cabecote->prox = NULL;
    No *fim = cabecote;

 

    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i].valor != NULL && vetorPrincipal[i].qtd > 0)
        {
            for (int j = 0; j < vetorPrincipal[i].qtd; j++)
            {
                No *novo = (No *) malloc(sizeof(No));
                if (novo == NULL)
                    return NULL;

                novo->conteudo = vetorPrincipal[i].valor[j];
                novo->prox = NULL;

                fim->prox = novo;
                fim = novo;

            }
        }
    }

    
    return cabecote;

}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    int i = 0;

    if (inicio == NULL)
        return;

    No *aux = inicio->prox; // ignora o cabeçote

    while (aux != NULL)
    {
        vetorAux[i] = aux->conteudo;
        i++;
        aux = aux->prox;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
      if (inicio == NULL || *inicio == NULL)
        return;

    No *atual = *inicio;
    No *prox;

    while (atual != NULL)
    {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }

    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    for (int i = 0; i < TAM; i++)
    {
        vetorPrincipal[i].valor = NULL;
        vetorPrincipal[i].qtd = 0;
        vetorPrincipal[i].tamanho = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/
void finalizar();

void finalizar()
{
     for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i].valor != NULL)
        {
            free(vetorPrincipal[i].valor);
            vetorPrincipal[i].valor = NULL;
        }

        vetorPrincipal[i].qtd = 0;
        vetorPrincipal[i].tamanho = 0;
    }

}
