/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:09:38 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/19 16:30:47 by ale-tron         ###   ########.fr       */
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

void	a_to_b(t_stack **a, t_stack **b)
{
	t_stack *node;

	node = get_cheapest(*a);
//	printf("cheapest node : %d\n", node->value);
	if (node->above_median == node->target->above_median)
	{
		if (node->above_median)
		{
			while (*a != node && *b != node->target)
				ft_rr(a, b);
		}
		else if (!node->above_median)
			while (*a != node && *b != node->target)
				ft_rrr(a, b);
	}
	cheapest_on_top(a, node, 'a');
	cheapest_on_top(b, node->target, 'b');
	ft_pb(a, b);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	a_len;
	int	i;

	a_len = stack_len(*stack_a);
	i = 0;
	while (i++ < 2 && a_len-- > 3 && !check_sorted(*stack_a))
		ft_pb(stack_a, stack_b);
//	while (a_len-- > 3 && !check_sorted(*stack_a))
	while (*stack_a)
	{
		set_index(*stack_a);
		set_index(*stack_b);
		smaller_target(*stack_a, *stack_b);
		set_cost(*stack_a, *stack_b);
		
		print_stack(*stack_a, "stack_a sort function");
		print_stack(*stack_b, "stack_b sort function");
		print_target(*stack_a, "stack_a targets");
		print_above_median(*stack_a, "stack_a above_median");
		print_cost(*stack_a, "sum target cost a");
		
		a_to_b(stack_a, stack_b);
		printf("\n\n");
			
	}
//	sort_three(stack_a);
	print_stack(*stack_b, "stack_b sort function");
//	print_target(*stack_a, "stack_a targets");
}
