#include "../include/push_swap.h"

void    print_stack(t_stack *node_a)
{
    while(node_a)
    {
        printf("%d ", node_a->value);
        node_a = node_a->next;
    }
    printf("\n");
}

void    print_stack_rev(t_stack *node_a)
{
    t_stack *tmp;

    tmp = find_last_node(node_a);
    while (tmp)
    {
        printf("%d ", tmp->value);
        tmp = tmp->previous;
    }
    printf("\n");
}


