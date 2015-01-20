CC=gcc
CFLAGS=-Wall -o3

all: stack_ua queue_ua circular_queue_ua singly stack_ull queue_ull doubly sentinel

stack_ua: ./src/stack/using_array/stack.c ./src/stack/using_array/stack.h ./tests/test_stack_using_array.c 
	$(CC) $(CFLAGS) ./src/stack/using_array/stack.c ./tests/test_stack_using_array.c -o $@

queue_ua: ./src/queue/using_array/simple_queue/queue.c ./src/queue/using_array/simple_queue/queue.h ./tests/test_queue_using_array.c
	$(CC) $(CFLAGS) ./tests/test_queue_using_array.c ./src/queue/using_array/simple_queue/queue.c -o $@
    
circular_queue_ua: ./src/queue/using_array/circular_queue/circular_queue.c ./src/queue/using_array/circular_queue/circular_queue.h ./tests/test_queue_using_array.c
	$(CC) $(CFLAGS) ./tests/test_queue_using_array.c ./src/queue/using_array/circular_queue/circular_queue.c -o $@
    
singly: ./src/linked_list/singly/linked_list.c ./src/linked_list/singly/linked_list.h ./tests/test_singly_linked_list.c
	$(CC) $(CFLAGS) ./src/linked_list/singly/linked_list.c ./tests/test_singly_linked_list.c -o $@

stack_ull: ./src/stack/linked_list/stack.c ./src/stack/linked_list/stack.h ./src/stack/linked_list/linked_list.h ./src/stack/linked_list/linked_list.c ./tests/test_stack_using_linked_list.c 
	$(CC) $(CFLAGS) ./src/stack/linked_list/stack.c ./src/stack/linked_list/linked_list.c ./tests/test_stack_using_linked_list.c -o $@

queue_ull: ./src/queue/linked_list/singly/linked_list.c ./src/queue/linked_list/singly/linked_list.h ./src/queue/linked_list/singly/queue.c ./src/queue/linked_list/singly/queue.h ./tests/test_queue_using_linked_list.c
	$(CC) $(CFLAGS) ./src/queue/linked_list/singly/queue.c ./src/queue/linked_list/singly/linked_list.c ./tests/test_queue_using_linked_list.c -o $@

doubly: ./src/linked_list/doubly/linked_list.c ./src/linked_list/doubly/linked_list.h ./tests/test_doubly_linked_list.c
	$(CC) $(CFLAGS) ./src/linked_list/doubly/linked_list.c ./tests/test_doubly_linked_list.c -o $@

sentinel: ./src/linked_list/sentinel/linked_list.c ./src/linked_list/sentinel/linked_list.h ./tests/test_sentinel_linked_list.c
	$(CC) $(CFLAGS) ./src/linked_list/sentinel/linked_list.c ./tests/test_sentinel_linked_list.c -o $@

install: stack_ua queue_ua circular_queue_ua stack_ull singly queue_ull doubly sentinel
	./stack_ua && ./queue_ua && ./circular_queue_ua && ./stack_ull && ./singly && ./queue_ull && ./doubly && ./sentinel

clean:
	rm queue_ua stack_ua circular_queue_ua singly stack_ull queue_ull doubly
