#include <stdio.h>

// Função que implementa o cálculo da raiz quadrada sem usar a biblioteca math.h

int main () {
double n, rk, rk1, e, r, err;
scanf("%lf", &n);
scanf("%lf", &e);
rk1=1;
rk=(rk1+(n/rk1))/2;
err=(rk*rk)-n;
printf("r: %.9lf, err: %.9lf\n", rk, err);
while (err>=e) {
rk1=rk;
rk=(rk1+(n/rk1))/2;
err=(rk*rk)-n;
printf("r: %.9lf, err: %.9lf\n", rk, err);
}
}
