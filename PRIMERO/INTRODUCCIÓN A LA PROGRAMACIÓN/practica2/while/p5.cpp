#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n,i;
	cout<<"Introduzca el n"<<endl;
	cin>>n;
	i=n;
	cout<<"Los divisores de "<<n<<" son"<<endl;
	while(i>=1){
		if (n%i==0){
			cout<<i<<",";
		}
		i=i-1;
	};
	cout<<". "<<endl;
		system("pause");

}
