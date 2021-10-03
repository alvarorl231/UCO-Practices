#include "ej7.h"
#include "ej6.h"

int **multiplicarMxM(int **matriz1,int **matriz2,int nFil1, int nCol1,int nCol2){
	int **mres;
	for(int i=0;i<nFil1;i++){
		for(int j=0;j<nCol2;j++){
			mres[i][j]=0;
			for(int k=0;k<nCol1;k++){
				mres[i][j]=mres[i][j]+matriz1[i][k]*matriz2[k][i];
			}
		}

	}
	return (mres);
}