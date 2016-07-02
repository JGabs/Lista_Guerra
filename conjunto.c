//Programa com as funcoes implementadas.

#include "conjunto.h"

//Verifica se existe determinado elemento no conjunto. Retorna TRUE, caso verdadeiro e FALSE, caso falso.
int verificar(conjunto * C, int numero) {

	while (C != NULL) {
		if (C->numero == numero) {
			return TRUE;
		}
		
		C = C->prox;
		
	}
	
	return FALSE;
	
}

//Verifica se um conjunto esta contido em outro. Retorna TRUE, caso verdadeiro e FALSE, caso falso.
int verificar_contido(conjunto * ca, conjunto * cb) {
    /*
    *EXPLICACAO LONGA ABAIXO!
    *Se quiser seguir adiante com o codigo, pule e volte em caso de duvida.
    *===========================================================================================================================================
    *Esse if trabalha com a seguinte logica:
    *   se (ca == NULL) e (cb == NULL), entao TRUE;
    *   se (ca == NULL) e ¬(cb == NULL)[cb != NULL], entao TRUE;
    *   logo, se (ca == NULL), entao TRUE, como pode ser verificado com uma tabela verdade.
    *   Portanto, se ¬(ca == NULL)[ca != NULL], entao FALSE se (cb == NULL), pois um conjunto nao pode estar contido em outro conjunto que seja vazio;
    *   Daí, temos que, se ¬(ca == NULL) e (cb == NULL), então FALSE;
    *   A unica outra forma de a saida ser FALSE, e' o caso de tanto ca quanto cb serem diferentes de NULL, onde deverao ser testastos os seus valores. Portanto, o programa faz uma das verificacoes que possam dar em FALSE, caso nao seja (else), ele faz a segunda. Se nenhum dos dois casos FALSE acontecerem, o retorno e' TRUE.
    *===========================================================================================================================================
    */
    if ((ca != NULL) && (cb == NULL)) {     //Primeira possibilidade de retornar FALSE.
        return FALSE;
    } else {
        while (ca != NULL) {
            if (verificar(cb, ca->numero) == FALSE)    //Segunda possibilidade de retornar FALSE.
                return FALSE;

            ca = ca->prox;
        }

    }
    //Caso nao caia em nenhuma das verificacoes do caso FALSO, retorno e' TRUE.
    return TRUE;

}

//Verifica se um conjunto contem outro. Retorna 0, caso falso e 1, caso verdadeiro.
int verificar_contem(conjunto *ca, conjunto * cb) {

if ((Ca == NULL) && (Cb == NULL)) {     //Verifica se os dois conjuntos são vazios
		return FALSE;
	} else if (Cb == NULL) {    //se ca for vazio e cb nao, ca nao contem cb
		return FALSE;
    } else if (Ca == NULL) {     //se cb for vazio e ca nao, ca contem cb
        return TRUE;
    } else {    //se nenhum dos dois for vazio, verifica os elementos de cada um
		while (Cb != NULL) {
			if (verificar(Ca,Cb->numero) == FALSE) {
				return FALSE;
			}

			Cb = Cb->prox;
		}
	}

	return TRUE;

}

//Insere um elemento no conjunto, caso ja nao exista uma ocorrencia do mesmo no conjunto.
conjunto * inserir(conjunto * C, int numero) {

	if (C != NULL){ // verifica se o conjunto é nulo
		if (verificar(C, numero) == TRUE){ // se não for, verifica se existe uma ocorrência do número 
			return C;
		}
	}

	conjunto * novo = (conjunto *) malloc(sizeof(conjunto));
	
	novo->numero = numero;
	novo->prox = C;
	C = novo;
	
	return C;
	
}

//Remove um elemento do conjunto.
conjunto * remover_elemento(conjunto * c, int numero) {
   
    conjunto * anterior = NULL;
    conjunto * p = c;
	
    while ((p != NULL) && (p->numero != numero)) { // percorre o conjunto mantendo referência ao anterior
		anterior = p;
		p = p->prox;
	}
	
    if (p == NULL) {
        return c; // não achou
	}
    if (anterior == NULL) {
		c = p->prox; // retira elemento do início 
	} else {
		anterior->prox = p->prox; //retira elemento do meio 
	}
	free(p);
	
    return c;
	
}

//Realiza a uniao de dois conjuntos em um novo.
conjunto * unir(conjunto * ca, conjunto * cb) {
	
	conjunto * uniao = NULL;

    while (ca != NULL) {    //insere todo conjunto a em uniao
		inserir(uniao, ca->numero);

        ca = ca->prox;
	}

	while (cb != NULL) {     //percorre o conjunto b
        // se o conjunto uniao nao tiver o elemento no qual o ponoteiro esta (lembrando que ele esta percorrendo a lista) insere esse elemeneto
        if (verificar(uniao, cb->numero) == FALSE) {
            inserir(uniao, cb->numero);
        }

		cb = cb->prox;
	}

    return uniao;

}

//Realiza a intersecao de dois conjunto em um novo.
conjunto * intersec(conjunto * ca, conjunto * cb) {
    //em um futuro sera preciso retornar ao inico da lista por isso um ponteiro pra percorrer e outro pra marcar o inicio
    conjunto * intersecao = NULL;
	conjunto * percorre_cb = cb;

	while (ca != NULL) {   // percorre a lista a
		while (percorre_cb != NULL) {     // percorre a lista b
			if (ca->numero == percorre_cb->numero) {     // se algum elemento coencidir
				inserir(intersecao, ca->numero);   // adicione esse elemento
				break;      // e pare de percorrer a lista b
			}

			percorre_cb = percorre_cb->prox;
		}

		percorre_cb = cb;     //volta ao inicio da lista b, para comparar ela toda com o proximo elemento de a
		ca = ca->prox;

	}

    return intersecao;

}
