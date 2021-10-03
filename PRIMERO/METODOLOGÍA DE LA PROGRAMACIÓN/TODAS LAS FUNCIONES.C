//		PRACTICA 1	 		PRACTICA 1	 		PRACTICA 1	 		PRACTICA 1	 		PRACTICA 1	 		PRACTICA 1	 		PRACTICA 1	 

int minimo(int num1,int num2){
	if(num1<num2){
		return num1;
	}
	else return num2;
}

void minimo_referencia(int num1,int num2,int *resultado){
	/*if(num1<num2){
		*resultado=num1;
	}
	else *resultado=num2;*/
	*resultado=minimo(num1,num2);
}

void estadisticasVector(int v[],int n,float *media,float *varianza,float *desvtipica){
	int i;
	float suma=0;
//MEDIA
	for(i=0;i<n;i++){
		suma+=v[i];
	}
	*media=suma/n;
	suma=0;
//VARIANZA
	for(i=0;i<n;i++){
		suma+=pow((v[i]-*media),2);
	}
	*varianza=suma/n;
//DESVIACIÓN TIPICA
	*desvtipica=sqrt(*varianza);


}

void estadisticasCadena(char cadena[], int *digitos, int *mayusculas, int *minusculas, int *espacios){
/*	int i,cont=0;
	for(i=0;cadena[i]!='\0';i++){
		if(isdigit(cadena[i])){
			cont++;
		}
	}
	*digitos=cont;
	cont=0;

	for(i=0;cadena[i]!='\0';i++){
		if(isupper(cadena[i])){
			cont++;
		}
	}
	*mayusculas=cont;
	cont=0;

	for(i=0;cadena[i]!='\0';i++){
		if(islower(cadena[i])){
			cont++;
		}
	}
	*minusculas=cont;
	cont=0;

	for(i=0;cadena[i]!='\0';i++){
		if(isspace(cadena[i])){
			cont++;
		}
	}
	*espacios=cont;
*/
	int i;
	
	*digitos=0;
	*mayusculas=0;
	*minusculas=0;
	*espacios=0;

	for(i=0;cadena[i]!='\0';i++){
		if(isdigit(cadena[i])){
			(*digitos)++;
		}
		if(isupper(cadena[i])){
			(*mayusculas)++;
		}
		if(islower(cadena[i])){
			(*minusculas)++;
		}
		if(isspace(cadena[i])){
			(*espacios)++;
		}
	}
}

void leeVector(double v[],int n){
	printf("Introduce los datos de tu vector:");
	for(int i=0;i<n;i++){
	scanf(" %lf ",&v[i]);
	}
}

void escribeVector(double v[],int n){
	printf("\nEstos son los datos de tu vector:");
for(int i=0;i<n;i++){
	printf(" %lf ",v[i]);
	}
		printf("\n");
}


void sumapositivos(double v[],int n,double *resultado){
*resultado=0;
	for(int i=0;i<n;i++){
		if(v[i]>0){
			(*resultado)+=v[i];
		}
	}
}

