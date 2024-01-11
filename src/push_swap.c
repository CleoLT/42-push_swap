/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:21:27 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/11 16:50:29 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	stack_len(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

void	print_stack(t_stack *node_a)
{
 	while(node_a)
    {
        printf("%d ", node_a->value);
        node_a = node_a->next;
    }
	printf("\n");
}

void	print_stack_rev(t_stack *node_a)
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

int	main(int argc, char **argv)
{
	t_stack	*node_a;

	node_a = NULL;
	if (argc == 1)
		return (0);
	if (error_syntax(argv))
		ft_error();
	fill_stack(&node_a, argv);
	if (error_duplicate(node_a))
	{
		free_stack(&node_a);
		ft_error();
	}
	if (check_sorted(node_a))
	{
		if (stack_len(node_a) == 2)
			ft_sa(&node_a);
		else if (stack_len(node_a) == 3)
			sort_three(&node_a);
		printf("max_node: %d\n", find_node_max(node_a)->value);	
	}
	print_stack(node_a);
	print_stack_rev(node_a);
/*   while(node_a)
    {
        printf("main: %d\n", node_a->value);
        node_a = node_a->next;
    }
*/
	free_stack(&node_a);
	return (0);
}
