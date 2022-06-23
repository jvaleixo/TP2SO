#include "lru.h"
#include "funcoes.h"
#include "fila.h"

#include <string.h>
int lru(Fila *F, LTable *T, int timer, int pgFault){ /*funcao principal do algoritmo*/
    /*recebe uma fila com todos os valores lidos do arquivo, uma tabela com valores padrao (0 em todos os atributos)
    recebe um timer que é o timer utilizado durante a execução do algoritmo e recebe o numero de pg fault*/
    LPage *p;
    NoF *aux; /*Nó da fila auxiliar para a execucao do programa*/
    const char *bin = NULL; /*para guardar o valor dos enderecos apos a transformacao para binario 
    aux = F->ini->prox;*/
    /*printf("aux lru: %s\n",aux->addr);*/
    while(aux != NULL){
        /*printf("timer: %d\n",timer);*/
        bin = strdup(aux->addr); /*copiando o valor do endereço para a variavel*/
        p = criaPage(bin,timer); /*chama a funcao criaPage com o valor do endereço recebido acima e o timer*/
        pgFault = updateTable(F,T,p,pgFault); /* com a pagina criada, chama a funcao de atualizacao da tabela*/
        timer++;
        aux = aux->prox; /*passa para o proximo valor da fila*/
    }
    /*imprimeTable(T);*/
    return pgFault;
}
int updateTable(Fila *F,LTable *T, LPage *p,int pgFault){
    LPage *aux;
    /*int aux2;
    aux2 = -1;
    aux2 = verificaPage(T,p);*/
    aux = T->st->prox; 
     /*variaveis auxiliares*/
    if(strcmp(aux->addr, "0") == 0){ /*verifica se a tabela ainda está com os valores padrao*/
        trocaPage(F,T,p); /*se sim, chama a funcao trocapage para trocar o valor da pagina*/
    }else{
        LPage *x = criaPage("0",0); 
        x = procuraLRU(T); /*se nao, chama a funcao para procurar a LRU*/
        trocaLRU(F,T,p,x); /*com a lru encontrada chama a funcao para trocar o valor da lru pelo valor da pagina*/
        /*pgFault++;*/
    }
    return pgFault;  
}
/*int verificaPage(LTable* T, LPage *p){
    LPage *aux3;
    aux3 = T->st->prox;
    while(aux3 != NULL){
        if(strcmp(aux3->addr, p->addr) == 0){ /* pagina referenciada na tabela
            return 1;
        }else{
            return 0; 
        }
        aux3 = aux3->prox;
    }
    return 0;
} */

LPage* procuraLRU(LTable *T){
    int min = INT_MAX;
    LPage *LRU;
    LRU = criaPage("0",0);
    LPage *p;
    p = T->st->prox;  /*variaveis auxiliares*/
    while(p != NULL){
        if(p->timer < min){ /*verifica se o timer da pagina é menor que o valor minimo*/
            min = p->timer; 
            LRU->addr = strdup(p->addr); /*se sim os valores de endereco e timer sao passados para a variavel LRU*/
            LRU->timer = p->timer+1;
            p = p->prox; /*passa para o proximo valor da tabela*/
        } else {
            p = p->prox; /*passa para o proximo valor da tabela*/
        }
    }
    /*printf("LRU:");
    imprimePage(LRU);*/
    return LRU;
}
void trocaLRU(Fila *F,LTable *T, LPage *p, LPage *LRU){
    LPage *aux;
    aux = T->st->prox; /*variaveis auxiliares*/
    while(aux != NULL){
        if(strcmp(aux->addr, LRU->addr) == 0){ /* encontra a pagina LRU */
            aux->addr = p->addr;
            aux->timer = p->timer+1;
            aux->ref = 1; /*valores da pagina que vai substituir a LRU são passados para a tabela*/
            break;
        }
        aux = aux->prox;
    }
}
void trocaPage(Fila *F, LTable *T, LPage *p){
    LPage *aux;
    NoF *aux2;
    aux = T->st->prox;
    aux2 = F->ini->prox; /*variaveis auxiliares*/
    while(aux2 != NULL){
        if(strcmp(aux->addr, "0") == 0){ /*verifica se a tabela, memoria, ainda esta com os valores padroes*/
            aux->addr = aux2->addr;
            aux->timer = p->timer+1;
            aux->ref = 1;  /*adiciona os valores na tabela substituindo os padroes*/
        }
        aux2 = aux2->prox;
        aux = T->st->prox->prox; /*passa para os proximos valores na fila e na tabela*/
    }
}
void insereTable(LTable *T, LPage *p){
    if(T->st == T->end){/*verifica se a tabela ainda está como apos a criacao com o metodo criatable*/
        T->st->prox = p;
        T->end = p; /*se sim adiciona os valores de modo que st, inicio, tenha o mesmo valor que end, fim*/
    }else{
        T->end->prox = p; 
        T->end = T->end->prox; /*se nao apenas adiciona o valor ao final da tabela*/
    }
}


LTable* criaTable(){
    LTable *T = (LTable*)malloc(sizeof(LTable));
    T->nPag = 0;
    T->st = criaPage("0",0);
    T->st->prox = NULL;
    T->end = T->st;
    return T; /*inicia a tabela com um valor padrao para que seja possivel operacoes com a mesma*/
}

LTable* criaMemoria(LTable *T, int Tam){
    
    int i;
    LPage *p;
    for (i = 0; i < Tam; i++){
        p = criaPage("0", 0);
        insereTable(T,p);
    } /*adiciona paginas com valores padrao para que sejam criadas x, x = nPag, paginas para a tabela*/
    return T;
}

LPage* criaPage(const char *addr, int timer){
    LPage *p = (LPage*)malloc(sizeof(LPage));
    p->addr = strdup(addr);
    p->timer = timer;
    p->prox = NULL;
    p->ref = 0; /*inicializacao da pagina*/
    return p;
}

void imprimeTable(LTable *T){ /*imprime a tabela*/
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

void imprimePage(LPage *p){ /*imprime os atributos especificos da pagina*/
    printf("addr: %s\n",p->addr);
    printf("timer: %lu\n",p->timer);
    printf("ref: %d\n",p->ref);
}