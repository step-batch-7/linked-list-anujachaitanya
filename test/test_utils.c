#include "../list.h"
#include <stdio.h>
#include <stdlib.h>

Status assert_linked_list(List_ptr actual, List_ptr expected)
{
  Status is_equal = Success;
  if (actual->count != expected->count)
  {
    return Failure;
  }
  Node_ptr p_walk_actual = actual->head;
  Node_ptr p_walk_expected = expected->head;
  while (p_walk_actual != NULL)
  {
    if (p_walk_actual->value != p_walk_expected->value)
    {
      is_equal = Failure;
      break;
    }
    p_walk_actual = p_walk_actual->next;
    p_walk_expected = p_walk_expected->next;
  }
  return is_equal;
}

List_ptr get_expected_list(int *array, int length)
{
  List_ptr expected_list = create_list();
  int counter = 0;
  while (counter < length)
  {
    Node_ptr new_node = malloc(sizeof(Node));
    new_node->value = array[counter];
    new_node->next = NULL;
    if (expected_list->head == NULL)
    {
      expected_list->head = new_node;
    }
    else
    {
      expected_list->last->next = new_node;
    }
    expected_list->last = new_node;
    expected_list->count++;
    counter++;
  }
  return expected_list;
}

void show_result(Status result, char *description)
{
  if (result)
  {
    printf("✅");
  }
  else
  {
    printf("❌");
  }
  printf(" %s \n", description);
}
