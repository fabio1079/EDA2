#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define Key(A) (A)
#define lesseq(A, B) (Key(A) <= Key(B))

#define MAX 140001

Item values[MAX];

void mergeAB(Item *C, Item *a, int a_size, Item *b, int b_size)
{
  int i = 0, j = 0, k = 0;

  while (i < a_size && j < b_size)
  {
    if (lesseq(a[i], b[j]))
      C[k++] = a[i++];
    else
      C[k++] = b[j++];
  }

  for (; i < a_size; ++i)
    C[k++] = a[i];
  for (; j < b_size; ++j)
    C[k++] = b[j];
}

void merge(Item *V, int l, int middle, int r)
{
  Item *C = malloc(sizeof(V) * (r - l + 1));

  mergeAB(C, &V[l], middle - l + 1, &V[middle + 1], r - middle);

  int k = 0, i = l;

  while (i <= r)
  {
    V[i] = C[k];
    i++;
    k++;
  }

  free(C);
}

void mergeSort(Item *V, int l, int r)
{
  if (l == r)
    return;

  int middle = (l + r) / 2;

  mergeSort(V, l, middle);
  mergeSort(V, middle + 1, r);

  merge(V, l, middle, r);
}

int main()
{
  int i=0, value=0;

  while(scanf("%d", &value) == 1)
  {
    values[i] = value;
    i += 1;
  }

  mergeSort(values, 0, i-1);

  for(int j=0; j < i; ++j)
  {
    printf("%d", values[j]);
    if(j != i-1) printf(" ");
  }
  printf("\n");

  return 0;
}
