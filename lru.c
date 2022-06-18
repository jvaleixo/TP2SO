#include "lru.h"

int lru(int nPag, Fila* F, int tamanho){
    
};





void insereFrame(LFrame *fr, Page *p){
    if(fr->st == fr->end){
        fr->st->prox = p;
        fr->end = p;
    }else{
        fr->end->prox = p;
        fr->end = fr->end->prox;
    }
};

LFrame* criaFrame(){
    LFrame *fr = (Fila*)malloc(sizeof(Fila));
    fr->st = criaPage("0",0);
    fr->st->prox = NULL;
    fr->end = fr->st;
    return fr;
};

Page* criaPage(const char *addr, int timer){
    Page *p = malloc(sizeof(Page));
    p->addr = strdup(addr);
    p->timer = timer;
    p->prox = NULL;
    return p;
};
typedef struct LFrame{
    Page* st;
    Page* end;
};
typedef struct LPage{
    const char* addr;
    long int timer;
    int ref;
    Page* prox;
};