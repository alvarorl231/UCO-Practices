#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

float string_calc(string val1,string val2,int op){
	float a=stof(val1);
	float b=stof(val2);

	switch(op){
	case 1:{return a+b;}break;
	case 2:{return a*b;}break;
	default:{cout<<"no introdujo ni 1 ni 2"<<endl;}
	}

}

int main(){
cout<<"Introduzca numeros"<<endl;
string v1;
cin>>v1;
cout<<"Introduzca numeros"<<endl;
string v2;
cin>>v2;

cout<<"Introduce 1 para sumar y 2 para multiplicar"<<endl;
int n;
cin>>n;

cout<<string_calc(v1,v2,n)<<endl;

cin.ignore();
cin.get();
}

