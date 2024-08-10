# get_next_line - erian

## The plan:

### - "char	*get_next_line(int fd)” - mother function that will:
    - Create a static list in which partial data from fd will be stored.
    - It should check for mistakes such as:
        - If the file is negative (then the file is not readable)
        - If the buffer that was created is greater than 0 (otherwise we could not copy from fd into the list)
        - If the file is readable (means that the read() function operates correctly)
    - Then we call another function "void	create_list(t_list **list, int fd)” that will copy by buffers from fd into the list.
    - Check if the created list is not NULL.
    - Call another function “char	*get_line(t_list *list)” that will get characters from list and copy them into char *next_line.
    - Call another function "void	polish_list(t_list **list)” that will polish the linked list for the next calls.
    - And finally - return next_line

### - "void	create_list(t_list **list, int fd)” - will copy by buffers from fd into the list.
    - Enter the while loop that will check if buf (size of 10 that will split the whole fd into lists containing 10 characters) doesn't contain '\n’.
    - Allocate memory for buf and do a quick check.
    - Run read() function and check if it went right, otherwise free().
    - Add '\0; to the buf and run "void	append(t_list **list, char *buf)” function that will copy buf into the list.

### - "int	found_newline(t_list *list)” - checks if the provided list contains '\n'.
    - Check if the list is NULL.
    - Go through all list and check if there is a '\n’ character, if yes - return 1 if no return 0.

### - "void	append(t_list **list, char *buf)” - will create nodes in the list and then will copy from received buf into the list.
    - Create new_node and last_node.
    - Use “t_list	*find_last_node(t_list *list)” to search for the last node and place it in the last_node
    - Allocate memory for the new_node and t_check if allocation went fine.
    - Then make a starting node through the if statement.
    - Otherwise, add a node to the end of the list
    - Copy buf into new node and set new_node→next to NULL

### - "t_list	*find_last_node(t_list *list)” - find last node.
    - Check if the given list is NULL, if so return NULL.
    - Otherwise, go to the last node and return it.

> At this point we have a uncutted blocks of buf from fd inside of a list, now we need to cut everything that is after the '\n’ and convert it into the char *. We go back to get_next_line function.
> 

### - “char	*get_line(t_list *list)” - will get characters from list and copy them into char *next_line.
    - Check if given list is NULL.
    - Use "int	len_to_newline(t_list *list)” to find length of the line in the list until it hits '\n'.
    - Allocate memory for the new char * according to the line length and check if it is NULL.
    - Use "void	copy_str(t_list *list, char *str)” to copy line  into char * and return it.

### - “int	len_to_newline(t_list *list)” - will go through the list and count characters until it reaches '\n'.

### - "void	copy_str(t_list *list, char *str)” - copy from the list to the str.

### - "void	polish_list(t_list **list)” - will polish the linked list for the next calls.
    - Create t_list for last_node and clear_node (malloc).
    - Create buf (malloc).
    - Check them both.
    - Assign last node to last_node.
    - Go through last node until it reaches '\0’ or '\n'.
    - Copy all characters after '\n’ to the buf, and set '\0'.
    - Copy buf to clear_node and set next to NULL (to mark the end of the list).
    - Run dealloc to clean previous line.

### - “void	dealloc(t_list **list, t_list *clean_node, char *buf)” - cleans the list.
    - Check if the list given is not NULL, if it is return nothing.
    - Enter the while loop where you will delete all nodes each by each.
    - Set list equal to NULL.
    - Check if the first character from the clean_node is not empty (NULL or '\0’).
    - If yes then assign clean_node to the list.
    - Otherwise, free buf and clean_code.