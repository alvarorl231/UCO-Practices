#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n,i;
	cout<<"Introduzca el n"<<endl;
	cin>>n;
	cout<<"Los divisores de "<<n<<" son"<<endl;
	for(i=n; i>=1;i=i-1){
		if (n%i==0){
			cout<<i<<",";
		}
	}
	cout<<". "<<endl;
			system("pause");

}
