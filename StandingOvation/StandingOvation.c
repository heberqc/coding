/*****************************************
* NombrePrograma: StandingOvation.c
* Descripcion: https://code.google.com/codejam/contest/6224486/dashboard#s=p0
*
* Autor: Heber Quequejana
* Fecha:
*
****************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
	int T;
	int SM;
	int *S;
	int *R;
	// input
	scanf("%d",&T);
	R = (int*) malloc(100*sizeof(int));
	for(int t = 0; t<T; t++){
		R[t] = 0;
		scanf("%d",&SM);
		S = (int*) malloc(1000*sizeof(int));
		char *dig = (char*) malloc(1000*sizeof(int));
		scanf("%s",dig);
		for(int i=0; i<= SM; i++){
			S[i] = dig[i] - 48;
		}
		if (SM != 0){
			for(int i=1; i<=SM; i++){
				int sum = 0;
				int dif = 0;
				for(int j=0; j<i; j++){
					sum = sum + S[j];
				}
				if(i>sum){
					dif = i - sum;
					R[t] = R[t] + dif;
					S[i] = S[i] + dif;
				}
				//printf("i: %d - sum: %d - dif: %d\n", i, sum, dif);
			}
		}
	}
	// output
	for(int t=0; t<T; t++){
		printf("Case #%d: %d\n",(t+1),R[t]);
	}
	system("pause");
	return 0;
}
