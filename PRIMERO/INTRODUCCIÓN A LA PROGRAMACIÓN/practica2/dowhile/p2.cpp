#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n,i=1,suma=0;
	cout<<"Introduzca el n"<<endl;
	cin>>n;
	do{
		suma=suma+i;
		i=i+1;
	}while(i<=n);
	cout<<"El valor final es "<< suma <<endl;
	system("pause");

}
