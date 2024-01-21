/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:54:22 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/21 14:57:21 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	print_stack(t_stack *node_a, char *str)
{
	printf("%s:\n", str);
	while (node_a)
	{
		printf("%d ", node_a->value);
		node_a = node_a->next;
	}
	printf("\n");
}

void	print_stack_rev(t_stack *node_a, char *str)
{
	t_stack	*tmp;

	printf("%s:\n", str);
	tmp = find_last_node(node_a);
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->previous;
	}
	printf("\n");
}

void	print_target(t_stack *stack, char *str)
{
	printf("%s:\n", str);
	while (stack)
	{
		printf("%d ", stack->target->value);
		stack = stack->next;
	}
	printf("\n");
}

void	print_above_median(t_stack *stack, char *str)
{
	printf("%s:\n", str);
	while (stack)
	{
		printf("%d ", stack->above_median);
		stack = stack->next;
	}
	printf("\n");
}

void	print_index(t_stack *stack, char *str)
{
	printf("%s:\n", str);
	while (stack)
	{
		printf("%d ", stack->index);
		stack = stack->next;
	}
	printf("\n");
}

void	print_cost(t_stack *stack, char *str)
{
	printf("%s:\n", str);
	while (stack)
	{
		printf("%d ", stack->cost);
		stack = stack->next;
	}
	printf("\n");
}
