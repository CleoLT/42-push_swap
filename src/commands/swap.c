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
    printf("\n\ntmp = *stack\n");
	printf("A: %d        B: %d        C: %d\n", (*stack)->value, (*stack)->next->value, (*stack)->next->next->value);
    printf("tA: %d       tB: %d      tC: %d\n\n", tmp->value, tmp->next->value, tmp->next->next->value);


    *stack = (*stack)->next;
	printf("*stack = (*stack)->next\n");
    printf("A: %d       B: %d       C: %d\n", (*stack)->value, (*stack)->next->value, (*stack)->next->next->value);
printf("tA: %d       tB: %d      tC: %d\n\n", tmp->value, tmp->next->value, tmp->next->next->value);


    tmp->next = (*stack)->next;
	printf("tmp->next = (*stack)->next\n");
   	printf("A: %d       B: %d       C: %d\n", (*stack)->value, (*stack)->next->value, (*stack)->next->next->value);
printf("tA: %d       tB: %d      tC: %d\n\n", tmp->value, tmp->next->value, tmp->next->next->value);


    (*stack)->next = tmp;
	printf("(*stack)->next = tmp\n");
	printf("A: %d       B: %d       C: %d\n", (*stack)->value, (*stack)->next->value, (*stack)->next->next->value);
printf("tA: %d       tB: %d      tC: %d\n\n", tmp->value, tmp->next->value, tmp->next->next->value);

	printf("\n(*stack)->next->next->previous: %d\nnew\n", (*stack)->next->next->previous->value);
	(*stack)->next->next->previous = (*stack)->next;
	printf("\n(*stack)->next->next->previous: %d\n", (*stack)->next->next->previous->value);

	(*stack)->next->previous = *stack;
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
