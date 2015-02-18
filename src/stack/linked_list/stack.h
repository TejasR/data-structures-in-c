#ifndef STACK_H
#define STACK_H

struct stack;
typedef struct stack stack;

int push(stack **, int );
int pop(stack *);
int peek(const stack *);

#endif //STACK_H
