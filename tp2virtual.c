#include "funcoes.h"
#include "fila.h"
#include "lista.h"
#include "lru.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){

    /*
        argv[1] = tipo de paginação;
        argv[2] = nome do arquivo;
        argv[3] = tamPag;
        argv[4] = tamMem;
        argv[5] = debug;
    */

    /*recebendo variaveis e definindo o numero de paginas.*/
    FILE *arquivo = NULL;
    int tamPag = atoi(argv[3])*1024;
    int tamMem = atoi(argv[4])*1024;
    int nPag = tamMem/tamPag;
    int nPagR = 0;
    int nPagW = 0;
    int pFault = 0;
    int s;
    int timer = 0;
    char addr[TAMANHO+1];
    char rw;
    s = enderecoPagina(tamPag);
    arquivo = abrirArquivo(argv[2]);
    Fila *F;
    F = criaFila();
    LTable *T;
    T = criaTable();
    while (fscanf(arquivo, "%s %c", addr, &rw) != EOF){
        
        const char *bin = hextobinary(addr);
        long int binint = strtoll(bin,NULL,2);
        long int page = binint >> s;

        NoF *n = criaNoF(bin);
        insereFila(F,n);
        /*printfs para verificar o funcionamento do código*/
        /*Quando argc == 6 significa que ha 5 parametros, ou seja, argv[6] e == debug*/
        if((argc == 6) && (strcmp(argv[5], "debug") == 0)){
            printf("s: %d\n", s);
            printf("tampag: %d\n",tamPag);
            printf("npag: %d\n", nPag); 
            printf("endereco em bin: %s\n",bin);
            printf("addr int: %lu\naddr: %s\n", binint, addr);
            printf("linha na tabela de pagina fisica %lu\n\n",page);
            imprimeFila(F);
            /*imprimeTable(T);*/
        }
        
        /*Define o numero de paginas lidas e escritas*/
        if(rw == 'R')
            nPagR++;
        if(rw == 'W')
            nPagW++;
        if (argc >= 5){
            if(strcmp(argv[1], "lru") == 0){
                pFault = lru(nPag,F,T,timer);
                /*imprimeTable(T);*/
            }else if(strcmp(argv[1], "nru") == 0){
                printf("nru!");
            }else if(strcmp(argv[1], "segunda_chance") == 0){
                /*Logica segunda_chance
                printf("segunda_chance!\n");
                segunda_chance();*/ 
                /*
                imprimeFila(F);
                verificaFila(F,bin);*/
            }else{
                printf("digite um comando valido!\n");
            }
        }else{
             printf("Falta argumentos\n");
        
        }
    }
    /*int j = 0;
    while (j < nPag){
        if (argc >= 5){
            if(strcmp(argv[1], "lru") == 0 ){
                lru(nPag,F,timer);
                imprimeTable(T);
                j++;
            }else if (strcmp(argv[1], "lru") == 0){
                lru(nPag,F,timer);
                j++; 
            }else if(strcmp(argv[1], "nru") == 0){
                printf("nru!");
            }else if(strcmp(argv[1], "segunda_chance") == 0){
                /*Logica segunda_chance
                printf("segunda_chance!\n");
                segunda_chance();*/ 
                /*
                imprimeFila(F);
                verificaFila(F,bin);
            }else{
                printf("digite um comando valido!\n");
            }
        }else{
             printf("Falta argumentos\n");
        
        }*/
    
    
    fecharArquivo(arquivo);

    printf("Executando o simulador...\n");
    printf("Arquivo de entrada: %s\n", argv[2]);
    printf("Tamanho da memoria: %d KB\n", tamMem/1024);
    printf("Tamanho das paginas: %d KB\n", tamPag/1024);
    printf("Tecnica de reposição: %s\n", argv[1]);
    printf("Paginas lidas: %d\n", nPagR);
    printf("Paginas escritas: %d\n", nPagW);
    printf("Page faults: %d\n",pFault);
    return 1;

}

