#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	int n,i=2;
	bool esprimo=true;
	cout<<"Introduzca el n"<<endl;
	cin>>n;	
	do{
		if (n%i==0){
			esprimo=false;
		}
		i=i+1;
	}while( (esprimo==true)  and (i<n) );
	if (esprimo || n==2 || n==1){cout<<"El numero es primo"<<endl;}
	else{cout<<"El numero no es primo"<<endl;}
	system("pause");
}
