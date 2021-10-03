PRACTICA 1

EJERCICIO 1: Codifica un programa que utilice la sentencia printf para escribir el tamaño de los tipos de las
siguientes variables:

int a, *b, **c;
double d, *e, **f;
char g, *h, **i;


	- printf("%lu %lu %lu \n",sizeof(a),sizeof(b),sizeof(c));
	- printf("%lu %lu %lu \n",sizeof(d),sizeof(e),sizeof(f));
	- printf("%lu %lu %lu \n",sizeof(g),sizeof(h),sizeof(i));




EJERCICIO 2:Explica el significado de cada una de las siguientes declaraciones, así como el valor inicial que
toman las variables en cada caso:
a) int *px;							Es un puntero con valor incial basura.
b) float a, b; 						A y B enteros de tipo flotante, con capacidad de almacenar decimales, convalor incial basura.
c) float *pa, *pb; 					Dos punteros a float con valor inicial basura.
d) float a=-0.167; 					Un float con valor incial asigando, en este caso -0.167.
e) float *pa =&a; 					Un puntero pa que apunta a un entero a. 
f) char c1, c2, c3; 				Tres variables char, con valor incial basura.
g) char *pcl, *pc2, *pc3 =&cl; 		Tres punteros tipo char, y el ultimo a punta a otro char cl.




EJERCCICO 3: Un programa de C contiene las siguientes sentencias
int i, j = 25;
int *pi, *pj = &i;		//*pj=25;
*pj = j + 5;			//*pj=30;
i = *pj + 5;			//i=35;
pi = pj;				//*pi=30;
*pi = i + j;			//*pi=60;
Si el valor asignado a i empieza en la dirección F9C (hexadecimal) y el valor asignado a j empieza
en FE9 entonces, después de ejecutar todas las sentencias:
a) ¿Qué valor es representado por &i? 							F9C
b) ¿Qué valor es representado por &j?							FE9
c) ¿Qué valor es asignado a pj?									F9C
d) ¿Qué valor es asignado a *pj?								30
e) ¿Qué valor es asignado a i?									35
f) ¿Qué valor es representado por pi?							F9C
g) ¿Qué valor es asignado a *pi?								60	
h) ¿Qué valor es representado por la expresión (*pi + 2)?		62




EJERCICIO 4: Un programa de C contiene las siguientes sentencias
float a = 0.001;
float b = 0.003;
float c, *pa, *pb;
pa = &a;				//*pa=0.001
*pa = 2 * a;			//*pa=0.002
pb = &b;				//*pb=0.003
c = 3 * (*pb + *pa );	//c=0.015
Si el valor asignado a la variable a empieza en la dirección 1130 (hexadecimal) , el valor asignado a
la variable b empieza en 1134, y el valor asignado a la variable c empieza en 1138, entonces, tras
ejecutar todas las sentencias:
a) ¿Qué valor es representado por &a?			1130
b) ¿Qué valor es representado por &b?			1134
c) ¿Qué valor es representado por &c?			1138
d) ¿Qué valor es asignado a pa?					1130
e) ¿Qué valor es representado por *pa?			0.002
f) ¿Qué valor es representado por &(*pa)?		1130
g) ¿Qué valor es asignado a pb?					1134
h) ¿Qué valor es representado por *pb?			0.003
i) ¿Qué valor es asignado a c?					0.015




EJERCICIO 5: Un programa en C contiene la siguiente declaración:
int x[8] = {10, 20, 30, 40, 50, 60, 70, 80};
a) ¿Cuál es el significado de x?				Es un puntero fijo que apunta a x[0].
b) ¿Cuál es el significado de (x + 2) ?			La direccion de memoria x[2]
c) ¿Cuál es el valor de *x?						10
d) ¿Cuál es el valor de (*x+2) ?				12
e) ¿Cuál es el valor de *(x+2)?					30