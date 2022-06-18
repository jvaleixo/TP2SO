#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

#ifndef _H_LISTA
#define _H_LISTA

typedef struct NoL NoL;
typedef struct Lista Lista;

struct NoL{
    /* colocar os atributos*/
    int id;
    NoL *prox;
};

struct Lista{
    NoL *cabeca;
    NoL *pe;
    int tam;
};

/* NOL */
NoL* criaNoL(int id);
void destroiNoL(NoL *n);

/* Lista */
Lista* criaLista();
void insereLista(Lista *l, NoL *n);
NoL* removeListaInicio(Lista *l);
int ehVazia(Lista *l);
void destroiLista(Lista *l);
void imprimeLista(Lista *l);
Lista** criaHash(int nPag);
void destroiHash(Lista **hash, int nPag);

#endif