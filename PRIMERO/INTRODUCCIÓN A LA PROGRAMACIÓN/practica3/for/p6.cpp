#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int i,n,xt_1=0,xt=1;
	cout<<"Introduzca el n"<<endl;
	cin>>n;
	cout<<"Los valores son"<<endl;
	if (n>=1){cout<<xt_1<<endl;}
	if (n>=2){cout<<xt<<endl;}
	for(i=2;i<n;i=i+1){
		int aux=xt+xt_1;
		xt_1=xt;
		xt=aux;
		cout<<xt<<endl;
	}
			system("pause");

}
