#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>

#define SIZE 5
#define NULL_POINTER_ABORT -1
#define QUEUE_OVERFLOW -2
#define QUEUE_UNDERFLOW -3

struct queue {
    int q_array[SIZE];
    int q_front;
    int q_rear;
};

typedef struct queue queue;

int enqueue( queue *, int );
int dequeue( queue * );
int peek( queue * );
int init( queue * );

#endif // QUEUE_H
