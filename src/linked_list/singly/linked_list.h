#include <stdio.h>
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
node* create_node();
int free_node(node **);
