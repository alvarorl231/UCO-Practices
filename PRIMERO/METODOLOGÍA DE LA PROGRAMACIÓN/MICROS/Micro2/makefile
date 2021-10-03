
all: saludo micro2.exe clean 

saludo:
	@echo Ejecutando el makefile de ALVARO ROLDAN LUCENA

micro2.exe: funciones.o main.o
	gcc -o $@ $^

funciones.o:funciones.c funciones.h
	gcc -c funciones.c

main.o:main.c funciones.h
	gcc -c main.c


.PHONY:clean

clean:
	@del *.o
