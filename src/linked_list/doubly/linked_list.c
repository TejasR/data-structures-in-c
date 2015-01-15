#include "linked_list.h"

node* create_node() {
	node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
        puts ("What the hell?");
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
    temp->left = NULL;
    temp->right = *first;
    temp->item = item;
    if (*first != NULL) {
        (*first)->left = temp;
    }
    *first = temp;
	return 0;
}

int insert_tail(node **first, int item) {
    if (first == NULL) {
        printf("NULL node has been passed\n");
        return -1;
    }
    node *temp = create_node();
    if (temp == NULL) {
        printf("No free space in memory\n");
        return -2;
    }
    temp->item = item;
    temp->right = NULL;
    if (*first == NULL) {
        temp->left = NULL;
        *first = temp;
    } else {
        node *last = *first;
        while (last->right != NULL) {
            last = last->right;
        }
        last->right = temp;
        temp->left = last;
    }
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
    (*first) = (*first)->right;
    if (*first != NULL) {
        (*first)->left = NULL;
    }
    temp->right = NULL;
    int item = temp->item;
    free_node(&temp);
    return item;
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
    while (current->right != NULL) {
        previous = current;
        current = current->right;
    }
    if (previous == NULL) {
        *first = NULL;
    } else {
        previous->right = NULL;
    }
    current->left = NULL;
    int item = current->item;
    free_node(&current);
    return item;
}
