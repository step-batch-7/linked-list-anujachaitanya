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

void test_add_to_end(List_ptr list)
{
  char test1[] = "Should add element when list is empty";
  List_ptr expected_list = create_list();
  add_to_start(expected_list, 8);
  Status result = add_to_end(list, 8) && assert_linked_list(list, expected_list);
  show_result(result, test1);
}

int main(void)
{
  List_ptr list = create_list();
  test_add_to_end(list);
  return 0;
}