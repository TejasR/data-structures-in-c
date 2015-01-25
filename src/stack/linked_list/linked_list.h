#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <malloc.h>

struct node {
    struct node *next;
    int item;
};

typedef struct node node;

int insert_head(node **, int);
int delete_head(node **);

#endif // LINKED_LIST_H
