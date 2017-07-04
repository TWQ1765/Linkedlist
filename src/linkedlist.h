#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef struct Item Item;
typedef struct LinkedList LinkedList;

struct Item{
  Item *next;//item is pionting the next item.Eg, Item1 pointing to Item2;
  void *data;//it is the pointer that we dont know which is the type 
             //of data we  put"void" not "student" if not we but "student *data;"
};

struct LinkedList
{
  Item *head;
  Item *tail;
  int len;
};

void listInit(LinkedList *list);
void listAdd(LinkedList *list, Item *item);
Item *listRemoveFrist(LinkedList *list);
Item *listRemovehead(LinkedList *list, char *name);  //strcmp()

#endif // _LINKEDLIST_H
        