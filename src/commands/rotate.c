/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:32:08 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/10 18:23:13 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack *first;
	t_stack	*last;

	if (!*stack || !((*stack)->next))
		return ;
	last = find_last_node(*stack);
	first = *stack; 
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	last->next = first;
	first->next = NULL;
	first->previous = last;
}

void	ft_ra(t_stack **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}
