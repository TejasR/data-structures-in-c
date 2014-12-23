CC=gcc
CFLAGS=-Wall -o3

all: stack queue circular_queue

stack: ./src/stack_using_array/stack.c ./src/stack_using_array/stack.h ./tests/test_stack_using_array.c 
	$(CC) $(CFLAGS) ./src/stack_using_array/stack.c ./tests/test_stack_using_array.c -o $@

queue: ./src/queue_using_array/queue.c ./src/queue_using_array/queue.h ./tests/test_queue_using_array.c
	$(CC) $(CFLAGS) ./tests/test_queue_using_array.c ./src/queue_using_array/queue.c -o $@
    
circular_queue: ./src/queue_using_array/circular_queue.c ./src/queue_using_array/circular_queue.h ./tests/test_queue_using_array.c
	$(CC) $(CFLAGS) ./tests/test_queue_using_array.c ./src/queue_using_array/circular_queue.c -o $@

install: stack queue circular_queue
	valgrind ./queue && valgrind ./stack && valgrind ./circular_queue
