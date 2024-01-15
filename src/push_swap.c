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
	}
	printf("main:\n");
	print_stack(node_a);
	print_stack_rev(node_a);
	free_stack(&node_a);
	return (0);
}
