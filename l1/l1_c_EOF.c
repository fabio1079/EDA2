#include <stdio.h>

int main()
{
  int value, sum=0;

  while(scanf("%d", &value) != EOF) sum += 1;

  printf("%d\n", sum);

  return 0;
}

