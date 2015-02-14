#include "stack.h"

struct stack {
	int st_top;
	int st_array[SIZE];
};

static int init(stack **);

int push(stack **st, int item) {
	if (st == NULL) {
		printf("Bad pointer passed\n");
		return NULL_POINTER_ABORT;
	}
    if (*st == NULL) {
        if (init(st) != 0) {
			printf("Allocation of memory failed\n");
			return -1;
		}
    }
    if ((*st)->st_top == SIZE-1) {
        return OVERFLOW_ABORT;
    }
    (*st)->st_array[++(*st)->st_top] = item;
    return 0;
}

int pop(stack *st) {
    if (st == NULL) {
        return NULL_POINTER_ABORT;
    }
    if (st->st_top == -1) {
        return UNDERFLOW_ABORT;
    }
	return st->st_array[st->st_top--];
}

int peek(const stack *st) {
    if (st == NULL) {
        return NULL_POINTER_ABORT;
    }
    if (st->st_top == -1) {
        return UNDERFLOW_ABORT;
    }
    int i;
    for (i = 0; i <= st->st_top; i++) {
        printf("%d\t",st->st_array[i]);
    }
    printf("\n");
    return 0;
}

static int init(stack **st) {
	*st = (stack *)malloc(sizeof(stack));
    if ( *st == NULL ) {
        return NULL_POINTER_ABORT;
    }
    (*st)->st_top = -1;
    return 0;
}

