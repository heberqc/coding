/*****************************************
* NombrePrograma: MinesweeperMaster.c
* Descripcion: 
*
* Autor: Heber Quequejana
* Fecha:
*
****************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void install_mines(char ***M, int Z, int dimY, int dimX, int N);
int n_mines(char ***m, int dimY, int dimX, int z, int y, int x);
void showMatrix(char ***m, int Z, int dimY, int dimX);

int main(){
	int T;
	char ***grid;
	int **output;
	// input
	scanf("%d",&T);
	grid = (char***) malloc(T * sizeof(char**));
	output = (int**) malloc(T * sizeof(int *));
	for (int i = 0; i < T; i++){
		output[i] = (int*) malloc(3 * sizeof(int));
	}
	for (int n = 0; n < T; n++){
		// ingreso de parámetros
		int R, C, M;
		// int m = R * C - M;
		// int aux = 0;
		// int p = 0;
		scanf("%d%d%d", &R, &C, &M);
		output[n][0] = R;
		output[n][1] = C;
		// construcción de la grilla
		grid[n] = (char**) malloc(R * sizeof(char*));
		for (int r = 0; r < R; r++){
			grid[n][r] = (char*) malloc(C * sizeof(char));
		}
		// preparar el campo
		install_mines(grid,n,R,C,M);
		// showMatrix(grid,n,R,C);
		// grid[n][0][0] = 'c';
		// resolver
		for (int j = 0; j < R ; j++){
			for (int i = 0; i < C; i++){
				if (grid[n][j][i] == '.' && (
					i > 0 && n_mines(grid, R, C, n, j, i-1) == 0 || 
					i > 0 && j > 0 && n_mines(grid,R,C,n,j-1,i-1) == 0 ||
					j > 0 && n_mines(grid, R, C, n,j-1,i) == 0 ||
					i < C-1 && j > 0 && n_mines(grid, R, C, n,j-1,i+1) == 0 ||
					i < C-1 && n_mines(grid, R, C, n,j,i+1) == 0 ||
					i < C-1 && j < R-1 && n_mines(grid, R, C, n,j+1,i+1) == 0 ||
					j < R-1 && n_mines(grid, R, C, n,j+1,i) == 0 ||
					i > 0 && j < R-1 && n_mines(grid, R, C, n,j+1,i-1) == 0)){
					grid[n][j][i] = (char) n_mines(grid, R, C, n, j, i) + 48;
				}
			}
		}
	}
	// output
	for (int n = 0; n < T; n++){
		printf("Case #%d:\n", n+1);
		showMatrix(grid,n,output[n][0],output[n][1]);
	}
	printf("\n");
	system("pause");
	return 0;
}

void install_mines(char ***G, int T, int R, int C, int M){
	int S = R * C - M;
	int cant = 0;
	int c = 0, r = 0;
	int n = 0;
	while(r < R || c < C){
		if (r < R && c < C){
			if(cant < M){
				G[T][r][c] = '*';
				cant++;
			}else{
				G[T][r][c] = '.';
			}
		}
		if(r == n && c == n){
			c++;
			r = 0;
			n++;
		}else if(r == n-1 && c == n){
			r = n;
			c = 0;
		}else if(r < n-1 && c == n){
			r++;
		}else if(r == n){
			c++;
		}
	}
}

void showMatrix(char ***m, int Z, int dimY, int dimX){
	for (int j = 0; j < dimY; j++){
		for (int i = 0; i < dimX; i++){
			printf("%c", m[Z][j][i]);
		}
		printf("\n");
	}
}

int n_mines(char ***m, int dimY, int dimX, int z, int y, int x){
	int cant = 0;
	if (x > 0 && m[z][y][x-1] == '*')
		cant++;
	if (x > 0 && y > 0 && m[z][y-1][x-1] == '*')
		cant++;
	if (y > 0 && m[z][y-1][x] == '*')
		cant++;
	if (x < dimX-1 && y > 0 && m[z][y-1][x+1] == '*')
		cant++;
	if (x < dimX-1 && m[z][y][x+1] == '*')
		cant++;
	if (x < dimX-1 && y < dimY-1 && m[z][y+1][x+1] == '*')
		cant++;
	if (y < dimY-1 && m[z][y+1][x] == '*')
		cant++;
	if (x > 0 && y < dimY-1 && m[z][y+1][x-1] == '*')
		cant++;
	return cant;
}
