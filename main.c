#include "conjunto.h" //Biblioteca que sera testada
#include <stdio.h>
//Funcao para imprimir a lista
void imprimir(conjunto * lista) {

    while (lista != NULL) {
        printf("%d\n", lista->numero);

        lista = lista->prox;
    }

}
//Programa com o unico proposito de testar as funcoes da biblioteca

int main() {
    conjunto * conjunto_a = NULL;
    conjunto * conjunto_b = NULL;

    //código que gera erro em verificar_contem:
    //=================================================================
    /*
    if (verificar_contem(conjunto_a, conjunto_b) == TRUE)
        printf("TRUE\n");
    else if (verificar_contem(conjunto_a, conjunto_b) == FALSE)
        printf("FALSE\n");
    else
        printf("ERRO\n");
    */
    //=================================================================
    //codigo que gera erro em remover_elemento:
    //===================================================
    for (int i = 0; i < 15; i += 2)
        conjunto_a = inserir(conjunto_a, i);
    /*
    remover_elemento(conjunto_a, 14);
    imprimir(conjunto_a);
    */
    //====================================================
    //codigo que gera erro em verificar_contem:
    //============================================================
    /*
    if (verificar_contem(conjunto_b, conjunto_a) == TRUE)
        printf("TRUE\n");
    else if (verificar_contem(conjunto_b, conjunto_a) == FALSE)
        printf("FALSE\n");
    else
        printf("ERRO\n");
    */
    //--------------------------------------------------------------
    /*
    if (verificar_contem(conjunto_a, conjunto_b) == TRUE)
        printf("TRUE\n");
    else if (verificar_contem(conjunto_a, conjunto_b) == FALSE)
        printf("FALSE\n");
    else
        printf("ERRO\n");
    */
    //===============================================================

    for (int i = 0; i < 15; i++)
        conjunto_b = inserir(conjunto_b, i);

    return 0;
}
