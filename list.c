#include "list.h"
#include <stdlib.h>
#include <stdio.h>

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
  list->count++;
  return Success;
}

Status add_to_start(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);

  if (list->head == NULL)
  {
    list->head = new_node;
    list->last = new_node;
  }
  else
  {
    Node_ptr temp = list->head;
    list->head = new_node;
    new_node->next = temp;
  }

  list->count++;
  return Success;
}

Status insert_at(List_ptr list, int value, int position)
{
  if (position > list->count)
  {
    return Failure;
  }
  Node_ptr p_walk = list->head;
  Node_ptr previous_node = list->head;
  int counter = 0;
  while (counter != position)
  {
    previous_node = p_walk;
    p_walk = p_walk->next;
    counter++;
  }
  Node_ptr new_node = create_node(value);
  previous_node->next = new_node;
  new_node->next = p_walk;
  list->count++;
  return Success;
}

Status is_exists(List_ptr list, int value)
{
  Status is_exists = Failure;
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    if (p_walk->value == value)
    {
      is_exists = Success;
      break;
    }
    p_walk = p_walk->next;
  }
  return is_exists;
}

Status add_unique(List_ptr list, int value)
{
  Status is_occurred = is_exists(list, value);
  if (!is_occurred)
  {
    add_to_end(list, value);
    return Success;
  }
  return Failure;
}

Status remove_from_start(List_ptr list)
{
  if (list->head == NULL)
  {
    return Failure;
  }
  Node_ptr temp = list->head;
  list->head = list->head->next;
  list->count--;
  free(temp);
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
  printf("\n");
  free(p_walk);
}