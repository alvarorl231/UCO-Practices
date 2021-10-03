#include "ej4ficheros.h"


void ficheroMayusculas(char *ficheroA, char *ficheroB,FILE *f_en,FILE *f_sal){
char let, may;
let=fgetc(f_en);
	while(let!=EOF){
		//Convertir en mayusculas
		may=toupper(let);
		//Escribirlo en el fichero de salida
		fputc(may,f_sal);
		//Leemos siguiente caracater
		let=fgetc(f_en);
	}
}

