#include "stack.h"
#include "linked_list.h"

struct stack {
    struct node *next;
    int top;
};

static int init(stack **st);

static int init(stack **st) {
    *st = (stack*)malloc(sizeof(stack));
	if (!(*st)) {
		return -1;
	}
    (*st)->next = (void*)0;
    (*st)->top = -1;
    return 0;
}

int push(stack **st, int item) {
	if (!st) {
		printf("Bad pointer passed, it is null\n");
		return -1;
	}
	if (!(*st)) {
		if (init(st) != 0) {
			printf("No memory available\n");
			return -2;
		}
	}
    int ret_val = insert_head(&((*st)->next), item);
    if (ret_val < 0) {
        return ret_val;
    }
    ++(*st)->top;
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

int peek(const stack *st) {
	if (!st) {
		puts("NULL has been passed");
		return -1;
	}
    if (st->top == -1) {
        puts("Underflow");
        return -2;
    }
	display_contents(st->next);
	return 0;
}

