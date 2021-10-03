#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n,i,suma=0;
	cout<<"Introduzca el n"<<endl;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		suma=suma+i;
	};
	cout<<"El valor final es "<< suma <<endl;
		system("pause");

}
