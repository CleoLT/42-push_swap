/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:09:38 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/20 15:13:17 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	set_target(t_stack *src, t_stack *target_node, char big_or_small)
{
	int		closest;
	t_stack	*target_count;

	while (src)
	{
		if (big_or_small == 's')
			closest = INT_MIN;
		else
			closest = INT_MAX;
		target_count = target_node;
		while (target_count && big_or_small == 's')
		{
			if (src->value > target_count->value && target_count->value >= closest)
			{
				closest = target_count->value;
				src->target = target_count;
			}
			target_count = target_count->next;
		}
		while (target_count && big_or_small == 'b')
		{
			if (src->value < target_count->value && target_count->value <= closest)
			{
				closest = target_count->value;
				src->target = target_count;
			}
			target_count = target_count->next;
		}
		if (closest == INT_MIN && big_or_small == 's')
			src->target = find_node_max(target_node);
		else if (closest == INT_MAX && big_or_small == 'b')
			src->target = find_node_min(target_node);
	//	printf("in set_target b %d \n", src->target->value);
		src = src->next;
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

void    min_on_top(t_stack **stack)
{
	t_stack	*node_min;

	node_min = find_node_min(*stack);
	while (*stack != node_min)
    {
        if (node_min->above_median)
            ft_ra(stack);
		else
			ft_rra(stack);
    }
}

void	b_to_a(t_stack **a, t_stack **b)
{
/*	t_stack *node;

	node = get_cheapest(*b);
//	printf("cheapest node : %d\n", node->value);
	if (node->above_median == node->target->above_median)
	{
		if (node->above_median)
		{
			while (*b != node && *a != node->target)
				ft_rr(a, b);
		}
		else if (!node->above_median)
			while (*b != node && *a != node->target)
				ft_rrr(a, b);
	}
	cheapest_on_top(b, node, 'b');
	cheapest_on_top(a, node->target, 'a');
//	ft_pb(a, b);
*/

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
		set_target(*stack_a, *stack_b, 's');
		set_cost(*stack_a, *stack_b);
		
	//	print_stack(*stack_a, "stack_a sort function");
	//	print_stack(*stack_b, "stack_b sort function");
	//	print_target(*stack_a, "stack_a targets");
	//	print_above_median(*stack_a, "stack_a above_median");
	//	print_cost(*stack_a, "sum target cost a");
		
		a_to_b(stack_a, stack_b);
	//	printf("\n\n");
			
	}
	sort_three(stack_a);
	while (*stack_b)
	{
//		printf("node min %d \n", find_node_min(*stack_b)->value);
		set_index(*stack_a);
		set_index(*stack_b);
		set_target(*stack_b, *stack_a, 'b');
		set_cost(*stack_b, *stack_a);
		


//		print_stack(*stack_a, "stack_a sort function");
//		print_stack(*stack_b, "stack_b sort function");
//		print_target(*stack_b, "stack_b targets");
	//	print_cost(*stack_b, "sum target cost b");
		b_to_a(stack_a, stack_b);
	}
//	print_stack(*stack_b, "stack_b sort function");
//	print_stack(*stack_b, "stack_b sort function");
	min_on_top(stack_a);
}
