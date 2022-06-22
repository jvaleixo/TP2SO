#include "lru.h"
#include "funcoes.h"
#include "fila.h"

#include <string.h>
int lru(Fila *F, LTable *T, int timer){
    
    int pgFault;
    LPage *p;
    NoF *aux;
    const char *bin = NULL;
    aux = F->ini->prox;
    /*bin = strdup(aux->addr);
    p = criaPage(bin,timer);
    imprimePage(p);
    printf("aux lru: %s\n",aux->addr);*/
    while(aux != NULL){
        /*printf("timer: %d\n",timer);*/
        bin = strdup(aux->addr);
        p = criaPage(bin,timer);
        pgFault = updateTable(F,T,p);
        timer++;
        aux = aux->prox;
    }
    /*imprimeTable(T);*/
    return pgFault;
}
int updateTable(Fila *F,LTable *T, LPage *p){
    LPage *aux;
    int aux2,pgFault;
    aux2 = -1;
    pgFault = 0;
    aux = T->st->prox;
    aux2 = verificaPage(T,p);
    if(strcmp(aux->addr, "0") == 0){
        trocaPage(F,T,p);
    }else{
        LPage *x = criaPage("0",0);
        x = procuraLRU(T);
        trocaLRU(F,T,p,x);
        pgFault++;
    }
      return pgFault;  
}
int verificaPage(LTable* T, LPage *p){
    LPage *aux3;
    aux3 = T->st->prox;
    while(aux3 != NULL){
        if(strcmp(aux3->addr, p->addr) == 0){ /* pagina referenciada na tabela*/
            return 1;
        }else{
            return 0; 
        }
        aux3 = aux3->prox;
    }
    return 0;
} 
LPage* procuraLRU(LTable *T){
    int min = INT_MAX;
    LPage *LRU;
    LRU = criaPage("0",0);
    LPage *p;
    p = T->st->prox;
    while(p != NULL){
        if(p->timer < min){
            min = p->timer;
            LRU->addr = strdup(p->addr);
            LRU->timer = p->timer+1;
            p = p->prox;
        } else {
            p = p->prox;
        }
    }
    /*printf("LRU:");
    imprimePage(LRU);*/
    return LRU;
}
void trocaLRU(Fila *F,LTable *T, LPage *p, LPage *LRU){
    LPage *aux;
    aux = T->st->prox;
    while(aux != NULL){
        if(strcmp(aux->addr, LRU->addr) == 0){ /* encontra a pagina LRU */
            aux->addr = p->addr;
            aux->timer = p->timer+1;
            aux->ref = 1;
            break;
        }
        aux = aux->prox;
    }
}
void trocaPage(Fila *F, LTable *T, LPage *p){
    LPage *aux;
    NoF *aux2;
    aux = T->st->prox;
    aux2 = F->ini->prox;
    while(aux2 != NULL){
        if(strcmp(aux->addr, "0") == 0){
            aux->addr = aux2->addr;
            aux->timer = p->timer+1;
            aux->ref = 1;  
        }
        aux2 = aux2->prox;
        aux = T->st->prox->prox;
    }
}
void insereTable(LTable *T, LPage *p){
    if(T->st == T->end){
        T->st->prox = p;
        T->end = p;
    }else{
        T->end->prox = p;
        T->end = T->end->prox;
    }
}


LTable* criaTable(){
    LTable *T = (LTable*)malloc(sizeof(LTable));
    T->nPag = 0;
    T->st = criaPage("0",0);
    T->st->prox = NULL;
    T->end = T->st;
    return T;
}

LTable* criaMemoria(LTable *T, int Tam){
    
    int i;
    LPage *p;
    for (i = 0; i < Tam; i++){
        p = criaPage("0", 0);
        insereTable(T,p);
        /*printf("a");*/
    }
    return T;
}

LPage* criaPage(const char *addr, int timer){
    LPage *p = (LPage*)malloc(sizeof(LPage));
    p->addr = strdup(addr);
    p->timer = timer;
    p->prox = NULL;
    p->ref = 0;
    return p;
}

void imprimeTable(LTable *T){
    LPage *p;
    int i;
    i = 0; 
    p = T->st->prox;
    printf("\ntabela:\n");
    while(p != NULL){
        printf("addr pos %d: %s\n",i,p->addr);
        printf("timer pos %d: %lu\n",i,p->timer);
        printf("ref pos %d: %d\n",i,p->ref);
        p = p->prox;
        i++;
    }    
}

void imprimePage(LPage *p){
    printf("addr: %s\n",p->addr);
    printf("timer: %lu\n",p->timer);
    printf("ref: %d\n",p->ref);
}