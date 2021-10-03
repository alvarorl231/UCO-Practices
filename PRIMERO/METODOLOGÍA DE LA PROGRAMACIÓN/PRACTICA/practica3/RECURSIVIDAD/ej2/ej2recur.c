#include "ej2recur.h"

int divisionRestas(int dividendo, int divisor){
	if(dividendo<divisor){
		return 0;
	}

	else{

		return 1+divisionRestas((dividendo-divisor),divisor);
	}
}