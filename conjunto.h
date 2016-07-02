//Biblioteca com as declaracoes
#ifndef CONJUNTO_H //Verifica se a biblioteca ja foi carregada no programa

#define CONJUNTO_H
//simulacao de tipo booleanos para melhor clareza do codigo
#define TRUE 1
#define FALSE 0

#include <stdlib.h>
/*
*struct que será a base usada:
**deve estar na biblioteca para que o compilador reconheca as funcoes que manipulem os dados desse tipo
**possui um campo inteiro para receber um valor numerico
**possui um ponteiro que aponta para o proximo elemento do conjunto
*/
typedef struct conjunto conjunto;
struct conjunto {
    int numero;
    conjunto * prox;
};

//verfica se um elemento esta contido no conjunto.
int verificar(conjunto * C, int numero);

//Verifica se um conjunto esta contido em outro. Retorna 1, caso verdadeiro e 0, caso falso.
int verificar_contido (conjunto * ca, conjunto * cb);

//Verifica se um conjunto contem outro. Retorna 0, caso falso e 1, caso verdadeiro.
int verificar_contem (conjunto *ca, conjunto * cb);

//Insere um elemento no conjunto, caso ja nao exista uma ocorrencia do mesmo no conjunto.
conjunto * inserir (conjunto * c, int numero);

//Remove um elemento do conjunto.
void remover_elemento (conjunto * c, int numero);

//Realiza a uniao de dois conjuntos em um novo.
conjunto * unir (conjunto * ca, conjunto * cb);

//Realiza a intersecao de dois conjunto em um novo.
conjunto * intersec (conjunto * ca, conjunto * cb);

#endif
