#include "ej4ficheros.h"

int main(){
	char ficheroEntrada[256];
	char ficheroSalida[256]="mayusculas_";

	FILE *f_entrada, *f_salida;

	char letra, mayus;

	printf("Introduce el nombre del fichero a convertir: ");
	scanf("%s",ficheroEntrada);

	//Creamos el nombre del fichero de salida
	strcat(ficheroSalida,ficheroEntrada);

	printf("El nombre del fichero de salida es: %s\n",ficheroSalida);

	//Abrir fichero y comrpobar ficheros están abiertos
	f_entrada=fopen(ficheroEntrada,"r");
	if(f_entrada==NULL){
		printf("No se ha podido abrir el fichero %s\n",ficheroEntrada);
		exit(-1);
	}

	f_salida=fopen(ficheroSalida,"w");
	if(f_salida==NULL){
		printf("No se ha podido abrir el fichero %s\n",ficheroSalida);
		exit(-1);
	}



	//Procesamiento
	letra=fgetc(f_entrada);
	while(letra!=EOF){
		//Convertir en mayusculas
		mayus=toupper(letra);
		//Escribirlo en el fichero de salida
		fputc(mayus,f_salida);

		//Leemos siguiente caracater
		letra=fgetc(f_entrada);
	}

	
	//Cerrar el fichero
	fclose(f_entrada);
	fclose(f_salida);


	return 0;
}
