#include <iostream>
using namespace std;
float media(int n){
	float suma=0,val;
	for(int i=1;i<=n;i++){
		cout<<"Introduzca el valor "<<i<<endl;
		cin>>val;
		suma=suma+val;
		}

	return suma/float(n);
}

int main(){
	int n;
	cout<<"Introduzca el numero"<<endl;
	cin>>n;
	float res=media(n);
	cout<<"La media es ="<<res<<endl;

}

