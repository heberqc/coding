/*****************************************
* NombrePrograma: InfiniteHouseOfPancakes.c
* Descripcion: https://code.google.com/codejam/contest/dashboard?c=6224486#s=p1
*
* Autor: Heber Quequejana
* Fecha:
*
****************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int maxOf(int *input, int dim, int *cant);
void reem(int *input, int *dim, int a, int b);

int main(){
	int T;
	int *O;
	// input
	scanf("%d", &T);
	O = (int *) malloc(T * sizeof(int));
	for (int t = 0; t < T; t++){
		int max = 0;
		int cant = 0;
		int ite = 0;
		int aux = 0;
		int D;
		scanf("%d", &D);
		int *I = (int *) malloc(1024 * 1024 * sizeof(int));
		for (int d = 0; d < D; d++){
			scanf("%d", &I[d]);
		}
		// proceso
		max = maxOf(I, D, &cant);
		O[t] = max + ite;
		ite += cant;
		reem(I, &D, max, (max - max/2));
		while(true){
			max = maxOf(I, D, &cant);
			aux = max + ite;
			if(aux <= O[t]){
				O[t] = aux;
				ite += cant;
				reem(I, &D, max, (max - max/2));
			}else{
				break;
			}
		}
	}
	// output
	for(int t = 0; t < T; t++){
		printf("Case #%d: %d\n",(t+1),O[t]);
	}
	system("pause");
	return 0;
}

int maxOf(int *input, int dim, int *cant){
	int O = 0;
	*cant = 0;
	for (int i = 0; i < dim; i++){
		if (input[i] > O){
			O = input[i];
			*cant = 1;
		}else if(input[i] == O){
			(*cant)++;
		}
		// printf("contador = %d\n", *cant);
	}
	return O;
}

void reem(int *input, int *dim, int a, int b){
	for (int i = 0; i < *dim; i++){
		if(input[i] == a){
			input[i] = b;
			input[*dim] = a - b;
			(*dim)++;
		}
	}

}
