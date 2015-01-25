#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct node {
    struct node *next;
    int item;
};

typedef struct node node;

int insert_head(node **, int);
int insert_tail(node **, int);
int delete_head(node **);
int delete_tail(node **);
bool isempty(const node *);
void display_contents(const node *);

#endif // LINKED_LIST_H
