#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct _queue {
    char letter;
    struct _queue *next;
}; typedef struct _queue Queue;

struct _sentinel {
    Queue *head;
    Queue *tail;
}; typedef struct _sentinel Sentinel;

Sentinel* initializeSentinel(){
    Sentinel *new = (Sentinel*)malloc(sizeof(Sentinel));
    new->head = new->tail = NULL;
    return new;
}

int isEmptyQ(Sentinel* to_verify){
    if(to_verify->head == NULL && to_verify->tail == NULL){
        return 1;
    } 
    return 0;
}

Queue* createQueue(char input){
    Queue *new_queue = (Queue*)malloc(sizeof(Queue));
    new_queue->next = NULL;
    new_queue->letter = input;
    return new_queue;

}

void enQueue(Sentinel *target, char input){
    Queue* new_queue = createQueue(input);
    if(target->head == NULL){
        target->head = target->tail = new_queue;
        return;
    }
    target-> tail->next = new_queue;
    target-> tail = new_queue;

}
void deQueue(Sentinel* target){
    if(isEmptyQ(target)){
        printf("Queue underflow.\n");
        return;
    }
    Queue *temporaire = target->head;
    target->head = target->head->next;

    if(target->head == NULL){
        target->tail == NULL;
    }
    free(temporaire);
}



int main() {
    Sentinel *in_usage = initializeSentinel();

    char input[] = "Bordeaux";

    for(int i = 0; i < strlen(input); i++){
        enQueue(in_usage,input[i]);
    }
    while(in_usage->head != NULL){
        printf("%c\n",in_usage->head->letter);
        deQueue(in_usage);
        
    }
}