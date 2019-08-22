#include <stdio.h>

int n=0, val=0, sum=0, i=0;

int main()
{
  scanf("%d", &n);

  for(i=0; i < n; ++i)
  {
    scanf("%d", &val);
    
    sum += val;
  }

  printf("%d\n", sum);

  return 0;
}
