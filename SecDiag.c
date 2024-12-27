#include<stdio.h>

//Função que calcula a diagonal secundária de uma matriz

int main(){

int n, i, j;
scanf("%d", &n);
int mat[n][n];
for ( i=0; i<n; i++ ){
  for ( j=0; j<n; j++ )
  {
     scanf ("%d", &mat[ i ][ j ]);
  }
}
  for (i=0; i<n; i++){
            for (j=0; j<n; j++){
                 if (j == (n-1 - i)){
                       printf("%d\n", mat[i][j]);
                   }
         }
      }

return 0;
}
