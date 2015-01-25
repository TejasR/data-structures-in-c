#include "queue.h"

int enqueue( queue *q, int item ) {
    int ret_val = insert_head(&(q->next), item);
    if (ret_val < 0) {
        return ret_val;
    }
    ++q->rear;
    return 0;
}

int dequeue( queue *q ) {
    if (q == NULL) {
        puts("NULL has been passed");
        return -1;
    }
    if (q->front > q->rear) {
        puts("Queue underflow");
        return -2;
    }
    ++q->front;
    int ret_val = delete_tail(&(q->next));
    return ret_val;
}

int init( queue *q ) {
    if ( q == NULL ) {
        return -1;
    }
    q->rear = -1;
    q->front = 0;
    return 0;
}
