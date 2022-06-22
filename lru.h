#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "fila.h"

#ifndef _H_LRU
#define _H_LRU

typedef struct Page LPage;
typedef struct Table LTable;

struct Page{
    const char* addr;
    long int timer;
    int ref;
    LPage* prox;
};

struct Table{
    int nPag;
    LPage* st;
    LPage* end;
};

int lru(Fila *F, LTable *T, int timer, int pgFault);
int verificaPage(LTable* T, LPage *p);
LPage* procuraLRU(LTable *T);
void trocaLRU(Fila *F,LTable *T, LPage *p, LPage *LRU);
void trocaPage(Fila *F, LTable *T, LPage *p);
int updateTable(Fila *F,LTable *T, LPage *p,int pgFault);
void imprimeTable(LTable *T);
void imprimePage(LPage *p);
void insereTable(LTable *T, LPage *p);
LTable* criaTable();
LTable* criaMemoria(LTable *T, int Tam);
LPage* criaPage(const char *addr, int timer);

#endif