#include "lru.h"
#include "funcoes.h"
#include "fila.h"

#include <string.h>
int lru(int nPag, Fila *F, LTable *T, int timer){
    int j,pgFault;
    for(j = 0; j< nPag; j++){
        LPage *p;
        NoF *aux;
        aux = F->ini->prox;
        const char *bin;
        bin = strdup(aux->addr);
        p = criaPage(bin,timer);
        if(T->nPag == 0){
            insereTable(T,p,nPag,timer);
            timer++;
        } else if (T->nPag > 0){
            pgFault = updateTable(T,p,nPag,timer);
            timer++;
        }
        free(bin);
    }
    return pgFault;
}

LPage* procuraLRU(LTable *T){
    int min = INT_MAX;
    LPage *LRU;
    LPage *p = T->st->prox;
    LRU = criaPage("0",0);
    while(p != T->end){
        if(p->timer < min){
            min = p->timer;
            LRU = p;
            p = p->prox;
        }
    }
    return LRU;
}

int updateTable(LTable *T, LPage *p,int tamanho,int timer){
    int aux2,pgFault;
    aux2 = verificaPage(T,p,tamanho);
    /*printf("%d\n",aux2);*/
    if(aux2 == 0){
        LPage *x = procuraLRU(T);
        insereTable(T,x,tamanho, timer);
        pgFault++;
    }
    return pgFault;
}

/*int verificaPage(Fila *F){
    NoF *aux3;
    aux3 = F->ini->prox;
    while(aux3 != F->end->prox){
        if(aux3->ref == 1){ /* pagina referenciada na tabela*/
         /*   return 1;
        }else{
            return 0; 
        }
        aux3 = aux3->prox;
    }
}*/

int verificaPage(LTable* T, LPage *p, int tamanho){
    int j = 0;
    LPage *aux3;
    aux3 = T->st;
    while(aux3 != T->end){
        if(strcmp(aux3->addr,p->addr) == 0){ /* pagina referenciada na tabela*/
            return 1;
        }else{
            return 0; 
        }
        aux3 = aux3->prox;
    }
    free(aux3);
} 


void insereTable(LTable *T, LPage *p, int tamanho,int timer){
    int j = 0;
    LPage *aux4,*aux5;
    aux4 = T->st;
    aux5 = T->end;
    if(T->nPag == 0 && T->st == T->end && aux4->ref ==0){
        aux4->prox = p;
        T->end = NULL;
        T->nPag++;
        aux4->ref = 1;
        aux4->pagina = j;
        aux4->timer = timer+1;
    } else{
    while(j < tamanho){ 
        if(aux4->ref == 0){
            if(T->st == T->end){
                aux4->prox = p;
                aux4->prox->prox = NULL;
                T->nPag++;
                aux4->ref = 1;
                aux4->pagina = j;
                aux4->timer = timer+1;
            } else{ 
                aux5->prox = p;
                aux4->prox->prox = NULL;
                aux4->pagina = j;
                aux4->ref = 1;
                }
            }
            j++;
        }
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

LPage* criaPage(const char *addr, int timer){
    LPage *p = (LPage*)malloc(sizeof(LPage));
    p->addr = strdup(addr);
    p->timer = timer;
    p->prox = NULL;
    p->pagina = 0;
    p->ref = 0;
    return p;
}

void imprimeTable(LTable *T){
    LPage *p = T->st->prox;
    printf("\ntabela:\n");
    while(p != NULL){
        printf("%s \n", p->addr);
        p = p->prox;
    }    

}

