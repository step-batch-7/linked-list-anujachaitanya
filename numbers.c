#include "list.h"
#include <stdio.h>
int main(void)
{
  List_ptr list = create_list();
  add_to_start(list, 10);
  add_to_start(list, 1032);
  add_to_start(list, 103);
  add_to_start(list, 1034);
  display(list);
  printf("%d", is_exists(list, 10));
  insert_at(list, 12, 3);
  return 0;
}