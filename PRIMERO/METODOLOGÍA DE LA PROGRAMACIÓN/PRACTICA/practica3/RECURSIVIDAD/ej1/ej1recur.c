#include "ej1recur.h"

int EuclidesMCD(int x,int y){
	if (y==0){
		return x;
	}
	else if((y>0)||(x>=y)){
		return EuclidesMCD(y,(x%y));
	}
}
