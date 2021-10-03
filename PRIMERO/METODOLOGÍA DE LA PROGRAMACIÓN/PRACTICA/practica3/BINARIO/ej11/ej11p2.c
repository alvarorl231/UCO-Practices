#include "ej11.h"
											//AXULIARES//
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
if((f=fopen(fichero,"rb"))==NULL){
	printf("ERROR AL ABRIR EL FICHEROo <%s>\n",fichero);
	exit(-1);
}

fread(lista,sizeof(Libro),n,f);

  fclose(f);
}
////////////////////////////////////////////////////////////////////////////////////////////////

//OPCION 5
void vendelibros(long n,Libro *lista,char *fichero){
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

		if((fmod=fopen(fichero,"wb"))==NULL){
			printf("ERROR AL ABRIR EL FICHERO <%s>\n",fichero);
			exit(-1);
		}

	fwrite(lista,sizeof(Libro),n,fmod);

fclose(fmod);

	}
}

//OPCION 6
void borrarregistro(char *fichero,long n,Libro *lista){
FILE *f;

	if((f=fopen(fichero,"wb"))==NULL){
		printf("ERROR AL ABRIR EL FICHEROo");
		exit(-1);
	}

		for(int i=0;i<n;i++){
			if(lista[i].unidades!=0){
				fwrite(&(lista[i]),sizeof(Libro),1,f);
			}
		}
	
fclose(f);

}