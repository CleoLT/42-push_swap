/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:13 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/19 15:27:36 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	first = *stack;
	last = find_last_node(*stack);
	last->next = *stack;
	last->previous->next = NULL;
	first->previous = last;
	*stack = (*stack)->previous;
	(*stack)->previous = NULL;
}

void	ft_rra(t_stack **a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void    ft_rrb(t_stack **b)
{
    reverse_rotate(b);
    ft_putstr_fd("rrb\n", 1);
}

void    ft_rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
	reverse_rotate(b);
    ft_putstr_fd("rrr\n", 1);
}
