#ifndef STACK_H
#define STACK_H

#include "linked_list.h"

struct stack {
    struct node *next;
    int top;
};

typedef struct stack stack;

int init(stack *);
int push(stack *, int );
int pop(stack *);
int peek(const stack *);

#endif //STACK_H
