#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define Key(A) (A)
// #define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
// #define exch(A, B) ({ Item t=B; B = A; A = t; })
// #define compAndSwap(A, B) ({ if(less(B, A)) exch(A, B); })

#define MAX 140001

Item forbidden[MAX];

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

int binarySearch(int *V, int l, int r, int value)
{
  while (l <= r)
  {
    int middle = (l + r) / 2;

    if (value == V[middle])
      return 1;
    else if (value < V[middle])
      r = middle - 1;
    else
      l = middle + 1;
  }

  return 0;
}

int main()
{
  int N, P, i;

  scanf("%d", &N);

  for (i = 0; i < N; ++i)
  {
    scanf("%d", &P);
    forbidden[i] = P;
  }

  if (N > 1)
    mergeSort(forbidden, 0, N - 1);

  while (scanf("%d", &P) == 1)
  {
    if (binarySearch(forbidden, 0, N - 1, P) == 1)
      printf("sim\n");
    else
      printf("nao\n");
  }

  return 0;
}