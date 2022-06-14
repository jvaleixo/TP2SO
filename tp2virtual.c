#include "funcoes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    /*
        argv[1] = tipo de algoritimo de reposição
        argv[2] = nome do arquivo com os endereçõs de memoria e tipos de comandos
        argv[3] = tamanho de cada pagina na memoria
        argv[4] = tamanho da memoria fisica disponivel
        recebendo variaveis e definindo o numero de paginas.
    */

    FILE *arquivo = NULL;
    int tamPag = atoi(argv[3]);
    int tamMem = atoi(argv[4]);
    int nPag = tamMem/tamPag;
    int nPagR = 0;
    int nPagW = 0;
    unsigned int addr;
    char rw;

    arquivo = abrirArquivo(argv[2]);
    while (fscanf(arquivo, "%x %c", &addr, &rw) != EOF){
        
        /*Define o numero de paginas lidas e escritas*/
        if(rw == 'R')
            nPagR++;
        if(rw == 'W')
            nPagW++;
        
        if (argc == 5){
            if(strcmp(argv[1], "lru") == 0){
                /*Logica lru*/
 
            }else if(strcmp(argv[1], "nru") == 0){
                /*Logica nru*/
                
            }else if(strcmp(argv[1], "segunda_chance") == 0){
                /*Logica segunda_chance*/
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