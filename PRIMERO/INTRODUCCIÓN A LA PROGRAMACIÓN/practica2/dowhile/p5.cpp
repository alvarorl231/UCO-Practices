#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n,i;
	cout<<"Introduzca el n"<<endl;
	cin>>n;
	i=n;
	cout<<"Los divisores de "<<n<<" son"<<endl;
	do{
		if (n%i==0){
			cout<<i<<",";
		}
		i=i-1;
	}while(i>=1);
	cout<<". "<<endl;
	system("pause");
}
