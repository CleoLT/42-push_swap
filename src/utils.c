/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:17:42 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/21 14:48:04 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

t_stack	*find_last_node(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

t_stack	*find_node_max(t_stack *node)
{
	int		max_value;
	t_stack	*max_node;

	if (!node)
		return (NULL);
	max_value = INT_MIN;
	while (node)
	{
		if (node->value > max_value)
		{
			max_value = node->value;
			max_node = node;
		}
		node = node->next;
	}
	return (max_node);
}

t_stack	*find_node_min(t_stack *node)
{
	int		min_value;
	t_stack	*min_node;

	if (!node)
		return (NULL);
	min_value = INT_MAX;
	while (node)
	{
		if (node->value < min_value)
		{
			min_value = node->value;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}

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
