#include "ej5.h"

void FicheroMayuscula(char *fichero){
	FILE *fich_entrada;
	FILE *fich_mayuscula;

	char nombre[256]="mayuscula-";
	strcat(nombre,fichero);

	fich_entrada=fopen(fichero,"r");
	if (fich_entrada==NULL){
		printf("ERROR AL ABRIR EL FICHERO <%S>\n",fichero);
	}

	fich_mayuscula=fopen(nombre,"w");
	if (fich_entrada==NULL){
		printf("ERROR AL ABRIR EL FICHERO <%S>\n",nombre);
	}


	char aux,letra;

	aux=fgetc(fich_entrada);

	while(aux!=EOF){
		letra=toupper(aux);
		fputc(letra,fich_mayuscula);
		aux=fgetc(fich_entrada);
	}

	fclose(fich_entrada);
	fclose(fich_mayuscula);
}