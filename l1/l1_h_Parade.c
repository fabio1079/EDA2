#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int V[MAX];

struct Node
{
  int value;
  struct Node* prev;
};

struct Node* makeNode(int value)
{
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));

  node->value = value;
  node->prev = NULL;

  return node;
}

void verifyPass(int* V, int max)
{
  struct Node* stack = NULL;
  int* ordered =  (int*) malloc(sizeof(int)*max);

  int current=1, i=0,j=0;

  while(i < max)
  {
    if(V[i] != current)
    {
      struct Node* node = NULL;
      if(stack != NULL && stack->value == current)
      {
        ordered[j++] = stack->value;
        current += 1;

        node = stack;
        stack = stack->prev;
        free(node);
      }
      else
      {
        node = makeNode(V[i++]);
        if(stack != NULL) node->prev = stack;
        stack = node;
      }
    }
    else
    {
      ordered[j++] = V[i++];
      current += 1;
    }
  }

  while(stack != NULL)
  {
    ordered[j++] = stack->value;

    struct Node* node = stack;
    stack = stack->prev;
    free(node);
  }

  int is_ordered=1;
  current=1;
  for(i = 0; i < j; ++i)
  {
    if(ordered[i] == current) current += 1;
    else
    {
      is_ordered = 0;
      break;
    }
  }

  if(is_ordered) printf("yes\n");
  else printf("no\n");

  free(ordered);
}

int main()
{
  int total=0;

  while(scanf("%d", &total) == 1 && total != 0)
  {
    int value, i;
    for(i = 0; i < total; ++i)
    {
      scanf("%d", &value);
      V[i] = value;
    }

    verifyPass(V, i);
  }
}