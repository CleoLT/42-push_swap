/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:44:06 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/19 17:34:44 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */#include "../include/push_swap.h"

void    set_index(t_stack *stack)
{
    int median;
    int i;

    i = 0;
    median = stack_len(stack);
	if (median % 2 == 0)
		median = median / 2;
	else
		median = (median + 1) / 2;
    while (i < median && stack)
    {
        stack->above_median = 1;
        stack->index = i;
        i++;
        stack = stack->next;
    }
    while (stack)
    {
        stack->index = i;
        stack->above_median = 0;
        stack = stack->next;
        i++;
    }
}

t_stack *get_cheapest(t_stack *node)
{
    int     min_cost;
    t_stack *cheapest_node;
	
	if (!node)
		return (NULL);
    min_cost = INT_MAX;
    while (node)
    {
        if (node->cost < min_cost)
        {
            min_cost = node->cost;
            cheapest_node = node;
        }
        node = node->next;
    }
    return (cheapest_node);
}

void	cheapest_on_top(t_stack **stack, t_stack *cheapest, char stack_name)
{
	while (*stack != cheapest)
	{
		if (cheapest->above_median)
		{
			if (stack_name == 'a')
				ft_ra(stack);
			else
				ft_rb(stack);
		}
		else
		{
			if (stack_name == 'a')
				ft_rra(stack);
			else
				ft_rrb(stack);
		}
	}
}
