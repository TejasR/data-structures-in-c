#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
#define NULL_POINTER_ABORT -1
#define UNDERFLOW_ABORT -2
#define OVERFLOW_ABORT -3

struct stack {
    int st_array[SIZE];
    int st_top;
};

typedef struct stack stack;

int push(stack *, int);
int pop(stack *);
int peek(const stack *);
int init(stack *);

#endif // STACK_H
