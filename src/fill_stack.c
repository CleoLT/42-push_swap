#include "../include/push_swap.h"

t_stack *find_last_node(t_stack *node)
{
    if (!node)
        return (NULL);
    while (node->next)
        node = node->next;
    return (node);
}

void	append_node(t_stack **stack, int value)
{
	t_stack *new_node;
	t_stack	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->value = value;
//	printf("append_node %d\n", new_node->value);

	if (!(*stack))
	{
		*stack = new_node;
		new_node->previous = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->previous = last_node;
	}
}

void	fill_stack(t_stack **node_a, char **argv)
{
	int value;
	int i;

	i = 1;
	while(argv[i])
	{
		value = atoi(argv[i]);
		printf("atoi: %d\n", value);
		append_node(node_a, value);
		i++;
	}
//	while(*node_a)
//	{
//		printf("fill_stack: %d\n", (*node_a)->value);
//		(*node_a) = (*node_a)->next;
//	}
}

