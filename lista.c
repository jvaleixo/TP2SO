#include "lista.h"

/* NOL */
NoL* criaNoL(int id){
    NoL *n = (NoL*)malloc(sizeof(NoL));
    n->prox = NULL;
    n->id = id;

    return n;
}

void destroiNoL(NoL *n){
    free(n);
}

/* Lista */
Lista* criaLista(){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->cabeca = criaNoL(-1);
    l->pe = l->cabeca;
    l->tam = 0;
    return l;
}

void insereLista(Lista *l, NoL *n){
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

NoL* removeListaInicio(Lista *l){
    NoL *n;

    if(l->tam == 1){
        l->pe = l->cabeca;
    }
    n = l->cabeca->prox;
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
        NoL *n = removeListaInicio(l);
        destroiNoL(n);
    }
    free(l->cabeca);
    free(l);
}

void imprimeLista(Lista *l){
    NoL *n = l->cabeca->prox;
    int i = 0;
    printf("cabeca -> ");

    while (l->tam > i++){
        printf("%d -> ", n->id);
        n = n->prox;
    }

    printf("pe\n");
}

Lista** criaHash(int nPag){
    int i;
    Lista **hash = (Lista**)malloc(sizeof(Lista*)*nPag);

    for (i = 0; i < nPag; i++){
        hash[i] = criaLista();
    }

    return hash;
}

void destroiHash(Lista **hash, int nPag){
    int i;
    for (i = 0; i < nPag; i++){
        destroiLista(hash[i]);    
    }
    free(hash);
}