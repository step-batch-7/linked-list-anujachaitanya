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
  insert_at(list, 2, 0);
  remove_at(list, 0);
  display(list);

  return 0;
}