/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:21:27 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/17 15:40:16 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (error_syntax(argv))
		ft_error();
	fill_stack(&stack_a, argv);
	if (error_duplicate(stack_a))
	{
		free_stack(&stack_a);
		ft_error();
	}
	if (!check_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			ft_sa(&stack_a);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort(&stack_a, &stack_b);	
	}
	printf("main:\n");
	print_stack(stack_a);
	print_stack_rev(stack_a);
	free_stack(&stack_a);
	return (0);
}
