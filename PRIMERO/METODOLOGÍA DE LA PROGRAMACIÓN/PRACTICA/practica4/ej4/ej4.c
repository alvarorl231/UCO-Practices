#include "ej4.h"

Lista *NuevoElemento(){
	return ((Lista*)malloc(sizeof(Lista)));
}

void anyadeMonomio(Lista **cabeza,float coef,int exp){
	Lista *aux=NULL;
	//RESERVAMOS ESPACIO PARA EL NUEVO ELEMENTO
	aux=NuevoElemento();
	if(aux==NULL){
		printf("ERROR EN LA RESERVA DE MEMORIA\n");
		exit(-1);
	}
	//PONEMOS VALORES DEL NUEVO ELEMENTO
	aux->exp=exp;
	aux->coef=coef;
	//ENLAZAMOS EL NUEVO ELEMENTO A LA CABEZA Y AHORA AUX ES LA NUEVA CABEZA
	aux->siguiente=*cabeza;
	*cabeza=aux;
}

void muestraPolinomio(Lista *cabeza,int n){
	Lista *aux=NULL;
	aux=cabeza;
	int cont=1;
	while(aux!=NULL){
		if(cont<n){
			printf("%fx^%d + ",aux->coef,aux->exp);
			aux=aux->siguiente;
		}
		else{
			printf("%fx^%d",aux->coef,aux->exp);
			aux=aux->siguiente;
		}
		cont++;
	}
}

float evaluaPolinomio(Lista *cabeza,int cont){
	Lista *aux=NULL;
	aux=cabeza;
	float res=0;
	while(aux!=NULL){
		//AQUI VAMOS A SUMAR EL RESULTADO ANTERIOR AL PRODUCTO DEL COEFICIENTE POR EL VALOR DE X Y SU EXPONENTE, EJ: X^Y
		res=res+aux->coef*pow(cont,aux->exp);
		aux=aux->siguiente;
	}
	return res;
}

void eliminaMonomio(Lista **cabeza,float coef, int exp){
	Lista *aux=NULL;		//ALMACENA EL ELEMENTO A BORRAR
	Lista *anterior=NULL;	//ALMACENA EL ELEMENTO ANTERIOR AL QUE SE BORRA
	aux=*cabeza;			//BUSCA EL ELEMENTO A BORRAR
	while((aux->coef!=coef)&&(aux->exp!=exp)){
		anterior=aux;
		aux=aux->siguiente;
	}
	if(aux==*cabeza){	//EL ELEMENTO A BORRAR ES LA CABEZA
		*cabeza=aux->siguiente;		//LA NUEVA CABEZA ES EL SIGUIENTe
		free(aux);		//SE LIBERA LA ANTIGUA CABEZA
	}
	else{		//ELEMENTO A BORRAR NO ES LA CABEZA
		anterior->siguiente=aux->siguiente; //ENLAZAMOS EL ANTERIOR CON EL SIGUIENTE
		free(aux); //SE LIBERA EL NODO A BORRAR
	}
}

int contiene(Lista *cabeza,float coeficiente,int exponente){
	int encontrado=0;
	Lista *aux=NULL;
	aux=cabeza;
	//SE RECORRE LA LISTA HASTA ENCONTRAR EL ELEMENTO O HASTA LLEGAR AL FINAL
	while(aux!=NULL && encontrado==0){
		if((aux->coef==coeficiente)&&(aux->exp==exponente)){
			encontrado=1;
		}
		else{
			aux=aux->siguiente;
		}
	}
	return encontrado;
}