#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n,ncopia;
	float suma=0,aux;
	cout<<"Introduzca el numero de valores a introducir"<<endl;
	cin>>n;

	for(ncopia=n;n>0;n=n-1)
	{
		cout<<"Introduzca dato"<<endl;
		cin>>aux;
		suma=suma+aux;
	}
	cout<<"La media es "<< ( suma/ncopia ) <<endl;
		system("pause");

}
