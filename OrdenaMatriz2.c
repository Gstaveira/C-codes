#include <stdio.h>
#include <stdlib.h>
#define max 100

//Função que ordena as linhas e colunas de uma Matriz

int main()
{
      long int M, N, var1, var2, i, j, matriz[max][max], matriz_aux[max][max];;


        printf("\nDigite o numero de linhas da matriz: ");
        scanf("%d",&N);

        printf("\nDigite o numero de colunas da matriz: ");
        scanf("%d",&M);

              for(i=0; i<N; i++){
              printf("\nDigite os numeros da %d linha: \n", i+1);
              for(j=0; j<M; j++){
              scanf("%d", &matriz[i][j]);
              }
           }

           /*Igualando os elementos de uma matriz a outra para facilitar o processo
           de ordenanao posteriormente.*/
           for(i=0; i<N; i++){
              for(j=0; j<M; j++){
                 matriz_aux[i][j]= matriz[i][j];
           }
            }

           /*Ordenando os elementos da matriz pelas linhas.*/
           for(i=0; i<N; i++){
              for(j= M-1; j>=0; j--){
                 for(var1= j-1; var1>=0; var1--){
                    if(matriz[i][j]< matriz[i][var1]){
                       var2= matriz[i][j];
                       matriz[i][j]= matriz[i][var1];
                       matriz[i][var1]=var2;
                    }
                 }
              }
           }

           /*Imprimindo a matriz.*/
           printf("\nMatriz ordenada pelas linhas a partir da original.");
           for(i=0; i<N; i++){
               printf("\n\nLinha %d:\n", i+1);
               for(j=0; j<M; j++)
                   printf("%d ", matriz[i][j]);
           }

           /*Ordenando os elementos da matriz pelas colunas.*/
              for(j=M-1; j>=0; j--){
                 for(i= N-1; i>=0; i--){
                     for(var1= i-1; var1>=0; var1--){
                         if(matriz_aux[i][j]< matriz_aux[var1][j]){
                            var2= matriz_aux[i][j];
                            matriz_aux[i][j]= matriz_aux[var1][j];
                            matriz_aux[var1][j]=var2;
                         }
                     }
                 }
              }
            printf("\n");

           /*Imprimindo a matriz.*/
           printf("\nMatriz ordenada pelas colunas a partir da original.\n");
           for(j=0; j<M; j++){
               printf("\ncoluna %d:\n", j+1);
                  for(i=0; i<N; i++)
                     printf("%d\n", matriz_aux[i][j]);
            }

return 0;
}
