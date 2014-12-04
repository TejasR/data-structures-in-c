#include "queue.h"

int enqueue( queue *q, int item ) {
    if ( q == NULL ) {
        return NULL_POINTER_ABORT;
    }
    if ( q->q_rear == SIZE-1 ) {
        return QUEUE_OVERFLOW;
    }
    q->q_array[++q->q_rear] = item;
    return 0;
}

int dequeue( queue *q ) {
    if ( q == NULL ) {
        return NULL_POINTER_ABORT;
    }
    if ( q->q_rear == -1 ) {
        return QUEUE_UNDERFLOW;
    }
    if ( q->q_rear < q->q_front ) {
        return QUEUE_UNDERFLOW;
    }
    return q->q_array[q->q_front++];
}

int peek( queue *q ) {
    if ( q == NULL ) {
        return NULL_POINTER_ABORT;
    }
    if ( q->q_rear == -1 ) {
        return QUEUE_UNDERFLOW;
    }
    if ( q->q_rear < q->q_front ) {
        return QUEUE_UNDERFLOW;
    }
    int i;
    for ( i = q->q_front; i <= q->q_rear; i++ ) {
        printf( "%d\t", q->q_array[i] );
    }
    printf("\n");
    return 0;
}

int init( queue *q ) {
    if ( q == NULL ) {
        return NULL_POINTER_ABORT;
    }
    q->q_rear = -1;
    q->q_front = 0;
    return 0;
}
