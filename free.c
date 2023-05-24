#include "push_swap.h"

void    free_memory(t_node **stack)
{
    t_node  *curr;

    curr = *stack;
    while (stack)
    {
        curr->content = NULL;
        curr->index = NULL;
        curr = curr->next;
    }
    free(stack)
}