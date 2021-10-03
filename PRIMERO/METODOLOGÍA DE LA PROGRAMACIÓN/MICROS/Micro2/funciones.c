#include "funciones.h"

int nAlumnos(char *fichero){

	FILE *f;
	if((f=fopen(fichero,"r"))==NULL){
		printf("ERROR AL ABRIR EL FICHERO <%s>",fichero);
		exit(-1);
	}

char linea[MAX];
int cont=0;

	while(fgets(linea,MAX,f)!=NULL){
		cont++;
	}

fclose(f);
return cont/2;
}

Alumno *reservarvectorA(int n){
Alumno *v;
if((v=(Alumno*)malloc(n*sizeof(Alumno)))==NULL){
		printf("ERROR AL RESERVAR MEMEORIA VECTOR\n");
	}

return v;

}

Nota *reservarvectorN(int n){
Nota *v;
if((v=(Nota*)malloc(n*sizeof(Nota)))==NULL){
		printf("ERROR AL RESERVAR MEMEORIA VECTOR\n");
	}

return v;

}

void rellenavector(char *ficheroN,char *ficheroA,int n,Alumno *lista,Nota *nota){
	FILE *fnotas;
if((fnotas=fopen(ficheroN,"r"))==NULL){
	printf("ERROR AL ABRIR EL FICHEROo <%s>\n",ficheroN);
	exit(-1);
}

	FILE *falumnos;
if((falumnos=fopen(ficheroA,"r"))==NULL){
	printf("ERROR AL ABRIR EL FICHEROo <%s>\n",ficheroA);
	exit(-1);
}

char linea[MAX];
long dni;
float notas1,notas2,notas3;
int i=0;

	while(fscanf(fnotas,"%ld %f %f %f",&dni,&notas1,&notas2,&notas3)!=EOF){
			nota[i].dni=dni;
			nota[i].nota1=notas1;
			nota[i].nota2=notas2;
			nota[i].nota3=notas3;
			i++;
}

i=0;
	while(fgets(linea,MAX,falumnos)!=NULL){
			strcpy(lista[i].nomyapell,linea);
			lista[i].nomyapell[strlen(lista[i].nomyapell)-1]='\0';

		fscanf(falumnos,"%ld",&dni);
			lista[i].dni=dni;
		i++;
		fgets(linea,MAX,falumnos);
}

  fclose(fnotas);
  fclose(falumnos);

  	for(int i=0;i<n;i++){
		printf("FICHERO NOTAS: %ld,%f,%f,%f.\n",nota[i].dni,nota[i].nota1,nota[i].nota2,nota[i].nota3);
		printf("fichero alumnos: %s,%ld.\n",lista[i].nomyapell,lista[i].dni);
 		printf("\n");
	}

fclose(fnotas);
fclose(falumnos);

}

void mediaAlumnosFichero(char *fichero,int n,Alumno *lista,Nota *nota){

	FILE *f;
	if((f=fopen(fichero,"w"))==NULL){
		printf("ERROR AL ABRIR EL FICHERO <%s>",fichero);
		exit(-1);
	}

float suma=0;
int cont=0;

	for(int i=0;i<n;i++){
		suma+=nota[i].nota1;
		suma+=nota[i].nota2;
		suma+=nota[i].nota3;
		nota[i].med=suma/3;
		suma=0;
		printf("Media %d = %f\n",i,nota[i].med);
	}

	for(int i=0;i<n;i++){
		fprintf(f,"%ld <",lista[i].dni);
		fputs(lista[i].nomyapell,f);
		fprintf(f,"> %f\n",nota[i].med);
	}

fclose(f);

}