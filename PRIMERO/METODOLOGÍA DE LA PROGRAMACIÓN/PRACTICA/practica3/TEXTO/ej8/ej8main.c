#include "ej8.h"

int main(int argc,char** argv){
	if(argc<2){
		printf("ERROR, NECESITAS INTRODUCIR EL NOMBRE DE TU FICHERO.");
		exit(-1);
	}

	int n;
	n=cuentalibros(argv[1]);

	Libro lib;
	Libro *lista;
	lista=reservarvector(n);

	int seleccion=0;
	seleccion=menu(seleccion);	
	int libros;
	switch(seleccion){
	case 1:{
		printf("\nComprobando existencia......\n");
		rellenavector(argv[1],n,lista);
		compruebaexistencia(n,lista);	
		free(lista);
		break;
		};

	case 2:{
		printf("\nProcediendo a introducir su nuevo libro....\n");
		rellenavector(argv[1],n,lista);
		introducirlibro(n,lista,argv[1],lib); 
		free(lista);

		break;
		};

	case 3:{
		printf("\nContando numero de libros....\n");
		libros=cuentalibros(argv[1]);
		printf("Numero de libros en stock: %d\n",libros);
		free(lista);
		break;
		};

	case 4:{
		printf("\nListando libros....\n");
		rellenavector(argv[1],n,lista);
		listarlibros(n,lista); 
		free(lista);
		break;
		};
	case 5:{
		printf("\nAccediendo a la lista de libros....\n");
		rellenavector(argv[1],n,lista);
		vendelibros(n,lista,argv[1]);
		free(lista);
		break;
		};
	case 6:{
		printf("\nBorrando registros....\n");
		rellenavector(argv[1],n,lista);
		borrarregistro(argv[1],n,lista);
		free(lista);
		break;
		};
	case 7:{
		exit(-1); 
		break;
		};
	default:{
		printf("\nError en la seleccion del menu.\n");
		break;
		};
	}

return 0;
}