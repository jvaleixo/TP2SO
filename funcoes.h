#define _GNU_SOURCE
#include <stdio.h>

#ifndef _H_FUNCOES
#define _H_FUNCOES

FILE* abrirArquivo(char* nome);
int fecharArquivo(FILE *arquivo);
#endif