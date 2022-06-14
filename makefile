#makefile

all: tp2virtual.o funcoes.o fila.o
	gcc tp2virtual.o funcoes.o -g -W -Wall -ansi -pedantic -o  tp2virtual 

tp2virtual.o: tp2virtual.c
	gcc -c tp2virtual.c -g -W -Wall -ansi -pedantic

funcoes.o: funcoes.c funcoes.h
	gcc -c funcoes.c -g -W -Wall -ansi -pedantic

fila.o: fila.c fila.h
	gcc -c fila.c -g -W -Wall -ansi -pedantic

clean:
	rm -rf *.o *~ tp2virtual