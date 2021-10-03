#include <iostream>
using namespace std;
bool esprimo(int n){
	//prueba si es divisible por los numeros del 2 al n-1
	for(int i=2;i<n;i++){
		if (n%i==0) {//si lo es, terminanos devolviendo falso
			return false;
		}
	}
//si hemos llegado hasta aqui, es que no es divisible por los numeros del 2 al n-1
//por tanto, es primo. Devolvemos true
	return true;
}

int main(){
	int n;
	cout<<"Introduzca el numero"<<endl;
	cin>>n;
	if (n>0){
		if( esprimo(n)==true){
			cout<<"El numero es primo"<<endl;
		}
		else{
			cout<<"El numero No es primo"<<endl;
		}
	}
	else{
		cout<<"Error, el numero debe ser positivo"<<endl;
	}	
}
