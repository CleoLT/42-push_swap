/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:17:57 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/05 16:31:19 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	error_syntax(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] && (argv[i][j] == '-' || argv[i][j] == '+'))
		{
			if (!ft_isdigit(argv[i][j + 1]))
				return (-1);
			j++;
		}
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (-1);
			j++;
		}
	//	printf("%d\n", ft_atoi(argv[i]) > 2147483647);
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			return (-1);
		i++;
	}
	return (0);
}

int	error_duplicate(t_stack *stack)
{
	t_stack *tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->value == tmp->value)
				return (-1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	check_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (1);		
		stack = stack->next;
	}
	return (0);
}

void free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack *current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->value = 0;
		free(current);
		current = tmp;	
	}
	*stack = NULL;
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}
