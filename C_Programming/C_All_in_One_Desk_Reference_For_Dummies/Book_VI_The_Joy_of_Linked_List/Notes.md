# NOTES
- Linked list is just pointers pointing one after another.

- Removing record from linked-list is easy. When some structure is not used anymore, make sure you call **free()** on it to clear it from memory.

- **Doubly** linked-list is nothing more than a linked list which contains pointer to **next** and **previous** items in list.

- To loop through linked-list **for(current = first; current != NULL; current = current->next)** is used.