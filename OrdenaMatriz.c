#include <stdio.h>
#define LIN 3
#define COL 3

//Função que ordena os elementos de uma Matriz

int main()
{
    int matriz[LIN][COL];

    int x,y;
    // entrada
    for(x=0;x<LIN;x++)
    {
       for(y=0;y<COL;y++)
       {
             printf("matriz[%d][%d]: ",x,y);
             scanf("%d%*c",&matriz[x][y]);
       }
    }

    int *p=matriz;
    int aux,n;
    n = LIN*COL;

    // ordena
    for(x=n;x>0;x--)
    {
       for(y=0;y<n;y++)
       {
             if(*(p+y)>*(p+(y+1)))
             {
                   aux = *(p+y);
                   *(p+y) = *(p+(y+1));
                   *(p+(y+1)) = aux;
             }
       }
    }
    // imprimir
    for(x=0;x<LIN;x++)
    {
       for(y=0;y<COL;y++)
       {
             printf("%d ",matriz[x][y]);
       }
       printf("\n");
    }
    return 0;
}
