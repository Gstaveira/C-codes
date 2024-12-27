#include <stdio.h>

//Define se um número é primo ou não

int main () {
    int i, x;
    int div = 0;
    scanf("%d", &x);
  if (x<0){
    printf("Numero invalido!\n");
  }
  else {
  for (i = 1; i <= x; i++) {
    if (x % i == 0) {
     div++;
    }
  }

  if (div == 2)
    printf("PRIMO\n");
  else
    printf("NAO PRIMO\n", x);


}
 return 0;
}
