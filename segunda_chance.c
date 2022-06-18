#include "segunda_chance.h"


void segunda_chance(int argc, char *argv[]){
    /*recebendo variaveis e definindo o numero de paginas.*/
    FILE *arquivo = NULL;
    FILE *debug = NULL;
    
    int tamPag = atoi(argv[3])*1024;/* definindo o tamanho da pagina */
    int tamMem = atoi(argv[4])*1024;/* definindo o tamanho da memoria real */
    int nPag = tamMem/tamPag;/* definindo o numero de paginas da memoria real */
    int nPagR = 0;/* numero de paginas lidas */
    int nPagW = 0;/* numero de paginas escritas */
    int pFault = 0;/* numero de page falts*/
    unsigned page;/* endereço real da pagina */
    unsigned s;/* numero de bits menos significativos a serem excluidos */
    unsigned addr;/* endereço em HEX */
    char addr2[TAMANHO+1];/* endereçe em char */
    char rw;/* leitura ou escrita */
    const char *bin;/* char com o endereço virtual em binario */
    long int binInt;/* int com o indereço virtual em inteiro */
    Fila *f;
    Lista **hash;

    /*Abrindo arquivos de leitura e escrita*/
    arquivo = abrirArquivo(argv[2], "r");
    debug = abrirArquivo("debug.log", "w");

    /*Definido numero de bits menos significativos a serem descartados*/
    s = enderecoPagina(tamPag);
    
    f = criaFila();
    criaFilaReal(f, nPag);
    hash = criaHash(nPag);

    while (fscanf(arquivo, "%x %c", &addr, &rw) != EOF){

        sprintf(addr2, "%x", addr); /* trasformando HEX em String */
        
        bin = hextobinary(addr2);
        binInt = strtoll(bin,NULL,2);

        /*define o endereço real da pagina*/
        page = addr >> s;

        /*
        insereLista[hash[?????]];
        */
        /*printfs para verificar o funcionamento do código*/
        /*Quando argc == 6 significa que ha 5 parametros, ou seja, argv[6] e == debug*/
        if((argc == 6) && (strcmp(argv[5], "debug") == 0)){
            salvarDebug(debug, s, tamPag, nPag, bin, binInt, addr, addr2, page);
        }
        
        /*Define o numero de paginas lidas e escritas*/
        if(rw == 'R')
            nPagR++;
        if(rw == 'W')
            nPagW++;
        
    }

    imprimeFila(f);
    destroiFila(f);
    destroiHash(hash, nPag);
    fecharArquivo(debug);
    fecharArquivo(arquivo);
    
    printf("Executando o simulador...\n");
    printf("Arquivo de entrada: %s\n", argv[2]);
    printf("Tamanho da memoria: %d KB\n", tamMem/1024);
    printf("Tamanho das paginas: %d KB\n", tamPag/1024);
    printf("Tecnica de reposição: %s\n", argv[1]);
    printf("Paginas lidas: %d\n", nPagR);
    printf("Paginas escritas: %d\n", nPagW);
    printf("Page faults: %d\n",pFault);
}