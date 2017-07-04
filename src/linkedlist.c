#include "linkedlist.h"
#include <stdio.h>

void listInit(LinkedList *list){
list->head = NULL;
list->tail = NULL;
list->len = 0;

}

void listAdd(LinkedList *list, Item* item){
 
  if (list->len==0){
    list->head=item;
    list->tail=item;
    list->len+=1;
    list->head->next=NULL;
  }
else  
  {
    list->len+=1;
    list->tail->next = item;
    list->tail=item;
    list->tail->next = NULL;
  }
Item *listRemoveFrist(LinkedList *list){

  if  (list->head == list->tail){
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
  }
  else{
    list->head = list->head->next;
    list->len-=1;
  }
}

Item *listRemovehead(LinkedList *list, char *name){
  
}