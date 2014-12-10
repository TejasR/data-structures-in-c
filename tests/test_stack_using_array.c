#include <check.h>
#include "../src/stack_using_array/stack.h"

stack st;

void setup() {
    init(&st);
}

void teardown() {
}

START_TEST( test_push_pop_normal_ops )
{
    push( &st, 10 );
    push( &st, 12 );
    ck_assert_int_eq( (int)pop( &st ), (int)12 );
    ck_assert_int_eq( pop( &st ), 10 );
}
END_TEST

START_TEST( test_pop_underflow )
{
    push( &st, 12 );
    ck_assert_int_eq( (int)pop( &st ), (int)12 );
    ck_assert_int_eq( pop( &st ), -2 );
}
END_TEST

START_TEST( test_push_overflow )
{
    push( &st, 2 );
    push( &st, 3 );
    push( &st, 4 );
    push( &st, 5 );
    push( &st, 6 );
    ck_assert_int_eq( push( &st, 7 ), -3 );
}
END_TEST

START_TEST( test_null_pointer )
{
    ck_assert_int_eq( init( NULL ), -1 );
    ck_assert_int_eq( push( NULL, 10 ), -1 );
    ck_assert_int_eq( pop( NULL ), -1 );
    ck_assert_int_eq( peek( NULL ), -1 );
}
END_TEST

Suite * stack_suite(void)
{
    Suite *s;
    TCase *tc_core, *tc_abnormal;

    s = suite_create("Stack");

    /* Core test case */
    tc_core = tcase_create("Core");
    /* Abnormal test case */
    tc_abnormal = tcase_create("Abnormal");

    tcase_add_checked_fixture(tc_core, setup, teardown);
    tcase_add_checked_fixture(tc_abnormal, setup, teardown);
    tcase_add_test(tc_core, test_push_pop_normal_ops);
    tcase_add_test(tc_abnormal, test_push_overflow);
    tcase_add_test(tc_abnormal, test_pop_underflow);
    tcase_add_test(tc_abnormal, test_null_pointer);
    suite_add_tcase(s, tc_core);
    suite_add_tcase(s, tc_abnormal);

    return s;
}

int main()
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = stack_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
