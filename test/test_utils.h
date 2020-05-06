#include "../list.h"

#ifndef __TEST_UTILS_H
#define __TEST_UTILS_H

Status assert_linked_list(List_ptr actual, List_ptr expected);
void show_result(Status result, char *description);
List_ptr get_expected_list(int *array, int length);

#endif