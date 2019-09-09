#include <stdio.h>

int main()
{
  int total = 123456, i = 0, value;

  while (total != 0)
  {
    scanf("%d", &total);
    if (total == 0)
      break;

    int currentColor = 0;
    int currentColorCount = 0;

    for (i = 0; i < total; ++i)
    {
      scanf("%d", &value);

      if (currentColorCount == 0)
      {
        currentColor = value;
      }

      if (value == currentColor)
      {
        currentColorCount += 1;
      }
      else
      {
        currentColorCount -= 1;
      }
    }

    printf("%d\n", currentColor);
  }
  return 0;
}
