#makefile

all: tp2virtual.o funcoes.o fila.o lista.o segunda_chance.o
	gcc tp2virtual.o funcoes.o fila.o lista.o segunda_chance.o -g -W -Wall -ansi -pedantic -o tp2virtual

tp2virtual.o: tp2virtual.c segunda_chance.h
	gcc -c tp2virtual.c -g -W -Wall -ansi -pedantic -l c

funcoes.o: funcoes.c funcoes.h
	gcc -c funcoes.c -g -W -Wall -ansi -pedantic

fila.o: fila.c fila.h
	gcc -c fila.c -g -W -Wall -ansi -pedantic

lista.o: lista.c lista.h
	gcc -c lista.c -g -W -Wall -ansi -pedantic

segunda_chance.o: segunda_chance.c segunda_chance.h fila.h lista.h
	gcc -c segunda_chance.c -g -W -Wall -ansi -pedantic

clean:
	rm -rf *.o *~ tp2virtual