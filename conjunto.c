//Programa com as funcoes implementadas.

#include "conjunto.h"

//Verifica se existe determinado elemento no conjunto. Retorna TRUE, caso verdadeiro e FALSE, caso falso.
int verificar(conjunto * c, int numero) {

	while (c != NULL) {
		if (c->numero == numero) {
			return TRUE;
		}
		
		c = c->prox;
		
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

if ((ca == NULL) && (cb == NULL)) {     //Verifica se os dois conjuntos são vazios
		return FALSE;
	} else if (cb == NULL) {    //se ca for vazio e cb nao, ca nao contem cb
		return FALSE;
    } else if (ca == NULL) {     //se cb for vazio e ca nao, ca contem cb
        return TRUE;
    } else {    //se nenhum dos dois for vazio, verifica os elementos de cada um
		while (cb != NULL) {
			if (verificar(ca,cb->numero) == FALSE) {
				return FALSE;
			}

			cb = cb->prox;
		}
	}

	return TRUE;

}

//Insere um elemento no conjunto, caso ja nao exista uma ocorrencia do mesmo no conjunto.
conjunto * inserir(conjunto * c, int numero) {

	if (c != NULL){ // verifica se o conjunto é nulo
		if (verificar(c, numero) == TRUE){ // se não for, verifica se existe uma ocorrência do número 
			return c;
		}
	}

	conjunto * novo = (conjunto *) malloc(sizeof(conjunto));
	
	novo->numero = numero;
	novo->prox = c;
	c = novo;
	
	return c;
	
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

//Soma dois conjuntos.
 conjunto * somar (conjunto * ca, conjunto * cb) {
	
	conjunto * c = NULL;
	
	while (ca != NULL){//insere todos os elementos de ca em c
		c = inserir (c, ca->numero);
		ca = ca->prox;
	}
	
	while (cb != NULL){//insere todos os elementos de cb em c
		c = inserir (c, cb->numero);
		cb = cb->prox;
	}
	
	
	return c;
 }
 
 //Subtrai um conjunto de outro.
 conjunto * subtrair (conjunto * ca, conjunto * cb) {
	
	conjunto * c = NULL;
	
	//clona a lista ca para poder deletar os elementos sem perder a lista anterior.
	c = somar (ca, NULL);
	
	while (cb != NULL){//remove os elementos de cb em ca.
		c = remover_elemento (c, cb->numero);
		cb = cb->prox;
	}
	
	return c;
 }
 

//Realiza a uniao de dois conjuntos em um novo.
conjunto * unir(conjunto * ca, conjunto * cb) {
	
	// A U B = (A - B) + B
	
	conjunto * uniao = NULL;
	conjunto * temp = NULL;//lista temporária para poder realizar o cálculo.
	
	temp = subtrair (ca, cb);
	uniao = somar (temp,cb);
	
	/*Com o tratamento feito pela função inserir a poderiamos usar apenas a seguinte linha:
	 *
	 *uniao = somar (ca, cb);
	 *poém qualquer alteração em inserir iria danificar a função, por isso opitei pela fórmula da teoria dos conjuntos. 
	*/
	
	while(temp!=NULL){//limpa a lista temporária
		temp = remover_elemento (temp, temp->numero);
	}
	
    return uniao;
	
	
}

//Realiza a intersecao de dois conjunto em um novo.
conjunto * intersec(conjunto * ca, conjunto * cb) {
    
	//A ∩ B = A - (A - B)
	
	conjunto * intersecao = NULL;
	conjunto * temp = NULL;//lista temporária para poder realizar o cálculo.
	
	temp= subtrair (ca, cb);
	intersecao = subtrair (ca, temp);
	
	while(temp!=NULL){//limpa a lista temporária
		temp = remover_elemento (temp, temp->numero);
	}
	
    return intersecao;

}
