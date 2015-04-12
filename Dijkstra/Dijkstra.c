/*****************************************
* NombrePrograma: Dijkstra.c
* Descripcion: https://code.google.com/codejam/contest/dashboard?c=6224486#s=p2
*
* Autor: Heber Quequejana
* Fecha:
*
****************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char quaternion(char a, char b);
int value(char c);
bool possible(char *I, int LX);

int main(){
	int T;
	int *O;
	int L, X;
	int LT;
	char *S;
	char *I;
	// input
	scanf("%d", &T);
	O = (int *) malloc(100 * sizeof(int));
	for (int t = 0; t < T; t++){
		O[t] = 0;
		scanf("%d%d",&L,&X);
		int LX = L * X;
		S = (char*) malloc(10000 * sizeof(char));
		I = (char*) malloc(10000 * sizeof(short));
		scanf("%s",S);
		for (int x = 0; x < X; x++){
			for (int l = 0; l < L; l++){
				I[x * L + l] = S[l];
			}
		}
		// proceso
		if(possible(I,LX)){
			O[t] = 1;
		}
	}
	// output
	for(int t = 0; t < T; t++){
		printf("Case #%d: %s\n",(t+1),(O[t] == 1)?"YES":"NO");
	}
	system("pause");
	return 0;
}

char quaternion(char a, char b){
	char Q[8][8] = {
			{'u','i','j','k','n','x','y','z'},
			{'i','n','k','y','x','u','z','j'},
			{'j','z','n','i','y','k','u','x'},
			{'k','j','x','n','z','y','i','u'},
			{'n','x','y','z','u','i','j','k'},
			{'x','u','z','j','i','n','k','y'},
			{'y','k','u','x','j','z','n','i'},
			{'z','y','i','u','k','j','x','n'}
		};
	return Q[value(a)][value(b)];
}

int value(char c){
	switch(c){
		case 'u':
			return 0;
		case 'i':
			return 1;
		case 'j':
			return 2;
		case 'k':
			return 3;
		case 'n':
			return 4;
		case 'x':
			return 5;
		case 'y':
			return 6;
		case 'z':
			return 7;
		default:
			return -1;
	}
}

bool possible(char *I, int LX){
	int m = 1;
	int n = 2;
	while(m < LX-1 && n < LX){
		n = m + 1;
		char aux_i = 'u';
		char aux_j = 'u';
		char aux_k = 'u';
		for (int a = 0; a < m; a++){
			aux_i = quaternion(aux_i,I[a]);
		}
		printf("aux_i: %c\n", aux_i);
		if(aux_i == 'i'){
			for (int b = m; b < n; b++){
				aux_j = quaternion(aux_j,I[b]);
			}
			printf("aux_j: %c\n", aux_j);
			if(aux_j == 'j'){
				for (int c = n; c < LX; c++){
					aux_k = quaternion(aux_k,I[c]);
				}
				printf("aux_k: %c\n", aux_k);
				if(aux_k == 'k'){
					return true;
				}
			}
		}else{
			m++;
		}
		printf("M: %d - N: %d\n", m,n);
		// n++;
		// m++;
	}
	return false;
}