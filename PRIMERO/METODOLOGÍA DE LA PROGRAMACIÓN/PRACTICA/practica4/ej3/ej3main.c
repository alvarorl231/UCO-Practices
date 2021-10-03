int main(){

	struct alumnado *vector;
	int n//cuenta alumnos
	int opcion;
	printf("¿Como desea ordenar el vector?\n");
	printf("1. Por nombre. 2.Por nota:  ");
	scanf("%d",&opcion);

	switch(opcion){
	case 1:{
		qsort(vector,n,sizeof(struct alumnado),&nombre);
		break;
	};
	case 2:{
		qsort(vector,n,sizeof(struct alumnado),&nota);
		break;
	};
	default:{
		printf("ERROR EN LA SELECCION.\n");
		break;
	};
}

}