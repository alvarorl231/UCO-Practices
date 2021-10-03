#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	int n,i=2;
	bool esprimo=true;
	cout<<"Introduzca el n"<<endl;
	cin>>n;	
	while( (esprimo==true)  and (i<n) ){
		if (n%i==0){
			esprimo=false;
		}
		i=i+1;
	}
	if (esprimo  ){cout<<"El numero es primo"<<endl;}
	else{cout<<"El numero no es primo"<<endl;}
		system("pause");

}
