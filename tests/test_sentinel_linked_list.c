#include "minunit.h"
#include "../src/linked_list/sentinel/linked_list.h"

int tests_run = 0;

/**
 * Test for create_node before it was made static
 *
	static char* test_create_normal_op() {
    	node *first = NULL;
    	mu_assert("error, no free memory", (first = create_node()) != NULL);
    	delete_head(&first);
    	return 0;
	}
 */

/**
 * What if sentinel node is already present, then it should ideally, not add another sentinel node - this is not being checked as this method is used internally in a controlled way and it is not exposed to the progrma which includes the header file
 *
	static char* test_create_head() {
		node *first = NULL;
		mu_assert("error, creation of head was unsuccessful", create_head(&first) == true);
		return 0;
	}
 */

/**
 * Tests:
 * 1. When list is empty
 * 2. When list is not empty
 */
static char* test_insert_head_normal_op() {
    node *first = NULL;
    /* List empty */
    mu_assert("error, unable to insert item into the list", insert_head(&first, 10) == 0);
    /* List not empty */
    mu_assert("error, unable to insert item into the list", insert_head(&first, 12) == 0);
    delete_head(&first);
    delete_head(&first);
    return 0;
}

/**
 * Tests:
 * 1. When list is empty
 * 2. When list is not empty
 */
static char* test_insert_tail_normal_op() {
    node *first = NULL;
    /* List empty */
    mu_assert("error, unable to insert item into the list", insert_tail(&first, 10) == 0);
    /* List not empty */
    mu_assert("error, unable to insert item into the list", insert_tail(&first, 12) == 0);
    delete_head(&first);
    delete_head(&first);
    return 0;
}

/**
 * Test for free_node before it was made static
 *
	static char* test_free_node_normal_op() {
    	node *first = NULL;
    	insert_head(&first, 10);
    	mu_assert("error, unable to free the memory being used by the node", free_node(&first) == 0);
    	return 0;
	}
 */

static char* test_delete_head_normal_op() {
    node *first = NULL;
    /* List empty */
    mu_assert("error, unable to free the memory being used by the node", delete_tail(&first) == -5);
    /* List not empty */
    insert_head(&first, 10);
    insert_head(&first, 12);
    mu_assert("error, unable to free the memory being used by the node", delete_head(&first) == 12);
    insert_tail(&first, 14);
    mu_assert("error, unable to free the memory being used by the node", delete_head(&first) == 10);
    mu_assert("error, unable to free the memory being used by the node", delete_head(&first) == 14);
    /* List empty */
    mu_assert("error, unable to free the memory being used by the node", delete_tail(&first) == -3);
    return 0;
}

static char* test_delete_tail_normal_op() {
    node *first = NULL;
    /* List empty */
    mu_assert("error, unable to free the memory being used by the node", delete_tail(&first) == -5);
    /* List not empty */
    insert_head(&first, 10);
    insert_head(&first, 12);
    mu_assert("error, unable to free the memory being used by the node", delete_tail(&first) == 10);
    insert_tail(&first, 14);
    mu_assert("error, unable to free the memory being used by the node", delete_tail(&first) == 14);
    mu_assert("error, unable to free the memory being used by the node", delete_tail(&first) == 12);
    /* List empty */
    mu_assert("error, unable to free the memory being used by the node", delete_tail(&first) == -3);
    return 0;
}

static char* test_display_contents() {
    node *first = NULL;
    /* Insert elements and check */
    insert_head(&first, 10);
    display_contents(first);
    insert_head(&first, 12);
    insert_tail(&first, 14);
    insert_tail(&first, 16);
    display_contents(first);
    delete_head(&first);
    display_contents(first);
    delete_tail(&first);
    delete_head(&first);
    delete_tail(&first);
    display_contents(first);
    return 0;
}

static char* test_null() {
    mu_assert("error, NULL was processed", insert_head(NULL, 10) == -1);
    mu_assert("error, NULL was processed", insert_tail(NULL, 10) == -1);
    mu_assert("error, NULL was processed", delete_head(NULL) == -1);
    mu_assert("error, NULL was processed", delete_tail(NULL) == -1);
    return 0;
}

static char* all_tests() {
    mu_run_test(test_insert_head_normal_op);
    mu_run_test(test_insert_tail_normal_op);
    mu_run_test(test_delete_head_normal_op);
    mu_run_test(test_delete_tail_normal_op);
	mu_run_test(test_display_contents);
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
