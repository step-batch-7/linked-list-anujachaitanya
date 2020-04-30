#include "list.h"
#include <stdio.h>

void switch_opertions(List_ptr list, char option)
{
  int number;
  switch (option)
  {
  case 'a':
    printf("Enter the number to add at the end of the list : ");
    scanf("%d", &number);
    add_to_end(list, number);
    printf("Number added");
    break;

  case 'l':
    printf("Your List : \n");
    display(list);
    break;

  case 'm':
    printf("exit");
    break;

  default:
    printf("Invalid Option");
    break;
  }
}

int main(void)
{
  char option;
  int number;
  List_ptr list = create_list();
  printf("Main Menu\n---------\n(a) add a number to the end of the list\n(b) add a number to the start of the list\n(c) insert a number at a given position in the list\n(d) add a unique item on the list at the end(if it alreay exists, do not insert)\n(e) remove a number from the beginning of the list\n(f) remove a number from the end of the list\n(g) remove a number from a given position in the list\n(h) remove first occurrence of a number\n(i) remove all occurrences of a number\n(j) clear the whole list\n(k) check if a number exists in the list\n(l) display the list of numbers\n(m) exit\n");
  while (option != 'm')
  {
    printf("\nPlease enter the alphabet of the operation you would like to perform\n");
    scanf(" %c", &option);
    switch_operations(list, option);
  }

  return 0;
}