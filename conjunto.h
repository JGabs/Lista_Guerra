/*
*struct que será a base usada:
**deve estar na biblioteca para que o compilador reconheca as funcoes que manipulem os dados desse tipo
**possui um campo inteiro para receber um valor numerico
**possui um ponteiro que aponta para o proximo elemento do conjunto
*/
struct conjunto {
    int numero;
    struct lista * prox;
};
//Verifica se existe determinado elemento no conjunto. Retorna 1, caso verdadeiro e 0, caso falso.
int verificar (struct conjunto * c, int numero) {

    return 1;

    return 0;
}
//Verifica se um conjunto esta contido em outro. Retorna 1, caso verdadeiro e 0, caso falso.
int verificar_contido (struct conjunto * ca, struct conjunto * cb) {

    return 1;

    return 0;
}
//Verifica se um conjunto contem outro. Retorna 0, caso falso e 1, caso verdadeiro.
int verficar_contem (struct conjunto *ca, struct conjunto * cb) {

    return 1;

    return 0;
}
//Insere um elemento no conjunto, caso ja nao exista uma ocorrencia do mesmo no conjunto.
struct conjunto * inserir (struct conjunto * c, int numero) {

    return c;
}
//Remove um elemento do conjunto.
struct conjunto * remover_elemento (struct conjunto * c, int numero) {

    return c;
}
//Realiza a uniao de dois conjuntos em um novo.
struct conjunto * unir (struct conjunto * ca, struct conjunto * cb) {
    struct conjunto * uniao = NULL;

    return uniao;
}
//Realiza a intersecao de dois conjunto em um novo.
struct conjunto * intersec (struct conjunto * ca, struct conjunto * cb) {
    struct conjunto * intersecao = NULL;

    return intersecao;
}
