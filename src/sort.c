/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:09:38 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/17 19:46:34 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	smaller_target(t_stack *stack_a, t_stack *stack_b)
{
	int		smaller;
	t_stack	*b_count;

	while (stack_a)
	{
		smaller = INT_MIN;
		b_count = stack_b;
		while (b_count)
		{
			if (stack_a->value > b_count->value && b_count->value >= smaller)
			{
				smaller = b_count->value;
				stack_a->target = b_count;
			}
			b_count = b_count->next;
		}
		if (!stack_a->target)
			stack_a->target = find_node_max(stack_b);
		stack_a = stack_a->next;
	}
}

void	above_median(t_stack *stack)
{
	int	median;
	int	i;

	i = 0;
	median = stack_len(stack) / 2;
	while (i < median && stack)
	{
		stack->above_median = 1;
		i++;
		stack = stack->next;
	}
	while (stack)
	{
		stack->above_median = 0;
		stack = stack->next;
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	a_len;
	int	i;

	a_len = stack_len(*stack_a);
	i = 0;
	while (i++ < 2 && a_len-- > 3 && !check_sorted(*stack_a))
		ft_pb(stack_a, stack_b);
	while (a_len-- > 3 && !check_sorted(*stack_a))
	{
		ft_pb(stack_a, stack_b);
		above_median(*stack_a);
		smaller_target(*stack_a, *stack_b);
		print_stack(*stack_a, "stack_a sort function");
		print_stack(*stack_b, "stack_b sort function");
	//	print_target(*stack_a, "stack_a targets");
		print_above_median(*stack_a, "stack_a above_median");
		printf("\n\n");
	}
	sort_three(stack_a);
//	print_stack(*stack_b, "stack_b sort function");
//	print_target(*stack_a, "stack_a targets");
}
