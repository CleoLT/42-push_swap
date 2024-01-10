/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:17:42 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/10 17:26:07 by ale-tron         ###   ########.fr       */
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
