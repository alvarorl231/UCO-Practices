
all: ej8.exe clean 

ej8.exe: ej8p1.o ej8p2.o ej8main.o
	gcc -o $@ $^ #gcc -o ej8.exe ej8p1.o ej8p2.o ej8main.o

ej8p1.o:ej8p1.c ej8.h
	gcc -c ej8p1.c

ej8p2.o:ej8p2.c ej8.h
	gcc -c ej8p2.c

ej8main.o:ej8main.c ej8.h
	gcc -c ej8main.c

.PHONY:clean

clean:
	@echo Borrando ficheros.o
	rm *.o 		#cuidado con esto que se lia
