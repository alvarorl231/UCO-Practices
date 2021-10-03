#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n,i=1,suma=0;
	cout<<"Introduzca el n"<<endl;
	cin>>n;
	while(i<=n){
		suma=suma+i;
		i=i+1;
	};
	cout<<"El valor final es "<< suma <<endl;
	system("pause");

}
