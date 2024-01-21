/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:09:38 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/21 17:29:25 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

static void	smaller_target(t_stack *stack_a, t_stack *stack_b)
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
		else if (smaller == INT_MIN && stack_a->target->value != INT_MIN)
			stack_a->target = find_node_max(stack_b);
		stack_a = stack_a->next;
	}
}

static void	bigger_target(t_stack *stack_b, t_stack *stack_a)
{
	int		bigger;
	t_stack	*a_count;

	while (stack_b)
	{
		bigger = INT_MAX;
		a_count = stack_a;
		while (a_count)
		{
			if (stack_b->value < a_count->value && a_count->value <= bigger)
			{
				bigger = a_count->value;
				stack_b->target = a_count;
			}
			a_count = a_count->next;
		}
		if (!stack_b->target)
			stack_b->target = find_node_min(stack_a);
		else if (bigger == INT_MAX && stack_b->target->value != INT_MAX)
			stack_b->target = find_node_min(stack_a);
		stack_b = stack_b->next;
	}
}

static void	a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = get_cheapest(*a);
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

static void	b_to_a(t_stack **a, t_stack **b)
{
	cheapest_on_top(a, (*b)->target, 'a');
	ft_pa(b, a);
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
		set_index(*stack_a);
		set_index(*stack_b);
		smaller_target(*stack_a, *stack_b);
		set_cost(*stack_a, *stack_b);
		a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		set_index(*stack_a);
		set_index(*stack_b);
		bigger_target(*stack_b, *stack_a);
		b_to_a(stack_a, stack_b);
	}
	min_on_top(stack_a);
}
