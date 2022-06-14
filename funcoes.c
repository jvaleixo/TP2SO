#include "funcoes.h"

FILE* abrirArquivo(char* nome){
    FILE *arquivo = NULL;
    arquivo = fopen(nome, "r");

    if(arquivo != NULL){
        return arquivo;
    }
    
    printf("Erro ao abrir o arquivo\n");
    return NULL;
}

int fecharArquivo(FILE *arquivo){
    if(fclose(arquivo) == 0){
        return 1;
    }
    printf("Erro ao fechar o arquivo\n");
    return 0;
}

int enderecoPagina(int tamPag){
    unsigned s, tmp;
    /* Derivar o valor de s: */
    tmp = tamPag;
    s = 0;
    while (tmp>1) {
        tmp = tmp>>1;
        s++;
    }

    return s;
}