#define mu_assert(message, test) \
    do { \
        if (!(test)) { \
            printf("Line number is %d\n", __LINE__); \
            return message; \
        } \
    } while (0)
#define mu_run_test(test) \
    do { \
        char *message = test(); \
        tests_run++; \
        if (message) { \
            printf("Line number is %d\n", __LINE__); \
            return message; \
        }  \
    } while (0)
extern int tests_run;
