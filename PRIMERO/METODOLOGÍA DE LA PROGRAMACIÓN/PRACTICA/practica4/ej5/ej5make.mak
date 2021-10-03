
#------- DESTINO SIMBOLICO ---------

all: cucrigrama.exe clean creaDocumentacion

crucigrama.exe: cucrigrama.o main.o ficheros.o libMemoria.a
	gcc -o $@ $^ #gcc -o crucigrama.exe cucrigrama.o main.o ficheros.o libMemoria.a

cucrigrama.o:cucrigrama.c cucrigrama.h
	gcc -c cucrigrama.c

main.o:mian.c crucigrama.h ficheros.h
	gcc -c main.c

ficheros.o:ficheros.c ficheros.h
	gcc -c ficheros.c

libMemoria.a: reservaMenmoria.o libMemoria.o
	ar -rsv $@ $^  #ar -rsv libMemoria.a reservaMenmoria.o libMemoria.o

reservaMenmoria.o: reservaMenmoria.c memoria.h
	gcc -c reservaMenmoria.c

libMemoria.o: libMemoria.c memoria.h
	gcc -c libMemoria.c


.PHONY:clean

clean:
	@echo Borrando ficheros.o
	rm *.o 		#cuidado con esto que se lia

creaDocumentacion:
	@doxygen Doxyfile