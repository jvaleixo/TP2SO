#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef _H_LRU
#define _H_LRU

typedef struct Page LPage;
typedef struct Table LTable;

typedef struct LPage{
    int pagina;
    const char* addr;
    long int timer;
    LPage* prox;
};

typedef struct LTable{
    int nPag;
    int ref;
    LPage* st;
    LPage* end;
};

void lru(int nPag, Fila *F, int timer);
void verificaPage(LTable *T, LPage *p)
void insereTable(LTable *T, LPage *p);
LTable* criaTable();
LPage* criaPage(const char *addr, int timer);

#endif