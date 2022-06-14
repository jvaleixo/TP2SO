#define _GNU_SOURCE
#include <stdio.h>

#ifndef _H_TESTE
#define _H_TESTE

FILE* abrirArquivo(char* nome);
int fecharArquivo(FILE *arquivo);
#endif