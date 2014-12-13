CC=gcc
CFLAGS=`pkg-config check --cflags` 
LFLAGS=`pkg-config check --libs`

all: stack queue

stack: ./src/stack_using_array/stack.c ./tests/test_stack_using_array.c 
	$(CC) $(CFLAGS) $? $(LFLAGS) -o $@

queue: ./tests/test_queue_using_array.c ./src/queue_using_array/queue.c
	$(CC) $(CFLAGS) $? $(LFLAGS) -o $@

install: stack queue
	./queue || ./stack
