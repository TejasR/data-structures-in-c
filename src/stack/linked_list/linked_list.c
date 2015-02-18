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

static int free_node(node **first) {
    free(*first);
	*first = NULL;
    return 0;
}

int delete_head(node **first) {
    node *temp = *first;
    *first = (*first)->next;
    temp->next = NULL;
    int item = temp->item;
    free_node(&temp);
    return item;
}

void display_contents(const node *first) {
	while (first) {
		printf("%d\t",first->item);
		first=first->next;
	}
	printf("\n");
	return;
}
