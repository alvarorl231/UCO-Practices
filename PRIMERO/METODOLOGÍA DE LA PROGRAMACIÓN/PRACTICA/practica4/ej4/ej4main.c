#include "ej4.h"

int main(){
	int opcion,exp,n;
	Lista *cabeza=NULL;
	float coef,cont=0;

	do{
		printf("\nINTRODUCE UNA OPCION: \n");
		printf("1. Crear un polinomio.\n");
		printf("2. Mostrar polinomio.\n");
		printf("3. Evaluar polinomio.\n");
		printf("4. Borrar polinomio.\n");
		printf("5. Comprobar existencia.\n");
		printf("Para salir, inserte cualquier otro numero.\n");
		scanf("%d",&opcion);

		switch(opcion){
			case 1:{
				printf("Cuantos monomios quieres que tenga el polinomio?\n");
				scanf("%d",&n);
				for(int i=0;i<n;i++){
					printf("Insertar un coeficiente: ");
					scanf("%f",&coef);
					printf("Insertar el exponente: ");
					scanf("%d",&exp);
					anyadeMonomio(&cabeza,coef,exp);
				}
				break;
			};
			case 2:{
				printf("P(x)=");
				muestraPolinomio(cabeza,n);
				printf("\n");
				break;
			};
			case 3:{
				while(cont<=5){
					printf("|x=%f, %f|\n",cont,evaluaPolinomio(cabeza,cont));
					cont=cont+0.5;
				}
				break;
			};
			case 4:{
				printf("Inserte el coeficiente del monomio a borrar: ");
				scanf("%f",&coef);
				printf("Inserte el exponente del monomio a borrar: ");
				scanf("%d",&exp);
				eliminaMonomio(&cabeza,coef,exp);
				n--;
				break;
			};
			case 5:{
				printf("Inserte el coeficiente del monomio a buscar: ");
				scanf("%f",&coef);
				printf("Inserte el exponente del monomio a buscar: ");
				scanf("%d",&exp);
				int res;
				res=contiene(cabeza,coef,exp);
				if(res==1){
					printf("Existe el polinmio:\n");
					printf("P(x)=");
					muestraPolinomio(cabeza,n);
				}
				else{
					printf("No existe el ponimonio.\n");
				}
				break;
			};
			default:{
				printf("Hasta pronto!\n");
				exit(-1);
			};
		}
	}
	
	while((opcion>0)&&(opcion<6));

	return 0;
}