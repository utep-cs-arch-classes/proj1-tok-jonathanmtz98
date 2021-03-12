#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history() {
  List *h= (List*)malloc(sizeof(List*)*100); //I need to allocate memory
  return h;//Return the initialized list
}

char *get_history(List *list, int id) {
  Item *item=list->root; // Keep track of the while loop
  while (item->next!=NULL) { // Read until the end of the list
    if (item->id==id) { //If there is the id wanted...
      return item->str; // return it
    }
    item=item->next; // Go to the next item
  }
  return item->str;//Return item
}

void print_history(List *list) {
  Item *item=list->root; // temporary iterator to move through list
  while(item->next!=NULL) { // Read list
    printf("%d, %s", item->id, item->str); // Print the history
    item = item->next; // Read next item
  }
  printf("%d, %s", item->id, item->str); // Read the last value
}

void free_history(List *list) {
  Item *item=list->root; //This will be used to keep track of the while loop
  while(item->next!=NULL){ // Read until the end of the list
    free(item); // Use "free" to free values
    item=item->next; // Read next item
  }
  free(list); // free the list
  free(item); // free last values
}
