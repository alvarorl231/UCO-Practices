#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n,i,factorial=1;
	cout<<"Introduzca el n"<<endl;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		factorial=factorial*i;
	};
	cout<<"El factorial es "<< factorial <<endl;
		system("pause");

}
