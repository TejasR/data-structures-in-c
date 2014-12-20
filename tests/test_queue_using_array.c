#include "minunit.h"
#include "../src/queue_using_array/queue.h"

queue q;
int tests_run = 0;

static char* test_normal_ops() {
    init(&q);

    enqueue( &q, 10 );
    enqueue( &q, 12 );

    mu_assert( "error, dequeue(&q) != 10", dequeue( &q ) == 10 );
    mu_assert( "error, dequeue(&q) != 12", dequeue( &q ) == 12 );

    init( &q );
    enqueue( &q, 10 );
    mu_assert( "error, dequeue(&q) != 10", dequeue( &q ) == 10 );
    enqueue( &q, 12 );
    enqueue( &q, 14 );
    mu_assert( "error, dequeue(&q) != 10", dequeue( &q ) == 12 );
    enqueue( &q, 16 );
    mu_assert( "error, dequeue(&q) != 10", dequeue( &q ) == 14 );
    enqueue( &q, 18 );
    mu_assert( "error, dequeue(&q) != 10", dequeue( &q ) == 16 );
    mu_assert( "error, dequeue(&q) != 10", dequeue( &q ) == 18 );
    return 0;
}

//START_TEST( test_normal_ops )
//{
//    enqueue( &q, 10 );
//    enqueue( &q, 12 );
//
//    ck_assert_int_eq( dequeue( &q ), 10 );
//    ck_assert_int_eq( dequeue( &q ), 12 );
//
//    init( &q );
//    enqueue( &q, 10 );
//    ck_assert_int_eq( dequeue( &q ), 10 );
//    enqueue( &q, 12 );
//    enqueue( &q, 14 );
//    ck_assert_int_eq( dequeue( &q ), 12 );
//    enqueue( &q, 16 );
//    ck_assert_int_eq( dequeue( &q ), 14 );
//    enqueue( &q, 18 );
//    ck_assert_int_eq( dequeue( &q ), 16 );
//    ck_assert_int_eq( dequeue( &q ), 18 );
//}
//END_TEST
//
//START_TEST( test_abnormal_enqueue )
//{
//    enqueue( &q, 12 );
//    enqueue( &q, 14 );
//    enqueue( &q, 16 );
//    enqueue( &q, 18 );
//    enqueue( &q, 10 );
//    ck_assert_int_eq( enqueue( &q, 15 ), -2 );
//}
//END_TEST
//
//START_TEST( test_abnormal_dequeue )
//{
//    enqueue( &q, 12 );
//
//    ck_assert_int_eq( dequeue( &q ), 12 );
//    ck_assert_int_eq( dequeue( &q ), -3 );
//}
//END_TEST
//
//START_TEST( test_null )
//{
//    ck_assert_int_eq( enqueue( NULL, 10 ), -1 );
//    ck_assert_int_eq( dequeue( NULL ), -1 );
//    ck_assert_int_eq( peek( NULL ), -1 );
//    ck_assert_int_eq( init( NULL ), -1 );
//}
//END_TEST
//
//Suite * queue_suite(void)
//{
//    Suite *s;
//    TCase *tc_core, *tc_abnormal;
//
//    s = suite_create("Queue");
//
//    /* Core test case */
//    tc_core = tcase_create("Core");
//    /* Abnormal test case */
//    tc_abnormal = tcase_create("Abnormal");
//
//    tcase_add_checked_fixture(tc_core, setup, teardown);
//    tcase_add_checked_fixture(tc_abnormal, setup, teardown);
//    tcase_add_test(tc_core, test_normal_ops);
//    tcase_add_test(tc_abnormal, test_abnormal_enqueue);
//    tcase_add_test(tc_abnormal, test_abnormal_dequeue);
//    tcase_add_test(tc_abnormal, test_null);
//    suite_add_tcase(s, tc_core);
//    suite_add_tcase(s, tc_abnormal);
//
//    return s;
//}

static char* all_tests() {
    mu_run_test(test_normal_ops);
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
