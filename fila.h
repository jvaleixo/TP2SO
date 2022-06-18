#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _H_FILA
#define _H_FILA

typedef struct NoF NoF;
typedef struct Fila Fila;

struct NoF{
    /* colocar os atributos*/
    int addrR;
    
    NoF *prox;
};

struct Fila{
    NoF *ini;
    NoF *fim;
    NoF *pontero;
};

/* NOF */
NoF* criaNoF(int addrR);
void destroiNoF(NoF *n);

/* FILA */
Fila* criaFila();
void criaFilaReal(Fila *f, int nPag);
void insereFila(Fila *f, NoF *n);
NoF* removeFila(Fila *f);
void destroiFila(Fila *f);
void imprimeFila(Fila *f);
NoF* verificaFila(Fila *f, int addrR);

#endif