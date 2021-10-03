#include "ej1.h"

double fx (int x){
	return 3*exp(x)-2*x; 
}

double gx (int x){
	return -x*sin(x)+1.5;
}

double zx (int x){
	return pow(x,3)-2*x+1;
}


double ValorMedio(int n, double (*eleccion)(int)){
	double val=0;
	double sustituciones=n/0.2;

	for(double i=0; i<n;i=i+0.2){
		val=val+(*eleccion)(i);
	}

	return val/sustituciones;
}