#makefile

all: tp2virtual.o funcoes.o
	gcc tp2virtual.o funcoes.o -g -W -Wall -ansi -pedantic -o  main 

tp2virtual.o: tp2virtual.c
	gcc -c tp2virtual.c -g -W -Wall -ansi -pedantic

funcoes.o: funcoes.c funcoes.h
	gcc -c funcoes.c -g -W -Wall -ansi -pedantic

clean:
	rm -rf *.o *~ main