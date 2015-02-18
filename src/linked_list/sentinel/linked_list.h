#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdbool.h>
#include <malloc.h>

struct node;
typedef struct node node;

int insert_head(node **, int);
int insert_tail(node **, int);
int delete_head(node **);
int delete_tail(node **);
void display_contents(const node*);

#endif //LINKED_LIST_H
