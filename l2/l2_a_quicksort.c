#include <stdio.h>

#define MAX 100001

int Arr[MAX];

void swap(int* V, int l, int r)
{
  int aux = V[l];
  V[l] = V[r];
  V[r] = aux;
}


static int separa(int* V, int l, int r)
{
  int c = V[r];
  int j=l;

  for(int i = l; i <r; ++i)
  {
    if(V[i] <= c)
    {
      swap(V, i, j);
      j++;
    }
  }

  swap(V, j, r);
  return j;
}


void quickSort(int* V, int l, int r)
{
  if(l < r)
  {
    int j = separa(V, l, r);

    quickSort(V, l, j-1);
    quickSort(V, j+1, r);
  }
}


int main()
{
  int i=0, value;

  while(scanf("%d", &value) == 1)
  {
    Arr[i++] = value;
  }

  quickSort(Arr, 0, i-1);

  for(int j =0; j < i; ++j)
  {
    printf("%d", Arr[j]);

    if(j < (i-1)) printf(" ");
  }
  printf("\n");

  return 0;
}
