#include "minunit.h"
#include "../src/linked_list/doubly/linked_list.h"

int tests_run = 0;

static char* test_create_normal_op() {
    node *first = (void*)0;
    mu_assert("error, no free memory", (first = create_node()) != NULL);
    delete_head(&first);
    return 0;
}

static char* test_insert_head_normal_op() {
    node *first = NULL;
    mu_assert("error, unable to insert item into the list", insert_head(&first, 10) == 0);
    mu_assert("error, item not inserted at the head", first->item == 10);
    mu_assert("error, unable to insert item into the list", insert_head(&first, 12) == 0);
    mu_assert("error, item not inserted at the head", first->item == 12);
    delete_head(&first);
    delete_head(&first);
    return 0;
}

static char* test_insert_tail_normal_op() {
    node *first = NULL;
    mu_assert("error, unable to insert item into the list", insert_tail(&first, 10) == 0);
    mu_assert("error, item cannot be found", first->item == 10);
    mu_assert("error, unable to insert item into the list", insert_tail(&first, 12) == 0);
    node *temp = first;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    mu_assert("error, item cannot be found", temp->item == 12);
    delete_head(&first);
    delete_head(&first);
    return 0;
}

static char* test_free_node_normal_op() {
    node *first = NULL;
    insert_head(&first, 10);
    mu_assert("error, unable to free the memory being used by the node", free_node(&first) == 0);
    first = NULL;
    mu_assert("error, unable to free the memory being used by the node", free_node(&first) == -3);
    return 0;
}

static char* test_delete_head_normal_op() {
    node *first = NULL;
    mu_assert("error, unable to free the memory being used by the node", delete_tail(&first) == -3);
    insert_head(&first, 10);
    insert_head(&first, 12);
    mu_assert("error, unable to free the memory being used by the node", delete_head(&first) == 12);
    insert_tail(&first, 14);
    mu_assert("error, unable to free the memory being used by the node", delete_head(&first) == 10);
    delete_head(&first);
    return 0;
}

static char* test_delete_tail_normal_op() {
    node *first = NULL;
    mu_assert("error, unable to free the memory being used by the node", delete_tail(&first) == -3);
    insert_head(&first, 10);
    insert_head(&first, 12);
    mu_assert("error, unable to free the memory being used by the node", delete_tail(&first) == 10);
    insert_tail(&first, 14);
    mu_assert("error, unable to free the memory being used by the node", delete_tail(&first) == 14);
    delete_head(&first);
    return 0;
}

static char* test_null() {
    mu_assert("error, NULL passed", insert_head(NULL, 10) == -1);
    mu_assert("error, NULL passed", insert_tail(NULL, 10) == -1);
    mu_assert("error, NULL passed", delete_head(NULL) == -1);
    mu_assert("error, NULL passed", delete_tail(NULL) == -1);
    mu_assert("error, NULL passed", free_node(NULL) == -1);
    return 0;
}

static char* all_tests() {
    mu_run_test(test_create_normal_op);
    mu_run_test(test_insert_head_normal_op);
    mu_run_test(test_insert_tail_normal_op);
    mu_run_test(test_free_node_normal_op);
    mu_run_test(test_delete_head_normal_op);
    mu_run_test(test_delete_tail_normal_op);
    mu_run_test(test_null);
    return 0;
}

int main() {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);
    return result != 0;
}
