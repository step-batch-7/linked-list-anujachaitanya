#include <stdio.h>
#include "list.h"

void switch_operations(List_ptr list, char option)
{
  Status result;
  int number, position;
  switch (option)
  {
  case 'a':
    printf("Enter the number to add at the end of the list : ");
    scanf("%d", &number);
    add_to_end(list, number);
    printf("Number added");
    break;

  case 'b':
    printf("Enter the number to add to start of the list : ");
    scanf("%d", &number);
    add_to_start(list, number);
    printf("Number added");
    break;

  case 'c':
    printf("Enter the position to add number : ");
    scanf("%d", &position);
    printf("Enter the number to add in list: ");
    scanf("%d", &number);
    add_to_start(list, number);
    printf("Number added");
    break;

  case 'd':
    printf("Enter unique number to add in the list: ");
    scanf("%d", &number);
    result = add_unique(list, number);
    if (result)
    {
      printf("Number added");
    }
    else
    {
      printf("%d is not unique", number);
    }
    break;

  case 'e':
    result = remove_from_end(list);
    if (result)
    {
      printf("Number removed");
    }
    else
    {
      printf("List is empty");
    }
    break;

  case 'f':
    result = remove_from_start(list);
    if (result)
    {
      printf("Number removed");
    }
    else
    {
      printf("List is empty");
    }
    break;

  case 'g':
    printf("Enter the position to delete number : ");
    scanf("%d", &position);
    result = remove_at(list, position);
    if (result)
    {
      printf("Number removed");
    }
    else
    {
      printf("List is empty");
    }
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