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

char quaternions(char a, char b);
int value(char c);
bool possible(char *I, int LX);

int main(){
	int T;
	int *O;
	int L, X;
	char *S;
	char *I;
	// input
	scanf("%d", &T);
	O = (int *) malloc(T * sizeof(int));
	for (int t = 0; t < T; t++){
		O[t] = 0;
		scanf("%d%d",&L,&X);
		int LX = L * X;
		S = (char*) malloc((L+1) * sizeof(char));
		I = (char*) malloc((LX+1) * sizeof(char));
		scanf("%s",S);
		for (int x = 0; x < X; x++){
			for (int l = 0; l < L; l++){
				I[x * L + l] = S[l];
			}
		}
		I[LX] = '\0';
		printf("%s\n", I);
		// process
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

char quaternions(char a, char b){
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
	char aux_i, aux_j, aux_k;
	aux_i = 'u';
	for (int b1 = 1; b1 < (LX-1); b1++){
		aux_i = quaternions(aux_i,I[b1-1]);
		if(aux_i == 'i'){
			aux_j = 'u';
			for (int b2 = (b1+1); b2 < LX; b2++){
				aux_j = quaternions(aux_j,I[b2-1]);
				if(aux_j == 'j'){
					aux_k = 'u';
					for (int i = b2; i < LX; i++){
						aux_k = quaternions(aux_k,I[i]);
					}
					// printf("aux_i: %c - aux_j: %c - aux_k: %c\n", aux_i, aux_j, aux_k);
					if(aux_k == 'k'){
						// printf("B1: %d - B2: %d\n", b1, b2);
						return true;
					}
				}
			}
		}
	}
	return false;
}