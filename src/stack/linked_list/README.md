Changed the return value of unable to allocate memory to -4 from -2
So that pop will function similar to its array counterpart
There is no abnormal push, as the stack can continue to grow as long as there is memory available for allocation to the node.
There is no need to have an 'if (ret_val < 0)' for pop after delete_head as we have taken care of NULL and underflow cases