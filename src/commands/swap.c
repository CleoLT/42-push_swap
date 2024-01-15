/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:24:59 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/10 18:24:39 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !((*stack)->next))
		return ;
	
	tmp = *stack;
    *stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	tmp->next->previous = tmp;
	tmp->previous = *stack;
	(*stack)->previous = NULL;
}

void	ft_sa(t_stack **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
