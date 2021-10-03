#include <stdio.h>
#include <string.h>
#include "ej11.h"


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