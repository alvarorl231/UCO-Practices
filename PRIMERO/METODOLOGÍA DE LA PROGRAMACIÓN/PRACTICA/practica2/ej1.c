1. Supón una matriz dinámica (float ** tabla) de 2x3 elementos, con los siguientes valores.
{ {1.1, 1.2, 1.3}, {2.1.,2.2, 2.3}}
● ¿Cual es el significado de tabla? 			//Direccion del puntero apunta *(tabla)
● ¿Cual es el significado de (tabla+1)?			//Direccion del puntero apunta *(tabla+1)
● ¿Cual es el significado de *(tabla+1)?		//Direccion del puntero apunta 1x0
● ¿Cual es el significado de (*(tabla+1)+1)?	//Direccion del puntero apunta 1x1
● ¿Cual es el significado de (*(tabla)+1)?		//Direccion del puntero apunta 0x1
● ¿Cual es el valor de *(*(tabla+1)+1)?			//2.2
● ¿Cual es el valor de *(*(tabla)+1)?			//1.2
● ¿Cual es el valor de *(*(tabla+1))?			//2.1