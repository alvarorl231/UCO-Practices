#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n,i=1,factorial=1;
	cout<<"Introduzca el n"<<endl;
	cin>>n;
	do{
		factorial=factorial*i;
		i=i+1;
	}while(i<=n);
	cout<<"El Factorial es "<< factorial <<endl;
	system("pause");

}
