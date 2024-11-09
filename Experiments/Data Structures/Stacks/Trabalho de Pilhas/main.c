#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    char link[20];
    struct node *previous;
} Node;
typedef struct sentinel {
    Node *top;
} Stack;

void push(char* val, Stack *target) {
    Node *redirect = (Node *)malloc(sizeof(Node));
    strcpy(redirect->link,val);
    redirect->previous = NULL;
    if(target->top == NULL) {
        target->top = redirect;
        return;
    }
    redirect->previous = target->top;
    target->top = redirect;
}

void pop(Stack *target) {
    if(target->top == NULL) {
        printf("Não posso retornar mais.\n");
        return;
    }
    Node *temp = target->top;
    target->top = target->top->previous;
    free(temp);
}

void freeAll(Stack *to_free) {
    while(to_free->top != NULL) {
        Node *target = to_free->top;
        to_free->top = to_free->top->previous;
        free(target);
    }
}

void browsingHistory(Stack *history) {
    Node *current = history->top;
    while(current != NULL) {
        printf("%s", current->link);
        current = current->previous;
    }
}
int main() {
    char input[20];
    Stack history;
    history.top = NULL;
    while(1) {
        scanf("%s", &input);
        if(strcmp(input,"R") == 0) {
            if(history.top)
            {
                printf("%s\n",history.top->link);
                pop(&history);
            } else {printf("empty\n");}

        }
        else if(strcmp(input,"Q") == 0) {
            break;
        }
        else {
            push(input, &history);
        }
    }
    freeAll(&history);
    return 0;
}