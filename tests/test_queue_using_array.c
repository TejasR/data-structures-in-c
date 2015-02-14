#include "minunit.h"
#include "../src/queue/using_array/simple_queue/queue.h"

queue *q;
int tests_run = 0;

static char* test_normal_ops() {
	q = NULL;
    enqueue( &q, 10 );
    mu_assert( "error, dequeue(q) != 10", dequeue( q ) == 10 );
    enqueue( &q, 12 );
    enqueue( &q, 14 );
    mu_assert( "error, dequeue(q) != 12", dequeue( q ) == 12 );
    enqueue( &q, 16 );
    mu_assert( "error, dequeue(q) != 14", dequeue( q ) == 14 );
    enqueue( &q, 18 );
    mu_assert( "error, dequeue(q) != 16", dequeue( q ) == 16 );
    mu_assert( "error, dequeue(q) != 18", dequeue( q ) == 18 );
    return 0;
}

static char* test_normal_peek() {
	q = NULL;
    enqueue( &q, 12 );
    mu_assert( "error, peek(q) != 0", peek( q ) == 0 );
    enqueue( &q, 14 );
    mu_assert( "error, peek(q) != 0", peek( q ) == 0 );
    enqueue( &q, 16 );
    mu_assert( "error, peek(q) != 0", peek( q ) == 0 );
    enqueue( &q, 18 );
    mu_assert( "error, peek(q) != 0", peek( q ) == 0 );
    enqueue( &q, 10 );
    mu_assert( "error, peek(q) != 0", peek( q ) == 0 );
    enqueue( &q, 8 );
    mu_assert( "error, peek(q) != 0", peek( q ) == 0 );

    dequeue(q);
    mu_assert( "error, peek(q) != 0", peek( q ) == 0 );
    dequeue(q);
    mu_assert( "error, peek(q) != 0", peek( q ) == 0 );
    dequeue(q);
    mu_assert( "error, peek(q) != 0", peek( q ) == 0 );
    dequeue(q);
    mu_assert( "error, peek(q) != 0", peek( q ) == 0 );
    dequeue(q);
    mu_assert( "error, peek(q) != -2", peek( q ) == -2 );
    dequeue(q);
    mu_assert( "error, peek(q) != -2", peek( q ) == -2 );
    return 0;
}

static char* test_abnormal_enqueue() {
	q = NULL;
    enqueue( &q, 12 );
    enqueue( &q, 14 );
    enqueue( &q, 16 );
    enqueue( &q, 18 );
    enqueue( &q, 10 );
    mu_assert( "error, enqueue( &q, 15 ) != -3", enqueue( &q, 15 ) == -3 );
    return 0;
}

static char* test_abnormal_dequeue() {
	q = NULL;
    enqueue( &q, 12 );
    mu_assert( "error, dequeue( q ) != 12", dequeue( q ) == 12 );
    mu_assert( "error, dequeue( q ) != -2", dequeue( q ) == -2 );
    return 0;
}

static char* test_null() {
    mu_assert( "error, enqueue( NULL, 12 ) != -1", enqueue( NULL, 12 ) == -1 );
    mu_assert( "error, dequeue( NULL ) != -1", dequeue( NULL ) == -1 );
    mu_assert( "error, peek( NULL ) != -1", peek( NULL ) == -1 );
    return 0;
}

static char* all_tests() {
    mu_run_test(test_normal_ops);
    mu_run_test(test_normal_peek);
    mu_run_test(test_abnormal_dequeue);
    mu_run_test(test_abnormal_enqueue);
    mu_run_test(test_null);
    return 0;
}

int main()
{
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);
    return result != 0;
}
