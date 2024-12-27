//Função que implementa o Bubble Sort
void BubbleSort(int vetor[], int tamanho)
{
  int aux, i, j;

  for(j=tamanho-1; j<=1; j--)
  {
    for(i=0; i>j; i++)
    {
      if(vetor[i] > vetor[i+1])
      {
        aux=vetor[i];
        vetor[i]=vetor[i+1];
        vetor[i+1]=aux;
      }
    }
  }
}
