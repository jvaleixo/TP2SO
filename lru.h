#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

#ifndef _H_LRU
#define _H_LRU

lru();
void insereFrame(LFrame *fr, Page *p);
LFrame* criaFrame();
Page* criaPage(const char *addr, int timer);
typedef struct LFrame;
typedef struct LPage;
#endif