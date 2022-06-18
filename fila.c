#include "fila.h"

/* NOF */
NoF* criaNoF(int addrR){
    NoF *n = malloc(sizeof(NoF));
    n->addrR = addrR;
    n->prox = NULL;
    return n;
}

void destroiNoF(NoF *n){
    free(n);
}

/* FILA */
Fila* criaFila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->ini = criaNoF(-1);
    f->ini->prox = NULL;
    f->pontero = NULL;
    f->fim = f->ini;
    return f;
}

void criaFilaReal(Fila *f, int nPag){
    int i;
    for (i = 0; i < nPag; i++){
        NoF *no = criaNoF(-1);
        insereFila(f, no);  
    }
    f->pontero = f->ini->prox;
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
        printf("%d -> ", n->addrR);
        n = n->prox;
    }    
    printf("fim\n");
}

/*ta errado*/
NoF* verificaFila(Fila *f, int addrR){
    NoF* no = f->ini->prox;
    while(no != f->fim->prox){
        if(no->addrR == 1){
            return no;
        }
        no = no->prox;
    }
    return no;
}