#include "ej8.h"

// OPCION 3
int cuentalibros(char *fichero){
	FILE *f;
	if(f==NULL){
		printf("ERROR AL ABRIR EL FICHERO <%s>",fichero);
	}
	char titulo[MAX];
	int nlibros=0,cont=0;
	f=fopen(fichero,"r");
	while(fgets(titulo,MAX,f)!=NULL){
		if(titulo[strlen(titulo)-1]=='\n'){
			titulo[strlen(titulo)-1]='\0';
			cont++;
		}
	}

	nlibros=cont/3;

	fclose(f);
	return(nlibros);
}


//OPCION 4
void listarlibros(int n,Libro *lista){
	for(int i=0;i<n;i++){
		printf("Titulo: %s\n",lista[i].titulo);
		printf("Autor: %s\n",lista[i].autor);
 		printf("Precio: %f\n",lista[i].precio);
 		printf("Unidades: %d\n",lista[i].unidades);
 		printf("\n");
	}
}

//RESERVA VECTOR DINAMICO
Libro *reservarvector(int n){
Libro *v;
if((v=(Libro*)malloc(n*sizeof(Libro)))==NULL){
		printf("ERROR AL RESERVAR MEMEORIA VECTOR\n");
	}
}


//RELLENA EL VECTOR DINAMICO
void rellenavector(char *fichero,int n,Libro *lista){
	FILE *f;
if((f=fopen(fichero,"r"))==NULL){
	printf("ERROR AL ABRIR EL FICHEROo <%s>\n",fichero);
	exit(-1);
}

char linea[MAX];
float pre;
int uds;
int i=0;
	while(fgets(linea,MAX,f)!=NULL){
			strcpy(lista[i].titulo,linea);
			lista[i].titulo[strlen(lista[i].titulo)-1]='\0';


		fgets(linea,MAX,f);
			strcpy(lista[i].autor,linea);
			lista[i].autor[strlen(lista[i].autor)-1]='\0';


		fscanf(f,"%f %d",&pre,&uds);
			lista[i].precio=pre;
			lista[i].unidades=uds;
		fgets(linea,MAX,f);
		i++;
	}
  fclose(f);
}


//OPCION 5
void vendelibros(int n,Libro *lista,char *fichero){
		int j;
	j=compruebaexistencia(n,lista);

	float precio;

	if(j!=-12){
		int selec;
		printf("Cuantas unidades desea comprar? ");
		fflush(stdin);
		scanf("%d",&selec);
		float pre;

if((selec)>(lista[j].unidades)){
        printf("En el stock hay solo %d.\n",lista[j].unidades);
        pre=(lista[j].precio)*((float)selec);
        printf(" %d vendidos de %s por %f euros.",lista[j].unidades,lista[j].titulo,pre);
        printf("El stock pasa a ser 0.");
        lista[j].unidades=0;
        }
    else if(selec<=0){
		printf("Error debe ser un numero mayor de 0.\n");
		printf("Cuantas unidades desea comprar? ");
		scanf("%d",&selec);
	}
    else{
        (lista[j].unidades)=(lista[j].unidades)-selec;
        pre=(lista[j].precio)*((float)selec);
        printf("Se han vendido %d libros de %s por %f euros.\n",selec,lista[j].titulo,pre);
        printf("El stock pasa a ser de %d libros.\n",(lista[j].unidades));
    }

		FILE* fmod;

		if((fmod=fopen(fichero,"w"))==NULL){
			printf("ERROR AL ABRIR EL FICHERO <%S>\n",fichero);
			exit(-1);
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
}


//OPCION 6
void borrarregistro(char *fichero,int n,Libro *lista){
	FILE *fmod;

	if((fmod=fopen(fichero,"w"))==NULL){
		printf("ERROR AL ABRIR EL FICHEROo");
	}

		for(int i=0;i<n;i++){
			if(lista[i].unidades!=0){
				fputs(lista[i].titulo,fmod);
				fputc('\n',fmod);
				fputs(lista[i].autor,fmod);
				fputc('\n',fmod);
				fprintf(fmod,"%f %d\n",lista[i].precio,lista[i].unidades);
			}
		}
	
fclose(fmod);
}