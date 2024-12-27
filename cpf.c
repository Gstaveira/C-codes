#include <stdio.h>

//Função que implementa um validador de cpf

int main () {
int cpf[10];
int t, i, b1=0, b2=0, k, b11, b22;
scanf("%d", &t);
while(t>0) {
    for(i=0;i<11;i++){
        scanf("%d", &cpf[i]);
    }

    for(i=0;i<9;i++){
        b1=b1+(cpf[i]*(i+1));
    }
    for(i=0, k=9; i<9; i++){
        b2=b2+(cpf[i]*k);
        k--;
    }
    b11=b1%11;
    b22=b2%11;

    if (b11!=cpf[9] || b22!=cpf[10]){
        printf("CPF invalido\n");
    }
    if (b11==cpf[9] && b22==cpf[10]){
        printf("CPF valido\n");
    }
    b1=0;
    b2=0;
    t--;
}
return 0;
}
