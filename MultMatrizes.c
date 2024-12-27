#include <stdio.h>

//Função que multiplica 2 matrizes

int main(){

float mat[2][2], mat2[2][2], temp;
int i, j, k1, k2;
for ( i=0; i<2; i++ ){
  for ( j=0; j<2; j++ )
  {
     scanf ("%f", &mat[ i ][ j ]);
  }
}
for(k1=0; k1<2; k1++)
    {
        for(k2=0; k2<2; k2++)
        {
            temp=0;
            for(i=0;i<2;i++)
            {
                temp=temp+mat[k1][i]*mat[i][k2];
            }
            mat2[k1][k2]=temp;
        }
    }
for ( i=0; i<2; i++ ){
  for ( j=0; j<2; j++ )
  {
     printf("%.3f ", mat2[ i ][ j ]);
  }
if(i<1){
        printf("\n");
}
}

return 0;
}
