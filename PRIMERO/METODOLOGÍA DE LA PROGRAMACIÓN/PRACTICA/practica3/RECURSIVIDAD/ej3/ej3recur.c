#include "ej3recur.h"

int cuentaX(char cad[],char x[],int tam){

if(tam==0){
	if(cad[tam]==x[0]){
		return 1;
	}
	else{
	 return 0;}
}

if(cad[tam]==x[0]){
	return 1+cuentaX(cad,x,tam-1);
}
else{ return 0+cuentaX(cad,x,tam-1);}

}