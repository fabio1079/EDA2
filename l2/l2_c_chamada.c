#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

void insertSort(char **V, int l, int r)
{
  int i, j;
  char minor[MAX];

  for (i = l + 1; i <= r; ++i)
  {
    j = i;
    strcpy(minor, V[i]);

    while ((j > l) && strcmp(minor, V[j - 1]) < 0)
    {
      strcpy(V[j], V[j - 1]);
      --j;
    }

    strcpy(V[j], minor);
  }
}

/*
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
*/

int main()
{
  int N, K, i;
  char name[MAX];
  char **students;

  scanf("%d %d", &N, &K);

  students = (char **)malloc(sizeof(char *) * N);
  for (i = 0; i < N; ++i)
  {
    students[i] = (char *)malloc(sizeof(char) * MAX);
    // memset(students[i], '\0', MAX);
  }

  for (i = 0; i < N; ++i)
  {
    scanf(" %s", name);
    strcpy(students[i], name);
  }

  if(N > 1) insertSort(students, 0, N - 1);

  printf("%s\n", students[K - 1]);

  for (i = 0; i < N; ++i)
  {
    // printf("%s\n", students[i]);
    free(students[i]);
  }

  return 0;
}
