CC=gcc
CFLAGS=-Wall -o3

all: stack queue

stack: ./src/stack_using_array/stack.c ./tests/test_stack_using_array.c 
	$(CC) $(CFLAGS) ./src/stack_using_array/stack.c ./tests/test_stack_using_array.c -o $@

queue: ./tests/test_queue_using_array.c ./src/queue_using_array/queue.c
	$(CC) $(CFLAGS)  ./tests/test_queue_using_array.c ./src/queue_using_array/queue.c -o $@

install: stack queue
	./queue
    ./stack
