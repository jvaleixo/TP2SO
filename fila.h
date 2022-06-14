#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

#ifndef _H_FILA
#define _H_FILA

typedef struct No No;
typedef struct Fila Fila;

struct No{
    int a;
    No *prox;
};

struct Fila{
    No *ini;
    No *fim;
};

/* NO */
No* criaNo(int a);
void destroiNo(No *n);

/* FILA */
Fila* criaFila();
void insereNo(Fila *f, No *n);
No* removeNo(Fila *f);
void destroiFila(Fila *f);
void imprimeFila(Fila *f);

#endif
