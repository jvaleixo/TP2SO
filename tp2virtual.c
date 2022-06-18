#include "segunda_chance.h"

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

    if (argc >= 5){
        if(strcmp(argv[1], "lru") == 0){
            /*Logica lru
            printf("lru!\n");*/
        }else if(strcmp(argv[1], "nru") == 0){
            /*Logica nru
            printf("nru!\n");*/
        }else if(strcmp(argv[1], "segunda_chance") == 0){
            /*Logica segunda_chance
            printf("segunda_chance!\n");*/
            segunda_chance(argc, argv);
        }else{
            printf("digite um comando valido!\n");
        }
    }else{
        printf("Falta argumentos\n");
    }

    return 1;
}