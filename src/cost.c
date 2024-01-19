/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:29:28 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/19 17:53:17 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */#include "../include/push_swap.h"

static void	simple_cost(t_stack *stack)
{
	int	len;

	len = stack_len(stack);
	while (stack)
	{
		if (stack->above_median)
			stack->cost = stack->index;
		else
            stack->cost = len - stack->index;
		stack = stack->next;
    }
}

static void	sum_target_cost(t_stack *a)
{
	while (a)
	{
		if (a->above_median == a->target->above_median && a->cost < a->target->cost)
			a->cost = a->target->cost;
		else if (a->above_median != a->target->above_median)
			a->cost = a->cost + a->target->cost;
		a = a->next;
	}
}

void    set_cost(t_stack *stack_a, t_stack *stack_b)
{
    int a_len;
    int b_len;

    a_len = stack_len(stack_a);
    b_len = stack_len(stack_b); 
	simple_cost(stack_a);
	simple_cost(stack_b);
//	print_cost(stack_a, "simple cost a");
//	print_cost(stack_b, "simple cost b");
	sum_target_cost(stack_a);
//	print_cost(stack_a, "sum target cost a");
}
