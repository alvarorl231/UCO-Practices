
void *ptr;

case 1:
bucle
	ptr[i]=entero
case 2:
	ptr[i]=cadena caracteres

case 3:
	ptr[i]=struct

return ptr;

int *ptrEnteros=(int *) ptr

//////////////////////////////////////

ordenacion:
	seleccion:


	inserccion:


	burbuja:
/////////////////////////////////////
int f1(int num){
	return num+1;
}
int f2(int num){
	return m+2;
}
int f3(int num, int(*f)(int)){ //Ejecuta la funcion 1 o 2
	return (*f)(num);
}

int main(){
	int (*f)(int);
////// Varias formas
	if(condicion1){
		f=&f1;
	}
	if(condicion2){
		f=&f2;
	}
////// Otra
	f=&f1;
	int num=*f(1);
///// Referido a f3
	int (*f)(int);
	if condicion
		f=&f1
	else
		f=&f2

	int resultado=f3(1,f);
}

////////////////////////////////////////////

ejercicio 1 usar math.h y al compilar -lm

///////////////////////////////////////////

ejercicio 2 hacer makefile y demás