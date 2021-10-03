#include <iostream>
using namespace std;
void divisores(int n){
	cout<<"Los divisores de "<<n<<" son: "<<endl;
	for(int i=1;i<=n;i++){
		if (n%i==0){cout<<i<<" ";}
		}

	cout<<endl;
}

int main(){
	int n;
	cout<<"Introduzca el numero"<<endl;
	cin>>n;
	divisores(n);	

}

