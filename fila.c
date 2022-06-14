#include "fila.h"

/* NO */
No* criaNo(){
    No *n = malloc(sizeof(No));
    n->prox = NULL;
    return n;
}

void destroiNo(No *n){
    free(n);
}

/* FILA */
Fila* criaFila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->ini = criaNo(-1);
    f->ini->prox = NULL;
    f->fim = f->ini;
    return f;
}

void insereNo(Fila *f, No *n){
    if(f->ini == f->fim){
        f->ini->prox = n;
        f->fim = n;
    }else{
        f->fim->prox = n;
        f->fim = f->fim->prox;
    }
}

No* removeNo(Fila *f){
    if (f->ini == f->fim){
        return NULL;
    }else if (f->ini->prox == f->fim){
        No *n = f->ini->prox;
        n->prox = NULL;
        f->ini->prox = NULL;
        f->fim = f->ini;
        return n;
    }else{
        No *n = f->ini->prox;
        f->ini->prox = n->prox;
        n->prox = NULL;
        return n;
    }
}

void destroiFila(Fila *f){

    while (f->ini != f->fim){
        No *n = removeNo(f);
        destroiNo(n);
    }   

    destroiNo(f->ini);
    free(f);
}

void imprimeFila(Fila *f){
    No *n = f->ini->prox;
    printf("Ini -> ");

    while(n != NULL){
    /*    printf("%d -> ", n->a)*/
        n = n->prox;
    }    
    printf("fim\n");
}