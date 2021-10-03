#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int i=2,n,xt_1=0,xt=1;
	cout<<"Introduzca el n"<<endl;
	cin>>n;
	cout<<"Los valores son"<<endl;
	if (n>=1){cout<<xt_1<<endl;}
	if (n>=2){cout<<xt<<endl;}
	if (n>=3){
		do{
		int aux=xt+xt_1;
		xt_1=xt;
		xt=aux;
		cout<<xt<<endl;
		i=i+1;
		}while(i<n);
	}
		system("pause");
}
