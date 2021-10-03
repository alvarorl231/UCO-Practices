#include <stdio.h>
#include <string.h>
#include "ej11.h"

int main(){
	if(es_prefijo("prefijo","pref")){
		printf("pref es prefijo de prefijo\n");
	}
	if(!es_prefijo("noprefijo","pref")){
		printf("pref no es prefijo de prefijo\n");
	}
	if(es_sufijo("sufijo","ijo")){
		printf("ijo es sufijo de sufijo\n");
	}
	if(!es_sufijo("sufijono","ijo")){
		printf("ijo no es sufijo de sufijo\n");
	}
	
	return 0;
 	
}