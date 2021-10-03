#ifndef __EJ8__
#define __EJ8__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 256

struct Libro{
	char titulo[MAX];
	char autor[MAX];
	float precio;
	int unidades;	
};

 typedef struct Libro Libro;

//MENU
int menu(int menu);
//OPCION 1
int compruebaexistencia(int n,Libro *lista);
//OPCION 2
void introducirlibro(int n,Libro *lista,char *fichero,Libro lib);
//OPCION 3
int cuentalibros(char *fichero);
//OPCION 4 Y AUXILIAR
void listarlibros(int n,Libro *lista);
Libro *reservarvector(int n);
void rellenavector(char *fichero,int n,Libro *lista);
//OPCION 5
void vendelibros(int n,Libro *lista,char *fichero);
//OPCION 6
void borrarregistro(char *fichero,int n,Libro *lista);

#endif