#include "fila.h"

/* NOF */
NoF* criaNoF(const char *addr){
    NoF *n = malloc(sizeof(NoF));
    n->addr = strdup(addr);
    n->prox = NULL;
    return n;
}

void destroiNoF(NoF *n){
    free(n);
}

/* FILA */
Fila* criaFila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->ini = criaNoF("0");
    f->ini->prox = NULL;
    f->fim = f->ini;
    return f;
}

void insereFila(Fila *f, NoF *n){
    if(f->ini == f->fim){
        f->ini->prox = n;
        f->fim = n;
    }else{
        f->fim->prox = n;
        f->fim = f->fim->prox;
    }
}

NoF* removeFila(Fila *f){
    if (f->ini == f->fim){
        return NULL;
    }else if (f->ini->prox == f->fim){
        NoF *n = f->ini->prox;
        n->prox = NULL;
        f->ini->prox = NULL;
        f->fim = f->ini;
        return n;
    }else{
        NoF *n = f->ini->prox;
        f->ini->prox = n->prox;
        n->prox = NULL;
        return n;
    }
}

void destroiFila(Fila *f){

    while (f->ini != f->fim){
        NoF *n = removeFila(f);
        destroiNoF(n);
    }   

    destroiNoF(f->ini);
    free(f);
}

void imprimeFila(Fila *f){
    NoF *n = f->ini->prox;
    printf("Ini -> ");

    while(n != NULL){
        printf("%s -> ", n->addr);
        n = n->prox;
    }    
    printf("fim\n");
}

NoF* verificaFila(Fila *f, const char *addr){
    NoF* no = f->ini->prox;
    while(no != f->fim->prox){
        if(no->addr[0] == addr[0] && no->addr[1] == addr[1] && no->addr[2] == addr[2] && no->addr[3] == addr[3] && no->addr[4] == addr[4]){
            return no;
        }
        no = no->prox;
    }
    return no;
}