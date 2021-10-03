#include "ej2.h"

int cuentaAlumnos(char *fichero){
	FILE *f;
	int nalumnos;
	if((f=fopen(fichero,"rb"))==NULL){
		printf("ERROR AL ABRIR EL FICHERO <%s>",fichero);
		exit(-1);
	}

	fseek(f,0L,SEEK_END); //Se va al final del fichero

	nalumnos=ftell(f)/sizeof(Alumno);  //ftell cuenta el numero de bytes desde el principio hasta el final

	fclose(f);
	return(nalumnos);
}


Alumno *reservaVector(int n){
Alumno *v;
if((v=(Alumno*)malloc(n*sizeof(Alumno)))==NULL){
		printf("ERROR AL RESERVAR MEMEORIA VECTOR\n");
	}
}


void rellenaVector(char *fichero,int n,Alumno *vector){
	FILE *f;
if((f=fopen(fichero,"rb"))==NULL){
	printf("ERROR AL ABRIR EL FICHERO <%s>\n",fichero);
	exit(-1);
}

fread(vector,sizeof(Alumno),n,f);

  fclose(f);
}

void listarAlumno(int n,Alumno *vector){
	for(int i=0;i<n;i++){
		printf("Nombre: %s",vector[i].nombre);
		printf("DNI: %s",vector[i].dni);
		printf("Nota: %s",vector[i].nota);
 		printf("\n");
	}
}

//ORDENACION POR METODO DE BURBUJA
void ordenaBurbuja(int n,Alumno *vector,int (*funaux)(int,int)){
	int posicion,aux;
	for(int i=0;i<n-1;i++){
		posicion=i;
		for(int j=i+1;j<n;j++){
			if((*funaux)(vector[j].dni,vector[posicion].dni)){
				posicion=j;
			}
		}
		aux=vector[posicion].dni;
		vector[posicion].dni=vector[i].dni;
		vector[i].dni=aux;
	}
}

int ascendente(int a,int b){
	return a>b;
}

int descendente(int a,int b){
	return a<b;
}