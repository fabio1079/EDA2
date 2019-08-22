#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX_STR_LENGTH 80

struct Show
{
  char name[MAX_STR_LENGTH];
  struct Show* next;
};


struct Show* makeShow(char* name)
{
  struct Show* s = (struct Show*) malloc(sizeof(struct Show));

  memset(s->name, '\0', MAX_STR_LENGTH);
  strcpy(s->name, name);
  s->next = NULL;

  return s;
}


int main()
{
  struct Show* first = NULL;
  struct Show* last = NULL;
  struct Show* current = NULL;

  char name[MAX_STR_LENGTH];

  // Read stdin input
  while(fscanf(stdin, "%s", name) == 1)
  {
    struct Show* newShow = makeShow(name);

    if(first == NULL)
    {
      first = newShow;
      last = newShow;
    }
    else
    {
      last->next = newShow;
      last = last->next;
    }
  }


  // print result
  current = first;
  while(current != NULL)
  {
    int len = strlen(current->name);
    char currLastChar = current->name[len-1];
    struct Show* next = current->next;

    if(next != NULL)
    {
      char nextFirstChar = tolower(next->name[0]);

      if(currLastChar == nextFirstChar) // send next to the end of queue
      {
        current->next = next->next;
        next->next = NULL;
        last->next = next;
        last = next;
      }
    }

    printf("%s\n", current->name);

    // free current from memory
    struct Show* temp = current;
    current = current->next;
    free(temp);
  }

  return 0;
}

