#include "circular_queue.h"

int init( queue *q ) {
    if ( q == NULL ) {
        return NULL_POINTER_ABORT;
    }
    q->q_rear = 0;
    q->q_front = 0;
    q->flag_for_MT = 0;
    return 0;
}

int enqueue( queue *q, int item ) {
    if ( q == NULL ) {
        return NULL_POINTER_ABORT;
    }
    if ( q->q_rear == q->q_front && q->flag_for_MT == 1 ) {
        return QUEUE_OVERFLOW;
    }
    q->flag_for_MT = 1;
    q->q_array[q->q_rear] = item;
    q->q_rear = (q->q_rear+1)%SIZE;
    return 0;
}

int dequeue( queue *q ) {
    if ( q == NULL ) {
        return NULL_POINTER_ABORT;
    }
    if ( q->q_front == q->q_rear && q->flag_for_MT == 0 ) {
        return QUEUE_UNDERFLOW;
    }
    if ( ( ( q->q_front + 1 ) % SIZE ) == q->q_rear ) {
        q->flag_for_MT = 0;
    }
    int item = q->q_array[q->q_front];
    q->q_front = (q->q_front + 1) % SIZE;
    return item;
}

int peek( queue *q ) {
    if ( q == NULL ) {
        return NULL_POINTER_ABORT;
    }
    if ( q->flag_for_MT == 0 ) {
        return QUEUE_UNDERFLOW;
    }
    int i = 0;
    for ( i = q->q_front; ; ) {
        printf("%d\t", q->q_array[i] );
        i = (i + 1) % SIZE;
        if ( i == q->q_rear ) {
            break;
        }
    }
    printf("\n");
    return 0;
}
