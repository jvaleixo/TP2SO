#include "funcoes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    FILE *arquivo = NULL;
        argv[1] = "nru";
        argv[2] = "compilador.log";
        argv[3] = "4";
        argv[4] = "128";
        /*recebendo variaveis e definindo o numero de paginas.*/
    

    /*FILE *arquivo = NULL;*/
    int tamPag = atoi(argv[3]);
    int tamMem = atoi(argv[4]);
    int nPag = tamMem/tamPag;
    printf("npag: %d\n", nPag);
    int nPagR = 0;
    int nPagW = 0;
    int s;
    char addr[MAX+1];
    char rw;
    argc = 5;

    s = enderecoPagina(tamPag);
    printf("s: %d\n", s);
    arquivo = abrirArquivo(argv[2]);
    while (fscanf(arquivo, "%s %c", &addr, &rw) != EOF){
        const char *bin = hextobinary(addr);
        /*printf("endereco em bin: %s\n",bin);*/
        /*Define o numero de paginas lidas e escritas*/
        if(rw == 'R')
            nPagR++;
        if(rw == 'W')
            nPagW++;
        
        if (argc == 5){
            if(strcmp(argv[1], "lru") == 0){
                /*Logica lru*/
                printf("lru!\n");
            }else if(strcmp(argv[1], "nru") == 0){
                /*Logica nru*/
                printf("nru!\n");
            }else if(strcmp(argv[1], "segunda_chance") == 0){
                /*Logica segunda_chance*/
                printf("segunda_chance!\n");
            }else{
                printf("digite um comando valido!\n");
            }
        }else{
             printf("Falta argumentos\n");
        }
    }
    
    fecharArquivo(arquivo);

    printf("Executando o simulador...\n");
    printf("Arquivo de entrada: %s\n", argv[2]);
    printf("Tamanho da memoria: %d KB\n", tamMem);
    printf("Tamanho das paginas: %d KB\n", tamPag);
    printf("Tecnica de reposição: %s\n", argv[1]);
    printf("Paginas lidas: %d\n", nPagR);
    printf("Paginas escritas: %d\n", nPagW);
    return 1;
}