#include <stdio.h>
#include <stdlib.h>


struct Node
{
  int value;
  struct Node* next;
};


struct Node* makeNode(int value)
{
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));

  node->value = value;
  node->next = NULL;

  return node;
}


void printSubSum(struct Node* head, int max)
{
  if(head == NULL) return;

  struct Node* current = head;
  int sum = 0, value;

  while(sum <= max && current != NULL)
  {
    value = current->value;
    sum += value;
    // printf(" -> (%d, %d)", value, sum);

    struct Node* temp = current;
    current = current->next;
    free(temp);
  }
  // printf("\n");

  if(sum > max)
  {
    printSubSum(current, max);
    printf("%d\n", value);
  }
}


int main()
{
  struct Node* head = NULL;
  struct Node* current = NULL;
  int value;

  while(scanf("%d", &value) == 1 && value != 0)
  {
    struct Node* node = makeNode(value);

    if(current == NULL)
    {
      head = node;
      current = node;
    }
    else
    {
      current->next = node;
      current = node;
    }
  }

  int max;
  scanf("%d", &max);
  printSubSum(head, max);

  return 0;
}

