#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

bool palindromo(string cad){
	for(int i=0;i<cad.size()/2;i++){
		if(cad[i]!=cad[cad.size()-i-1]){
		return false;	
		}
	}
return true;
}

int main(){
string palin,nopalin;
cout<<"Introduzca palabra palindroma"<<endl;
cin>>palin;
cout<<palindromo(palin)<<endl;

cout<<"Introduzca palabra no palindroma"<<endl;
cin>>nopalin;
cout<<palindromo(nopalin)<<endl;



cin.get();
cin.ignore();
}

