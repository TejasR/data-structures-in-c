#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"

struct queue {
    struct node *next;
    int front;
    int rear;
};

typedef struct queue queue;

int init(queue *);
int enqueue(queue *, int);
int dequeue(queue *);

#endif //QUEUE_H
