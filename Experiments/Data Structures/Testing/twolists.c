#include <stdlib.h>
#include <stdio.h>


struct tlist {
  int valor;
  struct tlist *next;
}; typedef struct tlist list;

list *mergeSub(list *h1, list *h2){
  list *first = (list*)malloc(sizeof(list));
  list *aux = first;
  int v1,v2 = 0;
  first->next = NULL;
  while(h1 != NULL  && h2!=NULL){
    list *new_list = (list*)malloc(sizeof(list));
    new_list->next = NULL;
     v1 = h1->valor;
     v2 = h2->valor;
    if(first->next == NULL){
      new_list->valor = v1 - v2;
      first->next = new_list;
    } else{
      aux->next = new_list;
      new_list->valor = v1-v2;
      aux = new_list;
    }
    h1 = h1->next;
    h2 = h2->next;


  }
  // Return the item after the dummy
  return first->next;
}

int main(){

}