#include "funciones.h"

int main(int argc, char **argv){
	if(argc<4){
		printf("ERROR, NECESITAS INTRODUCIR EL NOMBRE DE TU FICHERO NOTAS, ALUMNOS Y FICHERO RESULTADO.\n");
		exit(-1);
	}
	
int n;
n=nAlumnos(argv[2]);
printf("Hay %d alumnos\n",n);

Alumno *lista;
Nota *nota;
lista=reservarvectorA(n);
nota=reservarvectorN(n);
rellenavector(argv[1],argv[2],n,lista,nota);
mediaAlumnosFichero(argv[3],n,lista,nota);
free(lista);
free(nota);

	return 0;
}