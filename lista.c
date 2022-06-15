#include "lista.h"

/* NO */
No* criaNo(){
    No *n = (No*)malloc(sizeof(No));
    n->prox = NULL;

    return n;
}

void destroiNo(No *n){
    free(n);
}

/* Lista */
Lista* criaLista(){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->cabeca = criaNo();
    l->pe = l->cabeca;
    l->tam = 0;
    return l;
}

void insereLista(Lista *l, No *n){
    if (ehVazia(l)){
        l->cabeca->prox = n;
        l->pe = n;
        l->tam++;
        l->pe->prox = NULL;
    }else{
        l->pe->prox = n;
        l->pe = l->pe->prox;
        l->pe->prox = NULL;
        l->tam++;
    }
    
}

No* removeListaInicio(Lista *l){
    if(l->tam == 1){
        l->pe = l->cabeca;
    }
    No *n = l->cabeca->prox;
    l->cabeca->prox = n->prox;
    n->prox = NULL;
    l->tam--;
    return n;
}

int ehVazia(Lista *l){
    return (l->cabeca == l->pe);
}

void destroiLista(Lista *l){
    while (l->tam > 0){
        No *n = removeListaInicio(l);
        destroiNo(n);
    }
    free(l->cabeca);
    free(l);
}

void imprimeLista(Lista *l){
    No *n = l->cabeca->prox;
    printf("cabeca -> ");

    while (n != NULL){
        /*printf("%d ->", n.a);*/
        n = n->prox;
    }

    printf(" pe");

}