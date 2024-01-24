/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:21:27 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/24 19:13:12 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

static void	ft_duplicate(t_stack *stack_a)
{
	if (error_duplicate(stack_a))
	{
		free_stack(&stack_a);
		ft_error();
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (error_syntax(argv) || error_int(argv))
		ft_error();
	fill_stack(&stack_a, argv);
	ft_duplicate(stack_a);
	if (!check_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			ft_sa(&stack_a);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}
