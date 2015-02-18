#include "linked_list.h"

struct node {
    struct node *next;
    int item;
};

static node* create_node() {
	node *newNode = (struct node *)malloc(sizeof(struct node));
	return newNode;
}

static bool create_head(node **first) {
	node *temp = (node *)malloc(sizeof(node)*1);
	if (temp == NULL) {
		puts("Unable to create sentinel node");
		return false;
	}
	*first = temp;
	(*first)->next = NULL;
	(*first)->item = 0;
	return true;
}

int insert_head(node **first, int item) {
    if (first == NULL) {
        puts("NULL node has been passed");
        return -1;
    }
	if (*first == NULL) {
		if (!create_head(first)) {
			return -2;
		}
	}
    node *temp = create_node();
    if (temp == NULL) {
        puts("No free space in memory");
        return -2;
    }
    temp->next = (*first)->next;
    (*first)->next = temp;
    temp->item = item;
    (*first)->item++;
    return 0;
}

int insert_tail(node **first, int item) {
    if (first == NULL) {
        puts("NULL node has been passed");
        return -1;
    }
	if (*first == NULL) {
		if (!create_head(first)) {
			return -2;
		}
	}
    node *temp = create_node();
    if (temp == NULL) {
        puts("No free space in memory");
        return -2;
    }
    temp->item = item;
    temp->next = NULL;
    node *last = *first;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = temp;
    (*first)->item++;
    return 0;
}

static int free_node(node **first) {
    if (*first == NULL) {
        puts("Nothing to free");
        return -3;
    }
    free(*first);
	*first = NULL;
    return 0;
}

int delete_head(node **first) {
    if (first == NULL) {
        puts("NULL node has been passed");
        return -1;
    }
    if (*first == NULL) {
        puts("Sentinel node not found");
        return -5;
    }
    if ((*first)->next == NULL) {
	puts("Nothing to delete");
	return -3;
    }
    node *temp = (*first)->next;
    (*first)->next = temp->next;
    temp->next = NULL;
    int item = temp->item;
    free_node(&temp);
    (*first)->item--;
    return item;
}

int delete_tail(node **first) {
    if (first == NULL) {
        puts("NULL node has been passed");
        return -1;
    }
    if (*first == NULL) {
        puts("Sentinel node not found");
        return -5;
    }
    if ((*first)->next == NULL) {
        puts("Nothing to delete");
        return -3;
    }
    node *previous = *first;
    node *current = (*first)->next;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    int item = current->item;
    free_node(&current);
    (*first)->item--;
    return item;
}

void display_contents(const node *first) {
	if (!first) {
		puts("The list has not been initialised with sentinel node");
		return;
	}
	/* Ignoring the sentinel node, as it is not part of the data */
	int num_data = first->item;
	first = first->next;
	int i = 0;
	/* This for loop will not print the correct data if the header info is not updated properly in the various functions.
	 * Can use a while loop that executes until `first->next` is NULL
	 */
	for (;i < num_data;i++) {
		printf("%d\t",first->item);
		first=first->next;
	}
	printf("\n");
	return;
}
