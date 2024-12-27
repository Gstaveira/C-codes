#include <stdio.h>

//Fatora um número em fatores primos

int primo(int np)
{
    int i;
    int div = 0;
    for (i = 1; i <= np; i++) {
    if (np % i == 0) {
     div++;
    }
  }
    return(div);
}
int main() {
int div, np, n, nf;
np=2;
scanf("%d", &n);
nf=n;
if (n<=0){
    printf("Fatoracao nao e possivel para o numero %d!\n", n);
}
else {
printf("%d = ", n);
while (nf>1){
    while (nf%np==0){
        if (nf==np){
            printf("%d\n", np);
        }
        else {
            printf("%d x ", np);
        }
        nf=nf/np;
    }
    np++;
    div = primo(np);
    while (div!=2) {
        np++;
        div = primo(np);
    }
}
}
}
