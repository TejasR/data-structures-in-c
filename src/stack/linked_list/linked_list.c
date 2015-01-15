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
        return -4;
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

int delete_head(node **first) {
    if (first == NULL) {
        printf("NULL node has been passed\n");
        return -1;
    }
    if (*first == NULL) {
        printf("Nothing to free\n");
        return -3;
    }
    node *temp = *first;
    *first = (*first)->next;
    temp->next = NULL;
    int item = temp->item;
    free_node(&temp);
    return item;
}
