#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "fila.h"

#ifndef _H_LRU
#define _H_LRU

typedef struct Page LPage;
typedef struct Table LTable;

typedef struct Page{
    int pagina;
    const char* addr;
    long int timer;
    int ref;
    LPage* prox;
};

typedef struct Table{
    int nPag;
    LPage* st;
    LPage* end;
};
int lru(int nPag, Fila *F, LTable *T, int timer);
int verificaPage(LTable* T, LPage *p, int tamanho);
LPage* procuraLRU(LTable *T);
int updateTable(LTable *T, LPage *p,int tamanho,int timer);
void imprimeTable(LTable *T);
void insereTable(LTable *T, LPage *p, int tamanho,int timer);
LTable* criaTable();
LPage* criaPage(const char *addr, int timer);

#endif