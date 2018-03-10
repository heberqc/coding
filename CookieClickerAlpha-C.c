/*****************************************
* NombrePrograma: CookieClickerAlpha.c
* Descripcion: http://code.google.com/codejam/contest/2974486/dashboard#s=p1
*
* Autor: Heber Quequejana
* Fecha: 
*
****************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_FARMS 100

int main(){
	int T;
	double *output;
	scanf("%d",&T);
	// matriz de datos
	output = (double*) malloc(T * sizeof(double));
	// input
	for (int n = 0; n < T; n++){
		// ingresar C, F y X
		double C, F, X;
		scanf("%lf %lf %lf",&C,&F,&X);
		// variables
		int farms = 0;
		double ans = 0;
		double ratio = 2.0;
		int done = 0;
		// calcular
		while(!done && farms < MAX_FARMS){
			double aux1 = X/ratio;
			double aux2 = C/ratio;
			double aux3 = aux2 + X/(ratio + F);
			if (aux3 < aux1){
				ans += aux2;
				farms++;
				ratio += F;
			} else {
				ans += aux1;
				done = 1;
				output[n] = ans;
			}
		}
	}
	// output
	printf("\n");
	for (int i = 0; i < T; i++){
		printf("Case #%d: %-.7f\n", (i+1), output[i]);
	}
	printf("\n");
	return 0;
}