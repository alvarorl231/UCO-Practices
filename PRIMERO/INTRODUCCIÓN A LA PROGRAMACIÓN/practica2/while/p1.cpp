#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n,ncopia;
	float suma=0,aux;
	cout<<"Introduzca el numero de valores a introducir"<<endl;
	cin>>n;
	ncopia=n;
	while(n>0){
		cout<<"Introduzca dato"<<endl;
		cin>>aux;
		suma=suma+aux;
		n=n-1;		
	};
	cout<<"La media es "<< ( suma/ncopia ) <<endl;
	system("pause");
}
