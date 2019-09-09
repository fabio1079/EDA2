#include <stdio.h>

int binSearch(int *arr, int item, int l, int r)
{
  int found = -1;

  while (r >= l)
  {
    int mid = (l + r) / 2;

    if (item < arr[mid])
    {
      r = mid - 1;
    }
    else if (item > arr[mid])
    {
      l = mid + 1;
    }
    else
    {
      found = mid;
      break;
    }
  }

  return found;
}

int calcDist(int a, int b)
{
  if (a > b)
    return a - b;
  else
    return b - a;
}

int main()
{
  int n, m, i, value;

  scanf("%d %d", &n, &m);

  int houses[n];
  int packages[m];

  for (i = 0; i < n; ++i)
  {
    scanf("%d", &value);
    houses[i] = value;
  }

  for (i = 0; i < m; ++i)
  {
    scanf("%d", &value);
    packages[i] = value;
  }

  int count = 0;
  int current = 0;
  for (i = 0; i < m; ++i)
  {
    int found = binSearch(houses, packages[i], 0, n);

    if (found != -1)
    {
      int dictance = calcDist(found, current);
      count += dictance;
      current = found;
    }
  }

  printf("%d\n", count);

  return 0;
}