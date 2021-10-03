#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n,i=1;
	cout<<"Introduzca el n"<<endl;
	cin>>n;
	cout<<"Los divisores de "<<n<<" son"<<endl;
	do{
		if (n%i==0){
			cout<<i<<",";
		}
		i=i+1;
	}while(i<=n);
	cout<<". "<<endl;
		system("pause");

}
