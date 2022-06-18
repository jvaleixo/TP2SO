#include "funcoes.h"

FILE* abrirArquivo(char* nome, char *tipo){
    FILE *arquivo = NULL;
    arquivo = fopen(nome, tipo);

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
    unsigned int s, tmp;
    /* Derivando o valor de s: */
    tmp = tamPag;
    s = 0;
    while (tmp>1) {
        tmp = tmp>>1;
        s++;
    }
      
    return s;
}


const char* hextobinary(char* addr){
    /*char hex[MAX+1];*/
    int count;
    static char bin[TAMANHO*4];
    strcpy(bin,"");
    count = 0;
    /*strcpy(hex,addr);*/
    /*printf("addr: %s\n",addr);*/
    while(addr[count]){
        switch(addr[count]){
            case '0':
                strcat(bin,"0000");
                break;
            case '1':
                strcat(bin,"0001");
                break;
            case '2':
                strcat(bin,"0010");
                break;
            case '3':
                strcat(bin,"0011");
                break;
            case '4':
                strcat(bin,"0100");
                break;
            case '5':
                strcat(bin,"0101");
                break;
            case '6':
                strcat(bin,"0110");
                break;
            case '7':
                strcat(bin,"0111");
                break;
            case '8':
                strcat(bin,"1000");
                break;
            case '9':
                strcat(bin,"1001");
                break;
            case 'a':
                strcat(bin,"1010");
                break;
            case 'b':
                strcat(bin,"1011");
                break;
            case 'c':
                strcat(bin,"1100");
                break;
            case 'd':
                strcat(bin,"1101");
                break;
            case 'e':
                strcat(bin,"1110");
                break;
            case 'f':
                strcat(bin,"1111");
                break;
            default:
                printf("digite um valor valido\n");        
        }
        count++;
    }
    /*printf("valor hex: %s\n", addr);
    printf("%s\n",bin);*/
    return bin;
}

void salvarDebug(FILE *f, int s, int tamPag, int nPag, const char *bin,  long int binint, unsigned addr, char *addr2, unsigned addrR){
    fprintf(f, "\n");
    fprintf(f, "s: %d\n", s);
    fprintf(f, "tampag: %d\n",tamPag);
    fprintf(f, "npag: %d\n", nPag); 
    fprintf(f, "endereco em bin: %s\n", bin);
    fprintf(f, "endereco Real: %d\n", addrR);
    fprintf(f, "endereco HEX: %x\n", addr);
    fprintf(f, "addr int: %lu\naddr: %s\n", binint, addr2);
    fprintf(f, "\n");  
}
