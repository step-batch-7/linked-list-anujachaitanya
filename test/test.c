#include "../list.h"
#include <stdio.h>

void show_result(Status result, char *description)
{
  printf("* %s : ", description);
  if (result)
  {
    printf("PASSED\n");
  }
  else
  {
    printf("FAILED\n");
  }
}

void test_add_to_end(List_ptr list)
{
  char *test1 = "Should add element when list is empty";
  Status result = add_to_end(list, 8);
  show_result(result, test1);

  char *test2 = "Should add element when list has when list has elements";
  result = add_to_end(list, 10);
  show_result(result, test2);
}

int main(void)
{
  List_ptr list = create_list();
  test_add_to_end(list);
  return 0;
}