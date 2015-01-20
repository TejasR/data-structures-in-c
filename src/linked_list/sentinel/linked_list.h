#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdbool.h>
#include <malloc.h>

struct node {
    struct node *next;
    int item;
};

typedef struct node node;

int insert_head(node **, int);
int insert_tail(node **, int);
int delete_head(node **);
int delete_tail(node **);
bool create_head(node **);
node *create_node();
int free_node(node **);

#endif //LINKED_LIST_H
