/*****************************************
* NombrePrograma: MagicTrick.cpp
* Descripcion: http://code.google.com/codejam/contest/2974486/dashboard#s=p0
*
* Autor: Heber Quequejana
* Fecha:
*
****************************************/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int ncases;
	int resp[2]; // fila
	int cards[4][4][2];
	int *output;
	// input
	cin>>ncases;
	output = (int*) malloc(ncases * sizeof(int));
	for (int n = 0; n < ncases; n++)
	{
		output[n] = -1;
		for (int i = 0; i < 2; i++)
		{
			cin>>resp[i];
			for (int j = 0; j < 4; j++){
				for (int k = 0; k < 4; k++)
				{
					cin>>cards[k][j][i];
				}
			}
			// resolviendo
			if(i == 1){
				for (int j = 0; j < 4; j++)
				{
					for (int k = 0; k < 4; k++)
					{
						if(cards[k][resp[0] - 1][0] == cards[j][resp[1] - 1][1]){
							if(output[n] == -1){
								output[n] = cards[j][resp[1] - 1][1];
							}else{
								output[n] = 0;
							}
						}
					}
				}
			}
		}
	}
	// output
	for (int i = 0; i < ncases; i++)
	{
		cout<<"Case #"<<(i +1)<<": ";
		switch(output[i]){
			case -1:
				cout<<"Volunteer cheated!";
				break;
			case 0:
				cout<<"Bad magician!";
				break;
			default:
				cout<<output[i];
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}
