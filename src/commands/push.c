/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:06:19 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/17 16:30:01 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*first_node;

	first_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	if (!*dest)
	{
		*dest = first_node;
		(*dest)->next = NULL;
	}
	else
	{
		(*dest)->previous = first_node;
		first_node->next = *dest;
		*dest = first_node;
	}

}

void	ft_pb(t_stack **src_a, t_stack **dest_b)
{
	push(src_a, dest_b);
	ft_putstr_fd("pb\n", 1);
}

void	ft_pa(t_stack **src_b, t_stack **dest_a)
{
	push(src_b, dest_a);
	ft_putstr_fd("pa\n", 1);
}
