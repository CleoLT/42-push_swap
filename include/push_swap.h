/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:31:35 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/05 16:08:12 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int					value;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

int	error_duplicate(t_stack *stack);
int	error_syntax(char **argv);
int	check_sorted(t_stack *stack);
void	ft_error(void);
void	free_stack(t_stack **stack);

void	fill_stack(t_stack **node_a, char **argv);

void	swap(t_stack **stack);

#endif
