#include "linked_list.h"

node* create_node() {
	node *newNode = (struct node *)malloc(sizeof(struct node));
	return newNode;
}

int insert_head(node **first, int item) {
    if (first == NULL) {
        printf("NULL node has been passed\n");
        return -1;
    }
	node *temp = create_node();
    if (temp == NULL) {
        printf("No free space in memory\n");
        return -2;
    }
    temp->next = *first;
    temp->item = item;
    *first = temp;
	return 0;
}

int free_node(node **first) {
    if (first == NULL) {
        printf("NULL node has been passed\n");
        return -1;
    }
    if (*first == NULL) {
        printf("Nothing to free\n");
        return -3;
    }
    free(*first);
    return 0;
}

int delete_tail(node **first) {
    if (first == NULL) {
        printf("NULL node has been passed\n");
        return -1;
    }
    if (*first == NULL) {
        printf("Nothing to free\n");
        return -3;
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
