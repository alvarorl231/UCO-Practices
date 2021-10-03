#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

bool vectiguales(int v1[],int v2[],int n){
	for(int i=0;i<n;i++){
		if(v1[i]!=v2[i]){
		return false;}
	}
return true;	
}

int main(){
	int n=3;
	int v1[3]={2,3,5};
	int v2[3]={2,3,5};
	int v3[3]={1,3,5};

	cout<<vectiguales(v1,v2,n)<<endl;
	cout<<vectiguales(v1,v3,n)<<endl;

cin.ignore();
cin.get();
}

