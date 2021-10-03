#include "ej8.h"

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
return(menu);
}


// OPCION 1
int compruebaexistencia(int n,Libro *lista){
	char libnuevo[MAX];
	printf("\nIntroduce el titulo a buscar: ");
	
	fflush(stdin);
	fgets(libnuevo,MAX,stdin);
	libnuevo[strlen(libnuevo)-1]='\0';

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


// OPCION 2
void introducirlibro(int n,Libro *lista,char *fichero,Libro lib){

	int j;
	j=compruebaexistencia(n,lista);

	if(j!=-12){

	int selec;
		printf("Cuantas unidades desea agregar al stock? ");

	if(selec==1){
		lista[j].unidades++;
		printf(" +1 al stock de %s\n",lista[j].titulo);
	}

	else if(selec<=0){
		printf("Error debe ser un numero mayor de 0.\n");
	}

	else{
		scanf("%d",&selec);
		(lista[j].unidades)+=selec;
		printf(" +%d al stock de %s\n",selec,lista[j].titulo);
	}

		FILE* fmod;

		if((fmod=fopen(fichero,"w"))==NULL){
			printf("ERROR AL ABRIR EL FICHERO <%S>\n",fichero);
			exit(-1);
			//ABRO Y ESCRIBO EN EL NUEVO
		}



	for(int i=0;i<n;i++){
		fputs(lista[i].titulo,fmod);
		fputc('\n',fmod);
		fputs(lista[i].autor,fmod);
		fputc('\n',fmod);
		fprintf(fmod,"%f %d\n",lista[i].precio,lista[i].unidades);
	}
fclose(fmod);
}

	else{
			FILE *f;
	f=fopen(fichero,"a+");
	if(f==NULL){
		printf("ERROR AL ABRIR EL FICHERO <%s>",fichero);
	}

	fflush(stdin);

	printf("Introduce el titulo del libro: ");
    fgets(lib.titulo,MAX,stdin);
    fputs(lib.titulo,f);

    printf("Introduce el autor del libro: ");
    fgets(lib.autor,MAX,stdin);
	fputs(lib.autor,f);

	printf("Introduce el precio y unidades del libro: ");
    fscanf(stdin,"%f %d",&lib.precio,&lib.unidades);
	fprintf(f,"%f %d",lib.precio,lib.unidades);
	fputc('\n',f);
	fclose(f);
	}
}