int es_prefijo(char *cadena, char*prefijo){
	char *pos=strstr(cadena, prefijo);
	int i,size_pref=strlen(prefijo);
	if(pos!=NULL){
		for(i=0; i<size_pref;i++){
			if(cadena[i]!=prefijo[i]){
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

int es_sufijo(char *cadena, char* sufijo){
	int i, size_suf=strlen(sufijo), size_cad=strlen(cadena);
	char *pos=strstr(cadena, sufijo);
	if(pos!=NULL){
		for(i=(size_cad);i>(size_cad-size_suf);i--){
			if(cadena[i]!=sufijo[i-(size_cad-size_suf)]){
				return 0;
			}
			return 1;
		}
		return 0;
	}
}

void rellenarVectorAleatorio (int v[],int n,int rango){
	time_t t;
	srand((int)time(&t));
	for(int i=0;i<n;i++){
		v[i]=rand()%(rango+1);
	}
}

void imprimirVector(int v[], int n){
	printf("El vector es:\n");
	for(int i=0;i<n;i++){
		printf("v[%d]= %d\n",i,v[i]);
	}
}

void crearIndiceImpares(int v[],int **ind, int n, int *nindice){
	int i;
	*nindice=0;
	for(i=0;i<n;i++){
		if(v[i]%2!=0){
			ind[*nindice]=&v[i];
			(*nindice)++;
		}
	}
}

void crearIndiceDivisibles(int v[], int *ind[] ,int n,int *nindice){
	int i;
	*nindice=0;
	for(i=0;i<n;i++){
		if(v[i]%3==0){
			ind[*nindice]=&v[i];
			(*nindice)++;
		}
	}
}

void imprimeIndices(int *ind[],int nindice){
	printf("Los indices son:\n");
	int i;
	for (i=0;i<nindice;i++){
		printf("ind[%d]= %d\n",i,*(ind[i]));
	}
}


//		PRACTICA 2	 		PRACTICA 2	 		PRACTICA 2	 		PRACTICA 2	 		PRACTICA 2	 		PRACTICA 2	 		PRACTICA 2	 


int * reservaVector(int n){
	int *v;
	if((v=(int *)malloc(sizeof(int)*n))==NULL){
		printf("Error reserva");
	}
	return v;
}

void imprimeVector(int *v, int n){
	
	for(int i=0; i<n;i++){
	printf("%d ",v[i] );
	}
	printf("\n");
}

void separarVector(int *v, int n, int num,int **vmin, int **vmay, int *tam1, int *tam2){
	*tam1=0;
	*tam2=0;
	for(int i=0;i<n;i++){
		if(v[i]>=num){
			(*tam1)++;
		}
		else {
			(*tam2)++;
		}
	}
	*vmin=reservaVector(*tam2);
	*vmay=reservaVector(*tam1);

	int contmin=0;
	int contmay=0;

	for(int i=0;i<n;i++){
			if(v[i]<num){
				(*vmin)[contmin]=v[i];
				contmin++;
			}
			else{
				(*vmay)[contmay]=v[i];
				contmay++;
			}

	}

}

int ** reservarMemoria (int nFil, int nCol){
	int**matriz;
	int i,error=0;
	matriz=(int**)malloc(nFil*sizeof(int*));
	if(matriz==NULL){
		printf("\nError en la reserva memoria");
	}
	for(i=0;i<nFil;i++){
		matriz[i]=(int*)malloc(nCol*sizeof(int));

		if(matriz[i]==NULL){
				printf("\nError en la reserva memoria");
		}
	}
return (matriz);
}

void rellenaMatriz (int **matriz, int nFil, int nCol){
	time_t t;
	srand((int)time(&t));
	for(int i=0;i<nFil;i++){
		for(int j=0;j<nCol;j++){
			matriz[i][j]=rand()%20+1;
		}
	}
}

void imprimeMatriz (int **matriz, int nFil, int nCol){
	printf("\nTu matriz es:");
	for(int i=0;i<nFil;i++){
		printf("\n");
		for(int j=0;j<nCol;j++){
			printf("%d ",matriz[i][j]);
		}
	}
}

int * minCol (int **matriz, int nFil, int nCol){
	int *v;
	int i,j;

	v=(int*)calloc(nCol,sizeof(int));
	if (v==NULL)printf("ERROR");

	for(j=0;j<nCol;j++){
		v[j]=matriz[0][j];
		for(i=0;i<nFil;i++){
			if(matriz[i][j]<v[j]){
				v[j]=matriz[i][j];
		}
	}
}

	printf("\nEl vector minimo es:\n");
	for(int i=0; i<nCol;i++){
		printf("%d ",v[i]);
	}
	printf("\n");

	return (v);
}


void liberarMemoria(int ***matriz, int nFil){
	for(int i=0;i<nFil;i++){
		free(**matriz);
	}
	free(*matriz);
	(*matriz)=NULL;
}



int **multiplicarMxM(int **matriz1,int **matriz2,int nFil1, int nCol1,int nCol2){
	int **mres;
	for(int i=0;i<nFil1;i++){
		for(int j=0;j<nCol2;j++){
			mres[i][j]=0;
			for(int k=0;k<nCol1;k++){
				mres[i][j]=mres[i][j]+matriz1[i][k]*matriz2[k][i];
			}
		}

	}
	return (mres);
}

// DOXYGEN   DOXYGEN   DOXYGEN   DOXYGEN   DOXYGEN   DOXYGEN   DOXYGEN   DOXYGEN   DOXYGEN   DOXYGEN   DOXYGEN   DOXYGEN   DOXYGEN   DOXYGEN


/**																							¡¡ .h !!
@file ej6.h
@version 1.0
@author Alvaro Roldan L.
@date 11/04/2020
@brief Cabeceras funciones ej6.c
*/


/**																							¡¡ FUNCIONES !!
@date 11/04/2020
@author Alvaro Roldan L.
@fn reservarMemoria (int nFil, int nCol) Reserva memoria de una matriz 
@param nFil Numero de filas
@param nCol Numero de columnas
@return Matriz con memoria reservada
*/


/**																							¡¡ MAIN !!
@file ej6main.c
@version 1.0
@author Alvaro Roldan L.
@date 11/04/2020
@brief Programa rellena un vector con los numeros menores de las columnas de una matriz generada aleatoriamente.
*/

/** 																						¡¡ PLANTILLA !!
	@fn 	    Prototipo de la función
	@brief      Descripción breve de la función	
 	@param      parámetro 1 tipo y significado
 	...
 	@param      parámetro n tipo y significado
	@return     tipo de resultado
	@pre        precondición de la función
	@post       postcondición de la función					
	@warning    Aviso muy importante										(opcional)
	@attention  Aviso importante											(opcional)
	@note       Aviso														(opcional)
	@exception  Descripción de la excepción que se puede producir			(opcional)
	@sa         See also (véase también) otras funciones o tipos de datos	(opcional)
	@version    Descripción de la versión o de los cambios realizados		(opcional)
	@date       Fecha de la última modificación								(opcional)
	@author	    Nombre de la persona que ha escrito la función				(opcional)
	@todo       Trabajo pendiente de realizar     							(opcional)
*/



//	TERMINAL	TERMINAL	TERMINAL	TERMINAL	TERMINAL	TERMINAL	TERMINAL	TERMINAL	TERMINAL	TERMINAL	TERMINAL	TERMINAL	TERMINAL

/*

MOVERSE TERMINAL
cd *sitio*			ir a una carpeta
cd .. 				retroceder
ls 					ver elemntos de la carpeta


COMPILAR
1. gcc ej1.c -o ej1.exe
2. ./ej1

1.(error compilar) gcc -g ej1.c -o ej1.exe
2. gdb ej1.exe
-run
-bt
-quit (y)


LIBRERÍAS Y ENLAZAR
1. gcc -c *.c (crea .o con cada .c)
2. ar -rsv libCaso1.a operaciones.o suma.o … (crea librería)
3. gcc -o main.exe main.o libCaso1.a (programa a crear, main.o, librería)