#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n,i=1,factorial=1;
	cout<<"Introduzca el n"<<endl;
	cin>>n;
	while(i<=n){
		factorial=factorial*i;
		i=i+1;
	};
	cout<<"El Factorial es "<< factorial <<endl;
	system("pause");

}
