#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#define MAX 8
#ifndef _H_FUNCOES
#define _H_FUNCOES

FILE* abrirArquivo(char* nome);
int fecharArquivo(FILE *arquivo);
int enderecoPagina(int tamPag);
const char* hextobinary(char* addr);
#endif