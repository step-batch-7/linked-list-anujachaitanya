#include "../list.h"
#include "test_utils.h"

#include <stdio.h>

void test_add_to_end_in_empty_list(List_ptr list)
{
  char test1[] = "Should add element when list is empty";
  int expected_values[] = {8};
  List_ptr expected_list = get_expected_list(expected_values, 1);
  Status result = add_to_end(list, 8) && assert_linked_list(list, expected_list);
  show_result(result, test1);
}

void test_add_to_end_in_long_list(List_ptr list)
{
  char test2[] = "should add element in the end of long list";
  int expected_values[] = {8, 9};
  List_ptr expected_list = get_expected_list(expected_values, 2);
  Status result = add_to_end(list, 9) && assert_linked_list(list, expected_list);
  show_result(result, test2);
}

void test_insert_at_in_middle(List_ptr list)
{
  char test3[] = "Should insert the element in the middle of list";
  int expected_values[] = {8, 7, 9};
  List_ptr expected_list = get_expected_list(expected_values, 3);
  Status result = insert_at(list, 7, 1) && assert_linked_list(list, expected_list);
  show_result(result, test3);
}

void test_insert_at_start_of_list(List_ptr list)
{
  char test4[] = "Should insert in the start of the list";
  int expected_values[] = {6, 8, 7, 9};
  List_ptr expected_list = get_expected_list(expected_values, 4);
  Status result = insert_at(list, 6, 0) && assert_linked_list(list, expected_list);
  show_result(result, test4);
}

void test_insert_at_end_of_list(List_ptr list)
{
  char test5[] = "Should insert in the start of the list";
  int expected_values[] = {6, 8, 7, 9, 5};
  List_ptr expected_list = get_expected_list(expected_values, 5);
  Status result = insert_at(list, 5, 4) && assert_linked_list(list, expected_list);
  show_result(result, test5);
}

void test_invalid_position_in_insert_at(List_ptr list)
{
  char test6[] = "should not insert element at list";
  int expected_values[] = {6, 8, 7, 9, 5};
  List_ptr expected_list = get_expected_list(expected_values, 5);
  Status result = !(insert_at(list, 1, -3) && assert_linked_list(list, expected_list));
  show_result(result, test6);
}

int main(void)
{
  List_ptr list = create_list();
  test_add_to_end_in_empty_list(list);
  test_add_to_end_in_long_list(list);
  test_insert_at_in_middle(list);
  test_insert_at_start_of_list(list);
  test_insert_at_end_of_list(list);
  test_invalid_position_in_insert_at(list);
  return 0;
}