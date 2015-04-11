#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <conio.h>

using namespace std;

int main(){
	int T;
	int SM;
	int **S;
	int *R;
	// input
	scanf("%d",&T);
	S = (int**) malloc(T*sizeof(int*));
	R = (int*) malloc(T*sizeof(int));
	for(int t=0; t<T; t++){
		R[t] = 0;
		scanf("%d",&SM);
		char *dig = (char*) malloc((SM+1)*sizeof(char));
		scanf("%s",dig);
		for(int i=0; i<= SM; i++){
			S[t][i] = dig[i] - 48;
		}
		for(int i=1; i<=SM; i++){
			int sum = 0;
			for(int j=0; j<i; j++){
				sum = sum + S[t][j];
			}
			if(i<sum){
				int dif = i - sum;
				R[t] = R[t] + dif;
				S[t][i] = S[t][i] + dif;
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
