#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

#ifndef _H_LISTA
#define _H_LISTA

typedef struct No No;
typedef struct Lista Lista;

struct No{
    /* colocar os atribultos*/
    No *prox;
};

struct Lista{
    No *cabeca;
    No *pe;
    int tam;
};

/* NO */
No* criaNo();
void destroiNo(No *n);

/* Lista */
Lista* criaLista();
void insereLista(Lista *l, No *n);
No* removeListaInicio(Lista *l);
int ehVazia(Lista *l);
void destroiLista(Lista *l);
void imprimeLista(Lista *l);

#endif

