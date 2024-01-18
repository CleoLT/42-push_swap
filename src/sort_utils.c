/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:44:06 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/18 17:50:33 by ale-tron         ###   ########.fr       */
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
