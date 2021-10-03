//	PRACTICA 3	PRACTICA 3	PRACTICA 3	PRACTICA 3	PRACTICA 3	PRACTICA 3	PRACTICA 3	PRACTICA 3	PRACTICA 3//


//	FICHEROS DE TEXTO	//	FICHEROS DE TEXTO	//	FICHEROS DE TEXTO //

//ABRIR FICHEROS

FILE *fich;

if ((fich=fopen(fichero,"r"))==NULL){
		printf("ERROR AL ABRIR EL FICHERO <%s>\n",fichero);
	}

fclose(fich);


//BUCLE LETRA A LETRA 	(ej5bien)
char aux,letra;

aux=fgetc(fich_entrada);

while(aux!=EOF){
	letra=toupper(aux);				//Funcion que hace mayuculas
	fputc(letra,fich_mayuscula);	//Pone letra en fichero
	aux=fgetc(fich_entrada);		//Coge la siguiente letra del bucle
}


//GENERAR ALEATORIOS 	(ej6bien)
int generarAleatorios(int sup,int inf){		//USAR LIBRERIA <time.h>
	return (rand()%(sup-inf+1)+(inf));		//Usar una vez
}

		//Para implemetarlo (1º)
		time_t t;
		srand((int)time(&t));
		//Despues se llamaría a generarAleatorios (2º)


		//PARA GENERARLOS EN UN VECTOR (ej9)
		time_t t;
		srand((int)time(&t));

		for(int i=0;i<num;i++){
			vec[i]=rand()%(sup-inf+1)+(inf);
		}


// ATOI // ATOF // ATOL (ej6bien)
int n=atoi(cadena[1]);
float inf=atof(cadena[2]);
long sup=atol(cadena[3]);


//MEDIA NUMEROS PARES DE UN FICHERO YA DADO (ej7bien)
	char linea[256];
	float aux,suma=0;
	int cont=0;

while(fgets(linea,256,fichero)!=NULL){ 		//Va de linea en linea
		
		fscanf(fichero,"%f",&aux);			//Recoge el numeros

		if((int)aux%2==0){					//Hace que aux tome ints
			suma+=aux;						//Realiza la suma
			cont++;							//Contador aumenta
		}
	}

	float media;

	return media=suma/cont;				


//EJERCIO 8 MIRAR BIEN !!!





//	FICHEROS DE BINARIO	//	FICHEROS DE BINARIO	//	FICHEROS DE BINARIO//

//Crear fichero con datos de un vector 	(ej9bien)
void creabinario(int n){
FILE *fichero;

if((fichero=fopen("nombre.bin","wb"))==NULL){
		printf("ERROR AL ABRIR EL FICHERO <%S>\n",fichero);
}

int *vector=aleatorios(dato); //rellena el vector con aleatorios

fwrite(vector,sizeof(int),n,fichero); //FWRITE ESCRIBE TODO HASTA N EN EL FICHERO

fclose(fichero);
}


//RESERVAR VECTOR (ej10)
int *reservavector(int n){
int *v;
	if((v=(int*)malloc(n*sizeof(int)))==NULL){
		printf("ERROR AL RESERVAR MEMORIA\n");
		exit(-1);
	}
return v;
}


//Cuenta los datos de un fichero (numeros) 	(ej10)
int cont=0;
while(fread(&numero,sizeof(int),1,f)==1){
	cont++;
}


//rellenar el vector 	(ej10)
fread(v,sizeof(int),n,f);

//EJ11 MIRAR!!