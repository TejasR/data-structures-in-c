* The sentinel is made to keep track of the number of nodes present in the list
* free_node function does not verify whether the double pointer is not null. This is because, it should not be called on its own and should only be called via the delete_head and delete_tail methods
