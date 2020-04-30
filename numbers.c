#include "list.h"
#include <stdio.h>
int main(void)
{
  List_ptr list = create_list();
  add_to_start(list, 10);
  add_to_start(list, 1034);
  add_to_start(list, 1034);
  display(list);
  add_unique(list, 9);
  remove_from_start(list);
  display(list);
  insert_at(list, 12, 3);
  display(list);
  remove_from_end(list);
  display(list);
  return 0;
}