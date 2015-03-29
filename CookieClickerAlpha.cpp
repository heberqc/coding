/*****************************************
* NombrePrograma: CookieClickerAlpha.cpp
* Descripcion: http://code.google.com/codejam/contest/2974486/dashboard#s=p1
*
* Autor: Heber Quequejana
* Fecha: 
*
****************************************/

#include <bits/stdc++.h>
#define MAX_FARMS 100

using namespace std;

int main(){
	int T;
	double *output;
	cin>>T;
	// matriz de datos
	output = (double*) malloc(T * sizeof(double));
	// input
	for (int n = 0; n < T; n++){
		// ingresar C, F y X
		double C, F, X;
		cin>>C>>F>>X;
		// variables
		int farms = 0;
		double ans = 0;
		double ratio = 2.0;
		bool done = false;
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
				done = true;
				output[n] = ans;
			}
		}
	}
	// output
	printf("\n");
	for (int i = 0; i < T; i++){
		cout<<"Case #"<<(i+1)<<": ";
		printf("%-.7f\n", output[i]);
	}
	cout<<endl;
	system("pause");
	return 0;
}