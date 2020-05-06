#include "../list.h"
#include "test_utils.h"

#include <stdio.h>

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
  char test3[] = "Should insert the element in the middle of list";
  List_ptr expected_list = create_list();
  add_to_end(expected_list, 8);
  add_to_end(expected_list, 7);
  add_to_end(expected_list, 9);
  Status result = insert_at(list, 7, 1) && assert_linked_list(list, expected_list);
  show_result(result, test3);
}

void test_insert_at_start_of_list(List_ptr list)
{
  char test4[] = "Should insert in the start of the list";
  List_ptr expected_list = create_list();
  add_to_end(expected_list, 8);
  add_to_end(expected_list, 7);
  add_to_end(expected_list, 9);
  add_to_start(expected_list, 6);
  Status result = insert_at(list, 6, 0) && assert_linked_list(list, expected_list);
  show_result(result, test4);
}

void test_insert_at_end_of_list(List_ptr list)
{
  char test5[] = "Should insert in the start of the list";
  List_ptr expected_list = create_list();
  add_to_end(expected_list, 6);
  add_to_end(expected_list, 8);
  add_to_end(expected_list, 7);
  add_to_end(expected_list, 9);
  add_to_end(expected_list, 5);
  Status result = insert_at(list, 5, 4) && assert_linked_list(list, expected_list);
  show_result(result, test5);
}

int main(void)
{
  List_ptr list = create_list();
  test_add_to_end_in_empty_list(list);
  test_add_to_end_in_long_list(list);
  test_insert_at_in_middle(list);
  test_insert_at_start_of_list(list);
  test_insert_at_end_of_list(list);
  return 0;
}