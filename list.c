#include "list.h"
#include <stdlib.h>

List_ptr create_list(void)
{
  List_ptr new_list = malloc(sizeof(List));
  new_list->head = NULL;
  new_list->last = NULL;
  new_list->count = 0;
  return new_list;
}

Node_ptr create_node(int value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (list->head == NULL)
  {
    list->head = new_node;
  }
  else
  {
    list->last->next = new_node;
  }
  list->last = new_node;
  return Success;
}

Status add_to_start(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);

  if (list->head == NULL)
  {
    list->head = new_node;
    list->last = new_node;
    return Success;
  }

  Node_ptr temp = list->head;
  list->head = new_node;
  new_node->next = temp;
  return Success;
}

void display(List_ptr list)
{
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    printf("%d\t", p_walk->value);
    p_walk = p_walk->next;
  }
  free(p_walk);
}