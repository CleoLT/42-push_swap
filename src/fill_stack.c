#include "../include/push_swap.h"

static void	append_node(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->value = value;
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
	int	value;
	int	i;

	i = 1;
	while (argv[i])
	{
		value = atoi(argv[i]);
		append_node(node_a, value);
		i++;
	}
}
