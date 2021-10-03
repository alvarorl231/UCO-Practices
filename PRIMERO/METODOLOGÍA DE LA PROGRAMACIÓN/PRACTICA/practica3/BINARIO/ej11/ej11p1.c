#include "ej11.h"

int menu(int menu){
	printf("\n");
	printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
	printf("\n				MENU PRINCIPAL\n");
	printf("\n	1. Comrprobar la existencia de un libro en stock por titulo.\n");
	printf("	2. Intoducir un nuevo libro en el stock.\n");
	printf("	3. Contar el numero de libros diferentes que hay en el stock.\n");
	printf("	4. Listar los libros en el stock.\n");
	printf("	5. Vender unidades de un libro.\n");
	printf("	6. Borrar registros con 0 unidades disponibles.\n");
	printf("	7. Salir.\n");
	printf("\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
	printf("\nElige la opcion que desees: ");
	scanf("%d",&menu);
	getchar();
return(menu);
}

//OPCION 1
int compruebaexistencia(long n,Libro *lista){
	char libnuevo[MAX];
	printf("\nIntroduce el titulo a buscar: ");
	
	fflush(stdin);
	fgets(libnuevo,MAX,stdin);

	int control=0;

	for(int i=0;i<n;i++){
		if((strcmp(libnuevo,lista[i].titulo))==0){
			printf("\nLIBRO ENCONTRADO!!!\n");
			return i;
			control=1;
		}
	}

	if(control==0){
		printf("\nLIBRO NO ENCONTRADO!!!\n");
		return -12;
	}
}


//OPCION 2
void introducirlibro(char *fichero,long n,Libro lib,Libro *lista){

	int j;
	j=compruebaexistencia(n,lista);

	int selec;

	if(j!=-12){
		FILE *f;
		if((f=fopen(fichero,"wb"))==NULL){
			printf("ERROR AL ABRIR EL FICHEROoo <%s>",fichero);
		}

		printf("Cuantas unidades desea agregar al stock? ");
		scanf("%d",&selec);
		getchar();


		if(selec==1){
			lista[j].unidades++;
			printf(" +1 al stock de %s\n",lista[j].titulo);
			fwrite(lista,sizeof(Libro),n,f);
		}

		else if(selec<=0){
			printf("Error debe ser un numero mayor de 0.\n");
		}

	else{
		(lista[j].unidades)+=selec;
		printf(" +%d al stock de %s\n",selec,lista[j].titulo);
		fwrite(lista,sizeof(Libro),n,f);
	}

	fclose(f);
}

	else{	
		FILE *f;
		if((f=fopen(fichero,"ab"))==NULL){
			printf("ERROR AL ABRIR EL FICHEROoo <%s>",fichero);
		}

		printf("Introduce el titulo del libro: ");
			fgets(lib.titulo,MAX,stdin);
		printf("Introduce el autor del libro: ");
   			fgets(lib.autor,MAX,stdin);
		printf("Introduce el precio y unidades del libro: ");
			fscanf(stdin,"%f %d",&lib.precio,&lib.unidades);

		fwrite(&lib,sizeof(Libro),1,f);

		fclose(f);
	}
}


// OPCION 3
long cuentalibros(char *fichero){
	FILE *f;
	long nlibros;
	if((f=fopen(fichero,"rb"))==NULL){
		printf("ERROR AL ABRIR EL FICHERO <%s>",fichero);
		exit(-1);
	}

	fseek(f,0L,SEEK_END); //Se va al final del fichero

	nlibros=ftell(f)/sizeof(Libro);  //ftell cuenta el numero de bytes desde el principio hasta el final

	fclose(f);
	return(nlibros);
}

//OPCION 4
void listarlibros(long n,Libro *lista){
	for(int i=0;i<n;i++){
		printf("Titulo: %s",lista[i].titulo);
		printf("Autor: %s",lista[i].autor);
 		printf("Precio: %f\n",lista[i].precio);
 		printf("Unidades: %d\n",lista[i].unidades);
 		printf("\n");
	}
}