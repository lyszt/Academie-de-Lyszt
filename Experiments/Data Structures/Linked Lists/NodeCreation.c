#include <stdio.h>
#include <stdlib.h>


typedef struct _node {
  int data;
  struct _node *next;

} Node;

Node* createNode(int entry, Node *previous){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node -> data = entry;
    if(previous != NULL){
        previous->next = new_node;
    } 
    return new_node;
}
Node* createChain(int size_n, int data){
    Node *head = NULL;
    Node *aux = NULL;
    for(int i = 0; i < size_n-1; i++){
        Node *new_node = (Node*)malloc(sizeof(Node));
        new_node -> data = data;
        new_node->next = NULL;

        if(head == NULL){
            head = new_node;}
        else{
            aux->next = new_node;}
        aux = new_node;   
    }
    return head;  
}


int main(){
    Node *head = createChain(150, (100));
    while(head)
    {
        printf("%d\n",head->data);
        head = head->next;
    }
}