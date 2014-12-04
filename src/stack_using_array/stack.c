#include "stack.h"

int push( stack *st , int item ) {
    if ( st == NULL ) {
        return NULL_POINTER_ABORT;
    }
    if ( st->st_top == SIZE-1 ) {
        return OVERFLOW_ABORT;
    }
    st->st_array[ ++st->st_top ] = item;
    return 0;
}

int pop( stack *st ) {
    if ( st == NULL ) {
        return NULL_POINTER_ABORT;
    }
    if ( st->st_top == -1 ) {
        return UNDERFLOW_ABORT;
    }
    return st->st_array[ st->st_top-- ];
}

int peek( const stack *st ) {
    if ( st == NULL ) {
        return NULL_POINTER_ABORT;
    }
    int i;
    for ( i = 0; i <= st->st_top; i++ ) {
        printf("%d\t",st->st_array[i]);
    }
    return 0;
}

int init( stack *st ) {
    if ( st == NULL ) {
        return NULL_POINTER_ABORT;
    }
    st->st_top = -1;
    return 0;
}
