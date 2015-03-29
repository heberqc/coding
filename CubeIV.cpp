/*****************************************
* NombrePrograma: CubeIV.cpp
* Descripcion: http://code.google.com/codejam/contest/6214486/dashboard#s=p0
*
* Autor: Heber Quequejana
* Fecha:
*
****************************************/

#include <bits/stdc++.h>

using namespace std;

int main(){
   int ncases;
   int ***input;
   int **output;
   cin>>ncases;
   /// creacion de la estructura general
   input = (int***) malloc(ncases * sizeof(int **));
   output = (int**) malloc(ncases * sizeof(int*));
   for(int i = 0; i < ncases; i++)
      output[i] = (int*) malloc(2 * sizeof(int));
   // input
   for (int m = 0; m < ncases; m++){
      int S;
      int pos = 0;
      int maxRooms = 0;
      // lado de la matriz
      cin>>S;
      /// estructura interna
      for(int i = 0; i < ncases; i++){
         input[i] = (int**) malloc(S * sizeof(int*));
         for(int j = 0; j < S; j++){
            input[i][j] = (int*) malloc(S * sizeof(int));
         }
      }
      /// lectura
      for(int i = 0; i < S; i++){
         for(int j = 0; j < S; j++){
            cin>>input[m][i][j];
         }
      }
      /// buscar caminos
      for(int i = 0; i < S; i++){
         for(int j = 0; j < S; j++){
            int num = 1;
            int x, y;
            x = i;
            y = j;
            while(true){
               if(x >= 1 && input[m][x-1][y] == input[m][x][y]+1){
                   num++;
                  x = x-1;
               }else if(y >= 1 && input[m][x][y-1] == input[m][x][y]+1){
                  num++;
                  y = y-1;
               }else if(x < S-1 && input[m][x+1][y] == input[m][x][y]+1){
                  num++;
                  x = x+1;
               }else if(y < S-1 && input[m][x][y+1] == input[m][x][y]+1){
                  num++;
                  y = y+1;
               }else
               {
                  break;
               }
            }
            if(num > maxRooms || (num == maxRooms && input[m][i][j] < pos)){
               maxRooms = num;
               pos = input[m][i][j];
            }
         }
      }
      output[m][0] = pos;
      output[m][1] = maxRooms;
   }
   /// output
   cout<<endl;
   for(int i = 0; i < ncases; i++){
      cout<<"case #"<<(i+1)<<": "<<output[i][0]<<" "<<output[i][1]<<endl;
   }
   cout<<endl;
   system("pause");
   return 0;
}
