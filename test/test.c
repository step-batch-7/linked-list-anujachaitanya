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

void test_add_to_end_in_empty_list(List_ptr list)
{
  char test1[] = "Should add element when list is empty";
  List_ptr expected_list = create_list();
  add_to_start(expected_list, 8);
  Status result = add_to_end(list, 8) && assert_linked_list(list, expected_list);
  show_result(result, test1);
}

void test_add_to_end_in_long_list(List_ptr list)
{
  char test2[] = "should add element in the end of long list";
  List_ptr expected_list = create_list();
  add_to_start(expected_list, 9);
  add_to_start(expected_list, 8);
  Status result = add_to_end(list, 9) && assert_linked_list(list, expected_list);
  show_result(result, test2);
}

void test_insert_at_in_middle(List_ptr list)
{
  char test3[] = "should insert the element in the middle of list";
  List_ptr expected_list = create_list();
  add_to_end(expected_list, 8);
  add_to_end(expected_list, 7);
  add_to_end(expected_list, 9);
  Status result = insert_at(list, 7, 1) && assert_linked_list(list, expected_list);
  show_result(result, test3);
}

int main(void)
{
  List_ptr list = create_list();
  test_add_to_end_in_empty_list(list);
  test_add_to_end_in_long_list(list);
  test_insert_at_in_middle(list);
  return 0;
}