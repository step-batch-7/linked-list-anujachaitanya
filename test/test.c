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
  char *description = "should add element in the end of the list";
  Status result = add_to_end(list, 8);
  show_result(result, description);
}

int main(void)
{
  List_ptr list = create_list();
  test_add_to_end(list);
  return 0;
}