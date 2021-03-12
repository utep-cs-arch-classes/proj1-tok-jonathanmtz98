#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history() {
  List *h= (List*)malloc(sizeof(List*)*100); //I need to allocate memory
  return h;//Return the initialized list
}
