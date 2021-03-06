#INCLUDE "EJ4FICHEROS.H"

INT MAIN(){
	CHAR FICHEROENTRADA[256];
	CHAR FICHEROSALIDA[256]="MAYUSCULAS_";

	FILE *F_ENTRADA, *F_SALIDA;

	CHAR LETRA, MAYUS;

	PRINTF("INTRODUCE EL NOMBRE DEL FICHERO A CONVERTIR: ");
	SCANF("%S",FICHEROENTRADA);

	//CREAMOS EL NOMBRE DEL FICHERO DE SALIDA
	STRCAT(FICHEROSALIDA,FICHEROENTRADA);

	PRINTF("EL NOMBRE DEL FICHERO DE SALIDA ES: %S\N",FICHEROSALIDA);

	//ABRIR FICHERO Y COMRPOBAR FICHEROS ESTáN ABIERTOS
	F_ENTRADA=FOPEN(FICHEROENTRADA,"R");
	IF(F_ENTRADA==NULL){
		PRINTF("NO SE HA PODIDO ABRIR EL FICHERO %S\N",FICHEROENTRADA);
		EXIT(-1);
	}

	F_SALIDA=FOPEN(FICHEROSALIDA,"W");
	IF(F_SALIDA==NULL){
		PRINTF("NO SE HA PODIDO ABRIR EL FICHERO %S\N",FICHEROSALIDA);
		EXIT(-1);
	}



	//PROCESAMIENTO
	LETRA=FGETC(F_ENTRADA);
	WHILE(LETRA!=EOF){
		//CONVERTIR EN MAYUSCULAS
		MAYUS=TOUPPER(LETRA);
		//ESCRIBIRLO EN EL FICHERO DE SALIDA
		FPUTC(MAYUS,F_SALIDA);

		//LEEMOS SIGUIENTE CARACATER
		LETRA=FGETC(F_ENTRADA);
	}

	
	//CERRAR EL FICHERO
	FCLOSE(F_ENTRADA);
	FCLOSE(F_SALIDA);


	RETURN 0;
}
