#include "linked_list.h"

struct node {
    struct node *left;
    struct node *right;
    int item;
};

static node* create_node() {
	node *newNode = (node *)malloc(sizeof(node));
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
		errno = EINVAL;
		return;
	}
	while (first->right) {
		printf("%d\t",first->item);
		first=first->right;
	}
	printf("\n");
	return;
}
