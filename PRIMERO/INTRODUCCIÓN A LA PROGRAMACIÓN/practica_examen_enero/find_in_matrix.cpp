#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int find_in_matrix(float m[6][6], float val){
	int cont=0;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(m[i][j]==val){
			cont++;
			}
		}
	}
return cont;
}

int main(){

float num=3.5;
float matriz[6][6]={{1,2,3.5,4,5,3.5},{3,4,5,6,7,3.5}};
cout<<"las veces que aparece 3.5 en la matriz son "<<find_in_matrix(matriz,num);



cin.ignore();
cin.get();
}

