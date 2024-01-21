/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:09:38 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/21 14:12:11 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void    smaller_target(t_stack *stack_a, t_stack *stack_b)
{
    int     smaller;
    t_stack *b_count;

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
        if (smaller == INT_MIN)
            stack_a->target = find_node_max(stack_b);
        stack_a = stack_a->next;
    }
}

void    bigger_target(t_stack *stack_b, t_stack *stack_a)
{
    int     bigger;
    t_stack *a_count;
	int i=0;


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
		if (stack_b->target)
        //	printf("ieration %d , stack_b target %d \n", i, stack_b->target->value);
		if (bigger == INT_MAX && stack_b->target->value != INT_MAX)
		{
		//	printf("conditin\n");
            stack_b->target = find_node_min(stack_a);
		}
		stack_b = stack_b->next;
		i++;
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

void	b_to_a(t_stack **a, t_stack **b)
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
		
	//	print_stack(*stack_a, "stack_a sort function");
	//	print_stack(*stack_b, "stack_b sort function");
	//	print_target(*stack_a, "stack_a targets");
	//	print_above_median(*stack_a, "stack_a above_median");
	//	print_cost(*stack_a, "sum target cost a");
	//	printf("\n\n");
		a_to_b(stack_a, stack_b);
	//	printf("\n\n");
			
	}
	sort_three(stack_a);
	while (*stack_b)
	{
//		printf("node min %d \n", find_node_min(*stack_b)->value);
		set_index(*stack_a);
		set_index(*stack_b);
		bigger_target(*stack_b, *stack_a);


	//	print_stack(*stack_a, "stack_a sort function");
	//	print_stack(*stack_b, "stack_b sort function");
	//	print_target(*stack_b, "stack_b targets");
	//	printf("\n\n");

		b_to_a(stack_a, stack_b);


	}
//	print_stack(*stack_b, "stack_b sort function");
//	print_stack(*stack_b, "stack_b sort function");
	min_on_top(stack_a);
}
