#include "stack.h"

int init(stack *st) {
    if (!st) {
        puts("NULL has been passed");
        return -1;
    }
    st->next = (void*)0;
    st->top = -1;
    return 0;
}

int push(stack *st, int item) {
    int ret_val = insert_head(&(st->next), item);
    if (ret_val < 0) {
        return ret_val;
    }
    ++st->top;
    return 0;
}

int pop(stack *st) {
    if (!st) {
        puts("NULL has been passed");
        return -1;
    }
    if (st->top == -1) {
        puts("Underflow");
        return -2;
    }
    int ret_val = delete_head(&st->next);
    st->top--;
    return ret_val;
}
