#include "ej1.h"

int main(){
	int n, op;
	double (*elecc)(int);
	
	printf("\nIntroduce el valor del parametro N: ");
	scanf("%d",&n);

	printf("Introduce 1 para f(x), 2 para g(x) y 3 para z(x): ");
	scanf("%d",&op);

	switch(op){
		case 1:{
		elecc=&fx;
		break;
		};
		case 2:{
		elecc=&gx;
		break;
		};
		case 3:{
		elecc=&zx;
		break;
		};
		default:{
		printf("ERROR, debe de introduzca un valor entre 1 y 3.\n");
		exit(-1);
		break;
		};
	}

	double resultado = ValorMedio(n,elecc);
	printf("El valor medio de la funcion escogida es: %f\n",resultado);

	return 0;
}