#ifndef __EJ11__
#define __EJ11__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 256

struct libro {
 char titulo[MAX];
 char autor[MAX];
 float precio;
 int unidades;
};

 typedef struct libro Libro;

//MENU
int menu(int menu);
//OPCION 1
int compruebaexistencia(long n,Libro *lista);
//OPCION 2
void introducirlibro(char *fichero,long n,Libro lib,Libro *lista);
//OPCION 3
long cuentalibros(char *fichero);
//OPCION 4 Y AUXILIAR
void listarlibros(long n,Libro *lista);
Libro *reservarvector(int n);
void rellenavector(char *fichero,int n,Libro *lista);
//OPCION 5
void vendelibros(long n,Libro *lista,char *fichero);
//OPCION 6
void borrarregistro(char *fichero,long n,Libro *lista);

#endif