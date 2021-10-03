#include "ej2.h"

int main(int argc,char **argv){
	if(argc<2){
		printf("ERROR, NECESITAS INTRODUCIR EL NOMBRE DE TU FICHERO.");
		exit(-1);
	}

int n;
n=cuentaAlumnos(argv[1]);
printf("%d\n",n);

Alumno *vector;
vector=reservaVector(n);
rellenaVector(argv[1],n,vector);
listarAlumno(n,vector);

int opcion;
printf("¿Como desea ordenar el vector?\n");
printf("1. Ascendentemente. 2.Descendentemente:  ");
scanf("%d",&opcion);

//APLICACION PUNTERO A FUNCION
switch(opcion){
	case 1:{
		ordenaBurbuja(n,vector,&ascendente);
		break;
	};
	case 2:{
		ordenaBurbuja(n,vector,&descendente);
		break;
	};
	default:{
		printf("ERROR EN LA SELECCION.\n");
		break;
	};
}


return 0;
}