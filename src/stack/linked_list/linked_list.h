#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <malloc.h>

struct node;
typedef struct node node;

int insert_head(node **, int);
int delete_head(node **);
void display_contents(const node *);

#endif // LINKED_LIST_H
