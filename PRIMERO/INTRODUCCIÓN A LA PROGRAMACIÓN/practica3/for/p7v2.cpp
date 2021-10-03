#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n,i=2;
	bool esprimo=true;
	cout<<"Introduzca el n"<<endl;
	cin>>n;	
	for(i=2; (esprimo==true)  and (i<n)  ;i=i+1){
		if (n%i==0){
			esprimo=false;
		} 
	}
	if (esprimo  ){cout<<"El numero es primo"<<endl;}
	else{cout<<"El numero no es primo"<<endl;}
			system("pause");

}
