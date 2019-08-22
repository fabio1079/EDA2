#include <stdio.h>

#define MAX 10000

int V[MAX];

void insertSort(int* V, int l, int r)
{
  int i, j, minor;

  for(i=l+1; i <= r; ++i)
  {
    j = i;
    minor = V[i];

    while((j > l) && (minor < V[j-1]))
    {
      V[j] = V[j-1];
      --j;
    }

    V[j] = minor;
  }
}

int main()
{
  int value, i=0, j=0;

  while(scanf("%d", &value) != EOF) V[i++] = value;

  insertSort(V, 0, i-1);

  for(j=0; j<i; ++j)
  {
    printf("%d", V[j]);

    if(j < (i-1)) printf(" ");
  }
  printf("\n");

  return 0;
}

