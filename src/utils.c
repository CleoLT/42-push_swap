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
	t_stack	*tmp;
	
	if (!node)
		return (NULL);
	tmp = node;
	while (node)
	{
		if (node->value > tmp->value)
			 tmp->value = node->value;
		node = node->next;
	}
	node = tmp;
	return (node);
}
