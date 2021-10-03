#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n,i=1,n_divisores=0;
	cout<<"Introduzca el n"<<endl;
	cin>>n;	
	while(i<=n){
		if (n%i==0){
			n_divisores=n_divisores+1;
		}
		i=i+1;
	};
	if (n_divisores==2 || n==1 ){cout<<"El numero es primo"<<endl;}
	else{cout<<"El numero no es primo"<<endl;}
		system("pause");

}
