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
    while(aux != NULL){
        bin = strdup(aux->addr);
        p = criaPage(bin,timer);
        pgFault = updateTable(T,p);
        timer++;
        aux = aux->prox;
    }
    return pgFault;
}
int updateTable(LTable *T, LPage *p){
    int aux2;
    int pgFault = 0;
    aux2 = verificaPage(T,p);
    if(aux2 == 0){
        LPage *x = procuraLRU(T);
        trocaLRU(T,p,x);
        pgFault++;
    } else if(strcmp(T->st->prox->addr, "0") == 0){
        insereTable(T,p);
    }
    return pgFault;
}
int verificaPage(LTable* T, LPage *p){
    LPage *aux3;
    aux3 = T->st->prox;
    while(aux3 != NULL){
        if(strcmp(aux3->addr, p->addr) == 0){ /* pagina referenciada na tabela*/
            printf("alo\n");
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
    LPage *p;
    p = T->st->prox;
    while(p != NULL){
        if(p->timer < min){
            min = p->timer;
            LRU = p;
            p = p->prox;
        } else {
            p = p->prox;
        }
    }
    return LRU;
}
void trocaLRU(LTable *T, LPage *p, LPage *LRU){
    LPage *aux,*aux2;
    aux = T->st->prox;
    aux2 = T->end->prox;
    while(aux != aux2){
        if(strcmp(aux->addr, p->addr) == 0){ /* encontra a pagina LRU */
            aux->addr = LRU->addr;
            aux->timer = LRU->timer+1;
            aux->ref = 1;
            break;
        }
        aux = aux->prox;
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
    int i;
    i = 0;
    LPage *p; 
    p = T->st->prox;
    printf("\ntabela:\n");
    while(p != NULL){
        printf("addr pos %d: %s\n",i,p->addr);
        printf("timer pos %d: %lu\n",i,p->timer);
        p = p->prox;
        i++;
    }    
}

void imprimePage(LPage *p){
    printf("addr: %s\n",p->addr);
    printf("timer: %lu\n",p->timer);
}