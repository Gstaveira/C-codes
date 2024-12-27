#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função que compara duas strings e verifica se uma ocorre na outra

void comparastring(char *str1, char *str2)
{
    str1[ strcspn(str1, "\n") ] = 0;
    str2[ strcspn(str2, "\n") ] = 0;
}

int main()
{
    char str1[100];
    char str2[100];

    printf("Primeira string: ");
    fgets( str1, sizeof(str1), stdin );


    printf("Segunda string: ");
    fgets( str2, sizeof(str2), stdin );


    comparastring(str1, str2);

    if( strstr( str1, str2 ) )
        printf("A segunda string ocorre na primeira\n");

    return 0;
}
