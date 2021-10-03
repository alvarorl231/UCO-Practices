#ifndef __MICROS2__
#define __MICROS2__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

struct Alumnos{
	char nomyapell[MAX];
	long dni;
};

struct Notas{
	long dni;
	float nota1;
	float nota2;
	float nota3;
	float med;
};

 typedef struct Alumnos Alumno;
 typedef struct Notas Nota;


int nAlumnos(char *fichero);
Alumno *reservarvectorA(int n);
Nota *reservarvectorN(int n);
void rellenavector(char *ficheroN,char *ficheroA,int n,Alumno *lista,Nota *nota);
void mediaAlumnosFichero(char *fichero,int n,Alumno *lista,Nota *nota);

#endif