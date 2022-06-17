#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

#ifndef _H_FILA
#define _H_FILA

typedef struct NoF NoF;
typedef struct Fila Fila;

struct NoF{
    /* colocar os atributos*/
    NoF *prox;
};

struct Fila{
    NoF *ini;
    NoF *fim;
};

/* NOF */
NoF* criaNoF();
void destroiNoF(NoF *n);

/* FILA */
Fila* criaFila();
void insereFila(Fila *f, NoF *n);
NoF* removeFila(Fila *f);
void destroiFila(Fila *f);
void imprimeFila(Fila *f);

#endif
