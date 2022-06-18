#include "lru.h"
#include "funcoes.h"

void lru(int nPag, Fila *F, int timer){
    for(int j = 0; j< nPag; j++){
        LPage *p;
        p = criaPage(bin,timer);
        if(T->nPag == 1){
            insereTable(T,p,timer);
            timer++;
        } else if (T->nPag > 1){
            updateTable(T,p,nPag,timer);
            timer++;
        }
    }
};

LPage* procuraLRU(LTable *T, LPage *p, int tamanho){
    int min = INT_MAX;
    LPage *LRU;
    LPage *p = T->st->prox;
    LRU = criaPage("0",0);
    while(n != NULL){
        if(n->timer < min){
            min = n->timer;
            LRU = n;
            n = n->prox;
        }
    }
    return n;
}

void updateTable(LTable *T, LPage *p, int tamanho,int timer){
    if(verificaPage(T,p,tamanho) == false){
        LPage *x = procuraLRU(T,p,tamanho);
        insereTable(T,x,tamanho, timer);
    }
}

void verificaPage(LTable* T, LPage* p, int tamanho){
    int j = 0;
    while(j < tamanho){
        if(T[j]->ref == 1){ // pagina referenciada na tabela
            return true;
        }else{
            return false 
        }
    }
}


void insereTable(LTable *T, LPage *p, int tamanho,int timer){
    int j = 0;
    while(j < tamanho){ 
        if(T[j]->rf == 0){
            if(T->st == T->end){
                T->st->prox = p;
                T->end = p;
                T->nPag = T->nPag+1;
                T->ref = 1;
                T->p->pagina = j;
                T->p->timer = timer+1;
            }else{
                T->end->prox = p;
                T->end = T->end->prox;
                T->nPag = T->nPag+1;
                T->ref = 1;
            }
        }
        j++;
    }
};

LTable* criaTable(){
    LTable *T = (LTable*)malloc(sizeof(LTable));
    T->nPag = 1;
    T->st = criaPage("0",0);
    T->st->prox = NULL;
    T->end = T->st;
    return T;
};

LPage* criaPage(const char *addr, int timer){
    LPage *p = malloc(sizeof(LPage));
    p->addr = strdup(addr);
    p->timer = timer;
    p->prox = NULL;
    p->pagina = 0;
    return p;
};

void imprimeTable(LTable *T){
    LPage *p = T->st->prox;
    while(n != NULL){
        printf("%s ", n->addr);
        n = n->prox;
    }    

}

