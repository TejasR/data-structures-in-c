CC=gcc
CFLAGS=-Wall -o3

all: stack queue circular_queue

stack: ./src/stack/using_array/stack.c ./src/stack/using_array/stack.h ./tests/test_stack_using_array.c 
	$(CC) $(CFLAGS) ./src/stack/using_array/stack.c ./tests/test_stack_using_array.c -o $@

queue: ./src/queue/using_array/simple_queue/queue.c ./src/queue/using_array/simple_queue/queue.h ./tests/test_queue_using_array.c
	$(CC) $(CFLAGS) ./tests/test_queue_using_array.c ./src/queue/using_array/simple_queue/queue.c -o $@
    
circular_queue: ./src/queue/using_array/circular_queue/circular_queue.c ./src/queue/using_array/circular_queue/circular_queue.h ./tests/test_queue_using_array.c
	$(CC) $(CFLAGS) ./tests/test_queue_using_array.c ./src/queue/using_array/circular_queue/circular_queue.c -o $@

install: stack queue circular_queue
	valgrind ./queue && valgrind ./stack && valgrind ./circular_queue
