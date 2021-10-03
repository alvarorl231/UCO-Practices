#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int numeros_distintos(int n,int v[]){
	int cont=1;	
	for(int i=0;i<n-1;i++){
		if(v[i]!=v[i+1]){
		cont++;
		}
	}
	return cont;	
}

int main(){
int n=5;
int v[5]={1,2,1,1,1};

cout<<numeros_distintos(n,v)<<endl;

cin.get();
cin.ignore();
}

