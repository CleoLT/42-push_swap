/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:17:42 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/11 16:49:34 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

t_stack *find_last_node(t_stack *node)
{
    if (!node)
        return (NULL);
    while (node->next)
        node = node->next;
    return (node);
}

t_stack *find_node_max(t_stack *node)
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
