#include "linked_list.h"

struct node {
    struct node *next;
    int item;
};

static node* create_node() {
	node *newNode = (struct node *)malloc(sizeof(struct node));
	return newNode;
}

int insert_head(node **first, int item) {
	errno = 0;
    if (first == NULL) {
        printf("NULL node has been passed\n");
		errno = EINVAL;
        return -1;
    }
	node *temp = create_node();
    if (temp == NULL) {
        printf("No free space in memory\n");
		errno = ENOMEM;
        return -1;
    }
    temp->next = *first;
    temp->item = item;
    *first = temp;
	return 0;
}

int insert_tail(node **first, int item) {
	errno = 0;
    if (first == NULL) {
        printf("NULL node has been passed\n");
		errno = EINVAL;
        return -1;
    }
    node *temp = create_node();
    if (temp == NULL) {
        printf("No free space in memory\n");
		errno = ENOMEM;
        return -1;
    }
    temp->item = item;
    temp->next = NULL;
    if (*first == NULL) {
        *first = temp;
    } else {
        node *last = *first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = temp;
    }
    return 0;
}

static int free_node(node **first) {
	errno = 0;
    if (*first == NULL) {
        printf("Nothing to free\n");
		errno = EINVAL;
        return -1;
    }
    free(*first);
	*first = NULL;
    return 0;
}

int delete_head(node **first) {
	errno = 0;
    if (first == NULL) {
        printf("NULL node has been passed\n");
		errno = EINVAL;
        return -1;
    }
    if (*first == NULL) {
        printf("Nothing to free\n");
		errno = EINVAL;
        return -1;
    }
    node *temp = *first;
    *first = (*first)->next;
    temp->next = NULL;
    int item = temp->item;
    free_node(&temp);
    return item;
}

int delete_tail(node **first) {
	errno = 0;
    if (first == NULL) {
        printf("NULL node has been passed\n");
		errno = EINVAL;
        return -1;
    }
    if (*first == NULL) {
        printf("Nothing to free\n");
		errno = EINVAL;
        return -1;
    }
    node *previous = NULL;
    node *current = *first;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        *first = NULL;
    } else {
        previous->next = NULL;
    }
    int item = current->item;
    free_node(&current);
    return item;
}

bool isempty(const node *first) {
	errno = 0;
	if (!first) {
		return true;
	} else {
		return false;
	}
}

void display_contents(const node *first) {
	errno = 0;
	if (!first) {
		puts("Null has been passed");
		return;
	}
	while (first->next) {
		printf("%d\t",first->item);
		first=first->next;
	}
	printf("\n");
	return;
}
