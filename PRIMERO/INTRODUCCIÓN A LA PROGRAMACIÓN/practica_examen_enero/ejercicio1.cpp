#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int cuentadigitos(string cad){
 	int cont=0;
	for(int i=0;i<cad.size();i++){
		if(isdigit(cad[i])){
		cont++;
		}
	}
return cont;
}

int main(){
	string cadena;
	cout<<"Introduzca una cadena"<<endl;
	cin>>cadena;
	
	cout<<cuentadigitos(cadena)<<endl;

cin.ignore();
cin.get();
}

