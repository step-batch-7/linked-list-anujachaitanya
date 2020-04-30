#include "list.h"
#include <stdio.h>
int main(void)
{
  List_ptr list = create_list();
  add_to_start(list, 10);
  add_to_start(list, 1034);
  display(list);
  add_unique(list, 100);
  display(list);
  add_unique(list, 9);
  display(list);
  insert_at(list, 12, 3);
  return 0;
}