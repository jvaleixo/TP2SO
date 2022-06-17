#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#define TAMANHO 8
#ifndef _H_FUNCOES
#define _H_FUNCOES

typedef struct TFrame{
    int page;
    int r_b;
}Frame;


FILE* abrirArquivo(char* nome);
int fecharArquivo(FILE *arquivo);
int enderecoPagina(int tamPag);
const char* hextobinary(char* addr);

#endif