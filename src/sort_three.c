/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:01:36 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/11 16:51:41 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	sort_three(t_stack **stack)
{
	int	max;

	max = find_node_max(*stack)->value;
	if ((*stack)->value == max)
		ft_ra(stack);
	else if ((*stack)->next->value == max)
		ft_rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		ft_sa(stack);

	print_stack(*stack);
	print_stack_rev(*stack);
}
