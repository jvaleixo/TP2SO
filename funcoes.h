#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#define TAMANHO 8
#ifndef _H_FUNCOES
#define _H_FUNCOES


FILE* abrirArquivo(char* nome, char *tipo);
int fecharArquivo(FILE *arquivo);
int enderecoPagina(int tamPag);
const char* hextobinary(char* addr);
void salvarDebug(FILE *f, int s, int tamPag, int nPag, const char *bin,  long int binint, unsigned addr, char *addr2, unsigned addrR);

#endif