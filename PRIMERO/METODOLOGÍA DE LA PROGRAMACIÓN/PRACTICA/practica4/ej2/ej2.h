#ifndef __EJ2__
#define __EJ2__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumnado {
	char nombre[50];
	int dni;
	float nota;
};

typedef struct alumnado Alumno;

int cuentaAlumnos(char *fichero);
Alumno *reservaVector(int n);
void rellenaVector(char *fichero,int n,Alumno *vector);
void listarAlumno(int n,Alumno *vector);
void ordenaBurbuja(int n,Alumno *vector,int (*funaux)(int,int));
int ascendente(int a,int b);
int descendente(int a,int b);

#endif