#include "minunit.h"
#include "../src/stack_using_array/stack.h"

stack st;
int tests_run = 0;

static char* test_normal_ops() {
    init(&st);

    push( &st, 10 );
    push( &st, 12 );

    mu_assert( "error, pop(&st) != 10", pop( &st ) == 12 );
    mu_assert( "error, pop(&st) != 12", pop( &st ) == 10 );

    init( &st );
    push( &st, 10 );
    mu_assert( "error, pop(&st) != 10", pop( &st ) == 10 );
    push( &st, 12 );
    push( &st, 14 );
    mu_assert( "error, pop(&st) != 10", pop( &st ) == 14 );
    push( &st, 16 );
    mu_assert( "error, pop(&st) != 10", pop( &st ) == 16 );
    push( &st, 18 );
    mu_assert( "error, pop(&st) != 10", pop( &st ) == 18 );
    mu_assert( "error, pop(&st) != 10", pop( &st ) == 12 );
    return 0;
}

static char* test_normal_peek() {
    init(&st);

    push( &st, 12 );
    mu_assert( "error, peek(&st) != 0", peek( &st ) == 0 );
    push( &st, 14 );
    mu_assert( "error, peek(&st) != 0", peek( &st ) == 0 );
    push( &st, 16 );
    mu_assert( "error, peek(&st) != 0", peek( &st ) == 0 );
    push( &st, 18 );
    mu_assert( "error, peek(&st) != 0", peek( &st ) == 0 );
    push( &st, 10 );
    mu_assert( "error, peek(&st) != 0", peek( &st ) == 0 );
    push( &st, 8 );
    mu_assert( "error, peek(&st) != 0", peek( &st ) == 0 );

    pop(&st);
    mu_assert( "error, peek(&st) != 0", peek( &st ) == 0 );
    pop(&st);
    mu_assert( "error, peek(&st) != 0", peek( &st ) == 0 );
    pop(&st);
    mu_assert( "error, peek(&st) != 0", peek( &st ) == 0 );
    pop(&st);
    mu_assert( "error, peek(&st) != 0", peek( &st ) == 0 );
    pop(&st);
    mu_assert( "error, peek(&st) != -2", peek( &st ) == -2 );
    pop(&st);
    mu_assert( "error, peek(&st) != -2", peek( &st ) == -2 );
    return 0;
}

static char* test_abnormal_push() {
    init(&st);

    push( &st, 12 );
    push( &st, 14 );
    push( &st, 16 );
    push( &st, 18 );
    push( &st, 10 );
    mu_assert( "error, push( &st, 15 ) != -3", push( &st, 15 ) == -3 );
    return 0;
}

static char* test_abnormal_pop() {
    init(&st);

    push( &st, 12 );
    mu_assert( "error, pop( &st ) != 12", pop( &st ) == 12 );
    mu_assert( "error, pop( &st ) != -2", pop( &st ) == -2 );
    return 0;
}

static char* test_null() {
    mu_assert( "error, push( NULL, 12 ) != -1", push( NULL, 12 ) == -1 );
    mu_assert( "error, pop( NULL ) != -1", pop( NULL ) == -1 );
    mu_assert( "error, init( NULL ) != -1", init( NULL ) == -1 );
    mu_assert( "error, peek( NULL ) != -1", peek( NULL ) == -1 );
    return 0;
}

static char* all_tests() {
    mu_run_test(test_normal_ops);
    mu_run_test(test_normal_peek);
    mu_run_test(test_abnormal_pop);
    mu_run_test(test_abnormal_push);
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
